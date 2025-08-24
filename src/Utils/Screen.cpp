#include "Utils/Screen.hpp"
#include <SFML/Config.hpp>
#include <iostream>

#if defined(SFML_SYSTEM_WINDOWS)
    #include <windows.h>
#elif defined(SFML_SYSTEM_LINUX)
    #include <X11/Xlib.h>
    #include <X11/extensions/Xrandr.h>
#elif defined(SFML_SYSTEM_MACOS)
    #include <ApplicationServices/ApplicationServices.h>
#endif

namespace utils {
    ScreenInfo GetPrimaryMonitorResoulution() {
    #if defined(SFML_SYSTEM_WINDOWS)
        return { 0, 0, (unsigned int)GetSystemMetrics(SM_CXSCREEN), (unsigned int)GetSystemMetrics(SM_CYSCREEN) };
    #elif defined(SFML_SYSTEM_LINUX)
        const char* waylandDisplay = std::getenv("WAYLAND_DISPLAY");
        if (waylandDisplay) {
            sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
            return { 0, 0, desktop.width, desktop.height };
        }

        Display* display = XOpenDisplay(NULL);
        if (display) {
            Window root = DefaultRootWindow(display);
            XRRScreenResources* resources = XRRGetScreenResources(display, root);

            if (resources) {
                RROutput primaryOutput = XRRGetOutputPrimary(display, root);
                XRROutputInfo* outputInfo = XRRGetOutputInfo(display, resources, primaryOutput);

                if (outputInfo && outputInfo->crtc) {
                    XRRCrtcInfo* crtcInfo = XRRGetCrtcInfo(display, resources, outputInfo->crtc);

                    if (crtcInfo) {
                        ScreenInfo info = { crtcInfo->x, crtcInfo->y, crtcInfo->width, crtcInfo->height };
                        XRRFreeCrtcInfo(crtcInfo);
                        XRRFreeOutputInfo(outputInfo);
                        XRRFreeScreenResources(resources);
                        XCloseDisplay(display);
                        return info;
                    }
                    XRRFreeCrtcInfo(crtcInfo);
                }
                XRRFreeOutputInfo(outputInfo);
                XRRFreeScreenResources(resources);
            }
            XCloseDisplay(display);
        }

        std::cerr << "WARNING: can't get primary screen coords" << std::endl;

        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
        return { 0, 0, desktop.width, desktop.height };

    #elif defined(SFML_SYSTEM_MACOS)
        auto mainDisplayId = CGMainDisplayID();
        unsigned int width = CGDisplayPixelsWide(mainDisplayId);
        unsigned int height = CGDisplayPixelsHigh(mainDisplayId);
        return sf::VideoMode(width, height);

    #else
        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
        return { 0, 0, desktop.width, desktop.height };
    #endif
    }


}


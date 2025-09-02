#include <iostream>
#include "MobileAppManager.h"

int main() {
    MobileAppManager manager;

    manager.installApp("Instagram");
    manager.assignPermission("Instagram", "Camera");
    manager.assignPermission("Instagram", "Location");

    manager.installApp("WhatsApp");
    manager.assignPermission("WhatsApp", "Contacts");

    std::cout << "Installed Apps:\n";
    for (const auto& app : manager.listInstalledApps()) {
        std::cout << "- " << app << "\n";
        auto perms = manager.getPermissions(app);
        if (perms.empty()) {
            std::cout << "  No permissions assigned.\n";
        } else {
            for (const auto& perm : perms) {
                std::cout << "  * " << perm << "\n";
            }
        }
    }

    return 0;
}
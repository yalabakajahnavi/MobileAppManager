#include "MobileAppManager.h"

MobileAppManager::~MobileAppManager() {
    for (auto& pair : installedApps) {
        delete pair.second;
    }
}

bool MobileAppManager::installApp(const std::string& name) {
    if (installedApps.find(name) != installedApps.end()) return false;
    installedApps[name] = new App(name);
    return true;
}

bool MobileAppManager::uninstallApp(const std::string& name) {
    auto it = installedApps.find(name);
    if (it != installedApps.end()) {
        delete it->second;
        installedApps.erase(it);
        return true;
    }
    return false;
}

bool MobileAppManager::assignPermission(const std::string& appName, const std::string& permission) {
    auto it = installedApps.find(appName);
    if (it != installedApps.end()) {
        it->second->addPermission(permission);
        return true;
    }
    return false;
}

bool MobileAppManager::revokePermission(const std::string& appName, const std::string& permission) {
    auto it = installedApps.find(appName);
    if (it != installedApps.end()) {
        it->second->removePermission(permission);
        return true;
    }
    return false;
}

std::vector<std::string> MobileAppManager::listInstalledApps() {
    std::vector<std::string> appNames;
    for (const auto& pair : installedApps) {
        appNames.push_back(pair.first);
    }
    return appNames;
}

std::vector<std::string> MobileAppManager::getPermissions(const std::string& appName) {
    auto it = installedApps.find(appName);
    if (it != installedApps.end()) {
        return it->second->getPermissions();
    }
    return {};
}
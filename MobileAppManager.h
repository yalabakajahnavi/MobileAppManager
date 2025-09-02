#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <string>
#include <vector>
#include "App.h"

class MobileAppManager {
private:
    std::map<std::string, App*> installedApps;

public:
    ~MobileAppManager();
    bool installApp(const std::string& name);
    bool uninstallApp(const std::string& name);
    bool assignPermission(const std::string& appName, const std::string& permission);
    bool revokePermission(const std::string& appName, const std::string& permission);
    std::vector<std::string> listInstalledApps();
    std::vector<std::string> getPermissions(const std::string& appName);
};

#endif
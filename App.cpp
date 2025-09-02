#include "App.h"
#include <algorithm>

App::App(const std::string& name) : name(name) {}

std::string App::getName() const {
    return name;
}

void App::addPermission(const std::string& permission) {
    permissions.push_back(permission);
}

void App::removePermission(const std::string& permission) {
    permissions.erase(
        std::remove(permissions.begin(), permissions.end(), permission),
        permissions.end()
    );
}

std::vector<std::string> App::getPermissions() const {
    return permissions;
}
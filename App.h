#ifndef APP_H
#define APP_H

#include <string>
#include <vector>

class App {
private:
    std::string name;
    std::vector<std::string> permissions;

public:
    App(const std::string& name);
    std::string getName() const;
    void addPermission(const std::string& permission);
    void removePermission(const std::string& permission);
    std::vector<std::string> getPermissions() const;
};

#endif
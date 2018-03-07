#pragma once

#include <string>

class client {
public:
    explicit client(const std::string& host, const std::string& port);
    std::string invoke(const std::string& request);
};

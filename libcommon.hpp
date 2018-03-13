#pragma once

#include <cstdint>
#include <string>

class message {
private:
public:
    explicit message(std::string body = {});

    std::uint64_t id() const {
        return id_;
    }

    const std::string& body() const {
        return body_;
    }

    std::string to_string();

private:
    std::string body_;
    std::uint64_t id_{0};
};

#include "libclient.hpp"

#include <iostream>

#include "libcommon.hpp"

client::client(const std::string& host, const std::string& port) {
    std::cout << "client: connecting to port " << port << " on host " << host << "\n";
}

std::string client::invoke(const std::string& request) {
    message request_message(request);
    // Invoke server here.
    const auto reply_message = request_message;
    return {reply_message.body().crbegin(), reply_message.body().crend()};
}

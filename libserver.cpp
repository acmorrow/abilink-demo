#include "libserver.hpp"

#include <iostream>

#include "libcommon.hpp"

server::server() {
}

void server::run(int port) {
    std::cout << "server: listening on port" << port << "\n";
    while(true) {
        message request; // read a request and write it back.
    }
}

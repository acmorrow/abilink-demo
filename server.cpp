#include <cstdlib>
#include <iostream>

#include "libserver.hpp"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: server <port>\n";
        return EXIT_FAILURE;
    }

    server().run(std::atoi(argv[1]));

    return EXIT_SUCCESS;
}

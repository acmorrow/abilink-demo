#include <cstdlib>
#include <iostream>

#include "libclient.hpp"

int main(int argc, char* argv[]) {

    if (argc != 4) {
        std::cerr << "Usage: client <host> <port> <message>\n";
        return EXIT_FAILURE;
    }

    auto reply = client(argv[0], argv[1]).invoke(argv[3]);
    std::cout << reply << "\n";

    return EXIT_SUCCESS;
}

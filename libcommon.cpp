#include "libcommon.hpp"

#include <atomic>
#include <sstream>

namespace {
    std::atomic<std::uint64_t> next_id;
}

message::message(std::string body)
    : body_(std::move(body)) {
    id_ = next_id++;
}

std::string message::to_string() {
    std::stringstream buffer;
    buffer << "Message with id " << id() << " has contents " << "'" << body() << "'";
    return buffer.str();
}

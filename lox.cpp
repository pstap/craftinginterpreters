#include "lox.hpp"

namespace Lox {
    bool had_error = false;

    void report(int line, const std::string& where, const std::string& message) {
        std::cout << "[line " << line << "] Error" << where << ": " << message << '\n';
        had_error = true;
    }

    void error(int line, const std::string& message) {
        report(line, "", message);
    }

    void set_error(bool b) {
        had_error = b;
    }

    bool get_error() {
        return had_error;
    }
};

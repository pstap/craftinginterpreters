#ifndef LOX_H_
#define LOX_H_

#include <iostream>

namespace Lox {
    void report(int line, const std::string& where, const std::string& message);
    void error(int line, const std::string& message);
    void set_error(bool b);
    bool get_error();
};

#endif // LOX_H_

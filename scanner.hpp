#ifndef SCANNER_H_
#define SCANNER_H_

#include <vector>

#include "lox.hpp"
#include "token.hpp"

class Scanner {
    private:
        std::string source;
        std::vector<Token> tokens;

        int start = 0;
        int current = 0;
        int line = 1;

        bool is_at_end() const;
        char advance();
        void add_token(TokenType type);
        void add_token(TokenType type, Object literal);
        bool match(char expected);
        char peek() const;
        void string();

        void scan_token();
    public:
        Scanner(const std::string& source) : source(source) {}
        std::vector<Token> scan_tokens();
};

#endif // SCANNER_H_

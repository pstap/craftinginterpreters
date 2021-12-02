#include "token.hpp"


Token::Token(TokenType type, const std::string& lexeme, Object literal, int line) {
   this->type = type;
   this->lexeme = lexeme;
   this->literal = literal;
   this->line = line;
}

std::string Token::to_string() const {
    return this->lexeme;
}

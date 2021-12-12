#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>

enum class TokenType {
// Single-character tokens.
LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

// One or two character tokens.
BANG, BANG_EQUAL,
EQUAL, EQUAL_EQUAL,
GREATER, GREATER_EQUAL,
LESS, LESS_EQUAL,

// Literals.
IDENTIFIER, STRING, NUMBER,

// Keywords.
AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

END_OF_FILE
};

std::string token_type_to_string(TokenType t);

using Object = int;

class Token {
    public:
        Token(TokenType type, const std::string& lexeme, Object literal, int line);
        std::string to_string() const;
    private:
        TokenType type;
        std::string lexeme;
        Object literal;
        int line;
};


#endif // TOKEN_H_

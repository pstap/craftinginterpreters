#include "scanner.hpp"

#include <cctype> // for isdigit, isalpha
#include <string>
#include <map>

std::map<std::string, TokenType> keywords = {
    {"and", TokenType::AND},
    {"class", TokenType::CLASS},
    {"else", TokenType::ELSE},
    {"false", TokenType::FALSE},
    {"for", TokenType::FOR},
    {"fun", TokenType::FUN},
    {"if", TokenType::IF},
    {"nil", TokenType::NIL},
    {"or", TokenType::OR},
    {"print", TokenType::PRINT},
    {"return", TokenType::RETURN},
    {"super", TokenType::SUPER},
    {"this", TokenType::THIS},
    {"true", TokenType::TRUE},
    {"var", TokenType::VAR},
    {"while", TokenType::WHILE},
};


bool Scanner::is_at_end() const {
    return current >= source.length();
}

char Scanner::advance() {
    return source[current++];
}

void Scanner::add_token(TokenType type, Object literal) {
    const auto text = source.substr(start, current - start);
    tokens.push_back(Token(type, text, literal, line));
}

void Scanner::add_token(TokenType type) {
    add_token(type, 0);
}

bool Scanner::match(char expected) {
    if(is_at_end()) return false;
    if(source[current] != expected) return false;
    current++;
    return true;
}

char Scanner::peek() const {
    if(is_at_end()) return '\0';
    return source[current];
}

char Scanner::peek_next() const {
    if(current+1 >= source.length()) return '\0';
    return source[current+1];
}

void Scanner::string() {
    while(peek() != '"' && !is_at_end()) {
        if(peek() == '\n') line++;
        advance();
    }

    if(is_at_end()) {
        Lox::error(line, "Unterminated string.");
        return;
    }

    // closing "
    advance();

    // trim surrounding quotes
    const auto value = source.substr(start+1, current-1);

    // TODO put actual value here
    add_token(TokenType::STRING, 0);
}

void Scanner::number() {
    while(isdigit(peek())) advance();

    // look for fractional part
    if(peek() == '.' && isdigit(peek_next())) {
        advance();
        while(isdigit(peek())) advance();
    }

    float value = std::stof(source.substr(start, current - start));
    // TODO put actual value here
    add_token(TokenType::NUMBER, 15);
}

void Scanner::identifier() {
    const auto is_alpha_numeric = [](char c) -> bool { return isalpha(c) || isdigit(c); };
    while(is_alpha_numeric(peek())) advance();

    const auto text = source.substr(start, current - start);

    TokenType type;
    if(keywords.find(text) == keywords.end()) {
        type = TokenType::IDENTIFIER;
    } else {
        type = keywords[text];
    }

    add_token(type);
}

void Scanner::scan_token() {
    const char c = advance();
    switch(c) {
        case '(': add_token(TokenType::LEFT_PAREN); break;
        case ')': add_token(TokenType::RIGHT_PAREN); break;
        case '{': add_token(TokenType::LEFT_BRACE); break;
        case '}': add_token(TokenType::RIGHT_BRACE); break;
        case ',': add_token(TokenType::COMMA); break;
        case '.': add_token(TokenType::DOT); break;
        case '-': add_token(TokenType::MINUS); break;
        case '+': add_token(TokenType::PLUS); break;
        case ';': add_token(TokenType::SEMICOLON); break;
        case '*': add_token(TokenType::STAR); break;
        case '!':
            add_token(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
            break;
        case '=':
            add_token(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
            break;
        case '<':
            add_token(match('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
            break;
        case '>':
            add_token(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
            break;
        case '/':
            if(match('/')) {
                // comment goes to the end of the line
                while(peek() != '\n' && !is_at_end()) advance();
            } else {
                add_token(TokenType::SLASH);
            }
            break;
        case ' ':
        case '\r':
        case '\t':
            // ignorewhitespace
            break;
        case '\n':
            line++;
            break;
        case '"': string(); break;
        default:
            if(isdigit(c)) {
                number();
            } else if(isalpha(c)) {
                identifier();
            }
            else {
                Lox::error(line , "Unexpected character.");
            }
            break;
    }
}

std::vector<Token> Scanner::scan_tokens() {
    while(!is_at_end()) {
       start = current;
       scan_token();
    }
    tokens.push_back(Token(TokenType::END_OF_FILE, "", 1, line));
    return tokens;
}

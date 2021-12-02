#include "scanner.hpp"

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
    add_token(TokenType::STRING, value);
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
        case '"': string() break;
        default:
            Lox::error(line , "Unexpected character.");
            break;
    }
}

std::vector<Token> Scanner::scan_tokens() {
    while(!is_at_end()) {
       start = current;
       scan_token();
    }
    tokens.push_back(Token(TokenType::EOFF, "", 1, line));
    return tokens;
}

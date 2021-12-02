#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#include "lox.hpp"
#include "scanner.hpp"
#include "token.hpp"


void run(std::string code) {
    std::string lexeme;


    /*
    // adapted from: https://stackoverflow.com/a/46931770
    size_t pos_start = 0;
    size_t pos_end;
    while ((pos_end = code.find(' ', pos_start)) != string::npos) {
        lexeme = code.substr(pos_start, pos_end - pos_start);
        Token t = Token(TokenType::NUMBER, lexeme, 1, 1);
        pos_start = pos_end + 1;
        tokens.push_back(t);
    }
    lexeme = code.substr(pos_start, pos_end - pos_start);
    Token t = Token(TokenType::NUMBER, lexeme, 1, 1);
    tokens.push_back(t);
    */

    auto scanner = Scanner(code);
    auto tokens = scanner.scan_tokens();

    int i = 0;
    for(auto& x : tokens) {
        std::cout << i++ << ": " << x.to_string() << '\n';
    }
}

void run_file(std::string path) {
    std::ifstream in;
    in.open(path.c_str());
    std::stringstream stream;
    stream << in.rdbuf();
    std::string code = stream.str();
    run(code);
}

void run_prompt() {
    // REPL
    std::string buffer;

    while(true) {
        std::cout << "> "; // prompt
        std::getline(std::cin, buffer); // read

        if(buffer.length() == 0) {
            break;
        }

        run(buffer);
        Lox::set_error(false);
    }
}

int main(int argc, char *argv[]) {
    if(argc > 2) {
        std::cout << "Usage: " << argv[0] << " [script]\n";
        return 64;
    } else if(argc == 2) {
        run_file(argv[1]);
        if(Lox::get_error()) {
            return 65;
        }
    } else {
        run_prompt();
    }


    return 0;
}

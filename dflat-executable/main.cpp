#include <dflat/command_line_args.hpp>
#include <dflat/lexer.hpp>
#include <dflat/token.hpp>

#include <iostream>
#include <istream>

int main(int argc, char** argv) {
    const auto arg{ dflat::CommandLineArgs(argc, argv) };
    if (!arg.is_valid()) {
        return -1;
    }

    std::cout << "Absolute File: " << arg.get_file_runner() << '\n';
    std::ifstream ifs(arg.get_file_runner());

    auto lexer{ dflat::Lexer(ifs) };
    const auto& tokens{ lexer.tokenize() };
    for (const auto& token : tokens) {
        std::cout << token.type << ": " << token.token_value << '\n';
    }

}

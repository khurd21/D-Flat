#include <dflat/lexer.hpp>
#include <dflat/token.hpp>
#include <dflat/classifier.hpp>

#include <istream>
#include <iostream>
#include <vector>
#include <sstream>
#include <regex>

namespace {

const std::vector<std::pair<std::regex, dflat::Token::Type>> regex_to_token{
    { std::regex("[a-zA-Z][a-zA-Z0-9_]*"), dflat::Token::IDENTIFIER },
    { std::regex("\".*\""), dflat::Token::STRING },
    { std::regex("^[0-9]+$"), dflat::Token::LITERAL },
};

} // namespace

namespace dflat {

Lexer::Lexer(std::istream& is) : m_tokenized_values({}), m_is(is) {}

std::vector<Token> Lexer::tokenize() {
    if (!m_tokenized_values.empty()) {
        return m_tokenized_values;
    }

    std::vector<Token> tokens{};
    line_no line{ 1 };
    std::string buffer{};
    static const Token unknown_token("", Token::UNKNOWN);
    static Token identifier_token = unknown_token;

    bool is_identifier{ false };
    char c;
    while (true) {
        
        if (!is_identifier) {
            if (!(m_is >> std::noskipws >> c)) {
                break;
            }
        }
        std::cout << "IS IDENT? " << is_identifier << '\n';
        is_identifier = false;

        std::cout << "Buffer: " << buffer << '\n';
        std::cout << "Size: " << buffer.size() << '\n';
        std::cout << "C: " << c << '\n';
        if (c == '\n' || c == '\r') {
            if (!buffer.empty()) {
                std::cerr << "ERROR: on line " << line << ". Unknown token.\n";
                buffer = "";
            }
            ++line;
        }
        
        buffer.push_back(c);
        auto token{ this->get_token(buffer, line) };
        if (token.type == Token::WHITESPACE) {
            buffer = "";
            continue;
        }

        if (token.type == Token::WHITESPACE) {
            buffer = "";
            continue;
        }

        if (token.type == Token::IDENTIFIER) {
            identifier_token = token;
            continue;
        }

        // If it is an unknown, we need to check if it was an identifier the step before
        if (token.type == Token::UNKNOWN) {
            std::cout << "UNKNOWN TRIGGERED: " << token.token_value << " | SIZE: " << token.token_value.size() << '\n';
            if (identifier_token != unknown_token) {
                std::cout << " It is ident\n";
                token = identifier_token;
                identifier_token = unknown_token;
                is_identifier = true;
                buffer = "";
            }
            else continue;
        }

        buffer = "";
        identifier_token = unknown_token;
        std::cout << "Adding token: " << token.token_value << '\n';
        tokens.emplace_back(token);
    }

    m_tokenized_values = std::move(tokens);
    return m_tokenized_values;
}

Token Lexer::get_token(const std::string& buffer, const line_no line_number) const {

    for (const auto& value : Classifier::get_classifiers()) {
        if (value.contains(buffer)) {
            return Token(buffer, value.type());
        }
    }

    for (const auto& [regex, token] : regex_to_token) {
        if (std::regex_match(buffer, regex)) {
            return Token(buffer, token);
        }
    }

    return Token("", Token::UNKNOWN);
}

} // dflat
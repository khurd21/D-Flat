#include <dflat/syntax_tree.hpp>
#include <dflat/token.hpp>

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>

namespace {

constexpr std::string_view name_type_separator{ ":" };
constexpr std::string_view assignment_separator{ "=>" };
constexpr std::string_view open_function_separator{ "(" };
constexpr std::string_view closed_function_separator{ ")" };

const std::unordered_map<std::string, dflat::BaseType::DefinedType> literal_map{
    { "int", dflat::BaseType::INT },
    { "float", dflat::BaseType::FLOAT },
    { "string", dflat::BaseType::STRING },
};

} // namespace

namespace dflat {

AbstractSyntaxTree::AbstractSyntaxTree(const std::vector<Token>& tokens) {
    auto itr{ tokens.begin() };
    while (itr < tokens.end()) {

        if (itr->type == Token::IDENTIFIER) {
            if (itr + 4 >= tokens.end()) {
                std::cerr << "Error on line " << itr->line_number << ". Not enough arguments for identifier.\n";
                return;
            }
            const std::string& name{ itr->token_value };
            ++itr; // 1 :
            if (itr->token_value != name_type_separator) {
                std::cerr << "Error on line " << itr->line_number << ": expected " << name_type_separator << '\n';
                return;
            }
            ++itr; // 2 (
            if (itr->token_value == open_function_separator) {
                // TODO: Now we need to look for if it is a function type
            }

            // literal
            const auto literal_ptr{ literal_map.find(itr->token_value) };
            if (literal_ptr == literal_map.end()) {
                std::cerr << "Error on line " << itr->line_number << ": expected a literal type.\n";
                return;
            }

            ++itr; // 3 =>
            if (itr->token_value != assignment_separator) {
                std::cerr << "Error on line " << itr->line_number << ": expected " << assignment_separator << '\n';
                return;
            }

            // 4 value
            std::vector<BaseType> expression;
            while (++itr < tokens.end() && itr->type != Token::DELIM) {
                if (itr->type == Token::IDENTIFIER) {
                    // Check if the identifier is declared. If not, throw error.
                }
                else if (itr->type == Token::OPERATOR) {
                    // In this situation, variable_name is used as its value
                    expression.emplace_back(itr->token_value, itr->type);
                }
                else if (itr->type == Token::LITERAL) {
                    // TODO: May have to find if it is a float or int (only ints supported rn)
                    expression.emplace_back(itr->token_value, itr->type);
                }
                else {
                    // TODO: Throw an exception, not supported type.
                }
            }
        }

    }
}

} // namespace dflat
#ifndef DFLAT_TOKEN_HPP
#define DFLAT_TOKEN_HPP

#include <string>

namespace dflat {

struct Token  {

    enum Type {
        IDENTIFIER,
        KEYWORD,
        STRING,
        LITERAL,
        OPERATOR,
        DELIM,
        WHITESPACE,
        UNKNOWN,
    }; // enum Type

    Type type;
    std::string token_value;

    Token() = delete;

    Token(const std::string& token_value, const Type token_type);

}; // struct Token

inline bool operator==(const Token& lhs, const Token& rhs) {
    return lhs.token_value == rhs.token_value && lhs.type == rhs.type;
}

inline bool operator!=(const Token& lhs, const Token& rhs) {
    return !(lhs == rhs);
}

} // namespace dflat

#endif // DFLAT_TOKEN_HPP
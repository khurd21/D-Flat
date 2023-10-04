#include <dflat/token.hpp>

#include <string>

namespace dflat {

Token::Token(const std::string& token_value, const Type token_type)
    : type(token_type), token_value(token_value) {}

} // namespace dflat
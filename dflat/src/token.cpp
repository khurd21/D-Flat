#include <dflat/token.hpp>

#include <string>
#include <cstdint>

namespace dflat {

Token::Token(const std::string& token_value, const Type token_type, const std::uint64_t line_number)
    : type(token_type), token_value(token_value), line_number(line_number) {}

} // namespace dflat
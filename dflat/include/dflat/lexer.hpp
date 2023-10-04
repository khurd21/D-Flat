#ifndef DFLAT_LEXER_HPP
#define DFLAT_LEXER_HPP

// TODO: Can I somehow forward declare this Token struct 
// TODO: Or use a different include file for forward declaration?
#include <dflat/token.hpp>

#include <string>
#include <istream>
#include <fstream>
#include <vector>

namespace dflat {

using line_no = unsigned int;

class Lexer {
public:
    Lexer() = delete;
    Lexer(std::istream& is);

    std::vector<Token> tokenize();

private:

    Token get_token(const std::string& buffer, const line_no line_number) const;

    std::vector<Token> m_tokenized_values;
    std::ifstream m_ifs;
    std::istream& m_is;

}; // class Lexer

} // namespace dflat

#endif // DFLAT_LEXER_HPP
#include <dflat/classifier.hpp>
#include <string>
#include <vector>

namespace dflat {

Classifier::Classifier(const Token::Type ttype, const std::string& name, const std::unordered_set<std::string>& tokens)
    : m_token_type(ttype), m_name(name), m_tokens(tokens) {}

bool Classifier::contains(const std::string& token) const {
    return m_tokens.find(token) != m_tokens.end();
}

Token::Type Classifier::type() const {
    return m_token_type;
}

std::vector<Classifier> Classifier::get_classifiers() {
    static std::vector<Classifier> classifiers{
        { Token::OPERATOR, "Operator", { "+", "-", "/", "*", "<", ">", "<=", ">=" } },
        { Token::DELIM, "Delimeter", { ",", ":", "=>", "{", "}", "[", "]" , "(", ")" } },
        { Token::KEYWORD, "Keyword", { "return", "print", "str", "list", "int", "float" } },
        { Token::WHITESPACE, "Whitespace", { "\n", "\r", "\t", "\0", " " } },
    };
    return classifiers;
}

} // namespace dflat
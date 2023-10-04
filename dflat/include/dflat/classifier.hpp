#ifndef DFLAT_CLASSIFIER_HPP
#define DFLAT_CLASSIFIER_HPP

#include "token.hpp"

#include <unordered_set>
#include <string>
#include <vector>

namespace dflat {

class Classifier {
public:
    Classifier() = delete;
    bool contains(const std::string& token) const;
    Token::Type type() const;
    static std::vector<Classifier> get_classifiers();

private:
    Classifier(const Token::Type ttype, const std::string& name, const std::unordered_set<std::string>& tokens);

    Token::Type m_token_type;
    std::string m_name;
    std::unordered_set<std::string> m_tokens;

}; // class Classifier

} // namespace dflat

#endif // DFLAT_CLASSIFIER_HPP

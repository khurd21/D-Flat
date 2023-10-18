#ifndef DFLAT_SYNTAX_TREE_HPP
#define DFLAT_SYNTAX_TREE_HPP

#include <memory>
#include <cstdint>
#include <string>
#include <unordered_set>
#include <vector>

namespace dflat {
    struct Token;
}

namespace dflat {

class BaseType {
public:
    enum DefinedType {
        INT,
        FLOAT,
        STRING,
        FUNCTION,
        OPERATION,
        ADD,
        SUBTRACT,
        DIVIDE,
        MULTIPLY,
        UNKNOWN,
    }; // enum LiteralType
    std::string variable_name;
    DefinedType type;

    BaseType(const std::string& variable_name, const DefinedType type) : variable_name(variable_name), type(type) {}

}; // class BaseType

class OperationEvaluator {
public:
    struct OperationContainer {
        std::string value;
        BaseType::DefinedType type;
    }; // struct OperationContainer
    OperationEvaluator(const std::vector<BaseType::DefinedType>& expression);

};

class DeclarationType : public BaseType {
public:
    std::string value;

    DeclarationType(const std::string& variable_name, const DefinedType type, const std::vector<BaseType::DefinedType>& expression)
        : BaseType(variable_name, type), value(value), evaluator(expression) {}

private:
    OperationEvaluator evaluator;

}; // struct DeclarationType

class FunctionType : public BaseType {
public:
    std::unordered_set<DeclarationType> parameters;
    DefinedType return_type;
    // TODO: Tree of the Actual Program. //

}; // struct FunctionType

class AbstractSyntaxTree {
public:

    AbstractSyntaxTree(const std::vector<Token>& tokens);

};

} // namespace dflat

#endif // DFLAT_SYNTAX_TREE_HPP
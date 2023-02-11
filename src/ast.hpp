#ifndef AST_H
#define AST_H
#include <string>
#include <memory>
#include <vector>

struct ExprAST {
	virtual ~ExprAST() = default;
};
struct NumberExprAST : public ExprAST {
	double Val;
	NumberExprAST(double _Val) : Val(_Val) {}
};
struct VariableExprAST : public ExprAST {
	std::string Name;
	VariableExprAST(std::string& _Name) : Name(_Name) {}
};
struct BinaryExprAST : public ExprAST {
	char Op;
	std::unique_ptr<ExprAST> LHS, RHS;
	BinaryExprAST(char _Op, std::unique_ptr<ExprAST> _LHS, std::unique_ptr<ExprAST> _RHS) :
		Op(_Op), LHS(std::move(_LHS)), RHS(std::move(_RHS)) {}
};
struct CallExprAST : public ExprAST {
	std::string Callee;
	std::vector<std::unique_ptr<ExprAST>> Args;
	CallExprAST(std::string& _Callee, std::vector<std::unique_ptr<ExprAST>> _Args) :
		Callee(_Callee), Args(std::move(_Args)) {}
};
struct PrototypeAST {
	std::string Name;
	std::vector<std::string> Args;
	PrototypeAST(std::string& _Name, std::vector<std::string> _Args) :
		Name(_Name), Args(std::move(_Args)) {}
	const std::string &getName() const { return Name; }
};
struct FunctionAST {
	std::unique_ptr<PrototypeAST> Proto;
	std::unique_ptr<ExprAST> Body;
};
#endif

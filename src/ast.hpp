#ifndef AST_H
#define AST_H
struct AST {
	virtual ~AST() = default;
};
struct NumberExprAST : public AST {
	double Val;
	NumberExprAST(double _Val) : Val(_Val) {}
};
#endif

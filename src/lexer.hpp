#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <cstdio>
struct Lexer {
	enum Token {
		tok_eof = -1,

		// commands
		tok_def = -2,
		tok_extern = -3,

		// primary
		tok_identifier = -4,
		tok_number = -5,
	};
	static std::string IdentifierStr;
	static double NumVal;
	static std::string CommentStr;
	static int gettok();
};
#endif

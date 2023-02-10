#include "lexer.hpp"
#include <cstdio>
#include <cstdlib>

int Lexer::gettok() {
	static int LastChar = ' ';
	while (isspace(LastChar))
		LastChar = getchar();

	// identify keywords
	if (isalpha(LastChar)) {
		IdentifierStr = LastChar;
		while (isalnum((LastChar = getchar()))) {
			IdentifierStr += LastChar;
		}

		if (IdentifierStr == "def")
			return tok_def;
		if (IdentifierStr == "extern")
			return tok_extern;

		// otherwise is just some identifier token
		return tok_identifier;
	}

	// identify numbers
	if (isdigit(LastChar) || LastChar == '.') {
		std::string NumStr;

		// I can see an error like I input "..."
		// and it parses this as a number
		do {
			NumStr += LastChar;
			LastChar = getchar();
		} while (isdigit(LastChar) || LastChar == '.');

		// set NumVal to be a number
		NumVal = strtod(NumStr.c_str(), 0);
		return tok_number;
	}

	// comments
	if (LastChar == '#') {
		do {
			// the comment string does not include the '#'
			LastChar = getchar();
			CommentStr += LastChar;
		} while (LastChar != '\n' && LastChar != EOF && LastChar != '\r');

		if (LastChar != EOF)
			return gettok(); // this will error or is not a real token since it's some 8bit integer
	}

	if (LastChar == EOF)
		return tok_eof;

	LastChar = getchar();
	return getchar();
}

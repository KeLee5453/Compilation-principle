#pragma warning(disable:4996)
#include<iostream>
#include<fstream>
#include "../../../work7_PG/myparser.h"
#include "symbol.h"
#include "grammer_tree.h"

#include<set>
#include "../../../work7_PG/mylexer.h"

using namespace std;

extern symbol_table_type symtbl;
extern GrammerTree parse_tree;

int main() {
#if 0
	GrammerTreeNode * t;
	t = parse_tree.MakeNode(LEAF_NODE, CONST_LEAF, 'c', Char);
	t->output();
	t = parse_tree.MakeNode(STMT_NODE, COMP_STMT, 0, Notype);
	t->output();
	t = parse_tree.MakeNode(EXPR_NODE, COND_EXPR, 0, Notype);
	t->output();
	t = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, MINUS, Notype);
	t->output();
	t = parse_tree.MakeNode(DECL_NODE, VAR_DECL, 0, Notype);
	t->output();
#endif
//#if 0
	int n = 1;
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			freopen("test.txt", "r", stdin);
			n = parser.yyparse();
			freopen("CON", "r", stdin);

			ofstream out("test.asm");
			parse_tree.GetLabelProc();
			parse_tree.GenerateCodeProc(out);
		}
	}
//#endif
	system("pause");
	return 0;

}
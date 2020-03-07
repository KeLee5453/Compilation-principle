#pragma once
#pragma warning(disable:4996)
#ifndef _GRAMMER_TREE_H_
#define _GRAMMER_TREE_H_

#include<vector>

using namespace std;

enum {
	STMT_NODE = 0,
	EXPR_NODE,
	DECL_NODE,
	LEAF_NODE
};

enum {
	COMP_STMT = 0,
	EXPR_STMT,
	IF_STMT,
	SWITCH_STMT,
	WHILE_STMT,
	DO_WHILE_STMT,
	FOR_STMT,
	JUMP_STMT,
	INPUT_STMT,
	PRINT_STMT
};

enum {
	TYPE_LEAF=0,
	CONST_LEAF,
	ID_LEAF
};

enum {
	PRIMARY_EXPR=0,
	POSTFIX_EXPR,
	UNARY_EXPR,
	CAST_EXPR,
	OP_EXPR,
	COND_EXPR,
	EXPR_EXPR
};

enum {
	VAR_DECL = 0,
	ARRAY_DECL,
	DECLARATOR
};

enum {
	Notype = 0,
	Integer,
	Char,
	Double,
	Boolean
};

union NodeAttr {
	int op;
	int vali;
	char valc;
	double vald;
	int symtbl_seq;

	NodeAttr(void) { op = 0; }
	NodeAttr(int i) { op = i; }
	NodeAttr(char c) { valc = c; }
	NodeAttr(double d) { vald = d; }
};

struct Label {
	struct {
		string true_label;
		string false_label;
	};
	struct {
		string begin_label;
		string next_label;
	};
};

struct GrammerTreeNode {
	vector<GrammerTreeNode*> children;
	GrammerTreeNode * sibling;
	int lineno;
	int node_type;
	int node_kind;
	NodeAttr attr;
	int type;
	int seq;
	int temp_var;
	Label label;

	void output(void);
};

typedef vector<GrammerTreeNode*>::iterator GTN_iter;

class GrammerTree {
private:
	GrammerTreeNode *root;
	static int node_seq;
	static int temp_var_seq;
	static int label_seq;
	static int temp_var_size;
private:
	string NewLabel(void);
	void RecursiveGetLabel(GrammerTreeNode *t);
	void GenerateHeader(ostream &out);
	void GenerateDecl(ostream &out);
	void RecursiveGenCode(ostream &out, GrammerTreeNode *t);
	void GenerateWaitKey(ostream &out);

public:
	GrammerTreeNode * MakeNode(int node_type, int node_kind, NodeAttr attr,
		int type);
	void TypeCheck(GrammerTreeNode *t);
	void GetTempVar(GrammerTreeNode *t);
	void GetLabelProc(void);
	void GenerateCodeProc(ostream &out);
};
#endif // !_GRAMMER_TREE_H_

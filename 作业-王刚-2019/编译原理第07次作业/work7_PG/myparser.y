%{
#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "mylexer.h"
#include "grammer_tree.h"
#include "symbol.h"

#include <set>

extern GrammerTree parse_tree;
extern symbol_table_type symtbl;


set<int> id_pos;
int decl_var_cnt=0;
	%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// attribute type
%include{
#ifndef YYSTYPE
#define YYSTYPE GrammerTreeNode *
#endif
}

// place any declarations here
%token MAIN,INT,CHAR,DOUBLE,IF,ELSE,FOR,WHILE,DO,SWITCH,CASE,DEFAULT,BREAK,CONTINUE
%token ID,DOUBLE_NUM,INT_NUM,CONSTCHAR
%token PLUS2,MINUS2,PLUS,MINUS
%token TIMES,OVER,MOD
%token LSHIFT,RSHIFT
%token LT,LE,GT,GE,EQ,NE,BIT_AND,BIT_XOR,BIT_OR,AND,OR
%token QMARK,COLON,ASSIGN,PLUSA,MINUSA,TIMESA,OVERA,MODA
%token LPAREN,RPAREN,LBRACE,RBRACE,SEMICOLON,COMMA,NOT
%token INPUT,PRINT
%token ERROR

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

program		:	MAIN LPAREN RPAREN compound_statement
				{$$=$4;}
			;

id	:	ID
		{
			$$ = parse_tree.MakeNode(LEAF_NODE, ID_LEAF, $1->attr.symtbl_seq, Notype);
			$$->output();
			parse_tree.GetTempVar($$);
		}
	;
	
constant	:	INT_NUM
					{ 
						$$ = parse_tree.MakeNode(LEAF_NODE, CONST_LEAF, $1->attr.vali, Integer);
						$$->output();
                      }
				|DOUBLE_NUM
					{ 
						$$ = parse_tree.MakeNode(LEAF_NODE, CONST_LEAF, $1->attr.vald,Double);
						$$->output();
                      }
				|CONSTCHAR
					{
						$$ = parse_tree.MakeNode(LEAF_NODE, CONST_LEAF, $1->attr.valc, Char);
						$$->output();
                   	  }
				;
				
var_declaration	:	type_specifier init_declarator_list SEMICOLON
							{
								GrammerTreeNode * p;
								$$ = parse_tree.MakeNode(DECL_NODE, VAR_DECL, 0, Notype);
								($$->children).push_back($1);
								
								for (p = $2; p; p = p->sibling)
								{
									($$->children).push_back(p);
									(p->children[0])->type = $1->type;
									symtbl.setType((p->children[0])->attr.symtbl_seq, (p->children[0])->type);
									
									id_pos.insert((p->children[0])->attr.symtbl_seq);
									decl_var_cnt++;
									
									if(decl_var_cnt!=id_pos.size()){
										cerr<<"Symbol \""<<symtbl.symbol_table[(p->children[0])->attr.symtbl_seq].name<<"\" duplicate definited!"<<endl;
										freopen("CON", "r", stdin);
										system("pause");
									}
								}// end for
								$$->output();
						  }
						;
				
init_declarator_list	:	init_declarator
									{
										$$=$1;
									}
								|	init_declarator_list COMMA init_declarator
									{
										GrammerTreeNode * t = $1;
										if (t!=NULL){
											while (t->sibling!=NULL)
												t=t->sibling;
											t->sibling = $3;
											$$ = $1;
										}
										else 
											$$ = $3;
									}
								;
							
init_declarator	:	id
							{
								$$ = parse_tree.MakeNode(DECL_NODE, DECLARATOR, 0, Notype);
								($$->children).push_back($1);
								$$->output();
							}
						|	id ASSIGN assignment_expression
							{
								//这里为了体现int a=1这类的变量声明，创建了新种类的结点
								//主要还是想不太好怎样理解这个过程
								$$ = parse_tree.MakeNode(DECL_NODE, DECLARATOR, 0, Notype);
								($$->children).push_back($1);
								($$->children).push_back($3);
								$$->output();
							}
						;
						
type_specifier      : INT 
                      {
						$$ = parse_tree.MakeNode(LEAF_NODE, TYPE_LEAF, 0, Integer);
						$$->output();
                      }
                    | CHAR
                      { 
						$$ = parse_tree.MakeNode(LEAF_NODE, TYPE_LEAF, 0, Char);
						$$->output();
                      }
					| DOUBLE
                      { 
						$$ = parse_tree.MakeNode(LEAF_NODE, TYPE_LEAF, 0, Double);
						$$->output();
                      }
                    ;
				
/*
//	一种不考虑int a=1;的文法，但如果考虑的话应该如何处理呢？
var_declaration     : type_specifier idlist SEMICOLON
                      {
						GrammerTreeNode * p;
						$$ = parse_tree.MakeNode(DECL_NODE, VAR_DECL, 0, Notype);
						($$->children).push_back($1);
						
						set<int> id_pos;
						int cnt=0;
						
						for (p = $2; p; p = p->sibling)
						{
							($$->children).push_back(p);
							p->type = $1->type;
							symtbl.setType(p->attr.symtbl_seq, p->type);
							
							id_pos.insert(p->attr.symtbl_seq);
							cnt++;
							
							if(cnt!=id_pos.size()){
								cerr<<"Symbol \""<<symtbl.symbol_table[p->attr.symtbl_seq].name<<"\" conflict!"<<endl;
								freopen("CON", "r", stdin);
								system("pause");
							}
						}// end for
						$$->output();
                      }
                    ;
					
idlist				: idlist COMMA id
						{
							GrammerTreeNode * t = $1;
							if (t!=NULL){
								while (t->sibling!=NULL)
									t=t->sibling;
								t->sibling = $3;
								$$ = $1;
							}
							else 
								$$ = $3;
						}
					| id
						{
							$$ = $1;
						}
					;
*/
var	:	ID
		{
			$$ = parse_tree.MakeNode(LEAF_NODE, ID_LEAF, $1->attr.symtbl_seq, Notype);
			$$->output();
			parse_tree.GetTempVar($$);
		}
	;

primary_expression:	var
								{
									$$=$1;
									if(($$->attr.symtbl_seq!=0)&&(symtbl.getType($$->attr.symtbl_seq)==Notype)){
										cout<<"Undeclared identifier!"<<endl;
									}
								}
							|	constant
								{
									$$=$1;
								}
							|	LPAREN expression RPAREN
								{
									$$=$2;
								}
					;
					
postfix_expression	:	primary_expression
								{
									$$=$1;
								}
							|	postfix_expression PLUS2
								{
									$$ = parse_tree.MakeNode(EXPR_NODE, POSTFIX_EXPR, PLUS2, Notype);
									($$->children).push_back($1);
									$$->output();
									parse_tree.GetTempVar($$);
								}
							|	postfix_expression MINUS2
								{
									$$ = parse_tree.MakeNode(EXPR_NODE, POSTFIX_EXPR, MINUS2, Notype);
									($$->children).push_back($1);
									$$->output();
									parse_tree.GetTempVar($$);
								}
							;
					
unary_expression	:	postfix_expression
								{
									$$=$1;
								}
							|	PLUS2 unary_expression
								{
									$$ = parse_tree.MakeNode(EXPR_NODE, UNARY_EXPR, PLUS2, Notype);
									($$->children).push_back($2);
									$$->output();
									parse_tree.GetTempVar($$);
								}
							|	MINUS2 unary_expression
								{
									$$ = parse_tree.MakeNode(EXPR_NODE, UNARY_EXPR, MINUS2, Notype);
									($$->children).push_back($2);
									$$->output();
									parse_tree.GetTempVar($$);
								}
							|	MINUS unary_expression
								{
									$$ = parse_tree.MakeNode(EXPR_NODE, UNARY_EXPR, MINUS, Notype);
									($$->children).push_back($2);
									$$->output();
								}
							|	PLUS unary_expression
								{
									$$ = parse_tree.MakeNode(EXPR_NODE, UNARY_EXPR, PLUS, Notype);
									($$->children).push_back($2);
									$$->output();
								}
							|	NOT unary_expression
								{
									$$ = parse_tree.MakeNode(EXPR_NODE, UNARY_EXPR, NOT, Notype);
									($$->children).push_back($2);
									$$->output();
								}
							;
					
cast_expression	:	unary_expression
							{
								$$=$1;
							}
						|	LPAREN type_specifier RPAREN cast_expression
							{
								$$ = parse_tree.MakeNode(EXPR_NODE, CAST_EXPR, 0, Notype);
								($$->children).push_back($2);
								($$->children).push_back($4);
								$$->output();
							}
						;

multi_expression	:	cast_expression
								{
									$$=$1;
								}
							|	multi_expression TIMES cast_expression
								{
									$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, TIMES, Notype);
									($$->children).push_back($1);
									($$->children).push_back($3);
									$$->output();
									parse_tree.GetTempVar($$);
								}
							|	multi_expression OVER cast_expression
								{
									$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, OVER, Notype);
									($$->children).push_back($1);
									($$->children).push_back($3);
									$$->output();
									parse_tree.GetTempVar($$);
								}
							|	multi_expression MOD cast_expression
								{
									$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, MOD, Notype);
									($$->children).push_back($1);
									($$->children).push_back($3);
									$$->output();
									parse_tree.GetTempVar($$);
								}
							;
					
additive_expression	:	multi_expression
									{
										$$=$1;
									}
								|	additive_expression PLUS multi_expression
									{
										$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, PLUS, Notype);
										($$->children).push_back($1);
										($$->children).push_back($3);
										$$->output();
										parse_tree.GetTempVar($$);
									}
								|	additive_expression MINUS multi_expression
									{
										$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, MINUS, Notype);
										($$->children).push_back($1);
										($$->children).push_back($3);
										$$->output();
										parse_tree.GetTempVar($$);
									}
								;
						
shift_expression	:	additive_expression
							{
								$$=$1;
							}
						|	shift_expression LSHIFT additive_expression
							{
								$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, LSHIFT, Notype);
								($$->children).push_back($1);
								($$->children).push_back($3);
								$$->output();
								parse_tree.GetTempVar($$);
							}
						|	shift_expression RSHIFT additive_expression
							{
								$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, RSHIFT, Notype);
								($$->children).push_back($1);
								($$->children).push_back($3);
								$$->output();
								parse_tree.GetTempVar($$);
							}
						;
					
relational_expression	:	shift_expression
									{
										$$=$1;
									}
								|	relational_expression LT shift_expression
									{
										$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, LT, Notype);
										($$->children).push_back($1);
										($$->children).push_back($3);
										$$->output();
									}
								|	relational_expression GT shift_expression
									{
										$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, GT, Notype);
										($$->children).push_back($1);
										($$->children).push_back($3);
										$$->output();
									}
								|	relational_expression LE shift_expression
									{
										$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, LE, Notype);
										($$->children).push_back($1);
										($$->children).push_back($3);
										$$->output();
									}
								|	relational_expression GE shift_expression
									{
										$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, GE, Notype);
										($$->children).push_back($1);
										($$->children).push_back($3);
										$$->output();
									}
								;

equality_expression	:	relational_expression
									{
										$$=$1;
									}
								|	equality_expression EQ relational_expression
									{
										$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, EQ, Notype);
										($$->children).push_back($1);
										($$->children).push_back($3);
										$$->output();
									}
								|	equality_expression NE relational_expression
									{
										$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, NE, Notype);
										($$->children).push_back($1);
										($$->children).push_back($3);
										$$->output();
									}
								;
						
AND_expression	:	equality_expression
							{
								$$=$1;
							}
						|	AND_expression BIT_AND equality_expression
							{
								$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, BIT_AND, Notype);
								($$->children).push_back($1);
								($$->children).push_back($3);
								$$->output();
								parse_tree.GetTempVar($$);
							}
						;
				
XOR_expression	:	AND_expression
							{
								$$=$1;
							}
						|	XOR_expression BIT_XOR AND_expression
							{
								$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, BIT_XOR, Notype);
								($$->children).push_back($1);
								($$->children).push_back($3);
								$$->output();
								parse_tree.GetTempVar($$);
							}
						;
				
OR_expression	:	XOR_expression
							{
								$$=$1;
							}
						|	OR_expression BIT_OR XOR_expression
							{
								$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, BIT_OR, Notype);
								($$->children).push_back($1);
								($$->children).push_back($3);
								$$->output();
								parse_tree.GetTempVar($$);
							}
						;
				
logical_AND_expression	:	OR_expression
										{
											$$=$1;
										}
									|	logical_AND_expression AND OR_expression
										{
											$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, AND, Notype);
											($$->children).push_back($1);
											($$->children).push_back($3);
											$$->output();
										}
									;
						
logical_OR_expression	:	logical_AND_expression
										{
											$$=$1;
										}
									|	logical_OR_expression OR logical_AND_expression
										{
											$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, OR, Notype);
											($$->children).push_back($1);
											($$->children).push_back($3);
											$$->output();
										}
									;
						
conditional_expression	:	logical_OR_expression
										{
											$$=$1;
										}
									|	logical_OR_expression QMARK expression COLON conditional_expression
										{
											$$ = parse_tree.MakeNode(EXPR_NODE, COND_EXPR, 0, Notype);
											($$->children).push_back($1);
											($$->children).push_back($3);
											($$->children).push_back($5);
											$$->output();
										}
									;
						
assignment_expression	:	conditional_expression
										{
											$$=$1;
										}
									|	unary_expression ASSIGN assignment_expression
										{
											$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, ASSIGN, Notype);
											($$->children).push_back($1);
											($$->children).push_back($3);
											$$->output();
											parse_tree.GetTempVar($$);
										}
									|	unary_expression PLUSA assignment_expression
										{
											$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, PLUSA, Notype);
											($$->children).push_back($1);
											($$->children).push_back($3);
											$$->output();
											parse_tree.GetTempVar($$);
										}
									|	unary_expression MINUSA assignment_expression
										{
											$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, MINUSA, Notype);
											($$->children).push_back($1);
											($$->children).push_back($3);
											$$->output();
											parse_tree.GetTempVar($$);
										}
									|	unary_expression TIMESA assignment_expression
										{
											$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, TIMESA, Notype);
											($$->children).push_back($1);
											($$->children).push_back($3);
											$$->output();
											parse_tree.GetTempVar($$);
										}
									|	unary_expression OVERA assignment_expression
										{
											$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, OVERA, Notype);
											($$->children).push_back($1);
											($$->children).push_back($3);
											$$->output();
											parse_tree.GetTempVar($$);
										}
									|	unary_expression MODA assignment_expression
										{
											$$ = parse_tree.MakeNode(EXPR_NODE, OP_EXPR, MODA, Notype);
											($$->children).push_back($1);
											($$->children).push_back($3);
											$$->output();
											parse_tree.GetTempVar($$);
										}
									;
							
expression	:	assignment_expression
					{
						$$=$1;
					}
				|	expression COMMA assignment_expression
					{	
						GrammerTreeNode * t=$1;
						if(t!=NULL){
							while(t->sibling!=NULL)
								t=t->sibling;
							t->sibling=$3;
							$$=$1;
						}
						else
							$$=$3;
					}
				;
				
statement	:	compound_statement
					{
						$$=$1;
					}
				|	expression_statement
					{
						$$=$1;
					}
				|	selection_statement
					{
						$$=$1;
					}
				|	iteration_statement
					{
						$$=$1;
					}
				|	jump_statement
					{
						$$=$1;
					}
				|	input_statement
					{
						$$=$1;
					}
				|	print_statement
					{
						$$=$1;
					}
				;
			
compound_statement	:	LBRACE RBRACE
									{
										$$ = parse_tree.MakeNode(STMT_NODE, COMP_STMT, 0, Notype);
										$$->output();
									}
								|	LBRACE block_item_list RBRACE
									{
										GrammerTreeNode * t=$2;
										$$ = parse_tree.MakeNode(STMT_NODE, COMP_STMT, 0, Notype);
										($$->children).push_back(t);
										//这里需不需要判断t为NULL还需考虑
										while (t->sibling != NULL){
											t = t->sibling;
											($$->children).push_back(t);
										}
										$$->output();
									}
								;
					
block_item_list	:	block_item
							{
								$$=$1;
							}
						|	block_item_list block_item
							{
								GrammerTreeNode * t=$1;
								if (t!=NULL){
								
									while (t->sibling!=NULL)
										t=t->sibling;
										
									t->sibling = $2;
									$$ = $1;
								}
								else 
									$$ = $2;
							}
						;
				
block_item	:	var_declaration
						{
							$$=$1;
						}
					|	statement
						{
							$$=$1;
						}
					;
			
expression_statement	:	SEMICOLON
										{
											$$ = parse_tree.MakeNode(STMT_NODE, EXPR_STMT, 0, Notype);
											$$->output();
											parse_tree.GetTempVar($$);
										}
									|	expression	SEMICOLON
										{
											$$ = parse_tree.MakeNode(STMT_NODE, EXPR_STMT, 0, Notype);
											($$->children).push_back($1);
											$$->output();
										}
									;
						
selection_statement		:	if_statement
							{$$=$1;}
						|	switch_statement
							{$$=$1;}
						;
if_statement	:	IF LPAREN expression RPAREN statement ELSE statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, IF_STMT, 0, Notype);
											($$->children).push_back($3);
											($$->children).push_back($5);
											($$->children).push_back($7);
											$$->output();
										}
									|	IF LPAREN expression RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, IF_STMT, 0, Notype);
											($$->children).push_back($3);
											($$->children).push_back($5);
											$$->output();
										}
									;
switch_statement	:	SWITCH LPAREN expression RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, SWITCH_STMT, 0, Notype);
											($$->children).push_back($3);
											($$->children).push_back($5);
											$$->output();
										}
									;
						
iteration_statement		:	while_statement
							{$$=$1;}
						|	do_while_statment
							{$$=$1;}
						|	for_statement
							{$$=$1;}
						;
while_statement		:	WHILE LPAREN expression RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, WHILE_STMT, 0, Notype);
											($$->children).push_back($3);
											($$->children).push_back($5);
											$$->output();
										}
					;
do_while_statment	:	DO statement WHILE LPAREN expression RPAREN SEMICOLON
										{
											$$ = parse_tree.MakeNode(STMT_NODE, DO_WHILE_STMT, 0, Notype);
											($$->children).push_back($2);
											($$->children).push_back($5);
											$$->output();
										}
					;
for_statement		:	FOR LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											($$->children).push_back($3);
											($$->children).push_back($5);
											($$->children).push_back($7);
											($$->children).push_back($9);
											$$->output();
										}
									|	FOR LPAREN expression SEMICOLON expression SEMICOLON  RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											($$->children).push_back($3);
											($$->children).push_back($5);
											($$->children).push_back($8);
											$$->output();
										}
									|	FOR LPAREN expression SEMICOLON  SEMICOLON expression RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											($$->children).push_back($3);
											($$->children).push_back($6);
											($$->children).push_back($8);
											$$->output();
										}
									|	FOR LPAREN expression SEMICOLON  SEMICOLON  RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											($$->children).push_back($3);
											($$->children).push_back($7);
											$$->output();
										}
									|	FOR LPAREN  SEMICOLON expression SEMICOLON expression RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											($$->children).push_back($4);
											($$->children).push_back($6);
											($$->children).push_back($8);
											$$->output();
										}
									|	FOR LPAREN  SEMICOLON expression SEMICOLON  RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											($$->children).push_back($4);
											($$->children).push_back($7);
											$$->output();
										}
									|	FOR LPAREN  SEMICOLON  SEMICOLON expression RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											($$->children).push_back($5);
											($$->children).push_back($7);
											$$->output();
										}
									|	FOR LPAREN  SEMICOLON  SEMICOLON  RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											($$->children).push_back($6);
											$$->output();
										}
									|	FOR LPAREN var_declaration expression SEMICOLON expression RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											($$->children).push_back($3);
											($$->children).push_back($4);
											($$->children).push_back($6);
											($$->children).push_back($8);
											$$->output();
										}
									|	FOR LPAREN var_declaration expression SEMICOLON  RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											($$->children).push_back($3);
											($$->children).push_back($4);
											($$->children).push_back($7);
											$$->output();
										}
									|	FOR LPAREN var_declaration SEMICOLON expression RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											($$->children).push_back($3);
											($$->children).push_back($5);
											($$->children).push_back($7);
											$$->output();
										}
									|	FOR LPAREN var_declaration SEMICOLON  RPAREN statement
										{
											$$ = parse_tree.MakeNode(STMT_NODE, FOR_STMT, 0, Notype);
											($$->children).push_back($3);
											($$->children).push_back($6);
											$$->output();
										}
									;

jump_statement	:	CONTINUE SEMICOLON
								{
									$$ = parse_tree.MakeNode(STMT_NODE, JUMP_STMT, 0, Notype);
									$$->output();
								}
							|	BREAK SEMICOLON
								{
									$$ = parse_tree.MakeNode(STMT_NODE, JUMP_STMT, 0, Notype);
									$$->output();
								}
							;

input_statement	:	INPUT LPAREN expression RPAREN SEMICOLON
					{
						$$ = parse_tree.MakeNode(STMT_NODE, INPUT_STMT, 0, Notype);
						($$->children).push_back($3);
						$$->output();
					}
				;
				
print_statement	:	PRINT LPAREN expression RPAREN SEMICOLON
					{
						$$ = parse_tree.MakeNode(STMT_NODE, PRINT_STMT, 0, Notype);
						($$->children).push_back($3);
						$$->output();
					}
				;

%%

/////////////////////////////////////////////////////////////////////////////
// programs section


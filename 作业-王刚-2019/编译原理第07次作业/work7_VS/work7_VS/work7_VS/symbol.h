#pragma once
#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#include<string>
#include<vector>

using namespace std;

enum { Identifier = 0 };	//	待补充符号表token类型枚举

typedef struct {
	string name;
	int token;
	int type;
	int scope;
}symbol_table_item;

typedef vector<symbol_table_item>::iterator symtbl_iter;

class symbol_table_type {
public:
	vector<symbol_table_item> symbol_table;
public:
	symbol_table_type();

	int findItem(string name);
	int insert(string name, int token);
	string &getName(int pos);
	int setType(int pos, int type);
	int getType(int pos);
};

#endif // !_SYMBOL_H_

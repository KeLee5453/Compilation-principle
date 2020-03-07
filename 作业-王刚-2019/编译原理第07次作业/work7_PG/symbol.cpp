#include<iostream>

using namespace std;

#include "symbol.h"
#include"grammer_tree.h"

int cur_scope = -1;
symbol_table_type symtbl;

symbol_table_type::symbol_table_type()
{
	//	do nothing
}

int symbol_table_type::findItem(string name)
{
	symtbl_iter it;
	//	查找是否已有该符号
	//	首先判断符号表是否为空
	if (symbol_table.size() == 0) {
		// 符号表为空，返回-1
	}
	else {
		for (it = symbol_table.begin(); it < symbol_table.end(); it++) {
			if ((it->name) == name) {
				//	若找到该项
				//	返回该项相对于begin迭代器的偏移量
				return (int)(it - symbol_table.begin());
			}
		}
	}
	//	未找到
	return -1;
}

int symbol_table_type::insert(string name, int token)
{
	int offset = findItem(name);
	if (offset == -1) {
		//	若该符号尚未存在于符号表中
		symbol_table_item new_item = symbol_table_item();
		new_item.name = name;
		new_item.token = token;
		new_item.type = Notype;	//	在此刻我们是不知道数据类型的
		new_item.scope = cur_scope;
		symbol_table.push_back(new_item);

		//	返回插入项的pos
		return symbol_table.size() - 1;
	}
	else {
		cout << "Symbol \"" << symbol_table[offset].name << "\" conflict!" << endl;
		/*cerr << "Symbol \"" << symbol_table[offset].name << "\" conflict!" << endl;
		freopen("CON", "r", stdin);*/
		system("pause");
		return -1;
		/*//	若该符号已存在于符号表中
		//	更新（为了实现作用域）
		symbol_table[offset].name = name;
		symbol_table[offset].token = token;
		symbol_table[offset].type = Notype;
		symbol_table[offset].scope = cur_scope;

		//	返回插入项的pos
		return offset;*/
	}
}

string & symbol_table_type::getName(int pos)
{
	return symbol_table[pos].name;
}

int symbol_table_type::setType(int pos, int type)
{
	if (pos < 0 || pos >= symbol_table.size()) {
		cerr << "Bad Identifier" << endl;
		return -1;
	}

	symbol_table[pos].type = type;
	return 0;
}

int symbol_table_type::getType(int pos)
{
	if (pos < 0 || pos >= symbol_table.size()) {
		cerr << "Bad Identifier" << endl;
		return -1;
	}

	return symbol_table[pos].type;
}

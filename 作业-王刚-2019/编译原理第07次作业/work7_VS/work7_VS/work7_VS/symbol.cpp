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
	//	�����Ƿ����и÷���
	//	�����жϷ��ű��Ƿ�Ϊ��
	if (symbol_table.size() == 0) {
		// ���ű�Ϊ�գ�����-1
	}
	else {
		for (it = symbol_table.begin(); it < symbol_table.end(); it++) {
			if ((it->name) == name) {
				//	���ҵ�����
				//	���ظ��������begin��������ƫ����
				return (int)(it - symbol_table.begin());
			}
		}
	}
	//	δ�ҵ�
	return -1;
}

int symbol_table_type::insert(string name, int token)
{
	int offset = findItem(name);
	if (offset == -1) {
		//	���÷�����δ�����ڷ��ű���
		symbol_table_item new_item = symbol_table_item();
		new_item.name = name;
		new_item.token = token;
		new_item.type = Notype;	//	�ڴ˿������ǲ�֪���������͵�
		new_item.scope = cur_scope;
		symbol_table.push_back(new_item);

		//	���ز������pos
		return symbol_table.size() - 1;
	}
	else {
		cout << "Symbol \"" << symbol_table[offset].name << "\" conflict!" << endl;
		/*cerr << "Symbol \"" << symbol_table[offset].name << "\" conflict!" << endl;
		freopen("CON", "r", stdin);*/
		system("pause");
		return -1;
		/*//	���÷����Ѵ����ڷ��ű���
		//	���£�Ϊ��ʵ��������
		symbol_table[offset].name = name;
		symbol_table[offset].token = token;
		symbol_table[offset].type = Notype;
		symbol_table[offset].scope = cur_scope;

		//	���ز������pos
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

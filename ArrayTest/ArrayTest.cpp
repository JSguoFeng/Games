#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
char words[2][5] = { 'a','b','c','d','e','f','g','h','i','j' };
int main() {
	//char a ;
	//cout << &words[0] + 1 << endl;
	//cout << *words[0] + 1 << endl;
	//数组的名称与地址效果一样，直接使用名称解引用就能获得数组中的数据
	//printf("% c", *words[0]+2 );
	string arrays[2];
	arrays[1].append("abcdef");
	cout << arrays[1] << endl;
	string x = arrays[1];
	const char* y = arrays[1].c_str();
	//通过起始地址向后偏移取出数组中的元素。
	//有地址就能修改地址所对应的值。
	//有关string的字符串只能通过替换其中的数据来进行修改该//
	const char* z = "hello";
	string a;
	char g[6];
	strcpy_s(g, z);
	cout << g[1] << endl;
	cout << g[5] << endl;
	a = z;
	return 0;
}
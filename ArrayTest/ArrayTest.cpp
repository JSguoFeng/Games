#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
char words[2][5] = { 'a','b','c','d','e','f','g','h','i','j' };
int main() {
	//char a ;
	//cout << &words[0] + 1 << endl;
	//cout << *words[0] + 1 << endl;
	//������������ַЧ��һ����ֱ��ʹ�����ƽ����þ��ܻ�������е�����
	//printf("% c", *words[0]+2 );
	string arrays[2];
	arrays[1].append("abcdef");
	cout << arrays[1] << endl;
	string x = arrays[1];
	const char* y = arrays[1].c_str();
	//ͨ����ʼ��ַ���ƫ��ȡ�������е�Ԫ�ء�
	//�е�ַ�����޸ĵ�ַ����Ӧ��ֵ��
	//�й�string���ַ���ֻ��ͨ���滻���е������������޸ĸ�//
	const char* z = "hello";
	string a;
	char g[6];
	strcpy_s(g, z);
	cout << g[1] << endl;
	cout << g[5] << endl;
	a = z;
	return 0;
}
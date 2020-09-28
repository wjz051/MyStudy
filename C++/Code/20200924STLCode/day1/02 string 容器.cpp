#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
#include <stdexcept>
/*
string ���캯��
string();//����һ���յ��ַ��� ����: string str;
string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
string(const char* s);//ʹ���ַ���s��ʼ��
string(int n, char c);//ʹ��n���ַ�c��ʼ��

3.1.2.2 string������ֵ����
string& operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
string& operator=(const string &s);//���ַ���s������ǰ���ַ���
string& operator=(char c);//�ַ���ֵ����ǰ���ַ���
string& assign(const char *s);//���ַ���s������ǰ���ַ���
string& assign(const char *s, int n);//���ַ���s��ǰn���ַ�������ǰ���ַ���
string& assign(const string &s);//���ַ���s������ǰ�ַ���
string& assign(int n, char c);//��n���ַ�c������ǰ�ַ���
string& assign(const string &s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���

*/

void test01()
{
	string str; //Ĭ�Ϲ���
	string str2(str); //��������
	string str3 = str;

	string str4 = "abcd";
	string str5(10, 'a');

	cout << str4 << endl;
	cout << str5 << endl;

	//������ֵ
	str = "hello";
	str2 = str4;

	//string& assign(const char *s, int n);//���ַ���s��ǰn���ַ�������ǰ���ַ���
	str3.assign("abcdef", 4);
	cout << str3 << endl;


	//string& assign(const string &s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���
	string str6;
	str6.assign(str, 1, 3); //ell ? hel ��0����

	cout << str6 << endl;
}


/*
string��ȡ�ַ�����
char& operator[](int n);//ͨ��[]��ʽȡ�ַ�
char& at(int n);//ͨ��at������ȡ�ַ�

*/
void test02()
{
	string s = "hello world";

	for (int i = 0; i < s.size();i++)
	{
		//cout << s[i] << endl;
		cout << s.at(i) << endl;
	}
	//[] ��at����[]����Խ��  ֱ�ӹҵ� at���׳��쳣

	try
	{
		//cout << s[100] << endl;
		cout << s.at(100) << endl;
	}
	catch (out_of_range & e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Խ���쳣" << endl;
	}
}

/*
stringƴ�Ӳ���
string& operator+=(const string& str);//����+=������
string& operator+=(const char* str);//����+=������
string& operator+=(const char c);//����+=������
string& append(const char *s);//���ַ���s���ӵ���ǰ�ַ�����β
string& append(const char *s, int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
string& append(const string &s);//ͬoperator+=()
string& append(const string &s, int pos, int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
string& append(int n, char c);//�ڵ�ǰ�ַ�����β���n���ַ�c

3.1.2.5 string���Һ��滻
int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos = 0) const;  //����s��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos, int n) const;  //��posλ�ò���s��ǰn���ַ���һ��λ��
int find(const char c, int pos = 0) const;  //�����ַ�c��һ�γ���λ��
int rfind(const string& str, int pos = npos) const;//����str���һ��λ��,��pos��ʼ����
int rfind(const char* s, int pos = npos) const;//����s���һ�γ���λ��,��pos��ʼ����
int rfind(const char* s, int pos, int n) const;//��pos����s��ǰn���ַ����һ��λ��
int rfind(const char c, int pos = 0) const; //�����ַ�c���һ�γ���λ��
string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
string& replace(int pos, int n, const char* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s

*/

void test03()
{
	//ƴ��
	string s1 = "��";
	string s2 = "������";
	s1 += s2;
	cout << s1 << endl;
	s1.append("�찲��");

	cout << s1 << endl;

	//find����

	string s = "abcdefg";
	int pos = s.find("bcf"); //�Ҳ��������� -1
	cout << "pos = " << pos << endl;
	
	int pos2 = s.rfind("bc"); //rfind  ��find ���һ�����ڲ�����˳���෴
	cout << "pos2 = " << pos2 << endl; // 4 2 


	//�滻
	string s3 = "hello"; //�滻��pos��ʼn���ַ�Ϊ�ַ���str
	s3.replace(1, 3, "1111");
	cout << s3 << endl; // h1111o


}

/*
string�Ƚϲ���
/*
compare������>ʱ���� 1��<ʱ���� -1��==ʱ���� 0��
�Ƚ����ִ�Сд���Ƚ�ʱ�ο��ֵ�˳����Խǰ���ԽС��
��д��A��Сд��aС��

int compare(const string &s) const;//���ַ���s�Ƚ�
int compare(const char *s) const;//���ַ���s�Ƚ�
*/

void test04()
{
	string s1 = "abc";
	string s2 = "abcd";

	if (s1.compare(s2) == 0)
	{
		cout << "s1 ���� s2" << endl;
	}
	else if (s1.compare(s2) == 1)
	{
		cout << "s1 ���� s2" << endl;
	}
	else
	{
		cout << "s1 С�� s2" << endl;
	}

}


/*
string�Ӵ�
string substr(int pos = 0, int n = npos) const;//������pos��ʼ��n���ַ���ɵ��ַ���

*/

void test05()
{
	string s1 = "abcde";

	string s2 = s1.substr(1, 3);
	cout << "s2 = " << s2 << endl;

	//����  ����һ���Ҽ��� �û���
	string email = "zhangtao@sina.com";

	int pos = email.find("@");//8 
	cout << "pos " << pos << endl;

	string usrName = email.substr(0, pos);
	cout << "�û���Ϊ��" << usrName << endl;
}


/*
string�����ɾ������
string& insert(int pos, const char* s); //�����ַ���
string& insert(int pos, const string& str); //�����ַ���
string& insert(int pos, int n, char c);//��ָ��λ�ò���n���ַ�c
string& erase(int pos, int n = npos);//ɾ����Pos��ʼ��n���ַ�

*/

void test06()
{
	string s1 = "hello";
	s1.insert(1, "111");
	cout << s1 << endl; //h111ello

	//ɾ�� 111
	s1.erase(1, 3);
	cout << s1 << endl;

}


/*
string��c-style�ַ���ת��
*/

void func(string s)
{
	cout << s << endl;
}

void func2(const char * s)
{
	cout << s << endl;
}

void test07()
{
	string s = "abc";
	//string -> const char *

	const char * p = s.c_str();

	func(p); //const char * ��ʽ����ת��Ϊ string

	//const char * -> string 

	string s2(p);
	//func2(s2); //string ������ʽ����ת��Ϊ char * 
}

void test08()
{
	string s = "abcdefg";
	char& a = s[2];
	char& b = s[3];

	a = '1';
	b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;

	s = "pppppppppppppp";

	//a = '1';
	//b = '2';

	cout << s << endl;
	cout << (int*)s.c_str() << endl;

}

/*
дһ�������������ڲ���string�ַ����е�����Сд��ĸ����Ϊ��д��ĸ��
*/

void test09()
{
	string s = "abCdEfg";

	for (int i = 0; i < s.size();i++)
	{
		//s[i] = toupper(s[i]);

		//ȫ��Сд
		s[i] = tolower(s[i]);
	}

	cout << s << endl;
}

int main(){

//	test01();

	//test02();

	//test03();

	//test04();

	//test05();

	//test06();

//	test07();

	//test08();

	test09();

	system("pause");
	return EXIT_SUCCESS;
}
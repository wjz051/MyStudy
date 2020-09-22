/*
假设， 我们有类 Sender 类和 Mail 类， 实现发送邮件的功能。
Sender sender; Mail mail;
sender << mail;
sender左操作数，决定了 operator<<为 Sender的成员函数，而 mail决定了 operator<<要作 Mail 类的友员。
*/
#include <iostream>
using namespace std;

class Sender;

class Mail
{ 
    friend class Sender;
public:
    Mail(string _t,string _c ):_title(_t),_content(_c){}

    //友元
    //friend Sender& Sender::operator<<(const Mail & mail);

private:
    string _title;
    string _content;
};

class Sender
{ 
public:
    Sender(string s):_addr(s){}
    Sender& operator<<(const Mail & mail)
    {
        cout<<"Address:"<<_addr<<endl;
        cout<<"Title :"<<mail._title<<endl;
        cout<<"Content:"<<mail._content<<endl;
        return *this;
    }
private:
    string _addr;
};

// Sender& Sender::operator<<(const Mail & mail)
// {
//     cout<<"Address:"<<_addr<<endl;
//     cout<<"Title :"<<mail._title<<endl;
//     cout<<"Content:"<<mail._content<<endl;
//     return *this;
// }

int main()
{
    Sender sender("guilin_wang@163.com");
    Mail mail("note","meeting at 3:00 pm");
    Mail mail2("tour","One night in beijing");
    sender<<mail<<mail2;
    return 0;
}
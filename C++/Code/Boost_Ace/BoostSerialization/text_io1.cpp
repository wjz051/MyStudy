/*
 * text_io1.cpp
 *
 *  Created on: 2010-4-4 上午11:28:45
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct User {
    string name;
    string email;
    int age;
};

ostream& operator<<(ostream& os, const User& u) {
    return os << u.name << ' ' << u.email << ' ' << u.age << ' ';
}

istream& operator>>(istream& is, User& u) {
    return is >> u.name >> u.email >> u.age;
}

int main() {
    User u = {"tomcat", "tom@abc.com", 8};
    ofstream fout("users_text");
    fout << u << endl;
    fout.close();

    User u2;
    ifstream fin("users_text");
    fin >> u2;

    cout << u2 << endl;
}

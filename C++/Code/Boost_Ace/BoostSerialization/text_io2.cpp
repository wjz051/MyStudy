/*
 * text_io2.cpp
 *
 *  Created on: 2010-4-4 上午11:28:45
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

struct User {
    string name;
    string email;
    int age;
};

ostream& operator<<(ostream& os, const User& u) {
    return os << u.name << ',' << u.email << ',' << u.age << endl;
}

istream& operator>>(istream& is, User& u) {
    string line;
    getline(is, line);
    size_t pos = line.find(',', 0);
    if (pos != string::npos) {
        u.name = string(line, 0, pos);
    }

    size_t currPos = pos + 1;
    pos = line.find(',', currPos);
    if (pos != string::npos) {
        u.email = string(line, currPos, pos - currPos);
    }

    string ageStr = string(line, pos + 1, string::npos);
//    cout << ageStr << endl;
    u.age = atoi(ageStr.c_str());

    return is;
}

int main() {
    User u = { "tom cat", "tom@abc.com", 8 };
    ofstream fout("users_text_v2");
    fout << u;
    cout << u;
    fout.close();

    User u2;
    ifstream fin("users_text_v2");
    fin >> u2;

    cout << u2.name << endl;
    cout << u2.email << endl;
    cout << u2.age << endl;
}

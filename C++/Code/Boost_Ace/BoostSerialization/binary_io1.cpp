/*
 * binary_io2.cpp
 *
 *  Created on: 2010-4-4 上午11:55:45
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

// buggy version!!
int main() {
    User u = { "tom cat", "tom@abc.com", 8 };
    ofstream fout("users_bin");
    fout.write((const char*) &u, sizeof(User));

    fout.close();

    User u2;
    ifstream fin("users_bin");
    fin.read((char*) &u2, sizeof(User));

    cout << u2.name;
}

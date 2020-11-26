/*
 * binary_io1.cpp
 *
 *  Created on: 2010-4-4 上午11:55:45
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <fstream>

using namespace std;

struct User {
    char name[16];
    char email[64];
    int age;
};

int main() {
    User u = { "tom c,at", "tom@ab  c.com", 8 };
    ofstream fout("users_bin_v2");
    fout.write((const char*) &u, sizeof(User));

    fout.close();

    User u2;
    ifstream fin("users_bin_v2");
    fin.read((char*) &u2, sizeof(User));

    cout << u2.name << ' ' << u2.email << ' ' << u2.age << endl;
}

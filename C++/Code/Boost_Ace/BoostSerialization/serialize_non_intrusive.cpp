/*
 * serialize_non_intrusive.cpp
 *
 *  Created on: 2010-4-4 下午12:29:52
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <fstream>
#include <vector>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;

struct User {
    string name;
    string email;
    int age;
};

template<class Archive>
void serialize(Archive& ar, User& u, const unsigned version) {
    ar & u.name; // ar & name & email & age;
    ar & u.email;
    ar & u.age;
}

int main() {
    User u = { "tom c,at", "tom@ab  c.com", 8 };
    ofstream fout("users_non_intrusive");
    boost::archive::text_oarchive oa(fout);
    oa << u;
    fout.close();

    User u2;
    ifstream fin("users_non_intrusive");
    boost::archive::text_iarchive ia(fin);
    ia >> u2;

    cout << u2.name << ' ' << u2.email << ' ' << u2.age << endl;
}

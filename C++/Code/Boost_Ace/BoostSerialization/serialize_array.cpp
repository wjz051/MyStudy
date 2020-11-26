/*
 * serialize_array.cpp
 *
 *  Created on: 2010-4-4 下午12:29:52
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>

using namespace std;

class User {
public:
    User() :
        name(), email(), age() {
    }

    User(const string& _name, const string& _email, const int& _age) :
        name(_name), email(_email), age(_age) {
    }

    string getName() const {
        return name;
    }

    string getEmail() const {
        return email;
    }

    int getAge() const {
        return age;
    }

private:
    string name;
    string email;
    int age;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned version) {
        ar & name; // ar & name & email & age;
        ar & email;
        ar & age;
    }
};

ostream& operator<<(ostream& os, const User& u) {
    return os << u.getName() << ' ' << u.getEmail() << ' ' << u.getAge();
}

int main() {
    User ua[2] = { User("tomcat", "tom@abc.com", 8), User("jerry",
            "jerry@abc.com", 6) };

    ofstream fout("users_array");
    boost::archive::text_oarchive oa(fout);
    oa << ua;
    fout.close();

    User ua2[2];
    ifstream fin("users_array");
    boost::archive::text_iarchive ia(fin);
    ia >> ua2;

    copy(ua2, ua2 + 2, ostream_iterator<User> (cout, "\n"));
}

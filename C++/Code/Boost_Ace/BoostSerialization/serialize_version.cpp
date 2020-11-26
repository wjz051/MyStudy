/*
 * serialize_version.cpp
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
#include <boost/serialization/split_member.hpp>

using namespace std;

// ------------ version 0 -----------------
//class User {
//public:
//    User() :
//        name(), email(), age() {
//    }
//
//    User(const string& _name, const string& _email, const int& _age) :
//        name(_name), email(_email), age(_age) {
//    }
//
//    string getName() const {
//        return name;
//    }
//
//    string getEmail() const {
//        return email;
//    }
//
//    int getAge() const {
//        return age;
//    }
//
//private:
//    string name;
//    string email;
//    int age;
//
//    friend class boost::serialization::access;
//    template<class Archive>
//    void serialize(Archive& ar, const unsigned version) {
//        ar & name; // ar & name & email & age;
//        ar & email;
//        ar & age;
//    }
//};
//
//ostream& operator<<(ostream& os, const User& u) {
//    return os << u.getName() << ' ' << u.getEmail() << ' ' << u.getAge();
//}


// ------------ version 1 -----------------
class User {
public:
    User() :
        name(), email(), age(), gender() {
    }

    User(const string& _name, const string& _email, const int& _age,
            const int& _gender, const string& _addr) :
        name(_name), email(_email), age(_age), gender(_gender), address(_addr) {
    }

    friend ostream& operator<<(ostream& os, const User& u);

private:
    string name;
    string email;
    int age;
    int gender;
    string address;

    friend class boost::serialization::access;
    template<class Archive>
    void save(Archive& ar, const unsigned version) const {
        ar & name;
        ar & email;
        ar & age;
        if (version > 0) {
            ar & gender;
            ar & address;
        }
    }

    template<class Archive>
    void load(Archive& ar, const unsigned version) {
        ar & name; // ar & name & email & age;
        ar & email;
        ar & age;

        if (version > 0) {
            ar & gender;
            ar & address;
        }
    }
    BOOST_SERIALIZATION_SPLIT_MEMBER()
};

BOOST_CLASS_VERSION(User, 1)

ostream& operator<<(ostream& os, const User& u) {
    return os << u.name << ' ' << u.email << ' ' << u.age << ' ' << u.gender
            << ' ' << u.address;
}

int main() {
    {
        // read data from version_0 file
        ifstream fin("users_version_v0");
        boost::archive::text_iarchive ia(fin);
        User u2;
        ia >> u2;
        cout << "version 0: " << u2 << endl;
    }

    {
        // read data from version_1 file
        ifstream fin("users_version_v1");
        boost::archive::text_iarchive ia(fin);
        User u2;
        ia >> u2;
        cout << "version 1: " << u2 << endl;
    }
}

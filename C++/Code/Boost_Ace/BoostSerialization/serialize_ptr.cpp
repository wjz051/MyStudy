/*
 * serialize_ptr.cpp
 *
 *  Created on: 2010-4-4 下午12:29:52
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <fstream>


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

int main() {
    User* u = new User("tomcat", "tom@abc.com", 8);
    User* up = u;
    User* up2 = new User("jerry", "jerry@abc.com", 6);
    boost::shared_ptr<User> up3(new User("jerry2", "jerry2@abc.com", 6));
    boost::shared_ptr<User> up4 = up3;

    ofstream fout("users_ptr");
    boost::archive::text_oarchive oa(fout);
    oa << u;
    oa << up;
    oa << up2;
    oa << up3;
    oa << up4;
    fout.close();
    delete u;

    User* u2;
    User* u3;
    User* u4;
    ifstream fin("users_ptr");
    boost::archive::text_iarchive ia(fin);
    ia >> u2;
    ia >> u3;
    ia >> u4;

    boost::shared_ptr<User> u5, u6;
    ia >> u5;
    ia >> u6;
    cout << u2->getName() << ' ' << u2->getEmail() << ' ' << u2->getAge()
            << endl;
    cout << u3->getName() << ' ' << u3->getEmail() << ' ' << u3->getAge()
            << endl;

    cout << u4->getName() << ' ' << u4->getEmail() << ' ' << u4->getAge()
            << endl;
    cout << u5->getName() << ' ' << u5->getEmail() << ' ' << u5->getAge()
            << endl;
    cout << u6->getName() << ' ' << u6->getEmail() << ' ' << u6->getAge()
            << endl;
}

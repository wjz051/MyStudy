/*
 * serialize_base_class.cpp
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

using namespace std;

struct User {
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

struct VipUser: User {
    int level;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned version) {
        ar & boost::serialization::base_object<User>(*this);
        ar & level;
    }
};

int main() {
    VipUser u;
    u.name = "tom";
    u.email = "abc@abc.com";
    u.age = 25;
    u.level = 2;
    ofstream fout("users_vip");
    boost::archive::text_oarchive oa(fout);
    oa << u;
    fout.close();

    VipUser u2;
    ifstream fin("users_vip");
    boost::archive::text_iarchive ia(fin);
    ia >> u2;

    cout << u2.level << endl;
}

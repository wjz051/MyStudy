/*
 * serialize_member_container.cpp
 *
 *  Created on: 2010-4-4 下午12:29:52
 *      Author: kwarph
 *         Web: http://www.xuanyuan-soft.cn
 *        Mail: kwarph@gmail.com
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

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

ostream& operator<<(ostream& os, const User& u) {
    return os << u.name << ' ' << u.email << ' ' << u.age;
}

struct Group {
    string gid;
    User leader;
    vector<User> members;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned version) {
        ar & gid;
        ar & leader;
        ar & members;
    }
};

int main() {
    Group g;
    g.gid = "G01";
    User leader = { "tom", "tom@abc.com", 28 };
    g.leader = leader;

    User u1 = { "tom1", "tom1@abc.com", 28 };
    User u2 = { "tom2", "tom2@abc.com", 28 };
    User u3 = { "tom3", "tom3@abc.com", 28 };
    g.members.push_back(u1);
    g.members.push_back(u2);
    g.members.push_back(u3);

    ofstream fout("users_in_group");
    boost::archive::text_oarchive oa(fout);
    oa << g;
    fout.close();

    Group g2;
    ifstream fin("users_in_group");
    boost::archive::text_iarchive ia(fin);
    ia >> g2;

    cout << g2.leader << endl;
    copy(g2.members.begin(), g2.members.end(), ostream_iterator<User> (cout,
            "\n"));
}

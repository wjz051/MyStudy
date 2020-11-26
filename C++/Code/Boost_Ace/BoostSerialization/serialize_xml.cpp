/*
 * serialize_xml.cpp
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

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/vector.hpp>

using namespace std;

struct User {
    string name;
    string email;
    int age;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned version) {
        ar & BOOST_SERIALIZATION_NVP(name);
        ar & BOOST_SERIALIZATION_NVP(email);
        ar & BOOST_SERIALIZATION_NVP(age);
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
        ar & BOOST_SERIALIZATION_NVP(gid);
        ar & BOOST_SERIALIZATION_NVP(leader);
        ar & BOOST_SERIALIZATION_NVP(members);
    }
};

int main() {
    Group group;
    group.gid = "G01";
    User leader = { "tom", "tom@abc.com", 28 };
    group.leader = leader;

    User u1 = { "tom1", "tom1@abc.com", 28 };
    User u2 = { "tom2", "tom2@abc.com", 28 };
    User u3 = { "tom3", "tom3@abc.com", 28 };
    group.members.push_back(u1);
    group.members.push_back(u2);
    group.members.push_back(u3);

    ofstream fout("users_xml");
    boost::archive::xml_oarchive oa(fout);
    oa << BOOST_SERIALIZATION_NVP(group);
    fout.close();

    Group g2;
    ifstream fin("users_xml");
    boost::archive::xml_iarchive ia(fin);
    ia >> BOOST_SERIALIZATION_NVP(g2);

    cout << g2.leader << endl;
    copy(g2.members.begin(), g2.members.end(), ostream_iterator<User> (cout,
            "\n"));
}

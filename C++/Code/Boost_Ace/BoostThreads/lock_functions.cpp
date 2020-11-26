#include <iostream>
#include <boost/thread.hpp>

using namespace std;

using boost::thread;

// Code from http://www.justsoftwaresolutions.co.uk/threading/
// with some changes.

class Account {
    boost::mutex m;
    double balance;
public:
    Account() :
        balance() {
    }

    Account(const double& bal) :
        balance(bal) {
    }

    double getBalance() const {
        return balance;
    }

    friend void transfer(Account& from, Account& to, double amount);
};

// version 2: OK （使用lock() 和 lock_guard）
void transfer(Account& from, Account& to, double amount) {
    boost::lock(from.m, to.m);
    boost::lock_guard<boost::mutex> lockFrom(from.m, boost::adopt_lock);
    boost::this_thread::sleep(boost::posix_time::seconds(1));
    boost::lock_guard<boost::mutex> lockTo(to.m, boost::adopt_lock);
    from.balance -= amount;
    to.balance += amount;
}

//// version 3: OK （使用lock() 和 unique_lock）
//void transfer(Account& from, Account& to, double amount) {
//    boost::lock(from.m, to.m);
//    boost::unique_lock<boost::mutex> lockFrom(from.m, boost::adopt_lock);
//    boost::unique_lock<boost::mutex> lockTo(to.m, boost::adopt_lock);
//
//    from.balance -= amount;
//    to.balance += amount;
//}

// version 1: 可能造成死锁
//void transfer(Account& from, Account& to, double amount) {
//    boost::lock_guard<boost::mutex> lockFrom(from.m); // #1
//    boost::this_thread::sleep(boost::posix_time::seconds(1));
//    boost::lock_guard<boost::mutex> lockTo(to.m); // #2
//    from.balance -= amount;
//    to.balance += amount;
//}

int main() {
    Account a1(1200.00);
    Account a2(300.00);

    boost::thread t1(transfer, boost::ref(a1), boost::ref(a2), 134.85);
    boost::thread t2(transfer, boost::ref(a2), boost::ref(a1), 100.30);
    t1.join();
    t2.join();

    cout << "Balance of a1: " << a1.getBalance() << endl;
    cout << "Balance of a2: " << a2.getBalance() << endl;
}

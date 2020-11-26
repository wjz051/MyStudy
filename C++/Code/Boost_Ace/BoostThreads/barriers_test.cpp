#include <iostream>
#include <boost/thread.hpp>

using namespace std;

using boost::thread;

// Shared variables for generation barrier test
const int THREADS = 6;
boost::barrier barriers(THREADS / 2);
boost::mutex m;
long global;

void barrierThread(int n) {
    cout << "thread #" << n << " started." << endl;
    for (int i = 0; i < THREADS / 2; ++i) {
        if (barriers.wait()) {
            boost::mutex::scoped_lock lock(m);
            cout << "thread #" << n << " arrived here." << endl;
            ++global;
        }
    }
}

int main() {
    boost::thread_group g;
    try {
        for (int i = 0; i < THREADS; ++i)
            g.create_thread(boost::bind(barrierThread, i));
        g.join_all();
    } catch (...) {
        g.interrupt_all();
        g.join_all();
        throw ;
    }

    cout << global << endl; // 6
}

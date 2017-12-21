#include "queue.h"
#include <stdlib.h> 
#include <iostream>
using namespace std;

int main() {
    using alg::Queue;
    const int MAXELEMENT = 20;

    Queue<int> Q(MAXELEMENT);
    int i;

    for (i=0; i<MAXELEMENT; i++) {
        int value = rand() % 1000;
        cout << "queueing " << value << endl;
        Q.enqueue(value);
    }

    cout << "queue count " << Q.count() << endl;

    cout << ">DEQUEUE" << endl;
    while (!Q.is_empty()) {
        cout << "dequeue " << Q.front() << endl;
        Q.dequeue();
    }

    cout << Q.front() << endl;
    return 0;
}

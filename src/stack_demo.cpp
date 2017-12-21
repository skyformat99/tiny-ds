#include <iostream>
#include <stdlib.h>
#include "stack.h"
using namespace std;

int main() {
    alg::Stack<int> S(4);
    S.push(7);
    S.push(5);
    S.push(3);

    cout << "push return value when has capacity" << S.push(9) << endl;
    cout << "push return value when full" << S.push(10) << endl;

    for (uint32_t i = 0; i < S.count(); i++) {
        cout << "element" << i << " is " << S[i] << endl;
    }

    while(!S.is_empty()) {
        cout << S.top() << endl;
        S.pop();
    }
    return 0;
}

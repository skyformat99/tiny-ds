#include <iostream>
#include "generic.h"
#include "shuffle.h"

using namespace std;

int main() {
    const int MAX_ELEMENTS = 10;
    int list[MAX_ELEMENTS];

    int i ;
    for (i = 0; i < MAX_ELEMENTS; i++) {
        list[i] = i;
    }
    cout << "the list before shuffle:" << endl;
    alg::printlist(list, MAX_ELEMENTS);

    alg::shuffle<int>(list, MAX_ELEMENTS);

    cout << "the list after shuffle:" << endl;
    alg::printlist(list, MAX_ELEMENTS);

    return 0;
}

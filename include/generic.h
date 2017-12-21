#ifndef ALG_GENERIC_H_
#define ALG_GENERIC_H_

#include <stdio.h>

namespace alg{
    template<typename T>
        void printlist(T &list, int count) {
            int i;
            for (i = 0; i < count; i++) {
                printf("%d\t", list[i]);
            }
            printf("\n");
        }
}

#endif

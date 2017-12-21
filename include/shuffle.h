#ifndef ALG_SHUFFLE_H_
#define ALG_SHUFFLE_H_

namespace alg {
    template<typename T>
        static void shuffle(T *list, int len) {
            srand(time(NULL));
            int i = len, j;
            T temp;

            if (i == 0 ) return;
            while(--i) {
                j = rand() % (i+1);
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
}

#endif

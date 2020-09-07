
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


template<typename T>
int swap_val(T *p0, T*p1) {
    
    assert(p0 && p1);

    T temp = *p0;
    *p0 = *p1;
    *p1 = temp;

    return 0;
}

template<typename T>
int pop_sort(T *parray, int num_array) {

    assert(parray && (num_array > 0));

    for (int times = num_array - 1; times >0; times--) {
        for (int j = num_array - 1; j > 0; j--) {
            if (parray[j] < parray[j-1]) {
                swap_val(&(parray[j]), &(parray[j-1]));
            }
        }
    
    }

    return 0;
}

int main(int argc, char *argv[]) {
    
    int iarray[] = {7, 6 ,5, 4, 3, 2, 1};
    pop_sort(iarray, sizeof(iarray)/sizeof(iarray[0]));

    for (int i = 0; i < sizeof(iarray)/sizeof(iarray[0]); i++) {
        printf("%d, ", iarray[i]);
    }
    printf("\n");

    exit(0);
}


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

template<typename T>
int get_insert_index(T *parray, int num_array, int element) {

    assert(parray && (num_array > 0));

    int i = 0;
    for (; i < num_array; i++) {
        if (parray[i] > element) {
            break;
        }
    }

    return i;
}

template<typename T>
int swap_val(T *p0, T*p1) {
    
    assert(p0 && p1);

    T temp = *p0;
    *p0 = *p1;
    *p1 = temp;

    return 0;
}

template<typename T>
int insert_sort(T *parray, int num_array) {

    assert(parray && (num_array > 0));

    for (int i = 1; i < num_array; i++) {
        int index = get_insert_index(parray, i, parray[i]);

        T temp = parray[i];
        for (int j = i; j > index; j--) {
            swap_val(&(parray[j]), &(parray[j-1]));
        }
        parray[index] = temp;
    }

    
    return 0;
}

int main(int argc, char *argv[]) {
    
    //int iarray[] = {7, 6 ,5, 4, 3, 2, 1};
    int iarray[] = {7, 6 ,5, 4, 3, 2, 1, 14, 100, 19};
    insert_sort(iarray, sizeof(iarray)/sizeof(iarray[0]));

    for (int i = 0; i < sizeof(iarray)/sizeof(iarray[0]); i++) {
        printf("%d, ", iarray[i]);
    }
    printf("\n");

    exit(0);
}

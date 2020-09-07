
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

template<typename T>
int swap_val(T *pa, T *pb) {

    assert(pa && pb);

    T temp = *pa;
    *pa = *pb;
    *pb = temp;

    return 0;
}

template<typename T>
int partition(T *parray, int num_array) {

    assert(parray && (num_array > 0));

    int j = -1;
    int x = parray[num_array - 1];
    for (int i = 0; i < num_array - 1; i++) {
        if (parray[i] < x) {
            j += 1;
            swap_val(&(parray[j]), &(parray[i]));
        }
    }
    swap_val(&(parray[j+1]), &(parray[num_array-1]));

    return (j + 1);
}

template<typename T>
int quick_sort(T *parray, int num_array) {

    assert(parray && num_array >= 0);
    if ((0 == num_array) || (1 == num_array)) {
        return 0;
    }

    int i = partition(parray, num_array);

    quick_sort(parray, i);
    quick_sort(parray + i +1, num_array - i -1);

    return 0;
}

int main(int argc, char *argv[]) {

    //int iarray[] = {7, 6, 5, 4, 3, 2, 1};
    int iarray[] = {7, 6, 5, 4, 3, 2, 1, 14, 100, 19, 47, 25};
    quick_sort(iarray, sizeof(iarray)/sizeof(iarray[0]));

    for (int i = 0; i < sizeof(iarray)/sizeof(iarray[0]); i++) {
        printf("%d, ", iarray[i]);
    }
    printf("\n");
    
    exit(0);
}

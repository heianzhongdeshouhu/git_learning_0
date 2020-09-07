
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

template<typename T>
//int merge_array(T *pa, int astart, int aend, T *pb, int bstart, int bend) {
int merge_array(T *pa, int count_a, T *pb, int count_b) {

    assert(pa && count_a > 0);
    assert(pb && count_b > 0);
    assert(pa < pb);

    size_t len_mem = (count_a + count_b) * sizeof(T);
    T *pmem = new T[ len_mem];

    int k = 0;
    int ii = 0;
    int jj = 0;
    for (; ii < count_a; ) {
        for (; jj < count_b; ) {
            if (pa[ii] < pb[jj]) {
                pmem[k++] = pa[ii++];
            } else {
                pmem[k++] = pb[jj++];
            }
            break;
        }
        if ((ii == count_a) || (jj == count_b)) {
            break;
        }
    }
    if (ii == count_a) {
        for (; jj < count_b;) {
            pmem[k++] = pb[jj++];
        }
    }
    if (jj == count_b) {
        for (; ii < count_a;){
            pmem[k++] = pa[ii++];
        }
    }

    memcpy(pa, pmem, len_mem);

    delete []pmem;

    return 0;
}

template<typename T>
int merge_sort(T *parray, int tstart, int tend) {
    
    assert(parray && (tend >= tstart));
    if (tstart == tend) {
        return 0;
    }

    int half_index = (tstart + tend)/2;
    merge_sort(parray, tstart, half_index);
    merge_sort(parray, half_index + 1, tend);
        
    merge_array(parray + tstart, half_index - tstart + 1, 
            parray + half_index + 1, tend - half_index);

    return 0;
}


int main(int argc, char *argv[]) {

    //int iarray[] = {7, 6, 5, 4, 3, 2, 1};
    //int iarray[] = {7, 6, 5, 4, 3, 2, 1, 17, 100, 19};
    //int iarray[] = {7, 6};
    int iarray[] = {7};
    //int iarray[] = {7, 6, 5};
    //int iarray[] = {7, 6, 5, 4};
    merge_sort(iarray, 0, sizeof(iarray)/sizeof(iarray[0]) - 1);

    for (int i = 0; i < sizeof(iarray)/sizeof(iarray[0]); i++) {
        printf("%d, ", iarray[i]);
    }
    printf("\n");


    exit(0);
}

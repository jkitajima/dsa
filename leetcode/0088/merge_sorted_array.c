#include <stdio.h>

void printarr(int *arr, int arrlen, char *arrname) {
    printf("%s = [", arrname);
    for (int i = 0; i < arrlen; i++) {
        printf("%d", arr[i]);

        if (i+1 != arrlen) {
            printf(", ");
        }
    }
    printf("]\n");
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    // Print the first array (before replace)
    printarr(nums1, m+n, "nums1");

    // Replace zeroed elements from the first array
    for (int i = 0; i < n; i++) {
        nums1[m+i] = nums2[i];
    }

    // Print the first array (after replace)
    printarr(nums1, m+n, "nums1");

    // printf("%s\n", nums1);
}

int main(void) {
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int m = 3;

    int nums2[] = {2, 5, 6};
    int n = 3;

    int *nums1_ptr = nums1;
    int *nums2_ptr = nums2;

    merge(nums1_ptr, m, m, nums2_ptr, n, n);
    return 0;
}
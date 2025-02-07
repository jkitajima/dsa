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
    // Replace zeroed elements from the first array
    for (int i = 0; i < n; i++) {
        nums1[m+i] = nums2[i];
    }

    // Print the first array (after merge)
    printarr(nums1, m+n, "nums1 (after merge)");

    // Reorder the elements to non-decreasing order
    int idx = m+n;
    while (idx >= 0) {
        for (int i = 0; i < idx; i++) {
            if (i+1 < idx && nums1[i] > nums1[i+1]) {
                int tmp = nums1[i+1];
                nums1[i+1] = nums1[i];
                nums1[i] = tmp;
            }
        }
        idx--;
    }

    // Print the array after reordering
    printarr(nums1, m+n, "nums1 (reordered)");
}

int main(void) {
    // Example 1
    printf("[EXAMPLE 1]\n");
    int ex1_nums1[6] = {1, 2, 3, 0, 0, 0};
    int m = 3;

    int ex1_nums2[3] = {2, 5, 6};
    int n = 3;

    int *nums1_ptr = ex1_nums1;
    int *nums2_ptr = ex1_nums2;
    
    printarr(nums1_ptr, m+n, "nums1");
    printarr(nums2_ptr, n, "nums2");
    
    merge(nums1_ptr, m, m, nums2_ptr, n, n);
    printf("\n");

    // Example 2
    printf("[EXAMPLE 2]\n");
    int ex2_nums1[1] = {1};
    m = 1;

    int ex2_nums2[0] = {};
    n = 0;

    nums1_ptr = ex2_nums1;
    nums2_ptr = ex2_nums2;
    
    printarr(nums1_ptr, m+n, "nums1");
    printarr(nums2_ptr, n, "nums2");
    
    merge(nums1_ptr, m, m, nums2_ptr, n, n);
    printf("\n");

    // Example 3
    printf("[EXAMPLE 3]\n");
    int ex3_nums1[0] = {};
    m = 0;

    int ex3_nums2[1] = {1};
    n = 1;

    nums1_ptr = ex3_nums1;
    nums2_ptr = ex3_nums2;
    
    printarr(nums1_ptr, m+n, "nums1");
    printarr(nums2_ptr, n, "nums2");
    
    merge(nums1_ptr, m, m, nums2_ptr, n, n);
    printf("\n");

    return 0;
}
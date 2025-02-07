#include <stdio.h>
#include <limits.h>

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
    // Print the first array (before merge)
    printarr(nums1, m+n, "nums1 (before merge)");

    // Replace zeroed elements from the first array
    for (int i = 0; i < n; i++) {
        nums1[m+i] = nums2[i];
    }

    // Print the first array (after merge)
    printarr(nums1, m+n, "nums1 (after merge)");

    // Reorder the elements to non-decreasing order
    int counter = 1;
    int max = INT_MIN;
    loop:
    printf("####   LOOP COUNTER %d   ####\n", counter);
    // if (counter == 2) { return; }
    for (int i = 0; i < m+n; i++) {
        if (i+1 < m+n && nums1[i] > nums1[i+1]) {
            int tmp = nums1[i+1];
            nums1[i+1] = nums1[i];
            nums1[i] = tmp;
        }

        if (i+1 == m+n) {
            printf("[LAST_IDX] max = %d | curr = %d\n", max, nums1[i]);
            if (nums1[i] != max) {
                max = nums1[i];
                printarr(nums1, m+n, "[WILL_LOOP_AGAIN] nums1");
                counter++;
                goto loop;
            }
        }

        if (nums1[i] > max) {
            printf("max = %d | curr = %d (swapping)\n", max, nums1[i]);
            max = nums1[i];
        } else {
            printf("[DEBUG] max = %d | curr = %d\n", max, nums1[i]);
        }
    }

    printarr(nums1, m+n, "nums1");

    // printf("%s\n", nums1);
}

int main(void) {
    int nums1[6] = {1, 2, 3, 0, 0, 0};
    int m = 3;

    int nums2[3] = {2, 0, 1};
    int n = 3;

    int *nums1_ptr = nums1;
    int *nums2_ptr = nums2;

    merge(nums1_ptr, m, m, nums2_ptr, n, n);
    return 0;
}
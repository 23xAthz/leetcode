#include <stdio.h>
#include <stdlib.h>

/* ---------- MERGE SORT ---------- */

void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int *arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

/* ---------- MAIN LOGIC ---------- */

int minRemoval(int* nums, int numsSize, int k) {
    // Sort using merge sort
    mergeSort(nums, 0, numsSize - 1);

    int l = 0;
    int maxLen = 1;

    for (int r = 0; r < numsSize; r++) {
        while ((long long)nums[r] > (long long)nums[l] * k) {
            l++;
        }
        int windowSize = r - l + 1;
        if (windowSize > maxLen)
            maxLen = windowSize;
    }

    return numsSize - maxLen;
}

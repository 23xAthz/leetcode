/*
1984. Minimum Difference Between Highest and Lowest K Scores

Pattern: Sorting + Sliding Window
Difficulty: Easy
Platform: LeetCode

Approach:
1. Sort the array
2. Use a sliding window of size k
3. Compute difference using window endpoints

Time Complexity: O(n log n)
Space Complexity: O(1)

*/

#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minimumDifference(int* nums, int numsSize, int k) {
    if (k == 1)
        return 0;

    qsort(nums, numsSize, sizeof(int), cmp);

    int minDiff = INT_MAX;

    for (int i = 0; i <= numsSize - k; i++) {
        int diff = nums[i + k - 1] - nums[i];
        if (diff < minDiff)
            minDiff = diff;
    }

    return minDiff;
}

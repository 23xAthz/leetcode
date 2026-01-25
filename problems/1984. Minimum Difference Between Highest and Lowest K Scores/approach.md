# Intuition

Brute-forcing all possible groups of `k` students would require checking combinations, which is inefficient.
The key observation is that the difference depends only on the **maximum and minimum** values in a chosen group.

By sorting the scores, the minimum and maximum values of any group of `k` elements will always lie at the **ends of a contiguous window** of size `k`. This allows the problem to be reduced to scanning such windows efficiently.

---

# Approach

1. Sort the array of scores.
2. Use a sliding window of size `k` over the sorted array.
3. For each window, compute the difference between the first and last elements:
   - Minimum = `nums[i]`
   - Maximum = `nums[i + k - 1]`
4. Track the minimum difference across all windows.
5. Return the smallest difference found.

---

# Complexity

- **Time Complexity:** `O(n log n)` due to sorting  
- **Space Complexity:** `O(1)` (in-place sorting, no extra data structures)

---

# Code

```c
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

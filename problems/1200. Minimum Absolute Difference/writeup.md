# 1200. Minimum Abosulte Diference
---
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Brute force would mean checking every pair, which is unnecessary.
Once the array is sorted, the minimum absolute difference can only be between two adjacent elements, so sorting before anything.

Sliding window problem along with storing the pairs in another 2d array using two seperate loops.

# Approach
<!-- Describe your approach to solving the problem. -->
- Sort the array.
- Traverse the sorted array to find the minimum difference between consecutive elements.
- Traverse again to count how many such pairs exist.
- Allocate memory for the result.
- Traverse once more and store all pairs whose difference equals the minimum difference.

Because the array is sorted, each pair automatically satisfies a < b, and the result is already in ascending order.

# Complexity
- Time complexity: $$O(n log n)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $$O(n)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```c []
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <limits.h>

// adding a custom comparator for qsort
int cmp(const void* a, const void* b){
    return (*(int*)a-*(int*)b);
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {

    // sorting the array
    qsort(arr, arrSize, sizeof(int), cmp);

    // find minimum absolute difference between adjacent elements
    int minDiff=INT_MAX;
    for(int i=0; i<(arrSize-1); i++){
        int diff= (arr[i+1]-arr[i]);
        if(diff<minDiff){
            minDiff=diff;
        }
    }

    // count number of valid pairs with the same minDiff
    int count=0;
    for(int i=0; i<arrSize-1; i++){
        if(minDiff==(arr[i+1]-arr[i])){
            count++;
        }
    }

    // allocate result arrays from the count of pairs
    *returnSize = count;
    int** result = (int**)malloc(count*sizeof(int*));
    *returnColumnSizes = (int*)malloc(count*sizeof(int));

    // filling the results of teh matching minDiff element pairs into result array of arrays  
    int idx = 0;
    for(int i=0; i< arrSize-1; i++){
        if(minDiff == (arr[i+1]-arr[i])){
            result[idx] = (int*)malloc(2*sizeof(int));
            result[idx][0] = arr[i];
            result[idx][1] = arr[i+1];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }

    return result;
}
```

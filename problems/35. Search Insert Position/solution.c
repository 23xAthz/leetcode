int searchInsert(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;              // target found
        } 
        else if (target < nums[mid]) {
            high = mid - 1;          // go left
        } 
        else {
            low = mid + 1;           // go right
        }
    }

    // target not found → insertion position
    return low;
}

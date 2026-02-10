int longestBalanced(int* nums, int numsSize) {
    int maxLength = 0;
    
    // Try each starting position
    for (int i = 0; i < numsSize; i++) {
        int evenCount = 0, oddCount = 0;
        int even[100001] = {0};  // Track distinct even numbers
        int odd[100001] = {0};   // Track distinct odd numbers
        
        // Expand to the right
        for (int j = i; j < numsSize; j++) {
            if (nums[j] % 2 == 0) {
                // Even number
                if (even[nums[j]] == 0) {
                    even[nums[j]] = 1;
                    evenCount++;
                }
            } else {
                // Odd number
                if (odd[nums[j]] == 0) {
                    odd[nums[j]] = 1;
                    oddCount++;
                }
            }
            
            // Check if balanced
            if (evenCount == oddCount) {
                int length = j - i + 1;
                if (length > maxLength) {
                    maxLength = length;
                }
            }
        }
    }
    
    return maxLength;
}

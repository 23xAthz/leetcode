char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = (lenA > lenB ? lenA : lenB) + 1; // +1 for potential carry
    
    // Allocate memory for result (+1 for null terminator)
    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    result[maxLen] = '\0';
    
    int carry = 0;
    int i = lenA - 1;
    int j = lenB - 1;
    int k = maxLen - 1;
    
    // Add from right to left
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        
        result[k] = (sum % 2) + '0';
        carry = sum / 2;
        k--;
    }
    
    // Return pointer to where the actual result starts
    // k+1 is the index of the first digit we wrote
    return result + k + 1;
}

// Comparator for qsort
int cmp(const void* a, const void* b){
    return (*(int*)a-*(int*)b);
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {

    // Step 1: Sort the array
    qsort(arr, arrSize, sizeof(int), cmp);

    // Step 2: Find minimum absolute difference
    int minDiff=INT_MAX;
    for(int i=0; i<(arrSize-1); i++){
        int diff= (arr[i+1]-arr[i]);
        if(diff<minDiff){
            minDiff=diff;
        }
    }

    // Step 3: Count number of valid pairs
    int count=0;
    for(int i=0; i<arrSize-1; i++){
        if(minDiff==(arr[i+1]-arr[i])){
            count++;
        }
    }

    // Step 4: Allocate result arrays
    *returnSize = count;
    int** result = (int**)malloc(count*sizeof(int*));
    *returnColumnSizes = (int*)malloc(count*sizeof(int));

    // Step 5: Fill result
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

# 744. Find Smallest Letter Greater Than Target

## Intuition
Since the `letters` array is sorted in non-decreasing order, the problem reduces to finding the first element strictly greater than `target`. Because of the circular condition, if no such element exists, the answer defaults to the first element in the array.
## Approach
Perform a linear scan from the beginning of the array.

- At each index, compare `letters[i]` with `target.`

- The moment `letters[i] > target`, return that character, as it is guaranteed to be the smallest valid answer due to the sorted order.

- If the scan completes **without** a match, return `letters[0]` to handle the wrap-around requirement.
## Complexity
- Time complexity: $$O(n)$$


- Space complexity: $$O(1)$$

## Code
```c []
char nextGreatestLetter(char* letters, int lettersSize, char target) {
    for (int i = 0; i < lettersSize; i++)
        if (letters[i] > target) return letters[i];
    return letters[0];
}
```

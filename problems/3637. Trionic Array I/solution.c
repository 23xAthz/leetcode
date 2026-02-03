bool isTrionic(int* nums, int numsSize) {

    if (numsSize < 4)
        return false;

    int p, q;
    p = q = -1;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] >= nums[i + 1]) {
            p = i;
            break;
        }
    }

    if (p <= 0)
        return false;

    for (int i = p; i < numsSize - 1; i++) {
        if (nums[i] <= nums[i + 1]) {
            q = i;
            break;
        }
    }

    if (q == -1 || q >= numsSize - 1 || q == p)
        return false;

    for (int i = q; i < numsSize - 1; i++) {
        if (nums[i] >= nums[i + 1]) {
            return false;
        }
    }

    return true;
}

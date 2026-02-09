/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
// Count nodes
int count(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + count(root->left) + count(root->right);
}

// Store values in array
void toArray(struct TreeNode* root, int* arr, int* i) {
    if (!root) return;
    toArray(root->left, arr, i);
    arr[(*i)++] = root->val;
    toArray(root->right, arr, i);
}

// Build tree from array
struct TreeNode* build(int* arr, int start, int end) {
    if (start > end) return NULL;
    
    int mid = (start + end) / 2;
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = arr[mid];
    node->left = build(arr, start, mid - 1);
    node->right = build(arr, mid + 1, end);
    
    return node;
}

// Main function
struct TreeNode* balanceBST(struct TreeNode* root) {
    int n = count(root);
    int* arr = malloc(n * sizeof(int));
    int i = 0;
    
    toArray(root, arr, &i);
    struct TreeNode* result = build(arr, 0, n - 1);
    
    free(arr);
    return result;
}

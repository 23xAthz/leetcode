/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int height(struct TreeNode* node) {
    // Base case: empty tree has height 0 and is balanced
    if (node == NULL) {
        return 0;
    }
    
    // Get heights of left and right subtrees
    int left_height = height(node->left);
    int right_height = height(node->right);
    
    // If either subtree is unbalanced, return -1
    if (left_height == -1 || right_height == -1) {
        return -1;
    }
    
    // If current node is unbalanced, return -1
    if (abs(left_height - right_height) > 1) {
        return -1;
    }
    
    // Return height of current subtree
    return (left_height > right_height ? left_height : right_height) + 1;
}

bool isBalanced(struct TreeNode* root) {
    return height(root) != -1;
}

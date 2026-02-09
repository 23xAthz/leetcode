/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* rotateRight(struct TreeNode* parent, struct TreeNode* node) {
    struct TreeNode* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    parent->right = temp;
    return temp;
}

int treeToVine(struct TreeNode* root) {
    struct TreeNode* tail = root;
    struct TreeNode* rest = tail->right;
    int count = 0;
    
    while (rest != NULL) {
        if (rest->left == NULL) {
            tail = rest;
            rest = rest->right;
            count++;
        } else {
            rotateRight(tail, rest);
            rest = tail->right;
        }
    }
    
    return count;
}

void compress(struct TreeNode* root, int count) {
    struct TreeNode* scanner = root;
    
    for (int i = 0; i < count; i++) {
        struct TreeNode* child = scanner->right;
        scanner->right = child->right;
        scanner = scanner->right;
        child->right = scanner->left;
        scanner->left = child;
    }
}

int fullSize(int size) {
    int n = 1;
    while (n <= size) {
        n = n * 2 + 1;
    }
    return n / 2;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    if (root == NULL) return NULL;
    
    struct TreeNode* dummy = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    dummy->right = root;
    dummy->left = NULL;
    
    int n = treeToVine(dummy);
    int m = fullSize(n);
    
    compress(dummy, n - m);
    
    while (m > 1) {
        m = m / 2;
        compress(dummy, m);
    }
    
    root = dummy->right;
    free(dummy);
    
    return root;
}

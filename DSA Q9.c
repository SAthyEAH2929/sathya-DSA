#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function prototypes
int getNodeDepth(TreeNode* node, int target, int depth);
TreeNode* createNode(int value);

int main() {
    // Create a sample tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    int targetValue = 5;
    int depth = getNodeDepth(root, targetValue, 0);
    
    if (depth != -1) {
        printf("Depth of node with value %d: %d\n", targetValue, depth);
    } else {
        printf("Node with value %d not found in the tree.\n", targetValue);
    }
    
    // Free allocated memory
    // (In practice, you should also free all nodes, but it's omitted here for brevity)
    
    return 0;
}

// Function to calculate the depth of a specific node
int getNodeDepth(TreeNode* node, int target, int depth) {
    if (node == NULL) {
        return -1; // Node not found
    }
    
    if (node->value == target) {
        return depth; // Target node found
    }
    
    // Recursively search in left subtree
    int leftDepth = getNodeDepth(node->left, target, depth + 1);
    
    // If node is found in the left subtree, return the depth
    if (leftDepth != -1) {
        return leftDepth;
    }
    
    // Recursively search in right subtree
    return getNodeDepth(node->right, target, depth + 1);
}

// Function to create a new node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

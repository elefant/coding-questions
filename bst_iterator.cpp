/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class BSTIterator {
public:
    //@param root: The root of binary tree.
    BSTIterator(TreeNode *root) {
        while (root) {
            leftNodes.push(root);
            root = root->left;
        }
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return !leftNodes.empty();
    }

    //@return: return next node
    TreeNode* next() {
        auto ret = leftNodes.top();
        leftNodes.pop();
        auto ptr = ret->right;
        while (ptr) {
            leftNodes.push(ptr);
            ptr = ptr->left;
        }

        return ret;
    }

    stack<TreeNode*> leftNodes;
};
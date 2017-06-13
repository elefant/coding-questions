/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* helper(TreeNode* root, int val1, int val2, bool& val1Found, bool& val2Found) {
    if (!root) {
        return nullptr;
    }
    if (root->val == val1) {
        val1Found = true;
        //return root;
    } else if (root->val == val2) {
        val2Found = true;
        //return root;
    }
    auto leftLca = helper(root->left, val1, val2, val1Found, val2Found);
    auto rightLca = helper(root->right, val1, val2, val1Found, val2Found);

    if (root->val == val1 || root->val == val2) {
        return root;
    }
    if (leftLca && rightLca) {
        return root;
    }
    if (!leftLca && !rightLca) {
        return nullptr;
    }
    return leftLca ? leftLca : rightLca;
}

int Solution::lca(TreeNode* A, int val1, int val2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    bool val1Found = false;
    bool val2Found = false;
    auto ans = helper(A, val1, val2, val1Found, val2Found);
    if (!ans) {
        return -1;
    }
    if (val1 == val2) {
        return val1Found ? ans->val : -1;
    }
    return (val1Found && val2Found) ? ans->val : -1;
}

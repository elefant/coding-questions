/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void helper(TreeNode* root, int curDepth, int& sol) {
    if (!root) return;
    if (!root->left && !root->right) {
        sol = min(sol, curDepth);
        return;
    }
    helper(root->left, curDepth + 1, sol);
    helper(root->right, curDepth + 1, sol);
}

int Solution::minDepth(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    /*
    int sol = INT_MAX;
    helper(A, 1, sol);
    return sol;
    */
    if (!A) {
        return -1;
    }
    int leftMin = minDepth(A->left);
    int rightMin = minDepth(A->right);
    if (leftMin != -1 && rightMin != -1) {
        return min(leftMin, rightMin) + 1;
    }
    if (leftMin == -1 && rightMin == -1) {
        return 1;
    }
    return leftMin == -1 ? rightMin + 1 : leftMin + 1;
}

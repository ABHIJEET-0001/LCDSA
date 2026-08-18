class Solution {
public:

    vector<int> solve(TreeNode* root) {

        // Base case
        if (root == NULL) {
            return {0, 0};
        }

        // Get result from left subtree
        vector<int> left = solve(root->left);

        // Get result from right subtree
        vector<int> right = solve(root->right);

        // Case 1: Don't rob current node
        int notRob = max(left[0], left[1])
                   + max(right[0], right[1]);

        // Case 2: Rob current node
        int rob = root->val
                + left[0]
                + right[0];

        return {notRob, rob};
    }

    int rob(TreeNode* root) {

        vector<int> ans = solve(root);

        // max(not rob root, rob root)
        return max(ans[0], ans[1]);
    }
};
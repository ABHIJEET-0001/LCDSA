class Solution {
public:
    vector<string> ans;

    void dfs(TreeNode* root, string path) {

        if(root == NULL) return;

        // Current node add karo
        if(path.empty())
            path = to_string(root->val);
        else
            path += "->" + to_string(root->val);

        // Leaf node
        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
            return;
        }

        dfs(root->left, path);
        dfs(root->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        dfs(root, "");

        return ans;
    }
};
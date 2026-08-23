class Solution {
public:
    TreeNode* prev = NULL;
    int count = 0;
    int maxCount = 0;
    vector<int> ans;

    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;

        inorder(root->left);

        if(prev == NULL)
        {
            count = 1;
        }
        else if(prev->val == root->val)
        {
            count++;
        }
        else
        {
            count = 1;
        }

        if(count > maxCount)
        {
            maxCount = count;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(count == maxCount)
        {
            ans.push_back(root->val);
        }

        prev = root;

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root)
    {
        inorder(root);
        return ans;
    }
};
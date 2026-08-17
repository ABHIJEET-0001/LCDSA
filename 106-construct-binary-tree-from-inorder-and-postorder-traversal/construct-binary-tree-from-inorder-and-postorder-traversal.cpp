class Solution {
public:

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int, int> inMap;

        // Store inorder value -> index
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;

        return solve(inorder, postorder, 0,
                     inorder.size() - 1,
                     postIndex, inMap);
    }

    TreeNode* solve(vector<int>& inorder,
                    vector<int>& postorder,
                    int inStart,
                    int inEnd,
                    int& postIndex,
                    unordered_map<int, int>& inMap) {

        // No elements
        if (inStart > inEnd) {
            return NULL;
        }

        // Postorder last element = root
        int rootValue = postorder[postIndex--];

        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int rootIndex = inMap[rootValue];

        // IMPORTANT:
        // Right first because postorder is consumed backwards
        root->right = solve(inorder, postorder,
                            rootIndex + 1,
                            inEnd,
                            postIndex,
                            inMap);

        // Then left
        root->left = solve(inorder, postorder,
                           inStart,
                           rootIndex - 1,
                           postIndex,
                           inMap);

        return root;
    }
};
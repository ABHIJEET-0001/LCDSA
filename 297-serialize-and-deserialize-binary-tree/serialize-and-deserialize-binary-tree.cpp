
class Codec {
public:
    // Serialize: Tree -> String
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "#,";
        }

        string result = to_string(root->val) + ",";

        result += serialize(root->left);
        result += serialize(root->right);

        return result;
    }

    // Deserialize: String -> Tree
    TreeNode* build(vector<string>& nodes, int& i) {
        if (nodes[i] == "#") {
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;

        root->left = build(nodes, i);
        root->right = build(nodes, i);

        return root;
    }

    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string token;
        stringstream ss(data);

        while (getline(ss, token, ',')) {
            if (!token.empty()) {
                nodes.push_back(token);
            }
        }

        int i = 0;
        return build(nodes, i);
    }
};

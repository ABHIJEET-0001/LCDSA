class Solution {
public:

    struct Node {
        Node* child[2];

        Node() {
            child[0] = nullptr;
            child[1] = nullptr;
        }
    };

   
    void insert(Node* root, int num) {

        Node* curr = root;

      
        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            if (curr->child[bit] == nullptr) {
                curr->child[bit] = new Node();
            }

            curr = curr->child[bit];
        }
    }


    int findMaxXOR(Node* root, int num) {

        Node* curr = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            int opposite = 1 - bit;

            if (curr->child[opposite] != nullptr) {

               
                ans = ans | (1 << i);

                curr = curr->child[opposite];
            }
            else {
                curr = curr->child[bit];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {

        Node* root = new Node();

        
        for (int num : nums) {
            insert(root, num);
        }

        int ans = 0;

        
        for (int num : nums) {
            ans = max(ans, findMaxXOR(root, num));
        }

        return ans;
    }
};
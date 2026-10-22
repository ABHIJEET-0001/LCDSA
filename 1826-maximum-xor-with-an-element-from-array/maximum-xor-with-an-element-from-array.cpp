
class Solution {
public:
    struct Node {
        Node* links[2];

        Node() {
            links[0] = nullptr;
            links[1] = nullptr;
        }
    };

    class Trie {
    public:
        Node* root;

        Trie() {
            root = new Node();
        }

        void insert(int num) {
            Node* node = root;

            for (int bit = 30; bit >= 0; bit--) {
                int b = (num >> bit) & 1;

                if (node->links[b] == nullptr) {
                    node->links[b] = new Node();
                }

                node = node->links[b];
            }
        }

        int getMax(int num) {
            Node* node = root;
            int maxXor = 0;

            for (int bit = 30; bit >= 0; bit--) {
                int b = (num >> bit) & 1;
                int opposite = 1 - b;

                if (node->links[opposite] != nullptr) {
                    maxXor |= (1 << bit);
                    node = node->links[opposite];
                } else {
                    node = node->links[b];
                }
            }

            return maxXor;
        }
    };

    vector<int> maximizeXor(vector<int>& nums,
                            vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<array<int, 3>> offlineQueries;
        int q = queries.size();

        for (int i = 0; i < q; i++) {
            int x = queries[i][0];
            int m = queries[i][1];

            offlineQueries.push_back({m, x, i});
        }

        sort(offlineQueries.begin(), offlineQueries.end());

        vector<int> answer(q, -1);
        Trie trie;
        int j = 0;

        for (auto& query : offlineQueries) {
            int m = query[0];
            int x = query[1];
            int idx = query[2];

            while (j < nums.size() && nums[j] <= m) {
                trie.insert(nums[j]);
                j++;
            }

            if (j > 0) {
                answer[idx] = trie.getMax(x);
            }
        }

        return answer;
    }
};

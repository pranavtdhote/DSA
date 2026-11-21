class Solution {
public:
    vector<int> answer;
    vector<vector<int>> children;

    void dfs(int node, string &s, vector<int> &last) {
        int c = s[node] - 'a';

        // Store the previous closest ancestor with same character
        int previous = last[c];

        // Update the closest ancestor for this character
        last[c] = node;

        // Process children in the original tree
        for (int child : children[node]) {
            dfs(child, s, last);
        }

        // Restore previous ancestor while backtracking
        last[c] = previous;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        children.resize(n);
        answer.resize(n, 1);

        // Build original tree
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);

        // Find new parent of every node
        vector<int> newParent(n, -1);

        function<void(int)> findParent = [&](int node) {
            int c = s[node] - 'a';

            int previous = last[c];

            if (node != 0 && previous != -1) {
                newParent[node] = previous;
            } else {
                newParent[node] = parent[node];
            }

            last[c] = node;

            for (int child : children[node]) {
                findParent(child);
            }

            last[c] = previous;
        };

        findParent(0);

        // Build modified tree
        vector<vector<int>> newChildren(n);

        for (int i = 1; i < n; i++) {
            newChildren[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes in modified tree
        function<int(int)> calculate = [&](int node) {
            int size = 1;

            for (int child : newChildren[node]) {
                size += calculate(child);
            }

            answer[node] = size;
            return size;
        };

        calculate(0);

        return answer;
    }
};
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int size = n * m;
        int mod = 12345;

        vector<long long> arr(size);

        // Flatten grid
        int k = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[k++] = grid[i][j] % mod;
            }
        }

        // Prefix
        vector<long long> prefix(size, 1);
        for(int i = 1; i < size; i++) {
            prefix[i] = (prefix[i-1] * arr[i-1]) % mod;
        }

        // Suffix
        vector<long long> suffix(size, 1);
        for(int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i+1] * arr[i+1]) % mod;
        }

        // Result array
        vector<long long> result(size);
        for(int i = 0; i < size; i++) {
            result[i] = (prefix[i] * suffix[i]) % mod;
        }

        // Convert back to 2D
        vector<vector<int>> ans(n, vector<int>(m));
        k = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[i][j] = result[k++];
            }
        }

        return ans;
    }
};
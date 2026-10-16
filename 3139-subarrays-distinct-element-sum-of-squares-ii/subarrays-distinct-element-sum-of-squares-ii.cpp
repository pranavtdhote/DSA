
class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        long long x = val % MOD;

        tree[node].sq =
            (tree[node].sq + 2LL * x * tree[node].sum
             + x * x % MOD * len) % MOD;

        tree[node].sum =
            (tree[node].sum + x * len) % MOD;

        tree[node].lazy =
            (tree[node].lazy + x) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;

        apply(node * 2, l, mid, tree[node].lazy);
        apply(node * 2 + 1, mid + 1, r,
              tree[node].lazy);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long val) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r,
               ql, qr, val);

        tree[node].sum =
            (tree[node * 2].sum +
             tree[node * 2 + 1].sum) % MOD;

        tree[node].sq =
            (tree[node * 2].sq +
             tree[node * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n + 5, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int x = nums[r];

            // Increment distinct counts for subarrays
            // where x has not appeared before.
            update(1, 0, n - 1,
                   last[x] + 1, r, 1);

            // Sum of squares for all subarrays
            // ending at r.
            ans = (ans + tree[1].sq) % MOD;

            last[x] = r;
        }

        return (int)ans;
    }
};

class Solution {
public:
    string result = "";
    int count = 0;

    void solve(int n, int k, string &curr) {
        // if already found → stop recursion
        if (!result.empty()) return;

        if (curr.length() == n) {
            count++;
            if (count == k) {
                result = curr;
            }
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != ch) {
                curr.push_back(ch);
                solve(n, k, curr);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        solve(n, k, curr);
        return result;
    }
};
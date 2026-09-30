class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int> result(n,0);
        int dep = 0;

        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                result[i] = dep%2;
                dep++;
            }else{
                dep--;
                result[i]=dep%2;
            }
        }
        return result;
    }
};
class Solution {
public:
    int maxDepth(string s) {
        int cur=0,sol=0;
        for(auto i:s){
            if(i=='('){
                cur++;
                sol = max(sol,cur);
            }else if(i==')'){
                cur--;
            }
        }
        return sol;
    }
};
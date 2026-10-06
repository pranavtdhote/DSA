class Solution {
public:
    int minAddToMakeValid(string s) {
        int bal = 0;
        int ans = 0;

        for(char i:s){
            if(i=='('){
                bal++;
            }else{
                if(bal>0){
                    bal--;
                }else{
                    ans++;
                }
            }
        }
        return bal+ans;
    }
};
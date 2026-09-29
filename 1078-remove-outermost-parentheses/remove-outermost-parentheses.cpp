class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int dep = 0;

        for(char ch:s){
            if(ch == '('){
                if(dep>0){
                    result+=ch;
                }
                dep++;
            }
            else{
                dep--;
                if(dep>0){
                    result+=ch;
                }
            }
        } 
        return result;
    }
};
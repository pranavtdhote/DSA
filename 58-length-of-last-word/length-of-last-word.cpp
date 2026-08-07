class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int n = s.length();
        bool counting = false;
       for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){
                counting = true;
                ans++;
            }
            else if(counting){
                break;
            }
       }
       return ans ; 
    }
};
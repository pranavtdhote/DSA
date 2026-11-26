class Solution {
public:
    bool canAliceWin(int n) {
        int stones = n;
        int remove = 10;

        bool aliceturn = true;

        while(stones>=remove){
            stones-=remove;
            remove--;

            aliceturn = !aliceturn;
        }
        return !aliceturn;
    }
};
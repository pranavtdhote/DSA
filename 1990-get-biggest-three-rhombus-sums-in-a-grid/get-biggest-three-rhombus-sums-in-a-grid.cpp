class Solution {
public:
    //Pranav
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<int> sums;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                // radius 0 rhombus
                sums.insert(grid[i][j]);
                
                for(int k=1;;k++){
                    
                    if(i-k<0 || i+k>=m || j-k<0 || j+k>=n)
                        break;
                    
                    int sum = 0;

                    int x=i-k, y=j;

                    // top -> right
                    for(int t=0;t<k;t++){
                        sum += grid[x+t][y+t];
                    }

                    // right -> bottom
                    for(int t=0;t<k;t++){
                        sum += grid[i+t][j+k-t];
                    }

                    // bottom -> left
                    for(int t=0;t<k;t++){
                        sum += grid[i+k-t][j-t];
                    }

                    // left -> top
                    for(int t=0;t<k;t++){
                        sum += grid[i-t][j-k+t];
                    }

                    sums.insert(sum);
                }
            }
        }

        vector<int> ans;
        
        for(auto it = sums.rbegin(); it != sums.rend() && ans.size()<3; it++){
            ans.push_back(*it);
        }

        return ans;
    }
};
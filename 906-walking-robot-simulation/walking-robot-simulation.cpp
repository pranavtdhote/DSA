class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        // Directions: N, E, S, W
        vector<pair<int,int>> dirVec = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };
        
        int dir = 0; // start facing North
        int x = 0, y = 0;
        int maxDist = 0;

        // Store obstacles
        unordered_set<string> obs;
        for(auto &o : obstacles) {
            obs.insert(to_string(o[0]) + "#" + to_string(o[1]));
        }

        for(int cmd : commands) {
            
            if(cmd == -2) {
                // turn left
                dir = (dir + 3) % 4;
            }
            else if(cmd == -1) {
                // turn right
                dir = (dir + 1) % 4;
            }
            else {
                // move step by step
                for(int i = 0; i < cmd; i++) {
                    int nx = x + dirVec[dir].first;
                    int ny = y + dirVec[dir].second;

                    if(obs.count(to_string(nx) + "#" + to_string(ny))) {
                        break; // obstacle hit
                    }

                    x = nx;
                    y = ny;

                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};
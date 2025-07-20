class Solution {
    public:
        bool backtrack(vector<int> &matchsticks, int target, vector<int> &sides, int idx){
            if(idx == matchsticks.size()){
                if(sides[0] == sides[1] && sides[1] == sides[2] && sides[2]==sides[3]){
                    return true;
                }
                return false;
            }
    
            for(int i=0; i<4; i++){
                if(sides[i]+matchsticks[idx]>target) continue;
    
                int j = i-1;
                while(j>=0){
                    if(sides[j] == sides[i]) break;
                    j--;
                }
    
                if(j!=-1) continue;
                
                sides[i]+=matchsticks[idx];
                if(backtrack(matchsticks, target, sides, idx+1)) return true;
                sides[i]-=matchsticks[idx];
            }
            return false;
        }
    
        bool makesquare(vector<int>& matchsticks) {
            if(matchsticks.size() == 0) return false;
            vector<int> sides(4, 0);
            int sum = 0;
            for(int i=0; i<matchsticks.size(); i++) sum+=matchsticks[i];
    
            int target = sum/4;
            sort(matchsticks.begin(), matchsticks.end(), greater<int>());
            return backtrack(matchsticks, target, sides, 0);
        }
    };
class Solution {
    public:
        vector<int> range(int n){
            vector<int> ans;
            int a = pow(2, n);
            for(int i = 0; i < a; i++){
                ans.push_back(i);
            }
            return ans;
        }
    
        vector<int> grayCode(int n) {
            vector<int> nums = range(n);
            vector<int> gray;
            for (int i : nums) {
                gray.push_back(i ^ (i >> 1));
            }
            return gray;
        }
    };

// gray.push_back(i ^ (i >> 1));
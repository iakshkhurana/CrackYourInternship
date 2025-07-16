// TLE, optimised using DP

class Solution {
    public:
      bool helper(int target, int currentSum, vector<int>& nums, int i){
          if(currentSum==target){
              return true;
          }
          if(currentSum>target || i==nums.size()) return false;
          int include = helper(target,nums[i]+currentSum,nums,i+1);
          int exclude = helper(target,currentSum,nums,i+1);
          return include || exclude;
      }
      bool equalPartition(vector<int>& arr) {
          int totalSum = 0;
          for(auto num : arr){
              totalSum += num;
          }
          if(totalSum % 2 != 0){
              return false;
          }
          int target = totalSum/2;
          return helper(target,0,arr,0);
      }
  };
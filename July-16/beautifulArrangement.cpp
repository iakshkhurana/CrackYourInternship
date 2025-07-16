class Solution {
    public:
        void helper(vector<int>& arr, int n, int count, vector<bool>& visited, int& result) {
            if (count == n) {
                result++;
                return;
            }
    
            for (int j = 0; j < n; ++j) {
                if (!visited[j]) {
                    if ((arr[j] % (count + 1) == 0) || ((count + 1) % arr[j] == 0)) {
                        visited[j] = true;
                        helper(arr, n, count + 1, visited, result);
                        visited[j] = false;
                    }
                }
            }
        }
    
        int countArrangement(int n) {
            vector<int> arr(n);
            vector<bool> visited(n, false);
            int result = 0;
            
            for (int i = 0; i < n; ++i) {
                arr[i] = i + 1;
            }
    
            helper(arr, n, 0, visited, result);
            return result;
        }
    };
    
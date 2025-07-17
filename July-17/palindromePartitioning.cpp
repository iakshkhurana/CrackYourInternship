class Solution {
    public:
        /* how backtracking is working?
        ith index ++ hota jayega and recursively check hota rhega
        partitions me push krte jayenge agar kabhi bhi !isPalindrome toh stop
        agar all checks passed and i==s.size() then return the ans and
        backtrack ke liye pop_back() krdo partitions ko taaki next check ho ske
        */
        bool isPalindrome(string s){
            string rev = s;
            reverse(rev.begin(),rev.end());
            return s == rev;
        }
        void getAllParts(string s, vector<string>& partitions, vector<vector<string>> & ans){
            if(s.size()==0){
                ans.push_back(partitions);
                return;
            }
            for(int i=0;i<s.size();i++){
                string part = s.substr(0,i+1);
                if(isPalindrome(part)){
                    partitions.push_back(part);
                    getAllParts(s.substr(i+1),partitions, ans);
                    partitions.pop_back();
                }
            }
        }
        vector<vector<string>> partition(string s) {
            vector<string>partitions;
            vector<vector<string>>ans;
            getAllParts(s,partitions, ans);
            return ans;
        }
    };
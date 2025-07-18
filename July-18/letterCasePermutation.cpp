class Solution{
    public:
        void backtrack(string& s, int index, vector<string>& result) {
            if (index == s.length()) {
                result.push_back(s);
                return;
            }

            backtrack(s, index + 1, result);

            if (isalpha(s[index])) {
                s[index] ^= 32;
                backtrack(s, index + 1, result);
                s[index] ^= 32;
            }
        }

        vector<string> letterCasePermutation(string s) {
            vector<string> result;
            backtrack(s, 0, result);
            return result;
        }
};
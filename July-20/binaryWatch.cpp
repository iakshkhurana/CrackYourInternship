class Solution {
    public:
        vector<string> res;
        vector<int> hours = {1, 2, 4, 8}, minutes = {1, 2, 4, 8, 16, 32};
    
        void solve(pair<int, int> time, int turnedOn, int start) {
            if (turnedOn == 0) {
                if (time.second < 10)
                    res.push_back(to_string(time.first) + ":0" +
                                  to_string(time.second));
    
                else
                    res.push_back(to_string(time.first) + ":" +
                                  to_string(time.second));
    
                return;
            }
    
            for (int i = start; i < 10; i++) {
                if (i < hours.size()) {
                    time.first += hours[i];
                    if (time.first < 12)
                        solve(time, turnedOn - 1, i + 1);
                    time.first -= hours[i];
                } else {
                    time.second += minutes[i - hours.size()];
                    if (time.second < 60)
                        solve(time, turnedOn - 1, i + 1);
                    time.second -= minutes[i - hours.size()];
                }
            }
        }
    
        vector<string> readBinaryWatch(int turnedOn) {
            solve(make_pair(0, 0), turnedOn, 0);
    
            return res;
        }
    };
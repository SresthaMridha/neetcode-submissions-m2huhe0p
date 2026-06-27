class Solution {
private: 
    bool fun(unordered_map<char,int> &have, unordered_map<char,int> &needed){
        for(auto &x : needed){
            if(have[x.first] < x.second){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> have;
        unordered_map<char,int> needed;

        int n = s.size();
        int m = t.size();

        int low = 0;

        int res = INT_MAX;
        int start = 0;

        //calculating frequency.

        for(int i = 0; i < m; i++){
            needed[t[i]]++;
        }

        for(int high = 0; high < n; high++){
            have[s[high]]++;

            while(fun(have,needed)){
                int len = high - low + 1;
                if(res  > len){
                    res = len;
                    start = low;
                }

                have[s[low]]--;
                low++;
            }
        }
        return (res == INT_MAX) ? "":s.substr(start,res);
    }
};

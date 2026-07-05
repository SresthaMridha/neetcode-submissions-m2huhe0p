class Solution {
public:
    bool fun(unordered_map<char,int> &have, unordered_map<char,int> &needed){
        for(auto &x : needed){
            if(have[x.first] < x.second){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char,int> have;
        unordered_map<char, int> needed;

        for(auto x: t){
            needed[x]++;
        }
        int res = INT_MAX;
        int start = 0;
        int left = 0;

        for(int right = 0; right < n; right++){
            have[s[right]]++;
            while(fun(have, needed)){
                int len = right - left + 1;

                if(res > len){
                    res = len;
                    start = left;
                }
                have[s[left]]--;
                left++;
            }
        }

        return (res == INT_MAX) ? "" : s.substr(start, res);
        
    }
};

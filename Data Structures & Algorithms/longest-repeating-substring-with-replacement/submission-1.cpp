class Solution {
public:
    int characterReplacement(string s, int k) {
        //window size - max frequency ≤ k
        int low = 0;
        int n = s.size();
        int res = 0;
        int maxfreq = 0;
        unordered_map<char,int>f;


        for(int high = 0; high < n; high++){
            f[s[high]]++;

            maxfreq = max(maxfreq,f[s[high]]);

            while((high - low + 1) - maxfreq > k){
                f[s[low]]--;
                low++;
            }

            int len = high - low + 1;
            res = max(len, res);
        }
        return res;
    }
};

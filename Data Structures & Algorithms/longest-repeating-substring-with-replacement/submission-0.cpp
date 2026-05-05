class Solution {
public:
    int characterReplacement(string s, int k) {
        //window size - max frequency ≤ k
        int left = 0;
        int n = s.size();
        int maxfreq = 0;
        int maxlen = 0;
        unordered_map<char,int> freq;
        for(int right = 0; right < n; right++){
            freq[s[right]]++;
            maxfreq = max(maxfreq,freq[s[right]]);
            if((right-left+1)-maxfreq > k){
                freq[s[left]]--;
                left++;
            }
            else{
                maxlen = max(maxlen,(right-left+1));
            }
        }
        return maxlen;
        
    }
};

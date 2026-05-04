class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int maxlen = 0;
        int left = 0;
        for(int right = 0;right<s.size();right++){
            while(window.count(s[right])){
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            maxlen = max(maxlen, right -left + 1);
        }
        return maxlen;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> freq;
        for(auto x : strs){
            string s = x;
            sort(s.begin(),s.end());
            freq[s].push_back(x);
        }
        vector<vector<string>> result;
        for(auto x : freq){
            result.push_back(x.second);
        }
        return result;
    }
};

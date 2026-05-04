class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> myset(nums.begin(),nums.end());
        int longest = 0;
        for(auto x: myset){
            if(!myset.count(x-1)){
                int length = 1;
                while(myset.count(x+length)){
                    length++;
                }
                longest = max(longest,length);
            }
        }
        return longest;
    }
};

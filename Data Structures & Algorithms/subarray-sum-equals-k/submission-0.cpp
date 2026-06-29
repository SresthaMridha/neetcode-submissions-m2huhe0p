class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int>f;
        int n = nums.size();
        int res = 0;
        f[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int ques = sum - k;
            int freq = f[ques];

            res += freq;

            f[sum]++;
        }
        return res;
    }
};
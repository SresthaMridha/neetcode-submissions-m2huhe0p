class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //using bucket sorting


        unordered_map<int, int>f;

        for(auto x: nums){
            f[x]++;
        }
        int n = nums.size();
        vector<vector<int>> bucket(n+1);

        for(auto x: f){
            bucket[x.second].push_back(x.first);
        }

        vector<int> ans;

        for(int i = bucket.size()-1; i >=0 ; i--){
            for(auto c: bucket[i]){
                ans.push_back(c);
                if (ans.size() == k){
                    return ans;
                }
            }
        }

        return ans;


    }
};

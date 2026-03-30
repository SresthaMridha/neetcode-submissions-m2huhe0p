class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxnum = -1;
        vector<int> result;
        for(int i=arr.size()-1;i>=0;i--){
            
            result.push_back(maxnum);
            maxnum = max(maxnum,arr[i]);

        }
        reverse(result.begin(), result.end());
        return result;
    }
};
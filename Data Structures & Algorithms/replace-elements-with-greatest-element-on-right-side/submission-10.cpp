class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxnum = -1;
        for(int i=arr.size()-1;i>=0;i--){
            int curr = arr[i];
            arr[i] =maxnum;
            maxnum = max(maxnum,curr);

        }
        return arr;
    }
};
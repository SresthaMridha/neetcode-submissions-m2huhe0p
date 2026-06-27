class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0;
        int right = n-1;
        int maxarea = 0;

        while(left < right){
            int b = right - left;
            int l = min(heights[left] , heights[right]);
            int area = l * b;

            maxarea = max(area,maxarea);

            if(heights[left]  < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxarea;
    }
};

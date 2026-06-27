class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto x : s){
            if(isalnum(x)){
                str+=tolower(x);
            }
        }

        int left = 0;
        int n = str.size();
        int right = n - 1;

        while(left < right){
            if(str[left] != str[right]){
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
};

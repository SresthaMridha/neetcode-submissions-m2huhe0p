class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto ch: s){
            //isalnum to check if valid alphabet or number
            if(isalnum(ch)){
                //tolower so all chars are lower case n no case sensitivity
                str+=tolower(ch);
            }
        }
        int left = 0;
        int right = str.size()-1;
        while(left < right){
            if(str[left]!=str[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

class Solution {
public:
    int scoreOfString(string s) {
        int total = 0;
        int n = s.size();
        if(n<2){
            return 0;
        }
        else{
            int i = 1;
            while(i<s.size()){
                total += abs(s[i]-s[i-1]);
                i++;
            }
        }
        return total;
    }
};
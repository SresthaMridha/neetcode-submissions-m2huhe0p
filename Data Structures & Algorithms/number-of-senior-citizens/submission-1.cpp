class Solution {
public:
    int countSeniors(vector<string>& details) {
        //string sub = v[0].substr(1, 3);  // "ell"
        string sub;
        int count = 0; 
        for(int i = 0 ;i <details.size();i++){
            int age = (details[i][11] - '0') * 10 + (details[i][12] - '0');
            if(age>60){
                count++;
            }
        }
        return count;
        

    }
};
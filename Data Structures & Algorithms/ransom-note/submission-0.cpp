class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ransom;
        unordered_map<char,int> mag;

        for(auto x: ransomNote){
            ransom[x]++;
        }

        for(auto x: magazine){
            mag[x]++;
        }

        for(auto x: ransom){
            if(mag[x.first] < x.second){
                return false;
            }
        }
        return true;
    }
};
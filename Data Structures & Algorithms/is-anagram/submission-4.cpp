class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        unordered_map<char,int> maps;
        unordered_map<char, int> mapt;

        for(auto x: s){
            maps[x]++;
        }
        for(auto x: t){
            mapt[x]++;
        }

        for(auto x: mapt){
            if(maps[x.first] != x.second){
                return false;
            }
        }
        return true;
    }
};

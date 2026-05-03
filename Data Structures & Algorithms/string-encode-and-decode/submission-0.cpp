class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(auto x: strs){
            string s = x;
            int len = s.size();
            result = result + to_string(len) + "#" + s;
        }
        return result;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> result;
        while(i<s.size()){
            int j = i;
            while(s[j]!='#'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            string word = s.substr(j+1,len);
            result.push_back(word);
            i = j + 1 + len;

        }
        return result;
    }
};

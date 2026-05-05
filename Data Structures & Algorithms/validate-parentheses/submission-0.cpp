class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for(auto c : s){
            if(c == '(' || c == '[' || c == '{'){
                mystack.push(c);
            }
            else{
                if(mystack.empty()){
                    return false;
                }
                if(c == ')' && mystack.top() == '(' || c == ']' && mystack.top() == '[' || c == '}' && mystack.top() == '{' ){
                    mystack.pop();
                } else { 
                    return false;
                }
            }
        }
        return mystack.empty();
    }
};

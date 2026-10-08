class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int count = 0;
        for(char ch:s){
            if(ch == '('){
                count++;
                if(count>1)
                    result.push_back('(');
            }
            else{
                count--;
                if(count>0)
                    result.push_back(')');
            }
        }
        return result;
    }
};

class Solution {
public:
    string processStr(string s) {
        int i = 0;
        string result = "";
        while (i < s.length()){
            if ( islower(s[i]) ){
                result = result + s[i];
            }
            else if ( s[i] == '*'){
                if(!result.empty())
                    result.pop_back();
            }
            else if ( s[i] == '#'){
                result = result + result;
            }
            else if ( s[i] == '%'){
                reverse(result.begin(),result.end());
            }
            i = i+1;
        }
        return result;
    }
};
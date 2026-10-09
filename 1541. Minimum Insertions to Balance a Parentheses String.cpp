class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int res = 0;

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if(ch == '(') {
                st.push(ch);
            }
            else {
                if(st.empty()) {
                    if(i < s.length() - 1 && s[i + 1] == ')') {
                        i++;
                    }
                    else {
                        res++;
                    }
                    res++;
                }
                else {
                    if(i < s.length() - 1 && s[i + 1] == ')') {
                        i++;
                    }
                    else {
                        res++;
                    }
                    st.pop();
                }
            }
        }

        return res + st.size() * 2;
    }
};

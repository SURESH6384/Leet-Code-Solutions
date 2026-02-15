class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size(), n2 = b.size();
        int max = ::max(n1, n2);
        int C_in = 0, i = 0;
        string res = "";
        
        while (i < max || C_in > 0) {
            int A = 0, B = 0;
            if (i < n1)
                A = a[n1 - 1 - i] - '0';
            if (i < n2)
                B = b[n2 - 1 - i] - '0';

            int S = (A ^ B) ^ C_in;
            int C_out = ((A ^ B) & C_in) | (A & B);

            res = char(S + '0') + res;
            C_in = C_out;
            i++;
        }

        return res;
    }
};

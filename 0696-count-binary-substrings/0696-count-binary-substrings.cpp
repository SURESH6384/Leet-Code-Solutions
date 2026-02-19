class Solution {
public:
    int countBinarySubstrings(string s) {
        
        // previous continuous occurrence, current continuous occurrence
        int pre_cont_occ=0, cur_cont_occ= 1;
        
        // counter for binary substrings with equal 0s and 1s
        int counter = 0;
        
		// scan each character pair in s
        for( int idx = 1 ; idx < s.length() ; idx++ ){
            
            if( s[idx] == s[idx-1] ){
                
                // update current continuous occurrence
                cur_cont_occ += 1;
            
            }else{
                // update counter of binary substrings between prevous character group and current character group
                counter += min(pre_cont_occ, cur_cont_occ);

                // update previous as current's continuous occurrence
                pre_cont_occ = cur_cont_occ;
                
                // reset current continuous occurrence to 1
                cur_cont_occ = 1;
            }
        }
        // update for last time
        counter += min(pre_cont_occ, cur_cont_occ);
        
        return counter;
    }
};
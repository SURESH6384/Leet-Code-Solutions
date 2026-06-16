class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word = "";
        int len = min(word1.length(),word2.length());
        int i=0;
        while(i<len){
            word = word + word1[i];
            word = word + word2[i];
            i=i+1;
        }
        word = word + word1.substr(len);
        word = word + word2.substr(len);
        return word;
    }
};
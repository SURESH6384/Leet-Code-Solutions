class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<unordered_map<char, int>> freq(words.size());

        // Step 1: Count frequency of each character for all words
        for (int i = 0; i < words.size(); i++) {
            for (char ch : words[i]) {
                freq[i][ch]++;
            }
        }

        // Step 2: Keep first word, skip consecutive anagrams
        vector<string> result;
        result.push_back(words[0]);

        for (int i = 1; i < words.size(); i++) {
            // Compare frequency maps of current and previous word
            if (freq[i] != freq[i - 1]) {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};

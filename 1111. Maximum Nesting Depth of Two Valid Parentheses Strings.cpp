class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string& seq) {
        int n = seq.size();
        int maxDepth = 0;
        int depth = 0;
        for (char c : seq) {
            if (c == ')') {
                depth--;
                continue;
            }
            depth++;
            if (depth > maxDepth) maxDepth = depth;
        }

        std::vector<int> r(n, 0);
        int half = maxDepth >> 1;

        depth = 0;
        for (int i = 0; i < n; i++) {
            char c = seq[i];
            if (c == ')') {
                // Close A first if A has open
                if (depth > 0) {
                    depth--;
                    continue;
                }
                r[i] = 1;
                continue;
            }
            // A is full, rest goes to B
            if (depth >= half) {
                r[i] = 1;
                continue;
            }
            depth++;
        }
        return r;
    }
};

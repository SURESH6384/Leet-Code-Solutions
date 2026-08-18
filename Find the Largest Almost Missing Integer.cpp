class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == n)
            return *max_element(nums.begin(), nums.end());

        int freq[51] = {};

        for (int x : nums)
            freq[x]++;

        // k = 1 → largest globally unique element
        if (k == 1) {
            for (int x = 50; x >= 0; x--)
                if (freq[x] == 1)
                    return x;
            return -1;
        }

        // k > 1 → only first and last positions can be unique
        int a = nums[0];
        int b = nums[n - 1];

        bool aUnique = freq[a] == 1;
        bool bUnique = freq[b] == 1;

        if (aUnique && bUnique)
            return max(a, b);

        if (aUnique)
            return a;

        if (bUnique)
            return b;

        return -1;
    }
};

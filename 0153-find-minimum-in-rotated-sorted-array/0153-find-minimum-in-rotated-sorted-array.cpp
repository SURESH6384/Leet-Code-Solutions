class Solution {
public:
    int findMin(vector<int>& nums) {
        return *lower_bound(
            nums.begin(), nums.end(), true,
            [&](int n, bool val) { return (n <= nums.back()) < val; });
    }
};
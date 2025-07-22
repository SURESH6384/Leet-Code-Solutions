class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>set;
        int leftptr =0,rightptr =0;
        int maxsum =0,currentsum =0;
        int n = nums.size();
        while(right < n)
        {
            if(!set.count(nums[rightptr]))
            {
                currentsum = currentsum + nums[rightptr];
                set.insert(nums[rightptr]);
                maxsum = max (maxsum, currentsum);
                rightptr++;
            }
            else
            {
                currentsum = currentsum - nums[leftptr];
                set.erase(nums[leftptr]);
                leftptr++;
            }
        }
        return maxsum;
    }
};

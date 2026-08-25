class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> mp(nums.begin(),nums.end());
        int i=k;
        while(1){
            if(mp.find(i)==mp.end())
                return i;
            i += k;
        }
    }
};

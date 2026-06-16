class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(candies.begin(),candies.end()), i=0;
        vector<bool> result(candies.size());
        while ( i< candies.size()){
            if((candies[i] + extraCandies) >= max )
                result[i] = true;
            else 
                result[i] = false;
            i+=1;
        } 
        return result;
    }
};
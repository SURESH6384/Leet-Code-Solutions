class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // Step 1: Create the suffix sum array to easily get "Total Remaining Stones"
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        // Step 2: Create a 2D table where dp[i][M] represents the maximum stones 
        // a player can get if they start their turn at index 'i' with a given 'M'.
        // M can grow up to 'n', so we make the columns size n + 1.
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        
        // Step 3: Loop backwards from the end of the array to the start
        for (int i = n - 1; i >= 0; i--) {
            
            // We also need to check all values of M at this index
            for (int m = 1; m <= n; m++) {
                
                // If we can take all remaining piles, just take them!
                if (i + 2 * m >= n) {
                    dp[i][m] = suffixSum[i];
                } 
                else {
                    // Otherwise, simulate taking 1 to 2*m piles
                    for (int x = 1; x <= 2 * m; x++) {
                        
                        // My Score = (Total Remaining) - (Opponent's Best Score from next state)
                        int nextM = max(m, x);
                        int myScore = suffixSum[i] - dp[i + x][nextM];
                        
                        // Keep track of the absolute best move
                        dp[i][m] = max(dp[i][m], myScore);
                    }
                }
            }
        }
        
        // Step 4: The answer is just evaluating the start of the game (index 0, M=1)
        return dp[0][1];
    }
};
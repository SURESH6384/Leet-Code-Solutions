class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> last_k;

        // take last k elements in reverse order
        for (int i = n - 1; i >= n - k; --i) {
            last_k.push_back(energy[i]);
        }

        // build values by jumping backwards
        for (int idx = n - k - 1; idx >= 0; --idx) {
            last_k.push_back(last_k[last_k.size() - k] + energy[idx]);
        }

        // find maximum energy
        return *max_element(last_k.begin(), last_k.end());
    }
};

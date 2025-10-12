#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    long long modpow(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    vector<long long> fact, invFact;

    void precomputeComb(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
        invFact[n] = modpow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    struct Key {
        int rem, odd, idx, carry;
        bool operator==(const Key &other) const {
            return rem == other.rem && odd == other.odd && idx == other.idx && carry == other.carry;
        }
    };

    struct Hash {
        size_t operator()(const Key &k) const {
            return ((size_t)k.rem * 1315423911u) ^ ((size_t)k.odd << 6) ^ ((size_t)k.idx << 12) ^ ((size_t)k.carry << 18);
        }
    };

    unordered_map<Key, long long, Hash> memo;
    vector<int> nums;

    long long dfs(int remaining, int odd_needed, int index, int carry) {
        if (remaining < 0 || odd_needed < 0 || remaining + __builtin_popcount(carry) < odd_needed)
            return 0;
        if (remaining == 0)
            return (__builtin_popcount(carry) == odd_needed) ? 1 : 0;
        if (index >= (int)nums.size()) return 0;

        Key key{remaining, odd_needed, index, carry};
        if (memo.count(key)) return memo[key];

        long long ans = 0;
        for (int take = 0; take <= remaining; ++take) {
            long long ways = nCr(remaining, take) * modpow(nums[index], take) % MOD;
            int new_carry = carry + take;
            ans += ways * dfs(remaining - take, odd_needed - (new_carry % 2), index + 1, new_carry / 2) % MOD;
            ans %= MOD;
        }

        return memo[key] = ans;
    }

    int magicalSum(int total_count, int target_odd, vector<int>& numbers) {
        nums = numbers;
        precomputeComb(total_count);
        memo.clear();
        return dfs(total_count, target_odd, 0, 0);
    }
};

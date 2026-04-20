#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int derangeCount(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;

        vector<int> dp(n + 1);
        dp[1] = 0;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
        }
        return dp[n];
    }
};

// Recursive + Memoization

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,int> memo;
public:
    int derangeCount(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        if (memo.count(n)) return memo[n];
        return memo[n] = (n - 1) * (derangeCount(n - 1) + derangeCount(n - 2));
    }
};
// Direct Formula

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int derangeCount(int n) {
        double res = 0;
        for (int i = 0; i <= n; i++) {
            res += (pow(-1, i) / tgamma(i + 1)); // 1/i!
        }
        return round(tgamma(n + 1) * res); // n! * series
    }
};

#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()

using ll = long long;
using ld = long double;
using namespace std;

const ll inf = 2e18;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 5;

void code() {
    int n, m;
    cin >> n >> m;
    n = 100, m = 100;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &i : a) {
        for (auto &j : i) cin >> j, j = 0;
    }

    auto f = [&](int x) -> bool {
        vector<vector<int>> dp(n, vector<int>(m, -2e9)), go(n, vector<int>(m, 0));
        dp[0][0] = x + a[0][0];
        if (dp[0][0] < 1) return false;

        go[0][0] = 1;
        for (int i = 1; i < n; i++) {
            if (go[i - 1][0]) dp[i][0] = max(dp[i][0], dp[i - 1][0] + a[i][0]);
            if (dp[i][0] > 0) go[i][0] = 1;
        }
        for (int j = 1; j < m; j++) {
            if (go[0][j - 1]) dp[0][j] = max(dp[0][j], dp[0][j - 1] + a[0][j]);
            if (dp[0][j] > 0) go[0][j] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (go[i - 1][j]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
                    if (dp[i][j] > 0) go[i][j] = 1;
                }
                if (go[i][j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j]);
                    if (dp[i][j] > 0) go[i][j] = 1;
                }
            }
        }

        return go[n - 1][m - 1] == 1;

    };

    int lo = -1e9, hi = 1e9;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin>>t;

    while (t-- > 0) {
        code();
    }
}
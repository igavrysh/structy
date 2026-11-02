//
// Created by new on 10/31/26.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1000000007;
signed main() {
    int n,k;
    cin >> n >> k;
    vector<vector<long long>> a(n, vector<long long>(2));
    for (int i=0;i<n;i++) {
        cin >> a[i][0] >> a[i][1];
    }
    vector<vector<int>> dp(n+1, vector<int>(k+1, -2));
    for (int j=0;j<=k;j++) {
        if (j==0) {
            dp[n][j] = 1;
        } else {
            dp[n][j] = -1;
        }
    }
    vector<int> prefix(k+1, 1);
    for (int i=n-1;i>=0;i--) {
        for (int ks=0;ks<(k+1);ks++) {
            int res = -1;
            int start = ks-a[i][1];
            int end = ks-a[i][0];
            if (end>=0) {
                res = (prefix[end] - ((start-1)>=0?prefix[start-1]:0) + MOD)%MOD;
            }
            dp[i][ks] = res;
        }
        for (int j=0;j<k+1;j++) {
            int res = ((dp[i][j]!=-1 && dp[i][j]!=-2)?dp[i][j]:0) + (j-1>=0?prefix[j-1]:0);
            prefix[j] = res%MOD;
        }
    }
    cout << (dp[0][k]%MOD);
}
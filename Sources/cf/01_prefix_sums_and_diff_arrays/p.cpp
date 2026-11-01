//
// Created by new on 10/31/26.
//

#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
signed main() {
    int n,k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(2));
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
    // cout << "prefix[" << 0 << "]: ";
    // for (int j=0;j<k+1;j++) {
    //     cout << prefix[j] << " ";
    // }
    // cout << endl;
    for (int i=n-1;i>=0;i--) {
        for (int ks=0;ks<(k+1);ks++) {
            long long res = -1;

            int start = ks-a[i][1];
            int end = ks-a[i][0];
            res = (prefix[end] - (start-1>=0?prefix[start-1]:0) + MOD)%MOD;

            // for (int c=a[i][0];c<=a[i][1];c++) {
            //     if (c>ks) {
            //         continue;
            //     }
            //     int t = dp[i+1][ks-c];
            //     if (t!=-1 && t!=-2) {
            //         if (res==-1) {
            //             res = t;
            //         } else {
            //             res = (res + t)%MOD;
            //         }
            //     }
            // }
            dp[i][ks] = res;
        }
        for (int j=0;j<k+1;j++) {
            long long res = ((dp[i][j]!=-1&&dp[i][j]!=-2)?dp[i][j]:0) + (j-1>=0?prefix[j-1]:0);
            prefix[j] = res%MOD;
        }
        // cout << "prefix[" << i << "]: ";
        // for (int j=0;j<k+1;j++) {
        //     cout << prefix[j] << " ";
        // }
        // cout << endl;
    }
    // for (int i=0;i<n+1;i++) {
    //     cout << "dp[" << i << "]: ";
    //     for (int j=0;j<k+1;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << (dp[0][k]%MOD);
}

long long combs(int ptr, int k, vector<vector<int>> a, vector<vector<int>> dp) {
    if (dp[ptr][k] != -2) {
        return dp[ptr][k];
    }
    if (ptr>=a.size() || k<=0) {
        if (ptr==a.size() && k==0) {
            dp[ptr][k] = 1;
            return 1;
        }
        dp[ptr][k] = -1;
        return -1;
    }
    long long acc = 0;
    //cout << "a[i]: " << a[ptr][0] << " " << a[ptr][1] << endl;
    for (int i=a[ptr][0];i<=a[ptr][1];i++) {
        long long res = combs(ptr+1, k-i, a, dp);
        if (res!=-1) {
            acc = (acc + res)%MOD;
        }
    }
    dp[ptr][k] = acc;
    return acc;
}
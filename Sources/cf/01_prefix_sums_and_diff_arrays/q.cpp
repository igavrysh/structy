//
// Created by new on 11/1/26.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MOD = 1000000007;
signed main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    vector<long long> delta(n);
    vector<long long> rate(n);
    vector<long long> rate_level(n);
    int l,r,x,d;
    for (int i=0;i<m;i++) {
        cin >> l >> r >> x >> d;
        delta[l-1]+=x;
        rate[l-1]+=d;
        if (r<n) {
            delta[r]-=x;
            rate[r]-=d;
            rate_level[r]-=(r-l+1)*d;
        }
    }
    long long curr_delta=0;
    long long curr_rate=0;
    long long curr_rate_level = 0;
    for (int i=0;i<n;i++) {
        curr_delta+=delta[i];
        curr_rate_level = curr_rate_level + curr_rate + rate_level[i];
        if (i!=0) {
            cout << " ";
        }
        cout << a[i] + curr_delta + curr_rate_level;
        curr_rate += rate[i];
    }
}
//
// Created by new on 10/30/26.
//

#include <iostream>
#include <vector>
using namespace std;
signed main() {
    int mod = 1000000007;
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    char ch;
    for (int i=0;i<n;i++) {
        cin >> ch;
        if (ch == '#') {
            a[i] = -1;
        }
    }
    a[0] = 1;
    int acc_sum = 0;
    for (int i=1;i<n;i++) {
        acc_sum = (acc_sum + (a[i-1]!=-1 ? a[i-1] : 0))%mod;
        if (i-1-k>=0) {
            acc_sum = (acc_sum - (a[i-1-k]!=-1 ? a[i-1-k] : 0) + mod)%mod;
        }
        if (a[i] != -1) {
            a[i] = acc_sum;
        }
    }
    cout << acc_sum;
}
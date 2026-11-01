//
// Created by new on 10/29/26.
//

#include <vector>
#include <iostream>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    vector<long long> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    vector<long long> diff(n);
    for (int i=0;i<m;i++) {
        int l, r, x;
        cin >> l >> r >> x;
        diff[l-1] += x;
        if (r < diff.size()) {
            diff[r] -= x;
        }
    }
    long long acc_diff = 0;
    for (int i=0;i<n;i++) {
        acc_diff += diff[i];
        a[i] = (i-1>=0 ? a[i-1] : 0) + a[i] + acc_diff;
    }
    for (int i=0;i<q;i++) {
        int l, r;
        cin >> l >> r;
        if (i!=0) {
            cout << endl;
        }
        cout << a[r-1] - (l-2>=0 ? a[l-2] : 0);
    }
}
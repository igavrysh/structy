//
// Created by new on 10/29/26.
//

#include <vector>
#include <iostream>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<long long> diff(n);
    int num;
    int prev = 0;
    for (int i=0; i<n; i++) {
        cin >> num;
        diff[i] = num - prev;
        prev = num;
    }
    int l, r, x;
    for (int i=0; i<m; i++) {
        cin >> l >> r >> x;
        diff[l-1] += x;
        if (r<diff.size()) {
            diff[r] -= x;
        }
    }

    long long curr = 0;
    for (int i=0; i<diff.size(); i++) {
        curr += diff[i];
        if (i!=0) {
            cout << " ";
        }
        cout << curr;
    }
}
//
// Created by new on 10/30/26.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// H kills Scissors, S kill Paper, Paper kills Hoof
signed main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    vector<long long> delta(n);
    int l,r,x;
    for (int i=0;i<m;i++) {
        cin >> l >> r >> x;
        if (l<=r) {
            delta[l-1] += x;
            if (r<n) {
                delta[r] -= x;
            }
        } else {
            delta[l-1] += x;
            delta[0] += x;
            delta[r] -= x;
        }
    }
    long long curr_acc = 0;
    for (int i=0;i<n;i++) {
        curr_acc += delta[i];
        if (i!=0) {
            cout << " ";
        }
        cout << a[i] + curr_acc;
    }
}
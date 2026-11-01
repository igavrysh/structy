//
// Created by new on 10/29/26.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    long long minn = 0;
    long long res = 0;
    long long acc = 0;
    for (int i=0;i<n;i++) {
        acc += a[i];
        if (i==0) {
            res = acc;
        }
        res = std::max(res, std::max(acc - minn, acc));

        if (i==0) {
            minn = acc;
        }
        minn = std::min(minn, acc);
    }

    cout << res;
}
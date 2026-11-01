//
// Created by new on 10/30/26.
//

#include <iostream>
#include <vector>
using namespace std;
signed main() {
    int n, q;
    cin >> n >> q;
    vector<long long> prefix_weighted(n);
    vector<long long> prefix_sum(n);
    int num;
    long long acc = 0, acc_weighted = 0;
    for (int i=0;i<n;i++) {
        cin >> num;
        acc += num;
        prefix_sum[i] = acc;
        acc_weighted += (i+1)*num;
        prefix_weighted[i] = acc_weighted;
    }
    int l, r;
    for (int i=0;i<q;i++) {
        cin >> l >> r;
        const long long res = (prefix_weighted[r-1] - (l-2 >= 0 ? prefix_weighted[l-2] : 0))
            - (l-1) * (prefix_sum[r-1]- (l-2>=0 ? prefix_sum[l-2] : 0));
        cout << res << endl;
    }
}
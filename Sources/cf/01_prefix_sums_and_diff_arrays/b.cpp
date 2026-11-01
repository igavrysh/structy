#include <vector>
#include <iostream>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<long long> prefix(n);
    int num;
    long long acc = 0;
    for (int i=0; i<n; i++) {
        cin >> num;
        acc += num;
        prefix[i] = acc;
    }
    int l, r;
    for (int i=0; i<q; i++) {
        cin >> l >> r;
        cout << prefix[r-1] - (l-2>=0 ? prefix[l-2] : 0) << endl;
    }
}
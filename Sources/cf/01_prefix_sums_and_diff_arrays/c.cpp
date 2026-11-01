#include <vector>
#include <iostream>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<int> prefix(n);
    int num;
    int acc = 0;
    // prefix, (p1 xor p2) xor p1 = /xor is also commutative/ = p2 xor (p1 xor p1) = /* x xor x = 0 */ = p2
    // so the same solution up to change from long long to int as xor does not overflow the max num
    for (int i=0; i<n; i++) {
        cin >> num;
        acc ^= num;
        prefix[i] = acc;
    }
    int l, r;
    for (int i=0; i<q; i++) {
        cin >> l >> r;
        cout << (prefix[r-1] ^ (l-2>=0 ? prefix[l-2] : 0)) << endl;
    }
}
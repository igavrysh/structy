#include <iostream>
#include <iosfwd>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long acc = 0;
    // 10**9 * 2 * 10**5 = 2* 10**14
    // long long ~ 10 2**63 = 10**x, x=63*log2(10) = 63*0.3=18 > 2*10**14
    // long long should be enough to hold acc
    for (int i = 0; i<n; i++) {
        long long num;
        cin >> num;
        acc += num;
        if (i == 0) {
            cout << acc;
        } else {
            cout << " " << acc;
        }
    }
}

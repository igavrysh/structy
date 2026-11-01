//
// Created by new on 10/29/26.
//

#include <iostream>
#include <unordered_map>
using namespace std;
// two sum derivative....
signed main() {
    int n, s;
    cin >> n >> s;
    unordered_map<long long, int> m{};
    int a;
    int acc = 0;
    long long t = 0;
    long long res = 0;
    m[0] = 1;
    for (int i=0;i<n;i++) {
        cin >> a;
        acc += a;
        long long target = acc - s;
        if (m.find(target)!=m.end()) {
            res += m[target];
        }

        if (m.find(acc)==m.end()) {
            m[acc] = 0;
        }
        m[acc]+=1;
    }
    cout << res;
}
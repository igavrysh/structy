//
// Created by new on 10/30/26.
//

#include <iostream>
#include <vector>
using namespace std;
signed main() {
    int h,w,m;
    cin >> h >> w >> m;
    vector<vector<long long>> a(h, vector<long long>(w));
    for (int i=0;i<h;i++) {
        for (int j=0;j<w;j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<long long>> diff(h, vector<long long>(w));
    int r1,c1,r2,c2,x;
    for (int q=0;q<m;q++) {
        cin >> r1 >> c1 >> r2 >> c2 >> x;
        diff[r1-1][c1-1] += x;
        if (c2<w) {
            diff[r1-1][c2] -= x;
        }
        if (r2<h) {
            diff[r2][c1-1] -= x;
            if (c2<w){
                diff[r2][c2] += x;
            }
        }
    }
    vector<long long> pattern(w);
    for (int i=0;i<h;i++) {
        long long acc = 0;
        for (int j=0;j<w;j++) {
            pattern[j] += diff[i][j];
            acc += pattern[j];
            if (j!=0) {
                cout << " ";
            }
            cout << (a[i][j] + acc);
        }
        cout << endl;
    }
}
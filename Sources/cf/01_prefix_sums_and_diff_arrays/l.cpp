//
// Created by new on 10/30/26.
//

#include <iostream>
#include <vector>
using namespace std;
signed main() {
    int h,w,q;
    cin >> h >> w >> q;
    vector<vector<long long>> prefix(h, vector<long long>(w));
    for (int i=0;i<h;i++) {
        for (int j=0;j<w;j++) {
            int num;
            cin >> num;
            prefix[i][j] = num + (i-1>=0 ? prefix[i-1][j] : 0)
                + (j-1>=0 ? prefix[i][j-1] : 0)
                - (i-1>=0 && j-1>=0 ? prefix[i-1][j-1] : 0);
        }
    }
    int r1,c1,r2,c2;
    long long res;
    for (int i=0;i<q;i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        res = prefix[r2-1][c2-1]
                - (r1-2>=0 ? prefix[r1-2][c2-1] : 0)
                - (c1-2>=0 ? prefix[r2-1][c1-2] : 0)
                + (r1-2>=0 && c1-2>=0 ? prefix[r1-2][c1-2] : 0);
        cout << res << endl;
    }
}
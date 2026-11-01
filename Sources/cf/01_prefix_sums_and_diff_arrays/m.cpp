//
// Created by new on 10/30/26.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
signed main() {
    int h,w,d;
    cin >> h >> w >> d;
    unordered_map<int, vector<int>> mp;
    int num;
    for (int i=0;i<h;i++) {
        for (int j=0;j<w;j++) {
            cin >> num;
            mp[num] = {i,j};
        }
    }
    int slots = (h*w / d + 1);
    vector<vector<int>> pcost(d, vector<int>(slots));
    for (int d_rm=0;d_rm<d;d_rm++) {
        int prev_r = 0, prev_c = 0;
        for (int idx=0;idx<(h*w/d + 1);idx++) {
            int i = d_rm + idx*d;
            if (i>=h*w) {
                continue;
            }
            vector<int> curr_coord = mp[i+1];
            if (idx!=0) {
                int off_r = curr_coord[0]-prev_r;
                int off_c = curr_coord[1]-prev_c;
                int cost = abs(off_r) + abs(off_c);
                pcost[d_rm][idx] = cost + pcost[d_rm][idx-1];
            } else {
                pcost[d_rm][idx] = 0;
            }
            prev_r = curr_coord[0];
            prev_c = curr_coord[1];
        }
    }
    int q,l,r;
    cin >> q;
    for (int i=0;i<q;i++) {
        cin >> l >> r;
        int d_idx = (l-1)%d;
        int end = ((r-1)-d_idx)/d;
        int start = ((l-1)-d_idx)/d;
        cout << pcost[d_idx][end]-pcost[d_idx][start] << endl;
    }
}
//
// Created by new on 10/29/26.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// H kills Scissors, S kill Paper, Paper kills Hoof
signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int suffix[3] = {0};
    for (int i=0; i<n; i++) {
        char ch;
        int val = 0;
        cin >> ch;
        if (ch=='H') {
            val = 0;
        }
        if (ch=='S') {
            val = 1;
        }
        if (ch=='P') {
            val = 2;
        }
        suffix[val] += 1;
        a[i] = val;
    }
    int prefix[3] = {0};
    int max_wins = 0;
    int wins1, wins2;
    for (int i=0; i<=n; i++) {
        wins1 = *std::max_element(std::begin(suffix), std::end(suffix));
        wins2 = *std::max_element(std::begin(prefix), std::end(prefix));
        max_wins = max(max_wins, wins1 + wins2);
        // cout << "max_wins: " << max_wins << " suffix: " <<  suffix[0] <<", "<<suffix[1] << ", " << suffix[2] << endl;
        if (i<n) {
            prefix[a[i]] += 1;
            suffix[a[i]] -= 1;
        }
    }
    cout << max_wins;
}
//
// Created by new on 11/1/26.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

long long count_blacks(long long row, long long col, vector<vector<long long>>& prefix) {
    if (row < 0 || col < 0) {
        return 0;
    }
    long long res = 0;
    long long n = prefix.size();
    long long times_rows = (row+1)/n;
    long long times_cols = (col+1)/n;
    res += (times_rows * times_cols)*prefix[n-1][n-1];
    long long extra_cols = (col+1)%n;
    res += (extra_cols-1>=0 ? prefix[n-1][extra_cols-1] : 0) * times_rows;
    long long extra_rows = (row+1)%n;
    res += (extra_rows-1>=0 ? prefix[extra_rows-1][n-1] : 0) * times_cols;
    res += (extra_rows-1>=0 && extra_cols-1>=0 ? prefix[extra_rows-1][extra_cols-1] : 0);
    return res;
}

signed main() {
    int n, q;
    cin >> n >> q;
    vector<vector<long long>> prefix(n, vector<long long>(n));
    std::string str;
    for (int i=0;i<n;i++) {
        cin >> str;
        for (int j=0;j<str.size();j++) {
            if (str[j] == 'B') {
                prefix[i][j] += 1;
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            prefix[i][j] = prefix[i][j]
                + (i-1>=0?prefix[i-1][j]:0)
                + (j-1>=0?prefix[i][j-1]:0)
                - ((i-1>=0&&j-1>=0) ? prefix[i-1][j-1] : 0);
        }
    }
    int a,b,c,d;
    for (int i=0;i<q;i++) {
        cin >> a >> b >> c >> d;
        long long res = count_blacks(c, d, prefix)
            - count_blacks(a-1, d, prefix)
            - count_blacks(c, b-1, prefix)
            + count_blacks(a-1, b-1, prefix);
        cout << res << "\n";
    }
}
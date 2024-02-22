#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, int k, vector<vector<int>>& a) {
    int r = 0, c = 0;
    while (r < n && c < m ) {
        for (int i = c; i < m; ++i) {
            --k;
            if (k == 0) return a[r][i];
        }
        ++r;

        for (int i = r; i < n; ++i) {
            --k;
            if (k == 0) return a[i][m - 1];
        }
        --m;

        if (r < n) {
            for (int i = m - 1; i >= c; --i) {
                --k;
                if (k == 0) return a[n - 1][i];
            }
            --n;
        }

        if (c < m) {
            for (int i = n - 1; i >= r; --i) {
                --k;
                if (k == 0) return a[i][c];
            }
            ++c;
        }
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        cout << solve(n, m, k, a) << endl;
    }
}

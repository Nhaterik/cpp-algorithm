#include <bits/stdc++.h>
using namespace std;
int a[100][100];
void solve(int n, int m)
{
    int h1 = 0, h2 = n, c1 = 0, c2 = m;
    int cur = 0;
    while (h1 < h2 && c1 < c2)
    {
        if (h1 + 1 == h2 || c1 + 1 == c2)
            break;
        // this is the secret
        int pre = a[h1 + 1][c1];
        for (int i = c1; i < c2; i++)
        {
            cur = a[h1][i];
            a[h1][i] = pre;

            pre = cur;
        }
        h1++;
        for (int i = h1; i < h2; i++)
        {
            cur = a[i][c2 - 1];

            a[i][c2 - 1] = pre;
            pre = cur;
        }
        c2--;
        if (h1 < h2)
        {
            for (int i = c2 - 1; i >= c1; i--)
            {
                cur = a[h2 - 1][i];

                a[h2 - 1][i] = pre;
                pre = cur;
            }
            h2--;
        }
        if (c1 < c2)
        {

            for (int i = h2 - 1; i >= h1; i--)
            {
                cur = a[i][c1];

                a[i][c1] = pre;
                pre = cur;
            }
            c1++;
        }
    }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                cin >> a[i][j];
            }
        }
        solve(n, m);
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }
}
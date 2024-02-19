#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
int isPrime[MAX];
void sieve()
{
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i <= MAX; i++)
        isPrime[i] = 1;
    for (int i = 2; i * i <= MAX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = 0;
        }
    }
}
void solve(int n)
{
    int ok = 1;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] && isPrime[n - i])
        {

            cout << i << " " << n - i << endl;
            ok = 0;
            break;
        }
    }
    if (ok)
        cout << -1 << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}
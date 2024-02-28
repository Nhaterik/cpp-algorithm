#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long gcd(ll a, ll b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
long long reduce(ll a, string b)
{
    long long mod = 0;
    for (int i = 0; i < b.size(); i++)
    {
        mod = (mod * 10 + b[i] - '0') % a;
    }
    return mod;
}
long long solve(ll a, string b)
{
    ll rb = reduce(a, b);
    return gcd(a, rb);
}
int main()
{

    int test;
    cin >> test;
    while (test--)
    {
        long long a;
        string b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }

    return 0;
}
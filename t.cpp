#include <bits/stdc++.h>
using namespace std;
vector<int> v;

void solve(vector<int>& v, int n)
{
   int r[n], c[n];
   memset(r, 0, sizeof(r));
   memset(c, 0, sizeof(c));

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         r[i] += v[i*n+j];
         c[j] += v[i*n+j];
      }
   }
   int mx = 0, cn = 0;
   for (int i = 0; i < n; i++)
   {
      mx = max(r[i], mx);
      mx = max(c[i], mx);
   }
   int mn = 0;
   for (int i = 0, j = 0; i < n && j < n;)
   {
      mn = min(mx - r[i], mx - c[j]);

      r[i] += mn;

      c[j] += mn;
      if (r[i] == mx)
         i++;
      if (c[j] == mx)
         j++;
      cn += mn;
   }
   cout << cn << endl;
}
int main()
{
   system("cls");
   int T;
   cin >> T;
   while (T--)
   {
      int N;
      cin >> N;
      v.resize(N*N);
      for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
            cin >> v[i*N+j];
      }
      solve(v, N);
   }
   return 0;
}

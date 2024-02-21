#include <iostream>
   #include <iomanip>
   #include <cmath>
   typedef    unsigned long long ull;
   int gcd(int a, int b)
   {
      if (b == 0)
         return a;
      return gcd(b, a % b);
   }

   using namespace std;
   int main()
   {
      int test;
      cin >> test;
      while (test--)
      {
         int a, b, c, n;
         cin >> a >> b >> c >> n;
      ull LCM = a * b / gcd(a, b);
		LCM = LCM * c / gcd(LCM, c);
      ull l = (ull)pow(10, n - 1);
      ull p = (ull)pow(10, n);
         if (LCM >= p)
            cout << -1 << endl;
         else
         {
            ull tmp = l % LCM;
            if (tmp == 0)
               cout << l << endl;
            else
               cout << l + LCM - tmp << endl;
         }
      }
      return 0;
   }

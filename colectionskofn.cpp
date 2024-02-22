#include <bits/stdc++.h>

using namespace std;
const int Mod = (int)1e9 + 7;
#define ll long long
int c[1000][1000];
void init()
{
	for (int i = 0; i <= 13; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout<<"i="<<i<<" j="<<j<<endl;
			if (j == 0 || j == i)
				c[i][j] = 1;
			else
			{
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
				c[i][j] %= Mod;
			} 
		}
	}
}

int main()
{
	init();
	cout << c[9][5] << "=result" << endl;
	return 0;
}

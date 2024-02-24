#include <bits/stdc++.h>
using namespace std;
string sum(string s1, string s2)
{

    string res = "";
    if (s1.length() < s2.length())
        swap(s1, s2);
    int l1 = s1.length();
    int l2 = s2.length();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    s2 += string(l1 - l2, 0);
    int remainder = 0;
    for (int i = 0; i < l1; i++)
    {
        int s = s1[i] - '0' + s2[i] - '0' + remainder;
        res += s % 10 + '0';
        remainder = s / 10;
    }
    if (remainder)
        res += remainder + '0';
    reverse(res.begin(), res.end());
    return res;
}
int check(int left, int l1, int l2, string s)
{
    string s1 = s.substr(left, l1);
    string s2 = s.substr(l1 + left, l2);
    cout << s1 << " " << s2 << endl;
    // 1122335588143
    // 123415538
    string s3 = sum(s1, s2);
    if (s3.length() > (s.length() - left - l1 - l2))
        return 0;
    if (s3 == s.substr(left + l1 + l2, s3.length()))
    {
        if (s.length() == left + l1 + l2 + s3.length())
            return 1;
        return check(left + l1, l2, s3.length(), s);
    }
    return 0;
}
int main()
{
    system("cls");
    int test;
    cin >> test;
    cin.ignore();
    while (test--)
    {
        string s;
        int ok = 0;
        getline(cin, s);
        for (int i = 1; i < s.length(); i++)
        {
            for (int j = 1; j < s.length() - i; j++)
                if (check(0, i, j, s))
                    ok = 1;
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
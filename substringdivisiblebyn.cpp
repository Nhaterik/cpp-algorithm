/*Given a string S consisting only of digits. Your task is to count the substrings of S that are divisible by the string U (using the modulo operation). For example, U = "1234", N = 4 we get the result is 4 with 4 substrings of divisible by: 4, 12, 24, 124. The substring can contain non-adjacent characters.

Input:
    - The first line gives the number of test cases T.
    - The following lines give T test cases. Each test case consists of two parts: the first part is two numbers M,N; where M is the string S; the next part is the string S consisting of M numbers.
    - T,M,N,S satisfy the constraints: 1≤T≤100;1≤M,N≤100;1≤Length(S)≤50.

Output:
    - Give the result of each test on each line.

Input:
2
44
1234
3
6
676*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countDivisibleSubseq(string S, int N)
{
    int len = S.length();

    // division by N can leave only N remainder [0, N-1].
    // dp[i][j] indicates number of sub-sequences in string
    // till i'th index that leaves remainder j after division by N.
    vector<vector<int>> dp(len, vector<int>(N, 0));

    // Remainder of first digit of string when divided
    // by N.
    dp[0][((int)S[0] - '0') % N]++;

    for (int i = 1; i < len; i++)
    {
        // start a new sub-sequence with index i
        dp[i][((int)S[i] - '0') % N]++;

        for (int j = 0; j < N; j++)
        {
            // exclude i'th character from all the current
            // sub-sequences of string till index i-1
            cout << "j= " << j << "  i= " << i << endl;
            dp[i][j] += dp[i - 1][j];
            cout << "j*10 + (S[i]-'0'))%N= " << (j * 10 + (S[i] - '0')) % N << " j= " << j << " i= " << i << endl;
            // include i'th character in all the current
            // sub-sequences of string till index i-1
            dp[i][(j * 10 + (S[i] - '0')) % N] += dp[i - 1][j];
        }
    }

    return dp[len - 1][0];
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int M, N;
        string S;
        cin >> M >> N >> S;
        cout << countDivisibleSubseq(S, N) << endl;
    }
    return 0;
}

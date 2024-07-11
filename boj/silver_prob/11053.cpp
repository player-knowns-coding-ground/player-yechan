/**
 * 가장 긴 증가하는 부분 수열 문제
 * 문제 설명 : 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
 */

#include <bits/stdc++.h>
#define uint64 uint64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dp[1001][2] = {
        {0, 0},
    };
    int N;
    cin >> N;

    int it = 0;
    while (it++ < N)
    {
        int in;
        cin >> in;

        for (int i = 0; i < it; i++)
        {
            if (dp[i][0] < in)
            {
                dp[it][1] = max(dp[it][1], dp[i][1]);
            }
        }
        dp[it][0] = in;
        dp[it][1] += 1;
    }

    int res = 0;
    for (auto &cand : dp)
    {
        res = max(cand[1], res);
    }
    cout << res << "\n";

    return 0;
}
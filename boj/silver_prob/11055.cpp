/*
  문제 설명 : 수열 A가 주어졌을 때, 그 수열의 증가하는 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.
  예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가하는 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고,
  합은 113이다.
 */

/*
풀이 :
부분 수열이 증가하는 부분을 찾아야하기 때문에 , i번째 원소 보다 i+k번째 원소의 크기가 커야 한다.(k는 1이상의 정수)
- 테이블 정의 : dp[i] = { num, sub_sum }는 i번째 원소까지 증가하는 부분 수열의 합
- 점화식 정의 : dp[i][1] = max(dp[k][1]) + cur_num, dp[i][0] = num (among dp[k][1] less than cur_num)
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
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

        if (it == 1)
        {
            dp[it][0] = in; // 수열 끝 숫자
            dp[it][1] = in; // 누적합합
        }
        else
        {
            for (int i = 0; i < it; i++)
            {
                if (dp[i][0] < in)
                {
                    dp[it][1] = max(dp[it][1], dp[i][1]);
                }
            }
            dp[it][0] = in;
            dp[it][1] += in;
        }
    }

    int res = 0;
    for (auto &cand : dp)
    {
        res = max(cand[1], res);
    }
    cout << res << "\n";

    return 0;
}
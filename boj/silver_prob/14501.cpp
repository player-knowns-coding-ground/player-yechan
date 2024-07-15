/**
문제 유형 : dp
문제 설명 :

상담원으로 일하고 있는 백준이는 퇴사를 하려고 한다.
오늘부터 N+1일째 되는 날 퇴사를 하기 위해서, 남은 N일 동안 최대한 많은 상담을 하려고 한다.
백준이는 비서에게 최대한 많은 상담을 잡으라고 부탁을 했고, 비서는 하루에 하나씩 서로 다른 사람의 상담을 잡아놓았다.
각각의 상담은 상담을 완료하는데 걸리는 기간 Ti와 상담을 했을 때 받을 수 있는 금액 Pi로 이루어져 있다.

상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오.

풀이 :
- 테이블 정의 : dp[i][0]은 상담 기간, dp[i][1]는 i번째 날 최대 수익
- 점화식 : dp[i] = max(dp[i-k]) , k는 1부터 i-1까지, k + dp[i][0] <= i이어야 함. 만약 i + 상담기간이 N+1을 초과한다면 skip
 */

#include <bits/stdc++.h>
#define uint64 uint64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int dp[16][2] = {{
        0,
    }};

    int it = 0;
    while (it++ < N)
    {
        int T, P;
        cin >> T >> P;

        if (it + T > N + 1)
            continue;

        if (it == 1)
        {
            dp[it][0] = T;
            dp[it][1] = P;
        }
        else
        {
            for (int i = 1; i < it; i++)
            {
                if (i + dp[i][0] <= it)
                {
                    dp[it][1] = max(dp[it][1], dp[i][1]);
                }
            }
            dp[it][0] = T;
            dp[it][1] += P;
        }
    }

    int res = 0;
    for (auto &n : dp)
    {
        res = max(n[1], res);
    }

    cout << res << "\n";

    return 0;
}
/**
 * 일직선 식량 창고
 * 개미 전사는 식량 창고를 선택적으로 약탈
 * 메뚜기 정찰병은 인접한 식량창고가 공격받으면 바로 알아챌 수 있다.
 * -> 따라서 최소 한 칸 이상 떨어진 창고를 약탈해야함.
 */

// 테이블 : 현재 위치까지의 이전 약탈 식량의 최대 누적 수치
// 점화식 : i가 현재 위치 일 때, dp[i] = dp[i-2] + cost[i]

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    int N;
    cin >> N;

    vector<int> costs;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        costs.push_back(tmp);
    }

    // 풀이
    int dp[101] = {
        0,
    };
    dp[0] = costs[0];
    dp[1] = costs[1];
    dp[2] = costs[2] + dp[0];
    int res = 0;

    for (int i = 2; i < N; i++)
    {
        dp[i] = max(dp[i - 2] + costs[i], dp[i - 3] + costs[i]);
        res = max(res, dp[i]);
    }

    cout << res << "\n";

    return 0;
}
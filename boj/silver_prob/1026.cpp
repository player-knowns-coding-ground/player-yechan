/**
 * 유형 : 그리디
 * 풀이 :
 * B를 재배열 할 수 없어도, 어차피 A의 최솟값과 B의 최대값을 곱하는 것은 변함없는 사실이다.
 * 또한 대수적 덧셈의 교환법칙에 따라 연산 순서를 바꿀 수 있으므로, 두 배열을 정렬하여 문제 풀이를 진행한다.
 * 최적해 : (오름차순으로 정렬된 A의 각 원소 x 내림차순으로 정렬된 B의 각 원소)의 누적합
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

    vector<int> A;
    vector<int> B;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        B.push_back(tmp);
    }

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());
    int S = 0;
    for (int i = 0; i < N; i++)
    {
        S += A[i] * B[i];
    }
    cout << S << "\n";

    return 0;
}
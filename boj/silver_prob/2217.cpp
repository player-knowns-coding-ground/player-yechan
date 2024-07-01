/**
 * 유형 : 그리디
 * k개의 로프로 병렬로 들어올리면, 중량 w가 각 로프에 w/k로 분산되어 걸림.
 * 주어진 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량은?
 *
 * 알고리즘 :
 * - 주어진 로프 리스트를 오름차순으로 정렬한다.
 * - 현재 주어진 로프의 가용 중량이 최대 중량을 만든다고 가정.
 * - pivot 로프 결정 로직 : max(이전 결과, 신규 로프 가용 중량)
 */

#include <bits/stdc++.h>
#define uint64 uint64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64 N;
    cin >> N;
    vector<uint64> ropes;
    while (N-- > 0)
    {
        uint64 avail;
        cin >> avail;
        ropes.push_back(avail);
    }

    sort(ropes.begin(), ropes.end());

    uint64 res = 0;
    int len = ropes.size();

    for (int i = 0; i < ropes.size(); i++)
    {
        res = max(res, ropes[i] * (len - i));
    }

    cout << res << "\n";
    return 0;
}
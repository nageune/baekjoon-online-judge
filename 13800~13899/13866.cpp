// 13866: 팀 나누기
//
// - 문제
// 4명의 친구가 탁구를 하고 있다. 각각은 정수형으로 표현된 스킬 레벨을 가지고 있고, 숫자가 높을수록 더 좋은 플레이어다.
// 4명의 친구는 각각 두 명씩 구성된 두 팀을 구성하려고 한다. 게임이 더 흥미롭게 하기 위해서 팀의 스킬 레벨을 최대한 가깝게 유지하기를 원한다. 팀의 스킬 레벨은 팀원의 스킬 레벨의 합계이다.
// 그들은 탁구 선수로는 탁월하지만, 수학이나 컴퓨터와 같은 다른 것들에 능숙하지 않다. 팀의 스킬 레벨이 가능한 작은 차이를 갖도록 도와주자.
//
// - 입력
// 입력은 네 개의 정수 A, B, C 및 D가 포함된 한 줄로 구성되며 4명의 스킬 레벨이 주어진다. (0 ≤ A ≤ B ≤ C ≤ D ≤ 10^4)
//
// - 출력
// 두 팀의 스킬 레벨 차이의 최솟값을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  vector<int> v(4);
  for (int i = 0; i < 4; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  int ans = v[0] + v[3] - v[1] - v[2];
  cout << abs(ans);
  return 0;
}
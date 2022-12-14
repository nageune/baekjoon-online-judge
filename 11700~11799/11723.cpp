// 11723: 집합
//
// - 문제
// 비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.
// add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
// remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
// check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
// toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
// all: S를 {1, 2, ..., 20} 으로 바꾼다.
// empty: S를 공집합으로 바꾼다.
//
// - 입력
// 첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.
// 둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.
//
// - 출력
// check 연산이 주어질때마다, 결과를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int m;
  cin >> m;
  vector<int> v(21, 0);
  while (m--) {
    string s;
    cin >> s;
    if (s == "add") {
      int x;
      cin >> x;
      if (!v[x])
        v[x] = 1;
    } else if (s == "remove") {
      int x;
      cin >> x;
      if (v[x])
        v[x] = 0;
    } else if (s == "check") {
      int x;
      cin >> x;
      if (v[x])
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    } else if (s == "toggle") {
      int x;
      cin >> x;
      if (v[x])
        v[x] = 0;
      else
        v[x] = 1;
    } else if (s == "all") {
      for (int i = 1; i <= 20; i++)
        v[i] = 1;
    } else if (s == "empty") {
      for (int i = 1; i <= 20; i++)
        v[i] = 0;
    }
  }
  return 0;
}
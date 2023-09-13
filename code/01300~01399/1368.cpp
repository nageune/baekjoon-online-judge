// 1368: 물대기
//
// - 문제
// 선주는 자신이 운영하는 N개의 논에 물을 대려고 한다. 물을 대는 방법은 두 가지가 있는데 하나는 직접 논에 우물을 파는 것이고 다른 하나는 이미 물을 대고 있는 다른 논으로부터 물을 끌어오는 법이다.
// 각각의 논에 대해 우물을 파는 비용과 논들 사이에 물을 끌어오는 비용들이 주어졌을 때 최소의 비용으로 모든 논에 물을 대는 것이 문제이다.
//
// - 입력
// 첫 줄에는 논의 수 N(1 ≤ N ≤ 300)이 주어진다. 다음 N개의 줄에는 i번째 논에 우물을 팔 때 드는 비용 Wi(1 ≤ Wi ≤ 100,000)가 순서대로 들어온다. 다음 N개의 줄에 대해서는 각 줄에 N개의 수가 들어오는데 이는 i번째 논과 j번째 논을 연결하는데 드는 비용 Pi,j(1 ≤ Pi,j ≤ 100,000, Pi,j = Pj,i, Pi,i = 0)를 의미한다.
//
// - 출력
// 첫 줄에 모든 논에 물을 대는데 필요한 최소비용을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;
vector<pair<int, pair<int, int>>> edge;
vector<int> p;

int find(int x) {
  if (p[x] != x)
    p[x] = find(p[x]);
  return p[x];
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x < y)
    p[y] = x;
  else
    p[x] = y;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  p.resize(N + 1);
  iota(p.begin(), p.end(), 0);
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    edge.push_back({x, {0, i}});
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      int x;
      cin >> x;
      edge.push_back({x, {i, j}});
    }
  sort(edge.begin(), edge.end());
  for (auto [weight, path] : edge)
    if (find(path.first) != find(path.second)) {
      ans += weight;
      merge(path.first, path.second);
    }
  cout << ans;
  return 0;
}
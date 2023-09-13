// 11780: 플로이드 2
//
// - 문제
// n(1 ≤ n ≤ 100)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1 ≤ m ≤ 100,000)개의 버스가 있다. 각 버스는 한 번 사용할 때 필요한 비용이 있다.
// 모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값을 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 도시의 개수 n이 주어지고 둘째 줄에는 버스의 개수 m이 주어진다. 그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 버스의 정보는 버스의 시작 도시 a, 도착 도시 b, 한 번 타는데 필요한 비용 c로 이루어져 있다. 시작 도시와 도착 도시가 같은 경우는 없다. 비용은 100,000보다 작거나 같은 자연수이다.
//
// - 출력
// 먼저, n개의 줄을 출력해야 한다. i번째 줄에 출력하는 j번째 숫자는 도시 i에서 j로 가는데 필요한 최소 비용이다. 만약, i에서 j로 갈 수 없는 경우에는 그 자리에 0을 출력한다.
// 그 다음에는 n×n개의 줄을 출력해야 한다. i×n+j번째 줄에는 도시 i에서 도시 j로 가는 최소 비용에 포함되어 있는 도시의 개수 k를 출력한다. 그 다음, 도시 i에서 도시 j로 가는 경로를 공백으로 구분해 출력한다. 이때, 도시 i와 도시 j도 출력해야 한다. 만약, i에서 j로 갈 수 없는 경우에는 0을 출력한다.

#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define ll long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  ll dist[101][101];
  vector<int> path[101][101];
  cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      if (i == j) {
        dist[i][j] = 0;
      } else {
        dist[i][j] = INF;
        path[i][j] = {i, j};
      }
  while (M--) {
    ll a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = min(dist[a][b], c);
  }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          vector<int> tmp{path[i][k]};
          tmp.insert(tmp.end(), path[k][j].begin() + 1, path[k][j].end());
          path[i][j] = tmp;
        }
      }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++)
      cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
    cout << '\n';
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (path[i][j].size() == 0 || dist[i][j] == INF)
        cout << "0\n";
      else {
        cout << path[i][j].size() << ' ';
        for (int e : path[i][j])
          cout << e << ' ';
        cout << '\n';
      }
    }
  }
  return 0;
}
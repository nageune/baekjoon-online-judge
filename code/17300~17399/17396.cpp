// 17396: 백도어
//
// - 문제
// 유섭이는 무척이나 게으르다. 오늘도 할 일을 모두 미뤄둔 채 열심히 롤을 하던 유섭이는 오늘까지 문제를 내야 한다는 사실을 깨달았다. 그러나 게임은 시작되었고 지는 걸 무척이나 싫어하는 유섭이는 어쩔 수 없이 백도어를 해 게임을 최대한 빠르게 끝내기로 결심하였다.
// 최대한 빨리 게임을 끝내고 문제를 출제해야 하기 때문에 유섭이는 최대한 빨리 넥서스가 있는 곳으로 달려가려고 한다. 유섭이의 챔피언은 총 N개의 분기점에 위치할 수 있다. 0번째 분기점은 현재 유섭이의 챔피언이 있는 곳을, N-1 번째 분기점은 상대편 넥서스를 의미하며 나머지 1, 2, ..., N-2번째 분기점은 중간 거점들이다. 그러나 유섭이의 챔피언이 모든 분기점을 지나칠 수 있는 것은 아니다. 백도어의 핵심은 안 들키고 살금살금 가는 것이기 때문에 적 챔피언 혹은 적 와드(시야를 밝혀주는 토템), 미니언, 포탑 등 상대의 시야에 걸리는 곳은 지나칠 수 없다.
// 입력으로 각 분기점을 지나칠 수 있는지에 대한 여부와 각 분기점에서 다른 분기점으로 가는데 걸리는 시간이 주어졌을 때, 유섭이가 현재 위치에서 넥서스까지 갈 수 있는 최소 시간을 구하여라.
//
// - 입력
// 첫 번째 줄에 분기점의 수와 분기점들을 잇는 길의 수를 의미하는 두 자연수 N과 M이 공백으로 구분되어 주어진다.(1 ≤ N ≤ 100,000, 1 ≤ M ≤ 300,000)
// 두 번째 줄에 각 분기점이 적의 시야에 보이는지를 의미하는 N개의 정수 a0, a1, ..., aN-1가 공백으로 구분되어 주어진다. ai가 0이면 i 번째 분기점이 상대의 시야에 보이지 않는다는 뜻이며, 1이면 보인다는 뜻이다. 추가적으로 a0 = 0, aN-1 = 1이다., N-1번째 분기점은 상대 넥서스이기 때문에 어쩔 수 없이 상대의 시야에 보이게 되며, 또 유일하게 상대 시야에 보이면서 갈 수 있는 곳이다.
// 다음 M개의 줄에 걸쳐 세 정수 a, b, t가 공백으로 구분되어 주어진다. (0 ≤ a, b < N, a ≠ b, 1 ≤ t ≤ 100,000) 이는 a번째 분기점과 b번째 분기점 사이를 지나는데 t만큼의 시간이 걸리는 것을 의미한다. 연결은 양방향이며, 한 분기점에서 다른 분기점으로 가는 간선은 최대 1개 존재한다.
//
// - 출력
// 첫 번째 줄에 유섭이의 챔피언이 상대 넥서스까지 안 들키고 가는데 걸리는 최소 시간을 출력한다. 만약 상대 넥서스까지 갈 수 없으면 -1을 출력한다.

#include <bits/stdc++.h>
using namespace std;

#define INF 10000000001

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  cin >> N >> M;
  vector<int> v(N);
  for (int i = 0; i < N; i++)
    cin >> v[i];
  vector<pair<int, int>> graph[100001];
  while (M--) {
    int a, b, t;
    cin >> a >> b >> t;
    if (a != N - 1 && b != N - 1 && (v[a] == 1 || v[b] == 1))
      continue;
    graph[a].push_back({b, t});
    graph[b].push_back({a, t});
  }
  vector<int> visited(100001, 0);
  vector<long long> dist(100001, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  dist[0] = 0;
  pq.push({0, 0});
  while (!pq.empty()) {
    int curr;
    do {
      curr = pq.top().second;
      pq.pop();
    } while (!pq.empty() && visited[curr]);
    if (visited[curr])
      break;
    visited[curr] = 1;
    for (auto &p : graph[curr]) {
      int next = p.first, d = p.second;
      if (dist[next] > dist[curr] + d) {
        dist[next] = dist[curr] + d;
        pq.push({dist[next], next});
      }
    }
  }
  if (dist[N - 1] == INF)
    cout << "-1\n";
  else
    cout << dist[N - 1] << '\n';
  return 0;
}
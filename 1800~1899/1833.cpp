// 1833: 고속철도 설계하기
//
// - 문제
// N(1≤N≤200)개의 도시로 이루어진 나라가 있다. 이 도시들 사이를 다니는 고속철도망을 만들어 도시 간의 이동을 편하게 하려고 한다. 단, 고속철도망을 만든 후에 임의의 도시에서 다른 임의의 도시로 고속철도를 이용하여 이동할 수 있게 하려고 한다.
// 시범 사업으로 몇 개의 도시 사이에 고속철도가 설치되었는데 그 결과가 매우 좋아 국가에서는 이 사업을 완성하기로 하였다. 이제 당신은 몇 개의 도시 사이에 고속철도를 추가로 설치하여, 임의의 도시에서 다른 임의의 도시로 고속철도를 이용하여 이동할 수 있게 하려고 한다.
// 그러나 이 사업은 워낙 돈이 많이 드는 사업이기 때문에, 이 사업에 드는 총 비용을 최소화 하려고 한다. 두 도시 사이에 고속철도를 설치할 때 드는 비용이 주어졌을 때, 총 비용을 최소로 하여 사업을 완성하여 보자.
// 예를 들어 아래와 같은 경우를 보자. �
// 현재 1번 도시와 2번 도시, 2번 도시와 4번 도시, 1번 도시와 4번 도시 사이에 고속철도가 설치되어 있다. 각각의 수는 두 도시 사이에 고속철도를 설치하는데 드는 비용을 나타낸다. 예를 들어 2번 도시와 3번 도시 사이에 고속철도를 설치하면 10만큼의 비용이 든다는 것을 의미한다. 위의 그림에 나타나지 않은 비용은 다 1,000이라고 하자.
// 위와 같은 경우에는 2, 3번 도시 사이에 고속철도를 설치하고, 3, 5번 도시 사이에 고속철도를 설치하면, 임의의 도시에서 다른 임의의 도시로 고속철도를 이용하여 갈 수 있으며, 이 경우는 10+20+30+10+10=80만큼의 총 비용으로 사업을 완성할 수 있다. 10+20+30은 이미 설치된 고속도로에 대한 비용을 의미한다.
// 2, 4번 도시를 연결하는 고속철도가 없더라도 임의의 도시에서 다른 임의의 도시로 고속철도를 이용하여 이동할 수 있지만, 이미 설치되어 있는 고속철도를 돈을 들여가며 파괴할 필요가 없으므로, 이런 건 생각하지 않기로 한다.
//
// - 입력
// 첫째 줄에 자연수 N이 주어진다. 다음 N개의 줄에는 인접행렬 형태로 두 도시 사이에 고속철도를 설치할 때 드는 비용이 주어진다. 이 비용은 각각 10,000을 넘지 않는 자연수이다. 만약 비용이 음수라면, 그 두 도시 사이에 이미 고속철도가 설치되어 있는 경우를 의미한다.
//
// - 출력
// 첫째 줄에 두 정수 C, M를 출력한다. C는 고속철도망을 설치하는데 든 총 비용이며, M은 새로이 설치한 고속철도의 개수이다. 다음 M개의 줄에는 새로 고속철도가 설치된 두 도시번호를 출력한다. 우리가 최소화 하려는 것은 C이다.

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int N, C = 0, M = 0;
vector<pair<int, pii>> edge;
vector<pii> mst;
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
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      int x;
      cin >> x;
      if (x < 0) {
        merge(i, j);
        C -= x;
      } else {
        edge.push_back({x, {i, j}});
      }
    }
  C /= 2;
  sort(edge.begin(), edge.end());
  for (auto [weight, path] : edge)
    if (find(path.first) != find(path.second)) {
      C += weight;
      mst.push_back(path);
      merge(path.first, path.second);
    }
  cout << C << ' ' << mst.size() << '\n';
  for (auto [x, y] : mst)
    cout << x << ' ' << y << '\n';
  return 0;
}
// 24499: blobyum
//
// - 문제
// 오늘도 블롭은 배고프다. 그래서 블롭은 요리사 연우를 찾아가 맛있는 것을 달라고 부탁했다.
// 연우는 귀여운 블롭에게 이왕이면 맛있는 음식을 해 주고 싶었기에, 자신이 만드는 데에 가장 뛰어난 애플파이를 만들기로 하였다. 연우는 $N$개의 애플파이를 만들었으며, 이를 원 모양으로 책상에 배치해 놓았다.
// 각 애플파이는 하나의 양의 정수로 표현되며, 이는 맛있는 정도를 의미한다. (수가 클수록 더 맛있는 애플파이이다.)
// 블롭은 $N$개의 애플파이 중 $K$개를 먹으려고 한다. 물론 블롭은 힘을 들이지 않고 먹고 싶기 때문에, 연속으로 배치되어 있는 $K$개의 애플파이를 먹으려 한다.
// 블롭을 도와서 블롭이 먹을 애플파이의 맛의 합의 최댓값을 구해 주자!
//
// - 입력
// 첫째 줄에 애플파이의 개수와 먹으려는 애플파이의 개수 $N$과 $K$가 공백으로 구분되어 주어진다.
// 둘째 줄에 애플파이의 맛있는 정도를 나타내는 값인 $A_1, A_2, \cdots, A_N$이 공백으로 구분되어 주어진다.
//
// - 출력
// 블롭이 먹을 애플파이의 맛의 합의 최댓값을 출력한다.
//
// - 제한
// $1 \le K \le N \le 10^5$ 
// $1 \le A_i \le 100$ $(1 \le i \le N)$ 

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, ans = 0;
  cin >> n >> k;
  vector<int> v(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] += v[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    int j = i + k - 1;
    if (j > n) {
      j -= n;
      ans = max(ans, v[n] - v[i - 1] + v[j]);
    } else {
      ans = max(ans, v[j] - v[i - 1]);
    }
  }
  cout << ans;
  return 0;
}
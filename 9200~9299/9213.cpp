// 9213: 꽤 좋은 수
//
// - 문제
// 완전수는 자기 자신을 제외한 약수의 합이 자기 자신이 되는 자연수이다. 예를 들어, 6의 약수는 1, 2, 3인데 1+2+3은 6이기 때문에 완전수이고, 28도 1+2+4+7+14 = 28이기 때문에 완전수이다.
// 어떤 자연수의 나쁨이란 자기 자신을 제외한 약수의 합과 자기 자신과의 차이이다.
// 꽤 좋은 수는 자연수의 나쁨이 어떤 특정한 값보다 크지 않은 수이다. 예를 들어, 나쁨을 2까지 허용한다면, 100보다 작은 수 중에 꽤 좋은 수는 11가지 2, 3, 4, 6, 8, 10, 16, 20, 28, 32, 64)가 있다. 이 나쁨의 기준을 0으로 바꿔버리면 완전수의 정의와 같아진다.
// 허용하는 나쁨의 최댓값이 주어졌을 때, 꽤 좋은 수가 입력으로 주어지는 구간 안에 몇 개 있는지 구하는 프로그램을 작성하시오.
//
// - 입력
// 입력은 테스트 케이스 여러개로 이루어져 있다. 각 테스트 케이스는 한 줄이고 start stop badness 세 정수를 포함한다.
// start (2 ≤ start < 1000000)
// stop (start ≤ stop < 1000000)
// badness (0 ≤ badness < 1000)
// 입력의 마지막 줄에는 0이 세 개 주어진다.
//
// - 출력
// 각 테스트 케이스에 대해서, 입력으로 주어진 구간에 포함되는 자연수 중 꽤 좋은 수의 개수를 출력한다. (start와 stop도 구간에 포함되고, 나쁨의 최댓값은 badness로 주어진다)

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> sieve(1000001, 0);
  for (int i = 1; i <= 1000000; i++)
    for (int j = i * 2; j <= 1000000; j += i)
      sieve[j] += i;
  int cnt = 1;
  while (1) {
    int s, e, bad, ans = 0;
    cin >> s >> e >> bad;
    if (s == 0)
      break;
    for (int i = s; i <= e; i++) {
      if (abs(sieve[i] - i) <= bad)
        ans++;
    }
    cout << "Test " << cnt << ": " << ans << '\n';
    cnt++;
  }
  return 0;
}
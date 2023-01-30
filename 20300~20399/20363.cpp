// 20363: 당근 키우기
//
// - 문제
// 꽉꽉나라의 농부 오리는 당근을 키우려고 한다. 꽉꽉나라에서는 씨앗이 X만큼의 온기와 Y만큼의 수분을 가지면 당근으로 자란다고 한다.
// 씨앗은 햇빛을 1번 받을 때마다 1만큼의 온기가 증가하고, 햇빛을 10번 받을 때마다 1만큼의 수분이 감소한다.
// 씨앗은 물을 1번 받을 때마다 1만큼의 수분이 증가하고, 물을 10번 받을 때마다 1만큼의 온기가 감소한다.
// 만약, 감소되어야 하는 온기 혹은 수분이 이미 0이라면 감소되지 않는다. 즉, 온기와 수분은 음수가 되지 않는다. 맨 처음 씨앗의 온기와 수분은 0이다.
// 오리는 당근을 효율적으로 키우기 위해, 당근이 자랄 때까지 햇빛과 물을 주는 횟수의 합을 최소화하려고 한다. 예를 들어, X = 10, Y = 10이라고 하자.
// 씨앗에 햇빛을 10번 주면 온기 10, 수분 0이 된다. 그리고, 물을 10번 주면 온기 9. 수분 10이 된다. 마지막으로 햇빛을 1번 주면 온기 10, 수분 10으로 당근이 자라게 된다. 이때, 햇빛과 물을 준 횟수의 합은 21이고 위 예제에서의 최솟값이다.
// X와 Y가 주어졌을 때, 당근이 자랄 때까지 햇빛과 물을 주는 횟수의 합의 최솟값을 구하는 프로그램을 작성하라.
//
// - 입력
// 첫째 줄에 X와 Y (0 ≤ X, Y ≤ 109)를 의미하는 정수가 공백으로 구분되어 주어진다.
//
// - 출력
// 당근이 자랄 때까지 햇빛과 물을 주는 횟수의 합의 최솟값을 나타내는 정수를 출력하라.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int x, y;
  cin >> x >> y;
  if (x >= y)
    cout << x + (y / 10) + y;
  else
    cout << y + (x / 10) + x;
  return 0;
}
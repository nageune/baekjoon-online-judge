// 1669: 멍멍이 쓰다듬기
//
// - 문제
// 동물원에서 막 탈출한 원숭이 한 마리가 세상구경을 하고 있다. 그러다 오늘도 어김없이 그의 영원한 라이벌 멍멍이를 만나게 되었다. 원숭이는 멍멍이를 쓰다듬고 싶었다. 하지만 원숭이는 멍멍이보다 키가 작기 때문에 멍멍이를 쓰다듬어줄 수 없다. 원숭이가 멍멍이를 쓰다듬으려면 둘의 키가 같아야 하기 때문이다.
// 그래서 원숭이는 그 날부터 자신의 키를 조절하기로 마음먹었다. 원숭이는 초능력자이기 때문에 마음대로 키를 늘릴 수 있다. 하지만 안타깝게도 사람이 아니라 동물이기 때문에 하루에 늘릴 수 있는 키의 양을 1cm밖에 조절할 수 없다. 예를 들어 오늘 키를 5cm 만큼 늘렸다면, 내일은 키를 4cm, 5cm, 6cm 중 하나만큼 키를 늘릴 수 있다는 뜻이다. 늘릴 수 있는 키의 양은 음수가 될 수 없다. 그리고 첫째 날과 마지막 날에는 무조건 1cm 만큼 늘릴 수 있다.
// 현재 원숭이와 멍멍이의 키가 주어졌을 때, 원숭이가 매일 키를 늘려서 멍멍이와 키가 같아지는 최소의 일수를 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 원숭이의 키 X와 멍멍이의 키 Y가 주어진다. X, Y는 0 ≤ X ≤ Y < 2^31을 만족하는 정수이다.
//
// - 출력
// 첫째 줄에 원숭이가 멍멍이의 키와 같아지게 되는 최소의 일수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int x, y, ans = 0;
  cin >> x >> y;
  int gap = y - x, h = 1;
  while (gap) {
    gap -= 2 * h;
    ans += 2;
    if (gap <= h) {
      while (gap != 0) {
        if (gap < 0) {
          gap += h;
          ans--;
          h--;
        } else if (gap > 0) {
          gap -= h;
          ans++;
          h++;
        }
      }
    }
    h++;
  }
  cout << ans << '\n';
  return 0;
}
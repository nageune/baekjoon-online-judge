// 27962: 오렌지먹은지오랜지
//
// - 문제
// 오렌지를 먹은 지 오래된 선생님은 부족한 비타민C를 문자열 문제를 통해 보충하려고 한다. "오렌지 먹은 지 오랜지"의 "오렌지", "오랜지"와 같이, 길이가 동일하며 각각 맨 앞, 맨 뒤 문자를 포함하는 어떤 두 부분 문자열이 앞에서부터 하나씩 비교했을 때 정확히 한 문자만 다른 경우, 전체 문자열을 "비타민 문자열"이라 부르려고 한다. 주어진 문자열이 "비타민 문자열"이면 YES, 아니면 NO를 출력하라.
// 두 문자열 s와 t가 있을 때 t가 s에서 연속해서 나타난다면 t를 s의 부분 문자열이라 한다. 예를 들어, abcdedc의 부분 문자열로는 ab, bcde, dedc, abcdedc 등이 있다.
// 두 부분 문자열은 겹쳐도 무방하며, 부분 문자열의 길이는 1 이상이어야 한다. aabaacaa는 맨 앞 문자를 포함하는 부분 문자열 aabaa와 맨 뒤 문자를 포함하는 동일한 길이의 부분 문자열 aacaa를 앞에서부터 하나씩 비교했을 때 정확히 한 문자가 다르기 때문에, 비타민 문자열에 해당한다.
//
// - 입력
// 첫 번째 줄에 문자열의 길이 N이 주어진다. (2 ≤ N ≤ 2,000) 
// 두 번째 줄에 문자열이 주어진다. 문자열은 알파벳 소문자로만 이루어져 있다.
//
// - 출력
// 입력으로 주어진 문자열이 "비타민 문자열"이면 YES를, 아니면 NO를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    string a = s.substr(0, i);
    string b = s.substr(n - i, i);
    int cnt = 0;
    for (int j = 0; j < i; j++)
      if (a[j] != b[j])
        cnt++;
    if (cnt == 1) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
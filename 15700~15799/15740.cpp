// 15740: A+B - 9
//
// - 문제
// 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 A와 B (-10^10000 ≤ A, B ≤ 10^10000)가 주어진다.
//
// - 출력
// 첫째 줄에 A+B를 출력한다.

#include <iostream>
using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;
  cout << a + b << '\n';
  return 0;
}
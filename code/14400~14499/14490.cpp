// 14490: 백대열
//
// - 문제
// 대열이는 욱제의 친구다.
// “야 백대열을 약분하면 뭔지 알아?”
// “??”
// “십대일이야~ 하하!”
// n:m이 주어진다. 욱제를 도와주자. (...)
//
// - 입력
// n과 m이 :을 사이에 두고 주어진다. (1 ≤ n, m ≤ 100,000,000)
//
// - 출력
// 두 수를 최대한으로 약분하여 출력한다.

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  int n, m;
  scanf("%d:%d", &n, &m);
  int g = gcd(n, m);
  printf("%d:%d", n / g, m / g);
  return 0;
}
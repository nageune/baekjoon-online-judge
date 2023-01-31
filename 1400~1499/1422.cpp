// 1422: 숫자의 신
//
// - 문제
// 숫자의 신은 여러명이 있지만, 그 중에 자연수의 신은 오세준이다. 오세준은 자연수의 신으로 오래오래 살다가 어느 날 음수의 신과 전쟁을 하게 되었다. 오세준은 음수의 신 이다솜을 이기기위해서 큰 숫자를 만들기로 했다.
// 오세준은 지금 K개의 자연수를 가지고 있다. 오세준은 K개의 수 중에 정확하게 N개의 수를 뽑아내서 그 수를 붙여서 만들 수 있는 수중에 가장 큰 수를 만들고자 한다. 같은 수를 여러 번 이용해도 된다. 단, 모든 수는 적어도 한 번은 이용되어야 한다.
// 오세준이 현재 가지고 있는 K개의 수가 주어졌을 때, 이 수를 적어도 한 번 이상 이용해서 만들 수 있는 수 중에 가장 큰 수를 출력하는 프로그램을 작성하시오.
// 예를 들어 지금 오세준이 2, 3, 7 이라는 3개의 수를 가지고 있고, 4개의 수를 뽑아야 한다면, 7732를 만들면 가장 큰 수가 된다.
//
// - 입력
// 첫째 줄에 K와 N이 공백을 사이에 두고 주어진다. K와 N은 각각 50보다 작거나 같은 자연수이고, N은 K보다 크거나 같다. 둘째 줄에는 K개의 수가 한 줄에 하나씩 주어진다. 각 수는 1,000,000,000보다 작거나 같은 자연수이다. 이 수는 중복되어 들어올 수 있다. 만약 중복되어서 들어오는 경우에는 각 수가 적어도 입력으로 주어진 만큼 이용되어야 한다는 소리다.
//
// - 출력
// N개의 수를 뽑아서 연결해서 만들 수 있는 가장 큰 수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
  if (a.size() == b.size()) {
    string ab = a + b;
    string ba = b + a;
    return ab > ba;
  }
  return a.size() > b.size();
}

bool compare(string a, string b) {
  string ab = a + b;
  string ba = b + a;
  return ab > ba;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int k, n, flag = 0;
  cin >> k >> n;
  vector<string> v(k), tmp;
  for (int i = 0; i < k; i++)
    cin >> v[i];
  tmp = v;
  sort(v.begin(), v.end(), cmp);
  sort(tmp.begin(), tmp.end(), compare);
  for (int i = 0; i < k; i++) {
    if (tmp[i] == v[0] && !flag) {
      for (int j = 0; j < n - k + 1; j++)
        cout << tmp[i];
      flag = 1;
    } else
      cout << tmp[i];
  }
  return 0;
}
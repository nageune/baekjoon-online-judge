// 25703: 포인터 공부
//
// - 문제
// 용모는 오늘 객체지향프로그래밍1 시간에 포인터에 대해 배웠다. 포인터란, 프로그래밍 언어에서 다른 변수, 혹은 그 변수의 메모리 공간주소를 가리키는 변수를 의미한다.
// C/C++에서 포인터는 (자료형) *(변수명)으로 선언할 수 있으며 값은 &(이미 선언된 변수명)으로 지정할 수 있다. 이때 변수 선언에서 '*' 기호는 이 변수가 포인터임을 의미하고, '&' 기호는 변수의 메모리 주소값을 의미한다.
// 예를 들어, int형 변수 a에 대한 포인터 ptr을 다음과 같이 선언할 수 있다. 이때 ptr은 a가 저장된 메모리의 주소를 가리키고 있다.
// int a;
// int *ptr = &a;
// 또한 포인터의 포인터를 선언하는 식으로 다중 포인터를 선언하는 것이 가능하다. int형 변수 a에 대해 4중 포인터를 만들려 하는 경우 다음과 같이 코드를 작성해야 한다. 이중 포인터인 ptr2는 a의 포인터인 ptr의 주소를, 삼중 포인터인 ptr3는 이중 포인터인 ptr2의 주소를 가리키는 식으로 특정 변수에 대해 다중 포인터를 끝없이 선언할 수 있다.
// int a;
// int *ptr = &a;
// int **ptr2 = &ptr;
// int ***ptr3 = &ptr2;
// int ****ptr4 = &ptr3;
// 용모는 int형 변수 a에 대해 N중 포인터를 선언하는 코드를 작성할 때 필요한 변수 선언문들을 작성해야 하는 과제를 받았다. 이때 위 다중 포인터 선언 예시와 같이 각 포인터 변수의 이름은 "ptr", "ptr2", ..., "ptrN" (N은 수)이 되어야 하고, 코드 형식은 위 예시와 동일해야 한다.
// 하지만 공부가 너무 싫고 게임을 너무나 좋아했던 용모는 코드를 치는 시간이 아까웠기 때문에 과제의 코드를 대신 출력해주는 프로그램을 작성하고 게임을 하러 가기로 하였다.
// 용모가 작성할 프로그램을 여러분도 작성해보자.
//
// - 입력
// 정수 N이 주어진다.
//
// - 출력
// 용모가 과제로 작성해야 하는 변수 선언문들을 N + 1개의 줄에 걸쳐 출력한다.
//
// - 제한
// 1 ≤ N ≤ 100

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  cout << "int a;\n";
  for (int i = 1; i <= n; i++) {
    cout << "int ";
    for (int j = 0; j < i; j++) {
      cout << "*";
    }
    cout << "ptr";
    if (i != 1)
      cout << i;
    cout << " = ";
    if (i == 1)
      cout << "&a;\n";
    else {
      cout << "&ptr";
      if (i == 2)
        cout << ";\n";
      else
        cout << i - 1 << ";\n";
    }
  }
  return 0;
}
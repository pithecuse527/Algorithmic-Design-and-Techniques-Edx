#include <iostream>

int get_change(int m) {
  int num_of_10 = 0;
  int num_of_5 = 0;
  int num_of_1 = 0;

  while(m>=10)  // use $10 while we can use $10
  {
    m -= 10;
    num_of_10++;
  }
  while(m>=5)   // use $5 while we can use $5
  {
   m -= 5;
   num_of_5++;
  }
  while(m>=1)   // use $1 while we can use $1
  {
   m -= 1;
   num_of_1++;
  }

  return num_of_1 + num_of_5 + num_of_10;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

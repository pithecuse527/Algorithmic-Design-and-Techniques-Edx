#include <iostream>

long long int gcd_fast(long long a, long long b) {
 if(b == 0) return a;
 return gcd_fast(b, a%b);
}

long long lcm_fast(long long a, long long b) {
	if(a>b) std::swap(a,b);
 	long long gcd = gcd_fast(a,b);
 	return a*b/gcd;   // fast way to calculate the least common multiple
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}

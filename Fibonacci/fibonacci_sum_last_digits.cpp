#include <iostream>

long long fibonacci_sum(long long n) {

    long long f0 = 0;
    long long f1 = 1;
 	  long long s = 1;

 	if(n == 0 || n == 1) return n;

  // the pisano period for 10 is 60
  // if n is lower than the 10's pisano period, just calculate right away
 	if(n <= 60)
    {
     for(long long i = 0; i <= n-2 ; i++)
        {
           long long f = (f0 + f1) % 10;
           f0 = f1;
           f1 = f;
           s = s + (f%10);
        }
    }
    else
    {
     	long long p = n / 60; // how many pisano period cycle?

        // the loop will range from 2 to two terms after the remainder
        for(long long i = 0; i <= 57; i++)
        {
           long long f = (f0 + f1) % 10;
           f0 = f1;
           f1 = f;
           s += f;
        }

     	if(p>0) s *= p;

     	for(long long i=p*60; i<=n; i++)
        {
           long long f = (f0 + f1) % 10;
           f0 = f1;
           f1 = f;
           s += f;
        }

    }
 return s%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n) << std::endl;
}

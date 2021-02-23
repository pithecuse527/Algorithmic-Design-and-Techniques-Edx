#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>

using std::vector;

bool cmp(std::pair<int, double>& a, std::pair<int, double>& b)
{
    // compare based on the pair's second trait (first trait is a key and second one is a value)
    return a.second > b.second;   // non-decreasing
}

vector<std::pair<int, double> > get_sorted_hash(int n, vector<int> weights, vector<int> values){
 // return the hash table sorted by the second trait
 vector<std::pair<int, double> > hashT;
 for(int i=0; i<n; i++) {
  std::pair<int, double> tmp;
  tmp.first = i;
  tmp.second = (double)values[i] / weights[i];    // to determine which product has more high value per weight
  hashT.push_back(tmp);
 }

 sort(hashT.begin(), hashT.end(), cmp);
 return hashT;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, vector<std::pair<int, double> > hashT) {
  double value = 0.0;
  int a, loc;

  for(int i=0; i<hashT.size(); i++) {
    if (capacity == 0) return value;    // while there are some extra space for loot,
    loc = hashT[i].first;   // get the real location of the product while using the hash table
    a = capacity < weights[loc] ? capacity : weights[loc];  // loot as much as we can
    value += (a*hashT[i].second);
    capacity -= a;
  }
  return value;
}

int main() {
  int n;	// # items
  int capacity;	// W
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  // use the hash table to help us to choose what product is a greedy safe choice
  vector<std::pair<int, double> > hashT = get_sorted_hash(n, weights, values);
  double optimal_value = get_optimal_value(capacity, weights, values, hashT);

  // std::cout.precision(10);
  // std::cout << optimal_value << std::endl;
  printf("%.4lf\n", optimal_value);
  return 0;
}

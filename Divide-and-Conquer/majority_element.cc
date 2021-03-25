#include <algorithm>	// this and O(nlogn) would be a hint?
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<double> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right && a[left] == a[right]) return a[left];		// this could also be a hint

  int mid = (left+right)/2;
  int left_majority = get_majority_element(a, left, mid);
  int right_majority = get_majority_element(a, mid+1, right);
  if (left_majority == -1 && right_majority != -1) return right_majority;
  else if (left_majority != -1 && right_majority == -1) return left_majority;
  else if (left_majority == right_majority) return left_majority;
  else return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<double> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  double result = get_majority_element(a, 0, a.size()-1);
  int cnt = 0;
  for(int i=0; i<n; i++) if(result == a[i]) cnt++;
  if(cnt == n/2) result = -1;
  std::cout << (result != -1) << '\n';
}

#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsGreaterOrEqual(string a, string b) {
  // this callee is needed as the caller do not know what is really bigger with the two different digit string
  // i.e.  2 and 21 should return 221, not 212
  if(stoi(a+b) > stoi(b+a)) return true;

  return false;
}

string largest_number(vector<string> a) {
  sort(a.begin(), a.end(), IsGreaterOrEqual);   // sort by the customized function
  stringstream ret;

  // if the given vector is sorted, then just concatenate to the ret
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }

  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  cout << largest_number(a) << endl;
  return 0;
}

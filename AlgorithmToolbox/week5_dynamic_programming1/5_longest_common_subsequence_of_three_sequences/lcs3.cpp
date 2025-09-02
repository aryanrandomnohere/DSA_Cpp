#include <iostream>
#include <vector>

using std::vector;

vector<int> lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  vector<vector<int>> dp1(a.size()+1, vector<int>(b.size()+1, 0));
  for(int i =1 ; i <= a.size(); i++){
    for(int j = 1; j<= b.size(); j++){
      if(a[i-1] == b[j-1]) dp1[i][j] = 1+dp1[i-1][j-1];
      else dp1[i][j] = std::max(dp1[i-1][j], dp1[i][j-1]);
    }
    }
    //Building the common sequence
    int i = a.size(), j = b.size();
    vector<int> commonOfAB;
    while(i>0 && j>0){
    if(a[i-1] == b[j-1]){
      commonOfAB.push_back(a[i-1]);
      i--;
      j--;
    }else if(dp1[i-1][j]>dp1[i][j-1]) i--;
    else j--;
}
    reverse(commonOfAB.begin(), commonOfAB.end());
    vector<vector<int>> dp2(c.size() +1,vector<int>(commonOfAB.size()+1, 0));

      for(int k =1 ; k <= c.size(); k++){
    for(int l = 1; l<= commonOfAB.size(); l++){
      if(c[k-1] == commonOfAB[l-1]) dp2[k][l] = 1+dp2[k-1][l-1];
      else dp2[k][l] = std::max(dp2[k-1][l], dp2[k][l-1]);
    }
    }
    //Building the common sequence
    int k = c.size(), l = commonOfAB.size();
    vector<int> commonOfABC;
    while(k>0 && l>0){
    if(c[k-1] == commonOfAB[l-1]){
      commonOfABC.push_back(c[k-1]);
      k--;
      l--;
    }else if(dp2[k-1][l]>dp2[k][l-1]) k--;
    else l--;
  }
  reverse(commonOfABC.begin(), commonOfABC.end());

  return commonOfABC;
}


int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}

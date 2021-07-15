#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> dp(n,vector<int> (3,0));
  vector<vector<int>> day(n);
  for(auto &x:day){
    int t, y, z;
    cin >> t >> y >> z;
    x.push_back(t);
    x.push_back(y);
    x.push_back(z);
  }
  dp[0][0] = day[0][0];
  dp[0][1] = day[0][1];
  dp[0][2] = day[0][2];
  for(int i = 1; i < n; i++){
    dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + day[i][0];
    dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + day[i][1];
    dp[i][2] = max(dp[i-1][1],dp[i-1][0]) + day[i][2];
  }
  n--;
  int ans = max({dp[n][0],dp[n][1],dp[n][2]});
  cout << ans << endl;
  return 0;
}

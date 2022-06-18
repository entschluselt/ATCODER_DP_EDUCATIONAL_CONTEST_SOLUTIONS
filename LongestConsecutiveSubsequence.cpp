/*

You are given strings s and t. Find one longest string that is a subsequence of both s and t.

A subsequence of a string x is the 
string obtained by removing zero or more characters from x and concatenating the remaining characters without changing the order.

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(NULL); 

void solve(){
   string s , p;
   cin >> s >> p;
   int n = s.size();
   int m = p.size();
   vector<vector<int> > dp(n + 1, vector<int> (m + 1, 0));
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
         if(s[i-1] == p[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
         else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
   }
   string ans = "";
   int temp = dp[n][m];
   if(temp == 0) {
      cout << ans << endl; return;
   }
  
  //VERY CRUCIAL STEP TO PRINT THE SUBSEQUEUNCE
   //cout << dp[n][m] << endl;
   for(int i = n; i > 0; i--){
      for(int j = 1; j <= m; j++){
         //cout << dp[i][j] << endl;
         if(dp[i][j] == temp and s[i-1] == p[j-1]){
            ans += s[i-1];
            temp--;
         }
      }
   }
   /*
   for(auto x:dp){
      for(auto y:x) cout << y << " ";
      cout << endl;
   }*/
   reverse(ans.begin(),ans.end());
   cout << ans << endl;
}
signed main(){
   io
   int tt = 1;	
   //cin >> tt; 
   while(tt--){
      solve();
   }
}


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define io ios_base::sync_with_stdio(false);cin.tie(NULL); 
 
void solve(){
   int n , ww;
   cin >> n >> ww;
   vector<int> w(n), v(n);
   for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
   
   vector<vector<int>> dp(100, vector<int> (100001));
   
   dp[0][0] = 0;
   dp[0][w[0]] = v[0];
   
   for(int i = 1; i < n; i++){
      dp[i][0] = 0;
      for(int j = 1; j <= ww; j++){
         dp[i][j] = dp[i-1][j];
         
         if(j >= w[i])
            dp[i][j] = max(dp[i][j] , v[i] + dp[i-1][j - w[i]]);
            
      }
   }
   int ans = -1e18;
   for(int j = 0; j <= ww; j++)
      ans = max(ans , dp[n-1][j]);
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

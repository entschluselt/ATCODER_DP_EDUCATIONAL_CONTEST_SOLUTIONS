#include<bits/stdc++.h>
using namespace std;
int dp[100001];
vector<int> h(100001);
int recur(int n){
	if(n<=1)
		return dp[n] = 0;
	if(n == 2)
		return dp[n] = abs(h[1] - h[0]);
	if(n == 3)
		return dp[n] = min(abs(h[2] - h[0]), abs(h[2] - h[1]) + abs(h[1] - h[0]));
	if(dp[n] != -1)
		return dp[n];
	dp[n] = min( recur(n-1) + abs(h[n-1] - h[n-2]), recur(n-2) + abs(h[n-1] - h[n-3]));
	return dp[n];
}
int main(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) 
		cin >> h[i];
	recur(n);
	cout << dp[n] << endl;	
}

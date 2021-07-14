#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+1;
int main(){
	int n , k;
	cin >> n >> k;
	vector<int> h(n);
	for(auto &x:h) cin >> x;
	vector<int> dp(n,inf);
	dp[0] = 0;
	for(int i = 0; i  < n; i++){
		for(int j = i + 1; j <= i + k; j++){
			if( j < n){
				dp[j] = min(dp[j], dp[i] + abs(h[j] - h[i]));
			}
		}
	}
	cout << dp[n-1] << endl;
	return 0;
}

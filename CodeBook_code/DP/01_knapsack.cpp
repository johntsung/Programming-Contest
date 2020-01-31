struct Pack{
	int v,w;
};
int n,w;
int dp[1000004];
pack a[505];
int knapsack_01(){
	for(int i=1;i<=n;i++){
		for(int j=w;j>=0;j--){
			if(a[i].w<=j){
				dp[j]=max(dp[j],dp[j-a[i].w]+a[i].v);
			}
		}
	}
	return dp[w];
}

int nbit,n;
int weight[200200];
int dp[200200]; //initial to -1
int hybercube(int goal){
	if(goal==0) return dp[0]=weight[0];
	if(dp[goal]>=0) return dp[goal];
	int maxi=0;
	for(int i=0;i<nbit;i++){
		if(goal & (1<<i)){
			int k=hybercube(goal^(1<<i));
			maxi=max(k,maxi);
		}
	}
	dp[goal]=maxi+weight[goal];
	return dp[goal];
}

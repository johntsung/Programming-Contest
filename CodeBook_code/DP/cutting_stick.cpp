int l,n;
int dp[2000][2000];
int a[2000];
int cut(int l,int r){
	int cost=0x3f3f3f3f;
	if(dp[l][r]) return dp[l][r];
	if(r-l==2) return dp[l][r]=a[r]-a[l];
	if(r-l<2) return 0;
	for(int i=l+1;i<r;i++){
		cost=min(cost,a[r]-a[l]+cut(l,i)+cut(i,r));
	}
	return dp[l][r]=cost;
}
int cutting_stick(){
	return cut(0,n+1);
}

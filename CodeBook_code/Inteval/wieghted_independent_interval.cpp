struct inter{
	int L,R;
};
inter a[100100];
int n;
int dp[100100];
int binary(int x){
	int ll=0,lr=x,mid;
	while(lr-ll>1){
		mid=(lr+ll)/2;
		if(a[mid].right>a[x].left) lr=mid;
		else ll=mid;
	}
	return dp[ll];
}
int independent_interval(){
	sort(a+1,a+1+n,cmp); //sorting by right point;
	dp[0]=0;
	dp[1]=a[1].w;
	for(int i=2;i<=n;i++){
		dp[i]=max(dp[i-1],a[i].w+binary(i));
	}
	return dp[n];
}

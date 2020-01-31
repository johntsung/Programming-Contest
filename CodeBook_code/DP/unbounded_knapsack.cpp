const int N=100,W=100000;
int cost[N],weight[N];
int c[W+1];

int unbounded_knapsack(int n,int w){
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){
		for(int j=weight[i];j<=w;j++){
			c[j]=max(c[j],c[j-weight[i]]+cost[i]);
		}
	}
	return c[w];
}

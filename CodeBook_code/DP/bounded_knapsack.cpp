const int N=100,W=100000;
int cost[N],weight[N],number[N];
int c[W+1];

int unbounded_knapsack(int n,int w){
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){
		int num=min(number[i],w/weight[i]);
		for(int k=1;num>0;k*=2){
			if(k<num) k=num;
			num-=k;
			for(int j=w;j>=wieght[i]*k;j--){
				c[j]=max(c[j],c[j-weight[i]*k]+cost[i]*k);
			}
		}
	}
	return c[w];
}

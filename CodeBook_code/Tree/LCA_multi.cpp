const int MAX_N=10000,MAX_LOG_N=14;
int N,root,dep[MAX_N],par[MAX_LOG_N][MAX_N];
vector<int> child[MAX_N];
void dfs(int u,int p,int d){
	dep[u]=d;
	for(int i=0;i<(int)child.size();i++){
		int v=child[u][i];
		if(v!=p) dfs(v,u,d+1);
	}
}
void build(){
	dfs(root,-1,0);
	for(int i=0;i+1<MAX_LOG_N;i++){
		for(int u=0;u<N;u++){
			if(par[i][u]==-1) par[i+1][u]=-1;
			else par[i+1][u]=par[i][par[i][u]];
		}
	}
}
int lca(int u,int v){
	if(dep[u]>dep[v]) swap(u,v);
	int diff=dep[v]-dep[u];
	for(int i=0;i<MAX_LOG_N;i++){
		if(diff & (1<<i)) v=par[i][v];
	}
	if(u==v) return u;
	for(int i=MAX_LOG_N-1;i>=0;i--){
		if(par[i][u]!=par[i][v]){
			u=par[i][u];
			v=par[i][v];
		}
	}
	return par[0][u];
}

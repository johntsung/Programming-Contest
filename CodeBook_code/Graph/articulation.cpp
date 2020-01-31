const int MAX_V=10010;
int V,E;
vector<int> g[MAX_V];
int dfn[MAX_V],low[MAX_V],tot;
vector<pii> ans;

void dfs(int x,int fa){
	dfn[x]=low[x]=++tot;
	for(int i=0;i<g[x].size();i++){
		int v=g[x][i];
		if(v==fa) continue;
		if(!dfn[v]){
			dfs(v,x);
			low[x]=min(low[x],low[v]);
			if(low[v]>dfn[x]){
				ans.push_back({x,v});
			}
		}
		else{
			low[x]=min(low[x],dfn[v]);
		}
	}
}

void bcc_tarjan(){
	for(int i=0;i<V;i++){
		if(!dfn[i]) dfs(i,-1);
	}
}

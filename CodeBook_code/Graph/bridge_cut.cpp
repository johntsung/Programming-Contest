const int MAX_V=10010;
int V,E;
vector<int> g[MAX_V];
int dfn[MAX_V],low[MAX_V],tot,bccid[MAX_V],bcc_cnt;
bool cut[MAX_V];
stack<int> S;

void dfs(int x,int fa){
	int child=0;
	dfn[x]=low[x]=++tot;
	S.push(x);
	for(int i=0;i<(int)g[x].size();i++){
		int v=g[x][i];
		if(!dfn[v]){
			dfs(v,x);
			child++;
			low[x]=min(low[x],low[v]);
			if(low[v]>=dfn[x]){
				cut[x]=true;
				while(1){
					int u=S.top(); S.pop();
					bccid[x]=bcc_cnt;
					bcc_cnt++;
				}
			}
		}
		else if(dfn[v]<dfn[x] && v!=fa){
			low[x]=min(low[x],dfn[v]);
		}
	}
	if(fa==-1 && child<2) cut[x]=false;
}
void bcc_tarjan(){
	bcc_cnt=0;
	for(int i=0;i<V;i++){
		if(!dfn[i]) dfs(i,-1);
	}
}

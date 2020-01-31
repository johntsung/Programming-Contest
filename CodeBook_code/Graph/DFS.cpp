


bool visit[N];
void dfs(int u){
	if(visit[u]) return ;
	visit[u]=true;
	for(int v:graph[u]){
		dfs(v);
	}
}

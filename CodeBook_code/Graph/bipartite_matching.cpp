


int match[MAX_N+4];
bool used[MAX_N+4];
vector<int> edge[MAX_N+4];
int n,x,y,m;
bool dfs(int v){
	for(int u:edge[v]){
		if(used[u]) continue;
		used[u]=true;
		int temp=match[u];
		if(temp<0 || dfs(temp)){
			match[u]=v;
			return true;
		}
	}
	return false;
}
int bipartite_matching(){
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=0;i<x;i++){
		memset(used,false,sizeof(used));
		if(dfs(i)) ans++;
	}
	return ans;
}

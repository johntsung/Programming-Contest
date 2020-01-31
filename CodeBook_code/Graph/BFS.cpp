

void bfs(int s){
	bool visit[N];
	memset(visit,false,sizeof(visit));
	queue<int> q;
	q.push(s);
	visit[s]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:graph[u]){
			if(!visit[v]){
				visit[v]=true;
				q.push(v);
			}
		}
	}
}

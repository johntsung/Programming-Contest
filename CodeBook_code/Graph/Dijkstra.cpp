


int dis[N];
bool visit[N];
int dijkstra(int s,int t){
	memset(dis,0x3f3f3f3f.sizeof(dis));
	memset(visit,false,sizeof(visit));
	priority_queue<pii,vii,greater<pii> > pq;
	dis[s]=0;
	pq.push({dis[s],s});
	
	while(!pq.empty()){
		int u=pq.top().second; pq.pop();
		if(visit[u]) continue;
		visit[u]=true;
		for(auto e:g[u]){
			if(dis[e.u]+e.w<dis[e.v]){
				dis[e.v]=dis[e.u]+e.w;
				pq.push({dis[e.v],v});
			}
		}
	}

	return dis[t];
}

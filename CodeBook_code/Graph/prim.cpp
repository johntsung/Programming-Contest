


int prim(){
	int ans=0;
	bool used[n]={false};
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push(pii(0,0));

	while(!pq.empty()){
		pii vur = pq.top();
		pq.pop();

		int u=cur.second;
		if(used[u]) continue;
		ans+=cur.first;
		used[u]=true;
		for(int i=0;i<(int)g[u].size();i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(used[v]==false) pq.push(pii(w,v));
		}
	}
	return ans;
}

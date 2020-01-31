int diameter=0,radius[N],deg[N];
int findRadius(){
	queue<int> q; 
	for(int i=0;i<n;i++){
		if(deg[i]==1) q.push(i);
	}
	int mx=0;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int v:g[u]){
			deg[v]--;
			if(deg[v]==1){
				q.push(v);
				radius[v]=radius[u]+1;
				mx=max(mx,radius[v]);
			}
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(radius[i]==mx) cnt++;
	}
	diameter=max(diameter,mx*2+(cnt==2));
	return mx+(cnt==2);
}

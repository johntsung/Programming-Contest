int parent[N],childnum[N],value[N],nodenum[N];
int distance_tree(){
	queue<int> inque;
	memset(parent,-1,sizeof(parent));
	memset(childinum,0,sizeof(childnum));
	for(int i=2;i<=n;i++){
		scanf("%d",&parent[i]);
		childnum[parent[i]]++;
	}
	for(int i=2;i<=n;i++){
		scanf("%d",&value[i]);
	}
	for(int i=2;i<=n;i++){
		if(childnum[i]==1) inque.push(i);
	}
	for(int i=1;i<=n;i++) nodenum[i]=1;
	while(!inque.empty()){
		int u=inque.front();
		inque.pop();
		nodenum[parent[u]]+=nodenum[u];
		childnum[parent[u]]--;
		if(childnum[parent[u]]==0){
			inque.push(parent[u]);
		}
	}
	int ans=0;
	for(int i=2;i<=n;i++){
		ans+=(nodenum[1]-nodenum[i])*nodenum[i]*value[i];
	}
	return ans*2;
}

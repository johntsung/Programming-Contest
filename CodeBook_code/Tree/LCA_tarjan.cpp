struct Node{
	int v,ind;
};
int n,q;
int parent[MAX_N+4];
vector<int> edge[MAX_N+4];
vector<Node> ques[MAX_N+4];
bool visit[MAX_N+4];
UFDS uf;
int ans[MAX_N+4];
int LCA[MAX_N+4][MAX_N+4];
void tarjan(int u){
	if(visit[u]) return ;
	visit[u]=true;
	for(int v:edge[u]){
		tarjan(v);
		uf.Union(u,v);
	}
	for(Node v:ques[u]){
		if(visit[v.v]){
			ans[v.ind]=uf.Find(v.v);
		}
	}
}
int main(){
	int root;
	scanf("%d%d%d",&n,&q,&root);
	for(int i=0;i<n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i=0;i<q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		ques[u].push_back({v,i});
		ques[v].push_back({u,i});
	}
	uf.init(n,-1);
	tarjan(root);
	for(int i=0;i<q;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
}

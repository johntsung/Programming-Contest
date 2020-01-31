

int adj[N][N];
void Floyd_Warshall(){
	memset(adj,0x3f3f3f3f,sizeof(adj));
	for(int i=0;i<n;i++) adj[i][i]=0;
	// input the edge
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
			}
		}
	}
}


const int MAX_N=100;
int len[MAX_N+4];
int adj[MAX_N+4][MAX_N+4],vis[MAX_N+4][MAX_N+4];
int List[MAX_N+4][MAX_N+4];
int mc[MAX_N+4];
void dfs(int num){
	if(len[num]==0){
		if(num>ans){
			ans=num;
			found=true;
		}
		return ;
	}
	for(int k=0;k<len[num] && !found;k++){
		if(num_len[num]-k<=ans) break;
		int i=List[num][k];
		if(num+mc[i]<=ans) break;
		int j;
		for(int j=k+1,len[num+1]=0;j<len[num];j++){
			if(adj[i][List[num][j]]){
				List[num+1][len[num+1]++]=List[num][j];
			}
		}
		dfs(num+1);
	}
}
void max_clique(){
	mc[n]=ans=1;
	for(int i=n-1;i;i--){
		found=false;
		len[1]=0;
		for(int j=i+1;j<=n;j++){
			if(adj[i][j]) List[1][len[1]++]=j;
		}
		dfs(1);
		mc[i]=ans;
	}
}


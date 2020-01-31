

const MAX_N=10000;
const int INF=0x3f3f3f3f;
int N;
int dp[1<<MAX_N][MAX_N];
int TSP(){
	for(int S=0;S<(1<<N);S++){
		fill(dp[S],dp[S]+N,INF);
	}
	dp[(1<<N)-1][0]=0;
	for(int S=(1<<N)-2;S>=0;S--){
		for(int v=0;v<N;v++){
			for(int u=0;u<N;u++){
				if(!((S>>u)&1)){
					dp[S][v]=min(dp[S][v],dp[S | (1<<u)][u]+d[v][u]);
				}
			}
		}
	}
	return dp[0][0];
}

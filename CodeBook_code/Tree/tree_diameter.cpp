#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cstring>
using namespace std;

struct Edge{
	int v,w;
};
vector<Edge> edge[10010];
int dist[10010];
int bfs(int s){
	queue<int> q;
	memset(dist,-1,sizeof(dist));
	dist[s]=0;
	q.push(s);
	int maxi=0,ind=s;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=0;i<(int)edge[u].size();i++){
			Edge e=edge[u][i];
			if(dist[e.v]==-1){
				dist[e.v]=dist[u]+e.w;
				if(dist[e.v]>maxi){
					maxi=dist[e.v];
					ind=e.v;
				}
				q.push(e.v);
			}
		}
	}
	return ind;
}
int main(){
	int u,v,w;
	while(scanf("%d%d%d",&u,&v,&w)!=EOF){
		edge[u].push_back((Edge){v,w});
		edge[v].push_back((Edge){u,w});
	}
	printf("%d\n",dist[bfs(bfs(1))]);
}

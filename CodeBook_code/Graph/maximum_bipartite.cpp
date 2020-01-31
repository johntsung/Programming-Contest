#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int to,cap;
	int rev;
	Edge(int a,int b,int c){
		to=a;
		cap=b;
		rev=c;
	}
};
struct Point{
	int x,y,z;
};
const int INF=0x3f3f3f3f;
const int MAX_V=500+5;
vector<Edge> g[MAX_V];
int level[MAX_V];
int iter[MAX_V];
Point a[MAX_V],b[MAX_V];
inline void add_edge(int u,int v,int cap){
	g[u].push_back((Edge){v,cap,(int)g[v].size()});
	g[v].push_back((Edge){u,0,(int)g[u].size()-1});
}
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> q;
	level[s]=0;
	q.push(s);
	while(!q.empty()){
		int v=q.front(); q.pop();
		for(int i=0;i<(int)g[v].size();i++){
			const Edge& e=g[v][i];
			if(e.cap>0 && level[e.to]<0){
				level[e.to]=level[v]+1;
				q.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f){
	if(v==t) return f;
	for(int& i=iter[v];i<(int)g[v].size();i++){
		Edge& e=g[v][i];
		if(e.cap>0 && level[v]<level[e.to]){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				g[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	for(;;){
		bfs(s);
		if(level[t]<0) return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0){
			flow+=f;
		}
	}
}
int cost(Point a,Point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}
int main(){
	int ncase;
	scanf("%d",&ncase);
	while(ncase--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<MAX_V;i++) g[i].clear();
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		for(int i=0,j=n;i<n;i++,j++){
			scanf("%d%d%d",&a[j].x,&a[j].y,&a[j].z);
		}
		for(int i=0;i<n;i++){
			for(int j=n;j<2*n;j++){
				int w=cost(a[i],a[j]);
				add_edge(i,j,w);
				add_edge(j,i,w);
			}
		}
		for(int i=0;i<n;i++){
			add_edge(2*n,i,INF);
		}
		for(int i=n;i<2*n;i++){
			add_edge(i,2*n+1,INF);
		}
		fprintf(stderr,"ini\n");
		printf("%d\n",max_flow(2*n,2*n+1));
	}
}

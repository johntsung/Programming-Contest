#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define N 5010
#define M 50010
#define INF 0x3f3f3f3f
using namespace std;

struct Point{
	int x,y,z;
};
int n,m,ss,tt;
queue<int>q;
int dis[N],minv[N];
bool vis[N];
struct Edge{int to;int value;int cost;int next;}e[M<<1];
struct Pre{int id;int node;}pre[M<<1];
int head[N],cnt=-1;
Point a[510];
void add(int from,int to,int value,int cost)
{
    cnt++;
    e[cnt].to=to;
    e[cnt].value=value;
    e[cnt].cost=cost;
    e[cnt].next=head[from];
    head[from]=cnt;
}
bool spfa(int s,int t)
{
    q=queue<int>();
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(pre,-1,sizeof(pre));
    memset(minv,0x3f,sizeof(minv));
    dis[s]=0;
    vis[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x];i>-1;i=e[i].next)
        {
            int now=e[i].to;
            if(dis[now]>dis[x]+e[i].cost&&e[i].value)
            {
                dis[now]=dis[x]+e[i].cost;
                minv[now]=min(minv[x],e[i].value);
                pre[now].id=i;
                pre[now].node=x;
                if(!vis[now])
                {
                    vis[now]=1;
                    q.push(now);
                }
            }
        }
    }
    return dis[t]!=INF;
}
void MCMF(int s,int t,int &maxflow,int &mincost)
{
    while(spfa(s,t))
    {
        for(int i=t;i!=s;i=pre[i].node)
        {
            e[pre[i].id].value-=minv[t];
            e[pre[i].id^1].value+=minv[t];
        }
        maxflow+=minv[t];
        mincost+=minv[t]*dis[t];
    }
}
int disss(Point a,Point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}
int main()
{
    memset(head,-1,sizeof(head));
	scanf("%d",&n);
    //scanf("%d%d%d%d",&n,&m,&ss,&tt);
    for(int i=0;i<2*n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	for(int i=0;i<n;i++){
		for(int j=n;j<2*n;j++){
			int w=disss(a[i],a[j]);
			add(i,j,1,w);
			add(j,i,0,-w);
			//add(j,i,1,w);
			//add(i,j,0,-w);
		}
	}
	ss=2*n;
	tt=2*n+1;
	for(int i=0;i<n;i++){
		add(ss,i,0x3f3f3f3f,0);
		add(i+n,tt,0x3f3f3f3f,0);
	}
	int mf=0,mc=0;
    MCMF(ss,tt,mf,mc);
    printf("%d %d\n",mf,mc);
    return 0;
}

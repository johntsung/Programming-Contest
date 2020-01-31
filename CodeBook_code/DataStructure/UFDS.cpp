struct UFDS{
	int parent[N];
	void init(){
		memset(parent,-1,sizeof(parent));
	}
	int find(int x){
		return parent[x]<0?x:(parent[x]=find(parent[x]));
	}
	void Union(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y) return ;
		if(parent[x]>parent[y]) swap(x,y);
		parent[x]+=parent[y];
		parent[y]=x;
	}
};


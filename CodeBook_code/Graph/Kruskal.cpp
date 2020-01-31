

// include "Union Find - Disjoint Set"
int kruskal(){
	// m is the number of edge
	UFDS uf;
	uf.init();
	int ans=0;
	sort(edge,edge+m); // sorting by weighted.
	for(int i=0;i<m;i++){
		if(uf.find(edge[i].a)==uf.find(edge[i].b)){
			uf.Union(edge[i].a,edge[i].b);
			ans+=edge[i].w;
		}
	}
	return ans;
}

int dis[100100];
Inter inter[100100];
void SPOI(){
	sort(inter,inter+n,cmp); //sortint by left point
	inter[n].ll=inter[n-1].lr;
	inter[n]=0x3f3f3f3f;
	inter[n].w=0;
	n++;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push({0,0});
	for(int i=0;i<n;i++){
		while(!pq.empty() && pq.top().second<inter[i].ll){
			pq.pop();
		}
		dis[i]=pq.top().first;
		pq.push({dis[i]+inter[i].w,inter[i].lr});
	}
	return dis[n-1];
}

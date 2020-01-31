int FCFS(){
	int ll=0,lr=n,mid;
	while(lr-ll>1){
		bool flag=true;
		mid=(lr-ll)/2+ll;
		priority_queue<int,vector<int>,greater<int> > pq;
		for(int i=0;i<mid;i++){
			pq.push(0);
		}
		for(int i=0;i<n;i++){
			int k=pq.top(); pq.pop();
			if(k+a[i]>m){
				flag=false;
				break;
			}
			pq.push(k+a[i]);
		}
		if(flag) lr=mid;
		else ll=mid;
	}
	return lr;
}

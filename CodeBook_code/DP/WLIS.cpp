int solve(){
	map<int,int> mymp;
	mymp[-1]=0;
	mymp[a[0]]=w[0];
	for(int i=1;i<n;i++){
		auto ret=mymp.lower_bound(a[i]);
		auto ret2=ret;
		ret--;
		if(ret2==mymp.end()) mymp[a[i]]=ret->second+w[i];
		else if(ret->second+w[i]>ret2->second){
			while(ret->second+w[i]>ret2->second){
				mymp.erase(ret2->first);
				ret2=mymp.lower_bound(a[i]);
				if(ret2==mymp.end()) break;
			}
			mymp[a[i]]=ret->second+w[i];
		}
		else if(mymp.find(a[i])==mymp.end()){
			mymp[a[i]]=ret->second+w[i];
		}
	}
	return mymp.rbegin()->second;
}

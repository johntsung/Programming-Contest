struct inter{
	int L,R
}
int n;
inter a[200200];
int unweighted_independent_interval(){
	sort(a,a+n,cmp) //sorting by right point;
	int ans=1;
	int temp=a[0].R;
	for(int i=1;i<n;i++){
		if(a[i].L>=temp){
			temp=a[i].R;
			ans++;
		}
	}
	return ans;
}

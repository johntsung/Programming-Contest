inter a[200200];
int n;
int baby_sitter(){
	sort(a,a+n,cmp); //sorting by left point
	int temp=-1,maxi=-1,ans=0;
	for(int i=0;i<n;i++){
		if(a[i].L<=temp+1){
			if(a[i].R>maxi) maxi=a[i].R;
		}
		else{
			temp=maxi;
			maxi=a[i].R;
			ans++;
		}
		if(maxi==199) break;
	}
	return ans;
}

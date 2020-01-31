const int A,B,C; //dimension
int max1D(int a[]){
	int ans=-1e9;
	int s=0;
	for(int i=0;i<C;i++){
		if(s>=0) s+=a[i];
		else s=a[i];
		ans=max(ans,s);
	}
	return ans;
}
int max2D(int a[][C]){
	int ans=-1e9;
	int s[C];
	for(int i=0;i<B;i++){
		memset(s,0,sizeof(s));
		for(int j=i;j<B;j++){
			for(int k=0;k<C;k++){
				s[k]+=a[j][k];
			}
			ans=max(ans,max1D(s));
		}
	}
	return ans;
}
int max3D(int a[][B][C]){
	int ans=-1e9;
	int s[B][C];
	for(int i=0;i<A;i++){
		memset(s,0,sizeof(s));
		for(int j=i;j<A;j++){
			for(int k=0;k<B;k++){
				for(int l=0;k<C;l++){
					s[k][l]+=a[j][k][l];
				}
			}
			ans=max(ans,max2D(s));
		}
	}
	return ans;
}


int a[N],m[N],M;
int CRT(){
	M=1;
	for(int i=0;i<n;i++){
		M*=m[i];
	}
	int ans=0,x,y,d;
	for(int i=0;i<n;i++){
		Exgcd(M/m[i],m[i],d,x,y);
		while(x<0) x+=m[i];
		ans+=a[i]*x*(M/m[i]);
		ans%=M;
	}
	return ans;
}

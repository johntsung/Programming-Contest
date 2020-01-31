int binary(int x){
	int ll=0,lr=n,mid;
	while(lr-ll>1){
		mid=(lr-ll)/2+ll;
		if(mid>x) lr=x;
		else ll=x;
	}
	return lr;
}

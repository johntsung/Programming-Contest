lint binomialCoeff(lint n,lint k){
	lint res=1;
	if(k>n-k) k=n-k;
	for(int i=0;i<k;i++){
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}

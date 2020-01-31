lint fp(lint x,lint y,lint p){
	lint t=1;
	while(y){
		if(y&1){
			t*=x;
			t%=p;
		}
		x*=x;
		x%=p;
		y>>=1;
	}
	return t;
}

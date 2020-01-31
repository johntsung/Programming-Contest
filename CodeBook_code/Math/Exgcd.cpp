void Exgcd(lint a,lint b,lint &d,lint &x,lint &y){
	if(b==0){
		x=1;
		y=0;
		d=a;
		return ;
	}
	Exgcd(b,a%b,d,y,x);
	y-=a/b*x;
	return ;
}

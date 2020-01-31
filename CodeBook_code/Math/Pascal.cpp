#define N 210
lint c[N][N];

void Combination(){
	for(lint i=0;i<N;i++){
		c[i][0]=1;
		c[i][i]=1;
	}
	for(lint i=2;i<N;i++){
		for(lint j=1;j<=i;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%m;
		}
	}
}

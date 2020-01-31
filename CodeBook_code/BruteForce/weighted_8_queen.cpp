int weight[N][N];
int maxi,mini;
int column[N],slash[N],backslash[N+N];
void backtrack(int column[],int slash[],int backslash[],int queens[],int i,int weight){
	if(i>=n){
		maxi=max(maxi,weight);
		mini=min(mini,weight);
	}
	else{
		for(int j=0;j<n;j++){
			if(isvisitable(i,j,column,slash,backslash)){
				queens[i]=j;
				column[j]=slash[i+j]=backslash[i-j+n]=1;
				backtrack(column,slash,backslash,queens,i+1,weight+weighted[i][j]);
				cloumn[j]=slash[i+j]=backslash[i-j+n]=0;
			}
		}
	}
}
bool isvisitable(int i,int j,int column[],int slash[],int backslash[]){
	return !(column[j] || slash[i+j] || backslash[i-j+n]);
}
int queen_ans(){
	maxi=0;
	mini=0x3f3f3f3f;
	backtrack(column,slash,backslash,queens,0,0);
}

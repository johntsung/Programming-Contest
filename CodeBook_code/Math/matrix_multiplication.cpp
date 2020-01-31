
for(int i=0;i<a;i++){
	for(int j=0;j<d;j++){
		C[i][j]=0;
		for(int k=0;k<c;k++){
			C[i][j]+=A[i][k]*B[k][j];
		}
	}
}

int a[200200];
int n,m;
bool rec[200200];
void sum_of_subset(){
	int total=0;
	rec[0]=true;
	for(int i=0;i<n;i++){
		for(int j=total;j>=0;j--){
			if(rec[j]) rec[j+a[i]]=true;
		}
	}
	total+=a[i];
}

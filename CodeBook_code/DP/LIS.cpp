vector<int> LIS_list;
int LIS(){
	LIS_list.push_back(a[0]);
	for(int i=1;i<n;i++){
		if(a[i]>LIS_list.back()){
			LIS_list.push_back(a[i]);
		}
		else{
			*lower_bound(LIS_list.begin(),LIS_list.end(),a[i])=a[i];
		}
	}
	return (int)LIS_list.size();
}

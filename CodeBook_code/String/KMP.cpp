struct KMP_solution{
	vector<int> failure;
	void getfailure(string& needle){
		failure.assign(needle.size(),-1);
		for(int j=1;j<needle.size();j++){
			int i=failure[j-1];
			while((needle[j]!=needle[i+1]) && (i>=0)){
				i=failure[i];
			}
			if(needle[j]==needle[i+1]){
				failure[j]=i+1;
			}
		}
	}
	int KMP(string& haystack,string& needle){
		int i=0,j=0;
		while(i<haystack.size() && j<needle.size()){
			if(haystack[i]==needle[j]){
				i++;j++;
			}
			else{
				if(j==0) i++;
				else j=failure[j-1]+1
			}
		}
		if(j<needle.size()) return -1;
		else return i-needle.size();
	}
	int strStr(string haystack,string needle){
		getfailure(needle);
		return KMP(haystack,needle);
	}
};

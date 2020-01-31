int dp[504][504];
int LCS(string s,string t,int wrong,int connect,int gap){
	for(int i=0;i<=s.size();i++){
		dp[i][0]=gap*i;
	}
	for(int i=0;i<=t.size();i++){
		dp[0][i]=gap*i;
	}
	for(int i=0;i<(int)s.size();i++){
		for(int j=0;j<(int)t.size();j++){
			if(s[i]==t[j]){
				dp[i+1][j+1]=dp[i][j]+connect;
			}
			else{
				dp[i+1][j+1]=max(dp[i+1][j]+gap,dp[i][j+1]+gap);
				dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+connect);
			}
		}
	}
	return dp[s.size()][t.size()];
}

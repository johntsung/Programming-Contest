int dp[504][504];
int LCS(string s,string t){
	memset(dp,0,sizeof(dp));
	for(int i=0;i<(int)s.size();i++){
		for(int j=0;j<(int)t.size();j++){
			if(s[i]==t[j]) dp[i+1][j+1]=dp[i][j]+1;
			else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
		}
	}
	return dp[s.size()][t.size()];
}

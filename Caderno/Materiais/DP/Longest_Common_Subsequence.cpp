for(int i = 0; i <= N; i++) dp[i][0] = 0;
for(int i = 0; i <= M; i++) dp[0][i] = 0;
for(int i = 1; i <= N; i++) {
     for(int j = 1; j <= M; j++) {
         if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
          else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
}

int i = N, j = M;
string ans = "";
while(i > 0 && j > 0) {
     if(str1[i-1] == str2[j-1]) {
        ans += str1[i-1];
         i--, j--;
      }
     else {
          if(dp[i-1][j] > dp[i][j-1]) i--;
          else j--;
     }
}
reverse(ans.bb, ans.ee);
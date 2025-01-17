// basically we are taking LCS with the same string
// and are not considering when i==j
// thats it


#include <bits/stdc++.h>
using namespace std;

//must watch the video!

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if ( X[i - 1]==Y[j - 1] && i!=j )//just add a condition: element at ith posn should NOT be equal to jth posn, rest code is same as LCS
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else                           //this condition is NOT put in the else part, otherwise i==j wala part will never be considered
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

signed main() {
	string X; cin >> X;
	int n = X.length();

	cout << LCS(X, X, n, n) << endl;  // we take LCS with the same string itself
	return 0;
}
// https://www.geeksforgeeks.org/longest-repeating-subsequence/

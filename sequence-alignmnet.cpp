#include <bits/stdc++.h>

using namespace std;


void getMinimumPenalty(string x, string y, int pxy, int pgap)
{
	int i, j;
	int m = x.length();
	int n = y.length();

	int dp[n+m+1][n+m+1] = {0};

	for (i = 0; i <= (n+m); i++)
	{
		dp[i][0] = i * pgap;
		dp[0][i] = i * pgap;
	}


	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j] + pgap ,
								dp[i][j - 1] + pgap );
                dp[i][j] = min(dp[i - 1][j - 1] + pxy ,
                              dp[i][j]);
			}
		}
	}


	int l = n + m;
	i = m; j = n;

	int xpos = l;
	int ypos = l;

	int xans[l+1], yans[l+1];

	while ( !(i == 0 || j == 0))
	{
		if (x[i - 1] == y[j - 1])
		{
			xans[xpos--] = (int)x[i - 1];
			yans[ypos--] = (int)y[j - 1];
			i--; j--;
		}
		else if (dp[i - 1][j - 1] + pxy == dp[i][j])
		{
			xans[xpos--] = (int)x[i - 1];
			yans[ypos--] = (int)y[j - 1];
			i--; j--;
		}
		else if (dp[i - 1][j] + pgap == dp[i][j])
		{
			xans[xpos--] = (int)x[i - 1];
			yans[ypos--] = (int)'_';
			i--;
		}
		else if (dp[i][j - 1] + pgap == dp[i][j])
		{
			xans[xpos--] = (int)'_';
			yans[ypos--] = (int)y[j - 1];
			j--;
		}
	}
	while (xpos > 0)
	{
		if (i > 0) xans[xpos--] = (int)x[--i];
		else xans[xpos--] = (int)'_';
	}
	while (ypos > 0)
	{
		if (j > 0) yans[ypos--] = (int)y[--j];
		else yans[ypos--] = (int)'_';
	}


	int id = 1;
	for (i = l; i >= 1; i--)
	{
		if ((char)yans[i] == '_' && (char)xans[i] == '_')
		{
			id = i + 1;
			break;
		}
	}

    cout << "Minimum Penalty in aligning the Sequence = ";
	cout << dp[m][n] << "\n";
	cout << "The aligned sequence are :\n";
	for (i = id; i <= l; i++)
	{
		cout<<(char)xans[i];
	}
	cout << "\n";
	for (i = id; i <= l; i++)
	{
		cout << (char)yans[i];
	}
	return;
}


int main(){

	string gene1;
	string gene2;
	cout<<"Sequence 1: ";
	cin>>gene1;
	cout<<"Sequence 2: ";
	cin>>gene2;


	int misMatchPenalty = 3;
	int gapPenalty = 2;

	getMinimumPenalty(gene1, gene2,
    misMatchPenalty, gapPenalty);
	return 0;
}

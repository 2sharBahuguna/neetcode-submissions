class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int maxi=0;

        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;// If word2 is empty, remove all characters from word1
        }
        
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=j;// If word1 is empty, insert all characters of word2
        }


        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]; //nO EDIT NEEDED
                }
                else
                {
                    dp[i][j]=1+min({dp[i-1][j-1], // REPLACE
                                  dp[i][j-1],     //INSERT     
                                  dp[i-1][j]});    //DELETE
                }
            }
        }

        return dp[n][m];
    }
};

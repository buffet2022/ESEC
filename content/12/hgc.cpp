class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[25][25]={false};
        dp[0][0]=true;
        if(p.size()>=1&&p[1]=='*')dp[0][2]=true;
        for(int j=1;j<=p.size();j++)
        {
            if(p[j-1]=='*'&&dp[0][j-2]==true)dp[0][j]=true;//预处理dp[0][j]的情况
        }
        for(int i=1;i<=s.size();i++)
        {
            for(int j=1;j<=p.size();j++)
            {
                if(p[j-1]=='.')dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                {
                    if(p[j-2]=='.')//*前面有.时，只需要dp[k][j-2]（k<=i)存在匹配即可
                    {
                        for(int k=i;k>=0;k--)
                        {
                            if(dp[k][j-2]==true){dp[i][j]=true;break;}
                        }
                    }
                    if(dp[i][j-2]==true)//特殊处理为空的情况
                    {
                        dp[i][j]=true;continue;
                    }
                    for(int k=i;k>=0;k--)//要求k~i的所有字符为p[j-2]
                    {
                        if(dp[k][j-1]==true)
                        {
                            dp[i][j]=true;break;
                        }
                        if(k>=1)if(s[k-1]!=p[j-2])break;
                    }
                }
                else {
                    if(p[j-1]==s[i-1]&&dp[i-1][j-1]==true)dp[i][j]=true;
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
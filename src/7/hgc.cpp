class Solution {
public:
    int longestValidParentheses(string s) {
        int l=s.length();
        vector<int>vt(l,-1);
        for(int i=0;i<l;i++){
            if(s[i]==')'){
                int j=i;
                while(j>=1&&vt[j-1]!=-1){
                    j--;
                }
                if(j>=1&&s[j-1]=='('){
                    vt[i]=j-1;
                    vt[j-1]=i;
                }
            }
        }
        int t=0,ans=0;
        for(int i=0;i<l;i++){
            if(vt[i]!=-1){
                t++;
            }else {
                t=0;
            }
            ans=max(ans,t);
        }
        return ans;
    }
};
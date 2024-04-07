class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        //贪心配对
        int n=row.size();
        int hash[n];
        for(int i=0;i<n;i++){
            hash[row[i]]=i;
        }
        int ans=0;
        for(int i=0;i<n;i+=2){
            if(row[i+1]/2!=row[i]/2){
                swap(row[i+1],row[hash[row[i]+(row[i]%2==1?-1:1)]]);
                hash[row[hash[row[i]+(row[i]%2==1?-1:1)]]]=hash[row[i+1]];
                ans++;
            }
        }
        return ans;
    }
};
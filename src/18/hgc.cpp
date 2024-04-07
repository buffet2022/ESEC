class Solution {
public:
//1.按w从小到大排序
//2.如果w相同,按h从大到小排序
//3.[2,3] [5,4] [6,7] [6,4]
    int q[10010];
    int maxEnvelopes(vector<vector<int>>& e) {
        int n = e.size();
        sort(e.begin(),e.end(),[](vector<int>a,vector<int>b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        vector<int>q;
        for(int i = 0; i < n; i ++){
            int val = e[i][1];
            if(!q.size()||q.back()< val) q.push_back(val);
            else {
                int l = 0, r = q.size() - 1;
                while(l<r){
                    int mid = l + r >> 1;
                    if(q[mid]>=val) r = mid;
                    else l = mid + 1;
                }
                q[r] = min(q[r],val);
            }

        }
        return q.size();
    }
};

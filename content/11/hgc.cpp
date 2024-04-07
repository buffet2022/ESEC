class Solution {
public:
    void findF(unordered_map<string, string>& f, const string& a, string& root){
        root = a;
        while(root!=f[root])root = f[root];
    }
    void merge(unordered_map<string, string>& f, string a, string b){
        if(!f.count(a))f[a] = a;
        if(!f.count(b))f[b] = b;
        string fa, fb;
        findF(f, a, fa);
        findF(f, b, fb);
        if(fa==fb)return;
        int i=-1, j=-1;
        for(int k = 0; k < a.size(); k++){
            if(a[k]!=b[k]){
                if(i==-1)i=k;
                else if(j==-1)j=k;
                else return;
            }
        }
        if(i==-1||j==-1)return;
        if(a[i]==b[j]&&a[j]==b[i]){
            f[fb] = fa;
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        if(strs.size()==1)return 1;
        unordered_map<string, string> f;
        unordered_set<string> cnt;
        for(int i = 0; i < strs.size() - 1; i++){
            for(int j = i+1; j < strs.size(); j++)
                merge(f, strs[i], strs[j]);
        }
        string root;
        for(int i = 0; i < strs.size(); i++){
            findF(f, strs[i], root);
            cnt.insert(root);
        }
        return cnt.size();
    }
};
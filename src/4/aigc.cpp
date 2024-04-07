#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        unordered_map<char,int> m;
        for(int i=0,j=0;j<s.size();j++){
            m[s[j]]++;
            while(m[s[j]]>1) m[s[i++]]--;
            res=max(res,j-i+1);
        }
        return res;
    }
};
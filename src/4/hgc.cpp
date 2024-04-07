class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int max = 0;
        vector<int> vec;//无重复字符的容器
        for(char ch:s){
            int t = -1;
            for(int i = 0; i < vec.size(); i++){
                if(ch == vec[i]){
                    t = i;  //得到第一个重复的字符的位置
                    break;
                }
            }
            vec.push_back(ch);

            if(t != -1){    //在当前的最长子串中存在重复字符

                len = vec.size() - 1;
                max = max > len ? max : len;
                for(int i = 0; i < vec.size(); i++){
                    if(vec[i] != ch) vec.erase(vec.begin()+i);
                    else{
                        vec.erase(vec.begin()+i);
                        break;
                    }
                    i--;
                }
            }
        }
        len = vec.size();
        max = max > len ? max : len;

        return max;
    }
};
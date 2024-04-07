class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size()) return{};//s数组长度小于p数组长度，表示不存在结果。
        vector<int> sVec(26,0);//sVec用于在s数组上进行滑动
        vector<int> pVec(26,0);//pVec用于记录p数组每个字符个数
        //对sVec进行初始化，让sVec的有效长度和p数组长度相同，并统计p数组每个字符个数。
        //有效长度是指：在s上滑动的长度
        vector<int> res;//记录结果
        for(int i=0;i<p.size();++i)
        {
            sVec[s[i]-'a']++;
            pVec[p[i]-'a']++;
        }
        //窗口滑动过程
        int left=0,right=left+p.size()-1;//牢记：left指向固定大小窗口的最左边，right指向窗口的最右侧
        for(;right<s.size();)
        {
            if(sVec==pVec) res.emplace_back(left);//数组相同的话放入答案
            //数组不管是不是相等，都需要把左边界和右边界向右移动一位
            sVec[s[left]-'a']--;//移动之前要把原先的值去掉，因为移动之后，这个位置就不在判定长度内了
            left++;
            //上面两行代码合并Svec[s[left++]-'a']--;
            right++;
            if(right!=s.size())//当right处于最后一个位置时，right++之后就会越界，那么s[right]就会产生错误，需要判断一下。
            {
                sVec[s[right]-'a']++;//右边界移动之后，要把新的值加上去。为什么这里不需要把原先的值去掉？因为原先的值在移动后，仍然在判断范围内
                //上面两行代码合并 Svec[s[++right]-'a']++;
            }
        }
        return res;
    }
};

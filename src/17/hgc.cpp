class Solution {
public:
    vector<double> v1;//创建合并后的数组
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0;i < nums1.size();i++) //将nums1 录入 v1
        {
            v1.push_back(nums1[i]); // 尾插法
        }
        for(int i = 0;i < nums2.size();i++) //将nums2 录入 v1
        {
            v1.push_back(nums2[i]);
        }
        sort(v1.begin(),v1.end());  // v1进行排序

        if(v1.size()%2==0)    // 判读v1数组中的元素个数的奇偶
        {
            return (v1[v1.size()/2] + v1[v1.size()/2-1])/2;  //偶数返回
        }
        else
        {
            return v1[(v1.size()-1)/2];  //奇数返回
        }
    }
};

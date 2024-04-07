class Solution {
public:
    // 找到两个正序数组中第k小的数
    double findKth(std::vector<int>& nums1, int left1, int right1, std::vector<int>& nums2, int left2, int right2, int k) {
        if (left1 > right1) {
            return nums2[left2 + k - 1];
        }
        if (left2 > right2) {
            return nums1[left1 + k - 1];
        }
        if (k == 1) {
            return std::min(nums1[left1], nums2[left2]);
        }

        int numm = k / 2;
        int length1 = std::min(numm, right1 - left1 + 1);
        int length2 = std::min(numm, right2 - left2 + 1);

        if (nums1[left1 + length1 - 1] <= nums2[left2 + length2 - 1]) {
            return findKth(nums1, left1 + length1, right1, nums2, left2, right2, k - length1);
        } else {
            return findKth(nums1, left1, right1, nums2, left2 + length2, right2, k - length2);
        }
    }

    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;

        if (total % 2 == 1) {
            return findKth(nums1, 0, m - 1, nums2, 0, n - 1, total / 2 + 1);
        } else {
            return (findKth(nums1, 0, m - 1, nums2, 0, n - 1, total / 2) +
                    findKth(nums1, 0, m - 1, nums2, 0, n - 1, total / 2 + 1)) / 2.0;
        }
    }
};

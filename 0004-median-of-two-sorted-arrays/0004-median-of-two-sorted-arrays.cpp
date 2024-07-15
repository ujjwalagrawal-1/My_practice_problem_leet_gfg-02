class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int s = 0;
        int e = nums1.size();
        int cal = (nums1.size() + nums2.size() + 1) / 2;

        while (s <= e) {
            int mid1 = s + (e - s) / 2;
            int mid2 = cal - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int r1 = (mid1 == nums1.size()) ? INT_MAX : nums1[mid1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r2 = (mid2 == nums2.size()) ? INT_MAX : nums2[mid2];

            if (l1 <= r2 && l2 <= r1) {
                if ((nums1.size() + nums2.size()) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            } else if (l1 > r2) {
                e = mid1 - 1;
            } else {
                s = mid1 + 1;
            }
        }

        return 0.0;
    }
};

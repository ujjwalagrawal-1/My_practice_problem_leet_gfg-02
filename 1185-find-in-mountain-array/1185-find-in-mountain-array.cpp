// // /**
// //  * // This is the MountainArray's API interface.
// //  * // You should not implement it, or speculate about its implementation
// //  * class MountainArray {
// //  *   public:
// //  *     int get(int index);
// //  *     int length();
// //  * };
// //  */

// // class Solution {
// // public:

// // int find_pivot_in_array(MountainArray &mountainArr,int len){
// //     int s = 0;
// //     int e = len-1;
// //     int mid = s +(e-s)/2;
// //     int ans = -1;
// //     while(s<=e){
// //         int val = mountainArr.get(mid);
// //         if(mid-1 < len)
// //         int nextval = mountainArr.get(mid+1);
// //         if(mid+1 > 0)
// //         int prevval = mountainArr.get(mid-1);
// //         if(val > prevval && val < nextval){
// //             ans = mid;
// //             return ans;
// //         }
// //         else if(val < nextval && val > preval){
// //             ans = mid;
// //             s = mid+1;
// //         }
// //         else if(val < prevval && val > nextval){
// //             e = mid-1;
// //         }
// //         mid = s + (e - s)/2;
// //     }
// //     return ans;
// // }
// // int binarysearch(MountainArray &mountainArr,int target,int s,int e){
// //     // int s = len-1;
// //     int mid - s +(e-s)/2;
// //     int ans = -1;
// //     while(s<=e){
// //         int val = mountainArr.get(mid);
// //         if(val == target){
// //             return mid;
// //         }
// //         else if(val < target){
// //             ans = mid;
// //             s = mid-1;
// //         }
// //         else{
// //             e = mid+1;
// //         }
// //         mid = s + (e-s)/2;
// //     }
// //     return mid;
// // }
// //     int findInMountainArray(int target, MountainArray &mountainArr) {
// //     int len = mountainArr.length();
// //     int index = find_pivot_in_array(mountainArr,len);
// //     int ans1 = binarysearch(mountainArr,target,len-1,index + 1);
// //     int ans2 = binarysearch(mountainArr,target,0,index);
// //     if(ans1>=ans2){
// //         return ans2;
// //     }
// //     else{
// //         return ans1;
// //     }
    

// // };



// class Solution {
// public:
//     int findPeak(MountainArray &mountainArr, int left, int right) {
//         while (left < right) {
//             int mid = left + (right - left) / 2;
//             if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
//                 left = mid + 1;
//             } else {
//                 right = mid;
//             }
//         }
//         return left;
//     }

//     int find_pivot_in_array(MountainArray &mountainArr, int len, int target) {
//         int left = 0;
//         int right = len - 1;
//         int peak = findPeak(mountainArr, left, right);

//         int s = 0;
//         int e = peak;
//         int mid = s + (e - s) / 2;
//         int ans1 = -1;
//         while (s <= e) {
//             if (mountainArr.get(mid) == target) {
//                 ans1 = mid;
//                 break;
//             } else if (mountainArr.get(mid) > target) {
//                 e = mid - 1;
//             } else {
//                 s = mid + 1;
//             }
//             mid = s + (e - s) / 2;
//         }

//         int ans2 = -1; // Consistently initialize ans2
//         s = peak + 1; // Adjust the search range for the right subarray
//         e = len - 1;
//         mid = s + (e - s) / 2;
//         while (s <= e) {
//             if (mountainArr.get(mid) == target) {
//                 ans2 = mid;
//                 break;
//             } else if (mountainArr.get(mid) > target) {
//                 e = mid - 1;
//             } else {
//                 s = mid + 1;
//             }
//             mid = s + (e - s) / 2;
//         }

//         return (ans1 <= ans2) ? ans1 : ans2;
//     }

//     int findInMountainArray(int target, MountainArray &mountainArr) {
//         int len = mountainArr.length();
//         return find_pivot_in_array(mountainArr, len, target);
//     }
// };

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int length = mountainArr.length();

        // Find the index of the peak element in the mountain array.
        int peakIndex = findPeakIndex(1, length - 2, mountainArr);

        // Binary search for the target in the increasing part of the mountain array.
        int increasingIndex = binarySearch(0, peakIndex, target, mountainArr, false);
        if (mountainArr.get(increasingIndex) == target) 
            return increasingIndex; // Target found in the increasing part.

        // Binary search for the target in the decreasing part of the mountain array.
        int decreasingIndex = binarySearch(peakIndex + 1, length - 1, target, mountainArr, true);
        if (mountainArr.get(decreasingIndex) == target) 
            return decreasingIndex; // Target found in the decreasing part.

        return -1;  // Target not found in the mountain array.
    }

    int findPeakIndex(int low, int high, MountainArray &mountainArr) {
        while (low != high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1; // Move to the right side (increasing slope).
            } else {
                high = mid; // Move to the left side (decreasing slope).
            }
        }
        return low; // Return the index of the peak element.
    }

    int binarySearch(int low, int high, int target, MountainArray &mountainArr, bool reversed) {
        while (low != high) {
            int mid = low + (high - low) / 2;
            if (reversed) {
                if (mountainArr.get(mid) > target)
                    low = mid + 1; // Move to the right side for a decreasing slope.
                else
                    high = mid; // Move to the left side for an increasing slope.
            } else {
                if (mountainArr.get(mid) < target)
                    low = mid + 1; // Move to the right side for an increasing slope.
                else
                    high = mid; // Move to the left side for a decreasing slope.
            }
        }
        return low; // Return the index where the target should be or would be inserted.
    }
};

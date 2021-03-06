//Find Peak Element
//Tags: Array, Binary Search
/*A peak element is an element that is greater than its neighbors.
Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that num[-1] = num[n] = -∞.
For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

Note: Your solution should be in logarithmic complexity.
*/

// Standard
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 0;
        int l = 0, r = nums.size() - 1;
        if(nums[0] > nums[1]) return 0;
        if(nums[r] > nums[r-1]) return r;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            if(nums[mid] > nums[mid - 1]){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
    }
};

//Time: O(nlogn)

// More standard template. When we need access across the range, this is good.
// Key1: l + 1 < r.   Key2: r = mid or l = mid.   Key3: final compare
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return 0;
        int l = 0, r = nums.size()-1;
        while (l + 1 < r) {
            int mid = l + (r-l) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) 
                return mid;
            else if (nums[mid] < nums[mid-1]) {
                r = mid;
            }else{
                l = mid;
            }
        }
        return nums[l] > nums[r] ? l : r;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[mid] < nums[mid+1]){
                l = mid+1;
            }else{
                r = mid;
            }    
        }
        return l;
    }
};
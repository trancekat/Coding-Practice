// Contains Duplicate 
// Given an array of integers, find if the array contains any duplicates. Your function should 
// return true if any value appears at least twice in the array, and it should return false if 
// every element is distinct.


//Using set
//time: O(n), space: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) == s.end()){
                s.insert(nums[i]);
            }else{
                return true;
            }
        }
        return false;
    }
};

//Using hashmap
//time: O(n), space: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() <= 1) {return false;}
        map<int, int> IntMap;
        for(int i = 0; i < nums.size(); i++){
            if(IntMap.find(nums[i]) != IntMap.end()){
                return true;
            }
            IntMap[nums[i]] = i;
        }
        return false;
    }
};

//sort
//time: O(nlgn), space: O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2) return false;
        sort(nums.begin(), nums.end());
        for(int i = 1; i <nums.size(); ++i){
            if(nums[i-1] == nums[i]) return true;
        }
        return false;
    }
};

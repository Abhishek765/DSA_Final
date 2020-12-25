// ! Main functions
#include<bits/stdc++.h>
using namespace std;

int findPivotIndex(vector<int> a, int low, int high){
        
        while(low<=high){
            
            int mid = low + (high - low)/2;
            
            if(mid < high && a[mid] > a[mid+1])
                return mid;
            
            else if(mid > low && a[mid] < a[mid-1])
                return mid-1;
            
//             right side
            else if(a[mid] >= a[low])
                low = mid+1;
            else
                high = mid-1; 
        }
        
//         if not found
        return -1;
 
    }
    int findElementIndex(vector<int> a, int low, int high, int target){

        
        while(low<= high){
            int mid = low + (high -low)/2;
            
            if(a[mid] == target) return mid;
            
//             left side
            else if(a[mid] > target)
                high = mid-1;
            
            else 
               low = mid+1; 
        }
        
        return -1;
      
    }
    int search(vector<int>& nums, int target) {
        
//         finding the pivot element index
            int pivotIndex = findPivotIndex(nums,0,nums.size()-1);
        
//         if pivot not found array is already sorted
            if(pivotIndex == -1)
                return findElementIndex(nums,0,nums.size() - 1, target);
            
//            if target found at pivot 
            if(nums[pivotIndex] == target)
                return pivotIndex;
//             searching in right half of pivot
            if(target >= nums[0])
                    return findElementIndex(nums, 0, pivotIndex - 1, target);
            return findElementIndex(nums, pivotIndex + 1, nums.size()-1, target);

    }
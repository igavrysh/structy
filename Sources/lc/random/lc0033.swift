//
//  lc0033.swift
//  structy
//
//  Created by new on 5/21/26.
//

class lc0033 {
    func search(_ nums: [Int], _ target: Int) -> Int {
        var l = 0
        var r = nums.count - 1
        var result = -1
        
        while l <= r {
            let m = l + (r - l) / 2
            
            if nums[m] == target {
                result = m
                r = m - 1 // Continue searching in the left half for leftmost occurrence
            } else if nums[m] < target {
                l = m + 1
            } else {
                r = m - 1
            }
        }
        
        return result
    }
    
    // Alternative approach to find leftmost occurrence with the original rotation logic
    func searchRotated(_ nums: [Int], _ target: Int) -> Int {
        var l = 0
        var r = nums.count - 1
        var result = -1
        
        while l <= r {
            let m = l + (r - l) / 2
            
            if nums[m] == target {
                result = m
                r = m - 1 // Continue searching in the left half for leftmost occurrence
            } else if nums[l] <= nums[m] {
                // Left half is sorted
                if target >= nums[l] && target < nums[m] {
                    r = m - 1
                } else {
                    l = m + 1
                }
            } else {
                // Right half is sorted
                if target > nums[m] && target <= nums[r] {
                    l = m + 1
                } else {
                    r = m - 1
                }
            }
        }
        
        return result
    }
}

object BSearchRecursive {
    def search(nums: Array[Int], target: Int): Int = {
        return searchInternal(nums, target, 0, nums.length - 1)
    }
    
    def searchInternal(nums:Array[Int], target: Int, low: Int, high: Int): Int = {
        if(low <= high){
            val mid = low + ((high - low) >> 2)
            if(nums(mid) > target){
                searchInternal(nums, target, low, mid - 1)
            } else if (nums(mid) < target){                
                searchInternal(nums, target, mid + 1, high)
            } else {
                return mid
            }
        }else{
            return -1    
        }
    }
}

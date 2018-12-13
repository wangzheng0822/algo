object BSearch {
    def search(nums: Array[Int], target: Int): Int = {
        var low = 0
        var high = nums.length - 1
        while(low <= high){
            val mid = low + ((high - low) >> 2)
            if(nums(mid) > target){
                high = mid - 1
            } else if (nums(mid) < target){
                low = mid + 1
            } else {
                return mid
            }
        }
        
        return -1
    }
}

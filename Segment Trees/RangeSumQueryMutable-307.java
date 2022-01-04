// Given an integer array nums, handle multiple queries of the following types:

// Update the value of an element in nums.
// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// void update(int index, int val) Updates the value of nums[index] to be val.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

// Example 1:

// Input
// ["NumArray", "sumRange", "update", "sumRange"]
// [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
// Output
// [null, 9, null, 8]

// Explanation
// NumArray numArray = new NumArray([1, 3, 5]);
// numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
// numArray.update(1, 2);   // nums = [1, 2, 5]
// numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -100 <= nums[i] <= 100
// 0 <= index < nums.length
// -100 <= val <= 100
// 0 <= left <= right < nums.length
// At most 3 * 104 calls will be made to update and sumRange.

class NumArray {

     class SegmentTreeNode {
        int start, end;
        SegmentTreeNode left, right;
        int sum;

        public SegmentTreeNode(int start, int end) {
            this.start = start;
            this.end = end;
            this.left = null;
            this.right = null;
            this.sum = 0;
        }
    }
    
    SegmentTreeNode root = null; 
    
    public NumArray(int[] nums) {
        root = buildTree(nums, 0, nums.length - 1);
    }
    
    private SegmentTreeNode buildTree(int[] nums, int start, int end){
        if(start > end) return null;
        else {
            SegmentTreeNode node = new SegmentTreeNode(start, end);
            if(start == end)
                node.sum = nums[start];
            else{
                int mid = start + (end - start) / 2;
                node.left = buildTree(nums, start, mid);
                node.right = buildTree(nums, mid + 1, end);
                node.sum = node.left.sum + node.right.sum;
            }
            return node;
        }
    }
    
    public void update(int index, int val) {
        updateTree(root, index, val);
    }
    
    public void updateTree(SegmentTreeNode root, int pos, int val){
        if(root.start == root.end)
            root.sum = val;
        else{
            int mid = root.start + (root.end - root.start)/2;
            if(pos <= mid)
                updateTree(root.left, pos, val);
            else
                updateTree(root.right, pos, val);
            
            root.sum = root.left.sum + root.right.sum;
        }
    }
    
    public int sumRange(int left, int right) {
        return sumRangeHelper(root, left, right);
    }
    
    public int sumRangeHelper(SegmentTreeNode root, int start, int end){
        if(root.end == end && root.start == start)
            return root.sum;
        else{
            int mid = root.start + (root.end - root.start)/2;
            if(end <= mid)
                return sumRangeHelper(root.left, start, end);
            else if(start >= mid + 1)
                return sumRangeHelper(root.right, start, end);
            else
                return sumRangeHelper(root.left, start, mid) + sumRangeHelper(root.right, mid + 1, end);
        }
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
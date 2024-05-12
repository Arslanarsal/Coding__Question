class Solution {
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    isSumProperty(root) {
        if (!root || (!root.left && !root.right)) {
            return true;
        }
        
        let left = 0, right = 0;
        if (root.left) {
            left = root.left.data;
        }
        if (root.right) {
            right = root.right.data;
        }
        if (left + right !== root.data) {
            return false;
        }
        if (!(this.isSumProperty(root.left))) {
            return false;
        }
        if (!(this.isSumProperty(root.right))) {
            return false;
        }
        return true;
    }
}
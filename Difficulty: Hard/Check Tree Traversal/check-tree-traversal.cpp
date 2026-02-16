//Back-end complete function Template for C++
class Solution {
  public:
  
    bool solve(int preorder[], int inorder[], int postorder[],int preStart, int preEnd,int inStart, int inEnd,int postStart, int postEnd) {
        
        if(preStart > preEnd)
            return true;
        
        // Root check
        if(preorder[preStart] != postorder[postEnd])
            return false;
        
        int root = preorder[preStart];
        
        // Find root in inorder
        int pos = inStart;
        while(pos <= inEnd && inorder[pos] != root)
            pos++;
        
        if(pos > inEnd)
            return false;
        
        int leftSize = pos - inStart;
        
        // Check left subtree
        bool left = solve(preorder, inorder, postorder, preStart + 1,
                          preStart + leftSize, inStart, pos - 1,
                          postStart,postStart + leftSize - 1);
        
        // Check right subtree
        bool right = solve(preorder, inorder, postorder, preStart + leftSize + 1,
                           preEnd, pos + 1, inEnd,
                           postStart + leftSize,
                           postEnd - 1);
        
        return left && right;
    }
  
    bool checktree(int preorder[], int inorder[], int postorder[], int N) {
        
        return solve(preorder, inorder, postorder,0, N-1, 0, N-1, 0, N-1);
    }
};


//https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/
class Solution {
  public:
    int changeTree(Node *&node)
    {
        if(node==NULL) return 0;
        int temp=node->data;
        node->data=changeTree(node->left)+changeTree(node->right);
        return temp+node->data;
    }
    
    void toSumTree(Node *&node)
    {
        changeTree(node);
    }
};

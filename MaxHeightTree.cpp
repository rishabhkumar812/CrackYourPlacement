//https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1/?page=2&company[]=Walmart&query=page2company[]Walmart#
class Solution{
public:
    int height(int n){
        return (sqrt(1+8*n)-1)/2;
    }
};

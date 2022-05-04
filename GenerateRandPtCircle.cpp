//Concept of randomization, pdf, cdf and uniform distribution
//https://leetcode.com/problems/generate-random-point-in-a-circle/
//Proof - https://stackoverflow.com/questions/5837572/generate-a-random-point-within-a-circle-uniformly
class Solution {
public:
    double r, x, y;
    Solution(double R, double X, double Y):r(R),x(X),y(Y){}    
    vector<double> randPoint() 
    {
        double a=r*(sqrt((double)rand()/RAND_MAX));
        double b=2*M_PI*((double)rand()/RAND_MAX);
        if(a>r)
        cout<<a<<' '<<b<<endl;
        return {x+a*cos(b),y+a*sin(b)};
    }
};

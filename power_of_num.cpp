double power(double x, int n)
{
    if(n==0) return 1.0;
    if(n<0) {
        x = 1/x;
        n = -n;
    }
    if(n%2 == 0) {
        return power(x*x,n/2);
    } else {
        return x*power(x*x,n/2);
    }
    
}

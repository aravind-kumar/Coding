#include <iostream>
#include <limits>
#include <iomanip>

using std::cout;
using std::cin;
using std::numeric_limits;

int compare(const double& num1,const double& num2)
{
   double diff = (num1-num2)/num2;
   return (diff < -numeric_limits<double>::epsilon()) ? -1 :
	  (diff > numeric_limits<double>::epsilon());

}

double sqrt(double input)
{
    double low,high;
    if(compare(input,1.0) == -1)
    {
       low = input;
       high = 0.0;
    }
    else
    { 
        low = 0.0;
        high = input;
    }
    while(compare(low,high) == -1)
    {
       double mid = low + (high-low) * 0.5;
       if(compare(low,mid) == 1)
          low = mid;
       else if(compare(low,mid) == -1)
          high = mid;
       else
          return mid; 
    }
    return low;

}

int main()
{
  double num;
  cout<<"\n Enter the number for which sqrt is to be found";
  cin>>num;
  cout<<std::setprecision(20)<<std::fixed<<sqrt(num);
  return 0;
}

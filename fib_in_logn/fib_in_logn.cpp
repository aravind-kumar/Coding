#include <iostream>
#include <array>

typedef std::array<std::array<int,2>,2> twoDimenstionalArray;

twoDimenstionalArray multiply(const twoDimenstionalArray& A,
			      const twoDimenstionalArray& B)
{
  
   twoDimenstionalArray product;
   product[0][0] = (A[0][0] * B[0][0]) + (A[0][1] * B[1][0]);
   product[0][1] = (A[0][0] * B[0][1]) + (A[0][1] * B[1][1]);
   product[1][0] = (A[1][0] * B[0][0]) + (A[1][1] * B[1][0]);
   product[1][1] = (A[1][0] * B[0][1]) + (A[1][1] * B[1][1]);
   
   return product;
} 

twoDimenstionalArray pow(twoDimenstionalArray A,
			 unsigned int num)
{
   if (num==1)
   {
      return A;   
   }
 
   if (num & 1)
   {
      return multiply(A,pow(multiply(A,A),(num-1)/2)); 
   }
   else
   return pow(multiply(A,A),num/2);
   
}

void print2DArray(const twoDimenstionalArray& input)
{
   for(auto&& row : input)
   {
      for(auto&& elem : row)
         std::cout<<elem<<" ";
      std::cout<<"\n";
   }
}

int main()
{
  twoDimenstionalArray fib;
  fib[0] ={1,1};
  fib[1] ={1,0};
  fib = pow(fib,5); 
  print2DArray(fib); 
  return 0;
}

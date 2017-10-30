#include <iostream>
#include <vector>
#include <functional>


using std::cout;
using std::cin;
using std::vector;
using std::function;
 
typedef vector<vector<int>> twoDArray;


void printInSpiralOrder(const twoDArray& input)
{
   if(input.size())
   {
       int rowLow=0;
       int rowMax=input[0].size()-1;
       int colLow=0;
       int colMax=input.size()-1;
       int i=0;       
       while(rowLow <= rowMax 
	     &&
             colLow <= colMax)
       
       {
          for(i=colLow;i<=rowMax;++i)
             cout<<input[rowLow][i]<<" ";
          ++rowLow;

          cout<<"\n"; 

          for(i=rowLow;i<=colMax;++i)
             cout<<input[i][colMax]<<" ";
          --colMax;
          
          cout<<"\n"; 

          if(rowLow<=rowMax)
          {
            for(i=colMax;i>=colLow;--i)
 		cout<<input[rowMax][i]<<" ";
            --rowMax; 
          }

          cout<<"\n"; 

          if(colLow<=colMax)
          {
            for(i=rowMax;i>=rowLow;--i)
		cout<<input[i][colLow]<<" ";
             ++colLow;
          } 

          cout<<"\n";
       }
   }
}

void printNormalOrder(const twoDArray& input)
{
   for(int i=0;i<input.size();++i)
   {
       for(int j=0;j<input[i].size();++j)
           cout<<input[i][j];
       cout<<"\n";
   }
}

void print2DArray(const twoDArray&  input,function<void (twoDArray)> printFn)
{
    printFn(input);
}

int main()
{
  int num;
  twoDArray inputArray; 
  cout<<"\n Enter the number of rows and cols";
  cin>>num;
  inputArray.resize(num);
  cout<<"\n Enter the elements";
  for(int i=0;i<num;++i)
  {
      for(int j=0;j<num;++j)
      {
         int input;
         cin>>input;
         inputArray[i].push_back(input);
      }
  } 
  print2DArray(inputArray,printNormalOrder); 
  cout<<"--------------------------\n";
  print2DArray(inputArray,printInSpiralOrder);
  return 0;
}

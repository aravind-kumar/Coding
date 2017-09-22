#include <iostream>
#include <vector>
using namespace std;

void FillDiagnoals(vector<int>input,int Output[100][100])
{
   for(int i=0;i<input.size();++i)
   {
       Output[i][i] = input[i];
   }    
}

void PrintArray(int Output[100][100],
		int inputSize)
{
    for(int i=0;i<inputSize;++i)
    {
       for(int j=0;j<inputSize;++j)
       {
           cout<<Output[i][j]<<" ";
       }
       cout<<"\n";
    }
}

void getMaxSubArray(vector<int> input,
		   int Output[100][100])
{
  FillDiagnoals(input,Output);
  int ColumnNum = 1;
  for(int i=0,j=ColumnNum ; ColumnNum < input.size() ;)
  {
     Output[i][j] = Output[i][j-1] + Output[i+1][j];
     if(i+j >= input.size())
     {
        i=0;
        ++ColumnNum;
        j=ColumnNum;
     }
     else
     {
         ++i;
         j=i+1;
     }
  }
  PrintArray(Output,input.size());

}

int main()
{
   int sizeOfInput;
   vector<int> input;
   int Arr[100][100];

   cout<<"\n Enter the size of input less than 100";
   cin>>sizeOfInput;
   
   for(int i=0;i<sizeOfInput;++i)
   {
      int giveninput;
      cin>>giveninput;
      input.push_back(giveninput); 
   }
   
   getMaxSubArray(input,Arr);
   return 0;

}


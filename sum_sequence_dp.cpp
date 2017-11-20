#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<bool>>& input)
{
   cout<<"\n";
   for(auto&& rows : input)
   {
      for(auto&& element: rows)
         cout<<element<<" ";
      cout<<"\n";
   }
}

bool isValid(int index,int matrixLow,int matrixHigh)
{
    return index > matrixLow && index < matrixHigh;
}

bool doesSumExsist(vector<int> input,int sum)
{
  vector<vector<bool>> matrix(input.size()+1,(vector<bool>(sum+1,false)));
  for(int i=0;i<matrix.size();++i)
      matrix[i][0] = true;
  
  for(int i=1;i<=input.size();++i)
  {
      for(int j=1;j<=sum;++j)
      {
           if(j < input[i-1])
              matrix[i][j] = matrix[i-1][j];
           else
           matrix[i][j] = matrix[i-1][j] || matrix[i-1][j-input[i-1]];
      }
  }
  printMatrix(matrix);
  return matrix.back().back();
}

int main()
{
   int num;
   vector<int> input;
   cout<<"\n Enter the number of elements to in the array";
   cin>>num;
   for(int i=0;i<num;++i)
   {
     int givenNum;
     cin>>givenNum;
     input.push_back(givenNum);
   }
   cout<<"\n Enter the sum to check ";
   cin>>num;
   cout<<"\n Does the sum exsits in the array "<<((doesSumExsist(input,num))? "yes" : "no") ; 
   return 0;
}

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

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
       
        if(!matrix.empty()) {
            
            int rowLow = 0;
            int rowMax = matrix.size()-1; 
            int colLow = 0;
            int colMax = matrix.front().size()-1;
            
            while(rowLow <= rowMax 
                    &&
                 colLow <= colMax) {

                // Print the first row but we are iterating over the columns in doing so                
                for(int i=colLow;i<=colMax;++i) {
                    result.push_back(matrix[rowLow][i]);
                }

                // Print the last colum but we are iterating over the rows 
                for(int i=rowLow+1;i<=rowMax;++i) {
                    result.push_back(matrix[i][colMax]);
                }
               
                // Same as above but in reverse direction 
                if(rowLow<rowMax && colLow<colMax) {
                    for(int i=colMax-1;i>colLow;--i) {
                        result.push_back(matrix[rowMax][i]);
                    }
                    for(int i=rowMax;i>rowLow;--i) {
                        result.push_back(matrix[i][colLow]);
                    }
                }
                ++rowLow;
                --rowMax;
                ++colLow;
                --colMax;
            }
        }
        return result;

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

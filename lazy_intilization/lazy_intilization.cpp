#include <iostream>
#include <vector>


using std::cout;
using std::cin;
using std::vector;

template<typename T,size_t N>
class lazyArray
{
  private:
      vector<T> *input;
      vector<int> *to;
      vector<int> *from;
      unsigned int size;
  public:
      lazyArray(size_t n)
      {
        size=0;
        input = new vector<T>(n);
        to = new vector<T>(n);
        from = new vector<T>(n);
      }
      const bool isValid(const size_t& i) const 
      {
          return 0<= to[i] && to[i]<size && from[to[i]]==i;         
      }
      T& operator[](size_t n)
      {
         return isValid(n) ? input[n] : nullptr;
      } 
      
      const bool read(const size_t& i,T& val) const 
      {
           if(isValid(i))
           {
               val=input[i];
               return true;
           }
           return false;
      }
       
      void write(const size_t& i,const T& val)
      {
           if(!isValid(i))
           {
              from[size] = i;
              to[i]=size++;
           }
           input[i]=val;
      } 
};

int main()
{
  int n;
  cout<<"\n Enter the size of the array";
  cin>>n;
  

   return 0;
}

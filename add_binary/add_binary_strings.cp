#include <iostream>
#include <string>


string addBinary(string a, string b) {
        string result="";
        int i=a.length()-1;
        int j=b.length()-1;
        int carry = 0;
        while(i >= 0 || j >= 0 || carry)
        {
            
            int x = i>=0  ? a[i] - '0' : 0;
            int y = j>=0  ? b[j] - '0' : 0;
            
            int sum = x ^ y ^ carry;
            
            carry = (x & y) | (y & carry) | (x & carry);
            
            result+=to_string(sum);
            
            --i;
            --j;
            
        }
        reverse(result.begin(),result.end());
        return result;
    }


int main()
{
   string input1,input2;
   cout<<"\n Enter the string 1";
   cin>>input1;
   cout<<"\n Enter the string 2";
   cin>>input2;
   cout<<"\n The addition of the binary string are" <<addBinary(input1,input2);
   return 0;
}

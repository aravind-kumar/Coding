#include <iostream>
#include <algorithm>
#include <utility>

struct Interval
{
   int start;
   int end;
};

// The following program merges intervals which are overlapping into one single interval
vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        
        if(!intervals.empty()) {
            
            sort(intervals.begin(),intervals.end(),
                 [](Interval input1,Interval input2) 
                 {
                    return input1.start < input2.start; 
                 });
        
            result.emplace_back(intervals.front());
            
            for(int i=1;i<intervals.size();++i) {
                
                if(intervals.at(i).start > (result.back()).end) {
    
                    result.emplace_back(intervals.at(i));
                       
                }
                else
                    (result.back()).end = max(intervals.at(i).end,result.back().end);
                    
            }
        }
        return result;
}


int main()
{


   return 0;
}

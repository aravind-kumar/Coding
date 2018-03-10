class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        multiset<int> minHeap;
        multiset<int> maxHeap;
        
        for(auto num : nums) {
            
            if(minHeap.size()<3) {
                minHeap.insert(num);
            } else {
              auto minElement = *(minHeap.begin());
                if(num>(minElement)) {
                    minHeap.erase(minHeap.begin());
                    minHeap.insert(num);
                }  
            }
            
            if(maxHeap.size() < 2) {
                maxHeap.insert(num);
            } else {
                int maxElement = *(maxHeap.rbegin());
                if(num<maxElement) {
                    maxHeap.erase(maxHeap.find(maxElement));
                    maxHeap.insert(num);
                }
            }
        }
        
        int maxProd = accumulate(minHeap.begin(),minHeap.end(),1,multiplies<int>());
        int minProd = accumulate(maxHeap.begin(),maxHeap.end(),1,multiplies<int>());
        return max(maxProd,minProd*(*(minHeap.rbegin())));
        
    }
};


int main() {

    vector<int> nums;
    Solution s;    

}

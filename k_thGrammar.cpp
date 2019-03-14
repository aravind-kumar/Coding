class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N==1) return 0;
        if(K%2 == 0) 
            return 1-kthGrammar(N-1,(K+1)/2);
        else
            return kthGrammar(N-1,(K+1)/2);
        
    }
};

// The value at kth element depends upon the (K+1)/2 Parent node.
// If k is even then the result is 1-the parent value.
// If k is odd then the result is parentValue.

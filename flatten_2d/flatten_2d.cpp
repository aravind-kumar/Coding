#include <iostrea>
#include <vector>

class Vector2D {
    vector<vector<int>>::iterator row,rowEnd;
    vector<int>::iterator col,colEnd;
    bool isPresent;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        row = vec2d.begin();
        col = vec2d.front().begin();
        rowEnd = vec2d.end();
        colEnd = row->end(); 
 
    }

    int next() {
        
        if (row != rowEnd && col==colEnd) {
            ++row;
            col = row->begin();
            colEnd = row->end();
        }
        if(row != rowEnd && col!=colEnd) {
            int ans = *col;
            ++col;
            return ans;
        }
        return -1;
    }

    bool hasNext() {
       return (row != rowEnd-1 || col!=colEnd);
    }
};

int main() 
{

    return 0;
}

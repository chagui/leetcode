#include <algorithm>

using namespace std; // default on leetcode

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        const int areaABCD = (C - A) * (D - B);
        const int areaEFGH = (G - E) * (H - F);

        int intersectArea = 0;
        {
            const int blX = max(A, E), blY = max(B, F), trX = min(C, G), trY = min(D, H);
            if (blX < trX && blY < trY) {
                intersectArea = (trX - blX) * (trY - blY);
            }
        }

        return static_cast<long>(areaABCD) + areaEFGH - intersectArea;
    }
};

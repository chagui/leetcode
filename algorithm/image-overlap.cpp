class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        if (img1.size() == 1 && img1[0].size() == 1) return (img1[0][0] == 1 && img2[0][0] == 1) ? 1 : 0;
        const size_t size = img1.size();

        vector<int> permutations_overlap(8);
        const auto count_permutations_overlap = 
            [&permutations_overlap](vector<vector<int>>& img1,
               vector<vector<int>>& img2,
               int horizontal_offset,
               int vertical_offset)
        {
            permutations_overlap = {0, 0, 0, 0, 0, 0, 0, 0};
            for (int i = 0, io = vertical_offset; i < img1.size() - vertical_offset; ++i, ++io) {
                for (int j = 0, jo = horizontal_offset; j < img1.size() - horizontal_offset; ++j, ++jo) {
                    // move left
                    permutations_overlap[0] += (img1[i][jo] && img2[i][j]);
                    // move right
                    permutations_overlap[1] += (img1[i][j] && img2[i][jo]);
                    // move up
                    permutations_overlap[2] += (img1[io][j] && img2[i][j]);
                    // move down
                    permutations_overlap[3] += (img1[i][j] && img2[io][j]);
                    // move left-up
                    permutations_overlap[4] += (img1[io][jo] && img2[i][j]);
                    // move left-down
                    permutations_overlap[5] += (img1[i][jo] && img2[io][j]);
                    // move right-up
                    permutations_overlap[6] += (img1[io][j] && img2[i][jo]);
                    // move right-down
                    permutations_overlap[7] += (img1[i][j] && img2[io][jo]);
                }
            }
            return *max_element(permutations_overlap.cbegin(), permutations_overlap.cend());
        };

        int largest_overlap = 0;
        for (int vertical_offset = 0; vertical_offset < size; ++vertical_offset) {
            for (int horizontal_offset = 0; horizontal_offset < size; ++horizontal_offset) {
                // if the potential overlap is not big enough don't bother...
                if ((size - vertical_offset) * (size - horizontal_offset) < largest_overlap) {
                    // potential overlap will only get smaller so better break
                    break;
                }
                const int current_largest_overlap = count_permutations_overlap(img1, img2, vertical_offset, horizontal_offset);
                largest_overlap = max(largest_overlap, current_largest_overlap);
            }
        }
        return largest_overlap;
    }
};

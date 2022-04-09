#include <bitset>
#include <string>  // default on leetcode
#include <vector>

using namespace std;  // default on leetcode

namespace {
constexpr const size_t MAX_ROW_SIZE = 30;
}

class Solution {
 public:
  int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    return largestOverlapBitSet(img1, img2);
  }

  int largestOverlapBruteForce(vector<vector<int>>& img1,
                               vector<vector<int>>& img2) {
    if (img1.size() == 1 && img1[0].size() == 1)
      return (img1[0][0] == 1 && img2[0][0] == 1) ? 1 : 0;
    const size_t size = img1.size();

    vector<int> permutations_overlap(4);
    const auto count_permutations_overlap =
        [&permutations_overlap](vector<vector<int>>& img1,
                                vector<vector<int>>& img2,
                                int horizontal_offset, int vertical_offset) {
          permutations_overlap = {0, 0, 0, 0};
          for (int i = 0, io = vertical_offset;
               i < img1.size() - vertical_offset; ++i, ++io) {
            for (int j = 0, jo = horizontal_offset;
                 j < img1.size() - horizontal_offset; ++j, ++jo) {
              // move left-up
              permutations_overlap[0] += (img1[io][jo] && img2[i][j]);
              // move left-down
              permutations_overlap[1] += (img1[i][jo] && img2[io][j]);
              // move right-up
              permutations_overlap[2] += (img1[io][j] && img2[i][jo]);
              // move right-down
              permutations_overlap[3] += (img1[i][j] && img2[io][jo]);
            }
          }
          return *max_element(permutations_overlap.cbegin(),
                              permutations_overlap.cend());
        };

    int largest_overlap = 0;
    for (int vertical_offset = 0; vertical_offset < size; ++vertical_offset) {
      for (int horizontal_offset = 0; horizontal_offset < size;
           ++horizontal_offset) {
        // if the potential overlap is not big enough don't bother...
        if ((size - vertical_offset) * (size - horizontal_offset) <
            largest_overlap) {
          // potential overlap will only get smaller so better break
          break;
        }
        const int current_largest_overlap = count_permutations_overlap(
            img1, img2, vertical_offset, horizontal_offset);
        largest_overlap = max(largest_overlap, current_largest_overlap);
      }
    }
    return largest_overlap;
  }

  int largestOverlapBitSet(vector<vector<int>>& img1,
                           vector<vector<int>>& img2) {
    const size_t size = img1.size();
    vector<bitset<MAX_ROW_SIZE>> image1(MAX_ROW_SIZE), image2(MAX_ROW_SIZE);
    for (int row = 0; row < size; ++row) {
      for (int col = 0; col < size; ++col) {
        if (img1[row][col]) image1[row].set(col);
        if (img2[row][col]) image2[row].set(col);
      }
    }

    vector<int> permutations_overlap(4);
    const auto count_permutations_overlap =
        [size, &permutations_overlap, &image1, &image2](int horizontal_offset,
                                                        int vertical_offset) {
          permutations_overlap = {0, 0, 0, 0};
          for (int i = 0, io = vertical_offset; i < size - vertical_offset;
               ++i, ++io) {
            // move left-up
            permutations_overlap[0] +=
                ((image1[io] << horizontal_offset) & image2[i]).count();
            // move right-up
            permutations_overlap[1] +=
                ((image1[io] >> horizontal_offset) & image2[i]).count();
            // move right-down
            permutations_overlap[2] +=
                ((image1[i] >> horizontal_offset) & image2[io]).count();
            // move left-down
            permutations_overlap[3] +=
                ((image1[i] << horizontal_offset) & image2[io]).count();
          }
          return *max_element(permutations_overlap.cbegin(),
                              permutations_overlap.cend());
        };

    int largest_overlap = 0;
    for (int vertical_offset = 0; vertical_offset < size; ++vertical_offset) {
      for (int horizontal_offset = 0; horizontal_offset < size;
           ++horizontal_offset) {
        // if the potential overlap is not big enough break (it will only get
        // smaller)
        const int potential_overlap =
            (size - vertical_offset) * (size - horizontal_offset);
        if (potential_overlap < largest_overlap) break;

        const int current_largest_overlap =
            count_permutations_overlap(vertical_offset, horizontal_offset);
        largest_overlap = max(largest_overlap, current_largest_overlap);
      }
    }
    return largest_overlap;
  }
};

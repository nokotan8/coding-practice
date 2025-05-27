class Solution {
  public:
    int differenceOfSums(int n, int m) {
        int sum = (n * (n + 1)) / 2;
        int num_divis = n / m;
        return sum - num_divis * (num_divis + 1) * m;
    }
};

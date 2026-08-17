class Solution {
public:
    int count(int mid, vector<vector<int>>& matrix) {
        int n = matrix.size();
        int i = 0;
        int j = n - 1;
        int cnt = 0;
        while (i < n && j >= 0) {
            if (matrix[i][j] <= mid) {
                cnt += j + 1;
                i++;
            } else
                j--;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix[0].size();
        // apply binary search on answer
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int mid,cnt;
        while (low < high) {
            mid = low + (high - low)/2;
            cnt = count(mid, matrix);
            if (cnt < k)
                low = mid + 1;
            else
                high = mid; // not mid-1!
        }
        return low; // low == high == answer
    }
};
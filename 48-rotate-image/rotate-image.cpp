class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // first do transpose then reverse each row

        int n = matrix.size();

        // TRANSPOSE OF MATRIX
        for(int row=0; row < n; row++)
        {
            for(int col=0; col<=row; col++)
            {
                swap(matrix[row][col],matrix[col][row]);
            }
        }

        // REVERSE EACH ROW OF MATRIX
        for(int row=0; row<n; row++)
        {
            int left=0;
            int right=n-1;
            while(left < right)
            {
                swap(matrix[row][left],matrix[row][right]);
                left++;
                right--;
            }
        }
    }
};
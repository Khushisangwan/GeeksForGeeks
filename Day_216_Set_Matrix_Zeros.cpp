class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
          int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>original=mat;
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(original[row][col]==0){
                    for(int i=0;i<m;i++){
                        mat[row][i]=0;
                    }
                    for(int j=0;j<n;j++){
                        mat[j][col]=0;
                    }
                }
            }
        }
    }
};

class Solution {
  public:
    bool divby13(string &s) {
        int rem =0;
        for(char x : s){
            rem = (rem*10+(x-'0'))%13;
        }
        
        return rem==0;
    }
};
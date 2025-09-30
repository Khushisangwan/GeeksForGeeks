class Solution {
    public:
        vector<string> binstr(int n) {
                // code here
                vector<string> result;
                int total = 1 << n;  // Calculate 2^n - total number of binary strings possible

                // Iterate through all numbers from 0 to 2^n - 1
                for (int i = 0; i < total; i++) {
                        string s = bitset<20>(i).to_string(); // Convert number to 20-bit binary string
                        result.push_back(s.substr(20 - n));   // Extract last n bits and add to result
                }
                return result;
        }
};
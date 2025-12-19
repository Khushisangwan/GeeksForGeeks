
class Solution {
    public:
        int findMoves(vector<int>& chairs, vector<int>& passengers) {
                // Sort chairs in ascending order
                sort(chairs.begin(), chairs.end());
                // Sort passengers in ascending order
                sort(passengers.begin(), passengers.end());
                
                int res = 0;
                
                // Calculate total moves needed by matching each passenger to nearest chair
                for(int i = 0; i < chairs.size(); i++){
                        res += abs(chairs[i] - passengers[i]);
                }
                
                return res;
        }
};
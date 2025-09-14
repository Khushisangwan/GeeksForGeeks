#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int startStation(vector<int> &gas, vector<int> &cost) {
                // Get the number of gas stations
                int n = gas.size();
                int totalGas = 0, totalCost = 0;
                
                // Calculate total gas available and total cost required
                for (int i = 0; i < n; i++) {
                        totalGas += gas[i];
                        totalCost += cost[i];
                }
                
                // If total gas is less than total cost, it's impossible to complete the circuit
                if (totalGas < totalCost) return -1;
                
                // Initialize starting station and current tank fuel
                int start = 0, tank = 0;
                
                // Find the optimal starting station
                for (int i = 0; i < n; i++) {
                        // Add net fuel (gas gained minus cost to travel)
                        tank += gas[i] - cost[i];
                        
                        // If tank goes negative, we can't reach next station from current start
                        // Reset starting point to next station and reset tank
                        if (tank < 0) {
                                start = i + 1;
                                tank = 0;
                        }
                }
                
                // Return the starting station index
                return start;
        }
};
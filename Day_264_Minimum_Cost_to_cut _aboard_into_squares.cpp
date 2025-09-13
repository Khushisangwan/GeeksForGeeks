#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minCost(int n, int m, vector<int>& x, vector<int>& y) {
                // Create a max heap to store cuts with their costs and type (0 for vertical, 1 for horizontal)
                priority_queue<pair<int,int>>pq;
                
                // Add all vertical cuts (x array) to the priority queue with type 0
                for(auto it:x){
                        pq.push({it,0});
                }
                
                // Add all horizontal cuts (y array) to the priority queue with type 1
                for(auto it:y){
                        pq.push({it,1});
                }
                
                // Initialize counters: v = number of vertical pieces, h = number of horizontal pieces
                int v=1,h=1;
                int sum=0;
                
                // Process cuts in descending order of cost (greedy approach)
                while(!pq.empty()){
                        auto top=pq.top();
                        pq.pop();
                        int num=top.first;   // Cost of the cut
                        int axis=top.second; // Type of cut (0=vertical, 1=horizontal)
                        
                        // If it's a vertical cut
                        if(axis==0){
                                sum+=(num*v);  // Cost = cut_cost * number_of_vertical_pieces
                                h++;           // Increment horizontal pieces
                        }
                        // If it's a horizontal cut
                        else{
                                sum+=(num*h);  // Cost = cut_cost * number_of_horizontal_pieces
                                v++;           // Increment vertical pieces
                        }
                }
                return sum;
        }
};
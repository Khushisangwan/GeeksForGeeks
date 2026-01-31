#include<bits/stdc++.h>
using namespace std;

// Class to implement k queues in a single array
class kQueues {
    public:
    int cnt, nn;  // cnt: current number of elements, nn: total array size
    vector<queue<int>>vq;  // Vector of queues, one for each queue
    
        // Constructor: initialize k queues with max size n
        kQueues(int n, int k) {
                cnt=0; nn=n;
                vq.resize(k);
        }

        // Enqueue element x into queue i
        void enqueue(int x, int i) {
                vq[i].push(x);
                cnt++;
        }

        // Dequeue element from queue i
        int dequeue(int i) {
                if(vq[i].size()){
                        int xx=vq[i].front(); 
                        vq[i].pop();
                        cnt--; 
                        return xx;
                }
                return -1;  // Return -1 if queue is empty
        }

        // Check if queue i is empty
        bool isEmpty(int i) {
             return !vq[i].size();
        }

        // Check if all queues are full
        bool isFull() {
                return cnt==nn;
        }
};
class Solution {
public:
    static void rotateDeque(deque<int>& dq, int type, int k) {
        if (type == 1) {
            // Rotate right (last to front)
            while (k--) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        } else {
            // Rotate left (first to back)
            while (k--) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
};
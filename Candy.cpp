#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minCandy(vector<int> &arr) {
        int n=arr.size();
        int sum=1;
        int i=1;
        while(i<n){
        if(arr[i]==arr[i-1]){
            sum+=1;
            i++;
        }
        int peak=1;
        while(i<n&&arr[i]>arr[i-1]){
        peak+=1;
        sum+=peak;
        i++;
        }
        int down=1;
        while(i<n&&arr[i]<arr[i-1]){
        sum+=down;
        down++;
        i++;
        }
        if(down>peak){
            sum+=(down-peak);
        }
        }
        return sum;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //kitne ki kami hai
     int difict=0;
    // kitna extra hai
     int balance=0;
    //starting point
     int start=0; 
     for(int i=0;i<gas.size();i++){
        balance+=gas[i]-cost[i];
        if(balance<0){
            difict+=balance;
            start=i+1;
            balance=0;
        }
     } 
     if(balance+difict>=0) return start;
     return -1;
    }
};
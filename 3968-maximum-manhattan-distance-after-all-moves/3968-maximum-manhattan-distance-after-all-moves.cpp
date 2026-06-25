class Solution {
public:
    int maxDistance(string moves) {
     int cu=0;
     int cr=0;
     int c_=0;
    for(char ch:moves){
    if(ch=='U') cu++;
    else if(ch=='D') cu--;
  else if(ch=='L') cr--;
  else if(ch=='R') cr++;
  else c_++; 
    }
    
    return abs(cu)+abs(cr)+c_;;
    }
};
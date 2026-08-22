class Solution {
public:
    bool checkDivisibility(int n) {
    string str=to_string(n) ;
    int sum=0;
    int mul=1;
    for(char s:str){
        int x=s-'0';
        sum+=x;
        mul*=x;
    } 
    int tsum=sum+mul;
    if(n % tsum==0) return true;
    return false;
    }
};
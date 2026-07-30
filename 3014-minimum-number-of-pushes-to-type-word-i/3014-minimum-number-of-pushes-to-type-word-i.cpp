class Solution {
public:
    int minimumPushes(string word) {
    int n=word.size() ;
    int ans=0;
    if(n<=8) {
        ans=n;
    }
    else if(n>8 && n<=16){
    ans=8+(n-8)*2; 
    }
    else if(n>16&&n<=24){
     ans=24+(n-16)*3;
    }
    else{
        ans=48+4*(n-24);
    }
    return ans;
    }

};
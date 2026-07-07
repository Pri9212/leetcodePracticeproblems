class Solution {
public:
    long long sumAndMultiply(int n) {
     string st="" ;
     string s= to_string(n);
     long long sum=0;
     for(int i=0;i<s.size();i++)  {
        if(s[i]!='0'){
            sum+=(s[i]-'0');
            st+=s[i];
        }
     }
     if(sum==0) return 0;
     long long x=stoi(st);
     return sum*x;
    }
};
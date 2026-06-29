class Solution {
public:
    bool issubstring(string strs,string word){
    
      
       int res = word.find(strs);
	if (res != string::npos)
      	return true;
  	else
      	return false;

    }
    
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
       for(string str:patterns){
if(issubstring(str,word))count++;
       }
       return  count;
    }
};
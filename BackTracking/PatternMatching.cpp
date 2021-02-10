
#include <bits/stdc++.h>
using namespace std;


bool isWildCard(int i,int j, int patternLen,int strLen, string pattern, string str,vector<int> dp[]){
    
    // Base conditions
    // 1. when both crosses
     if(i == patternLen && j == strLen){
        return true;
    }
    
    
    // 2.  if i reach the end but j not
    if(j == strLen){
        for(int k=i;k<patternLen;k++){
            if(pattern[k] != '*')
                return false;
        }
        return true;
    }
    
     // 3. if pattern is complete
    if(i == patternLen){
        return false;
    }

        
    
    // if current character is not present in dp arr
   if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    // if pattern[j] is '?'
    if(pattern[i] == '?')
        return dp[i][j] = isWildCard(i+1,j+1,patternLen,strLen,pattern,str,dp);

        
    // if pattern[j] is '*'
    if(pattern[i] == '*'){
        return dp[i][j] = isWildCard(i+1,j,patternLen,strLen,pattern,str,dp) || isWildCard(i,j+1,patternLen,strLen,pattern,str,dp);
    }
    
    
    
    // if pattern[j] alphabet and not matched with str char
    if(pattern[i] != str[j])
        return dp[i][j] = false;

    return dp[i][j] = isWildCard(i+1,j+1,patternLen,strLen,pattern,str,dp);
    
}
/*You are required to complete this method*/
int wildCard(string pattern,string str)
{
    int patternLen = pattern.length();
    int strLen = str.length();
    
    vector<int> dp[patternLen];
    
    for(int i=0;i<patternLen;i++){
        for(int j=0;j<strLen;j++){
            dp[i].push_back(-1);
        }
    }
    
    return isWildCard(0,0, patternLen,strLen,pattern,str,dp);
}
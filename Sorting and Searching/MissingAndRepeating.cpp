int * findTwoElement(int *arr, int n) {
      int *ans=new int(2);
      long long int len = n;
      long long int sum = (len*(len+1))/2;
      long long int sum_sq = (len* (len+1) * (2*len + 1))/6;
      long long int missNum = 0,repeaNum = 0; 
      for(int i=0;i<n;i++){
          sum -= (long long int)arr[i];
          sum_sq -= ((long long int)arr[i]*(long long int)arr[i]);
      }
      
      missNum = (sum + sum_sq/sum)/2;
      repeaNum = missNum - sum;
      
      ans[0] = repeaNum;
      ans[1] = missNum;
      
        return ans;  
    }
#include<bits/stdc++.h>
  using  namespace std;


int solve(int idx,vector<int>& nums,int &prev_index,  vector<vector<int>> &dp){

        if(idx==nums.size()){

            return 0;
        }

        if(dp[idx][prev_index+1]!=-1){

            return dp[idx][prev_index+1];
        }

        //notake

        int op1=0+solve(idx+1,nums,prev_index,dp);

        //take

        int op2=0;

        if(prev_index==-1 || nums[idx]>nums[prev_index]){
              
              op2=1+solve(idx+1,nums,idx,dp);

        }

        return dp[idx][prev_index+1]=max(op1,op2);



        
    }
    int lengthOfLIS(vector<int>& nums) {
         
         int prev_index=-1;
         int n=nums.size();
         //N+1 SIZE WAS TAKEN BECAUSE WE HAVE ASSIGNED -1 prev_index AND DP INDEX  CANT BE NEGATIVE THEREORE WE HAVE DONE SHIFTING OF INDEX
         vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,nums,prev_index,dp);
        
    }
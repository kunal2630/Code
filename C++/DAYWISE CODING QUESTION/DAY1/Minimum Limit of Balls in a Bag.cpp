/*

You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.

*/

//THINK IN TERMS OF PENALTY


#include<bits/stdc++.h>
using  namespace std;
  

int minimumSize(vector<int>& nums, int maxOperations) {
        
        int max_penalty=INT_MIN;
        for(auto it:nums){

            max_penalty=max(max_penalty,it);
        }
        int ans=max_penalty;
        int s=1;
        int e=max_penalty;
        while(s<e){

            int curr_penalty=s+(e-s)/2;
            int operation=0;
            for(int i=0;i<nums.size();i++){

                if(nums[i]>curr_penalty){

                    if(nums[i]%curr_penalty==0){

                        operation +=((nums[i]/curr_penalty)-1);
                    }
                    else{

                        operation +=(nums[i]/curr_penalty);
                    }
                }
            }

            if(operation<=maxOperations){
                ans=curr_penalty;
                e=curr_penalty;
            }
            else{

                s=curr_penalty+1;

            }
        }

        return ans;

    }
 
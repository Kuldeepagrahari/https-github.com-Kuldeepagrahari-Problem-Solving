class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int maxi=0;
        int ans=0,c=0,sum=0;
        for(int i=0;i<colors.length()-1;i++){
            sum+=neededTime[i];
            if(colors[i]==colors[i+1]){
                maxi=max(maxi,neededTime[i]);
                c++;
            }
            else{
                  maxi=max(maxi,neededTime[i]);
                  ans+=maxi;
                  maxi=0;
                  c=0;
            }
        }
           maxi=max(maxi,neededTime[neededTime.size()-1]);
                  ans+=maxi; sum+=neededTime[neededTime.size()-1];
        return sum-ans;
    }
};
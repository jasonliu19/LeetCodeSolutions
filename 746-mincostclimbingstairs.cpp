class Solution {
public:
    int recurse(vector<int>& cost, int i, unordered_map<int, int>& cost_from_here){
        if(i + 2 >= cost.size()){
            return cost[i];
        }
        
        int cost1, cost2;
        if(cost_from_here.count(i+1)){
            cost1 = cost_from_here[i+1];
        } else{
            cost1 = recurse(cost, i +1, cost_from_here);
            cost_from_here[i+1] = cost1;
        }

        if(cost_from_here.count(i+2)){
            cost2 = cost_from_here[i+2];
        } else{
            cost2 = recurse(cost, i +2, cost_from_here);
            cost_from_here[i+2] = cost2;
        }
        
        if(cost1 < cost2){
            return cost[i] + cost1;
        } else {
            return cost[i] + cost2;
        }

    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int> *cost_from_here = new unordered_map<int, int>();
        int cost1 = recurse(cost, 0, *cost_from_here);
        int cost2 = recurse(cost, 1, *cost_from_here);
        
        return min(cost1, cost2);
    }
    
};

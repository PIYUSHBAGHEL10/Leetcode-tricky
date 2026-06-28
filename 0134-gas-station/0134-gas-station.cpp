class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, tank = 0, start = 0,delta;
        for (int i = 0; i < gas.size(); i++) {
            delta = gas[i] - cost[i];
            total += delta;
            tank += delta;

            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return (total >= 0) ? start : -1;
    }
};
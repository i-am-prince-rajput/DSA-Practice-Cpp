class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totgas = 0;
        int totcost = 0;

        for (auto i : gas) {
            totgas += i;
        }

        for (auto i : cost) {
            totcost += i;
        }

        if (totgas < totcost) {
            return -1;
        }

        int currgas = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {
            currgas = currgas + gas[i] - cost[i];

            if (currgas < 0) {
                start = i + 1;  
                currgas = 0;
            }
        }

        return start;
    }
};
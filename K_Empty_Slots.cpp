class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days;
        for(int i = 0; i < flowers.size(); i++) {
            days.push_back(0);
        }
        for(int i = 0; i < flowers.size(); i++) {
            days[flowers[i] - 1] = i + 1;
        }
        
        int leftPointer = 0;
        int rightPointer = leftPointer + k + 1;
        int flag = 0;
        int min = -1;
        while(rightPointer < days.size()) {
            for (int i = leftPointer + 1; i < rightPointer; i++) {
                if (days[i] < days[leftPointer] || days[i] < days[rightPointer]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                leftPointer++;
                rightPointer++;
                flag = 0;
                continue;
            }
            else {
                int currMin = days[leftPointer] < days[rightPointer] ? days[rightPointer] : days[leftPointer];
                if (currMin < min || min == -1) {
                    
                    min = currMin;
                    
                }
            }
            leftPointer++;
            rightPointer++;
        }
        
        return min;
    }
};
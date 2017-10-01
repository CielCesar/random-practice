class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        
        int count = 0;
        vector<char> myVector;
        for (auto it = S.rbegin(); it != S.rend(); it++) {
            if (*it == '-') {
                continue;
            }
            
            if (count == K) {
                myVector.push_back('-');
                count = 0;
            }
            
            if (*it <= 122 && *it >= 97) {
                myVector.push_back(*it - ('a' - 'A'));
            }
            else {
                myVector.push_back(*it);
            }
            
            count++;
            
        }
        char myCharArr[myVector.size()+1] = {'a'};
        int index = 0;
        for (auto it = myVector.rbegin(); it != myVector.rend(); it++) {
            myCharArr[index] = *it;
            index++;
        }
        myCharArr[myVector.size()] = '\0';
        
        return myCharArr;
    }
};
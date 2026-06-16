class Solution {
public:
    int calPoints(vector<string>& operations) {
        // if(operations.size() <= 1)
        int result = 0;

        vector<int> temp;

        for(string c : operations)
        {
            // int n = temp.size();
            if(c == "+")
            {
                temp.push_back(temp[temp.size()-1] + temp[temp.size()-2]);
            }
            else if(c == "D")
            {
                temp.push_back(2*temp.back());
            }
            else if(c == "C")
                temp.pop_back();
            else
            {
                temp.push_back(stoi(c));
            }
        }

        for(int t : temp)
            result += t;
        
        return result;
    }
};
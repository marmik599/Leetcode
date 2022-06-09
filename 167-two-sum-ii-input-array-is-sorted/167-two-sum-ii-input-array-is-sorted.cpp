class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
         int end=numbers.size()-1;
         int start=0;
            vector<int> result;
        while(start<=end)
        {
            if(numbers[start] + numbers[end] < target)
            {
                start++;
            }
            else if(numbers[start] + numbers[end] > target)
            {
                end--;
            }
            else
            {
                result.push_back(start+1);
                result.push_back(end+1);
                break;
            }
        }
        return result;
        
    }
};
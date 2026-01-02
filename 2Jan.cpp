class Solution {
private:
    bool solve(vector<int>& arr, int index, vector<bool>& visited)
    {
        if(index < 0 || index >= arr.size() || visited[index] == true)
            return false;
        if(arr[index] == 0)
            return true;

        visited[index] = true;
        
        bool right = solve(arr, index+arr[index], visited);
        if(right == true)
            return true;
        
        bool left = solve(arr, index-arr[index], visited);
        if(left == true)
            return true;
        
        return false;        
    }
public:
    bool canReach(vector<int>& arr, int start) 
    {
        vector<bool> visited(arr.size(), false);
        return solve(arr, start, visited);    
    }
};

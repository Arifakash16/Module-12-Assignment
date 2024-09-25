class Solution {
public:
    int maxDisjointIntervals(vector<vector<int>>& A) {
        //Sort the intervals based on the end times
        sort(A.begin(), A.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

      
        int count = 0; // To count the maximum disjoint intervals
        int lastEnd = INT_MIN; // To track the end of the last added interval

        //Iterate through sorted intervals
        for (auto& interval : A) {
            // If the current interval starts after the last added interval ends
            if (interval[0] > lastEnd) {
                count++; // Include this interval
                lastEnd = interval[1]; // Update the end of the last added interval
            }
        }

        return count; // Return the count of disjoint intervals
    }
};

// Time complexity: O(log(n))
// Space complexity: O(1);
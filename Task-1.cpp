class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        // Sort boxTypes based on number of units per box in descending order
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a,vector<int>& b) {
            return a[1] > b[1];
        });

        int totalUnits = 0;

        for (const auto& boxType : boxTypes) {
            // Determine the number of boxes to take
            int boxesToTake = min(boxType[0], truckSize);
            totalUnits += boxesToTake * boxType[1];
            truckSize -= boxesToTake;

            // If the truck is full, break out of the loop
            if (truckSize <= 0) {
                break;
            }
        }

        return totalUnits;
    }
};

// Time complexity: O(log(n))
// Space complexity: O(1);

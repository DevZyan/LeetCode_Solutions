/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//Function to find the two indices that sum up to the target
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result = (int*)malloc(2 * sizeof(int)); // Allocate memory to store the two indices

    // Loop through each element in the array
    for(int i = 0; i < numsSize; i++)
    {
        // Loop through the elements following the current element
        for (int j = i + 1; j < numsSize; j++)
        {
            // Check if the sum of the two elements equals the target
            if (nums[i]+nums[j] == target)
            {
                result[0] = i;  // Store the index of the first element
                result[1] = j;  // Store the index of the second element
                *returnSize = 2;// Indicate that two indices have been found
                return result;  // Return the array containing the two indices
            }
        }
    }

    *returnSize = 0;    // If no valid pair is found, set returnSize to 0 
    return NULL;        // Return NULL indicating no solution was found
}
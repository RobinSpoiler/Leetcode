#include <iostream>
#include <vector>

using namespace std;

// Nice try, still have a long way to go understaning out of bounds memory

int searchInsert(vector<int> &nums, int target)
{
    int r = nums.size() - 1; // Considering the last valid index
    int l = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    int mid = l + (r - l) / 2;
    cout << r << endl;

    // left will always be in bounds, no runtime error
    return l;
}

int main()
{
    vector<int> nums = {0, 1, 3, 5, 8, 9};
    vector<int> nums2 = {1, 3, 5, 6};
    vector<int> nums3 = {1, 3};
    cout << searchInsert(nums2, 0) << endl;
    return 0;
}
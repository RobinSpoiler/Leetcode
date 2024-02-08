#include <iostream>
#include <vector>

using namespace std;

// no era el approach correcto, muchas cosas para poco

int removeDuplicates(vector<int> &nums)
{
    int realUnique = 1;
    if (nums.size() == 1)
    {
        return realUnique;
    }
    int possUnique = nums[nums.size() - 1] - nums[0];
    for (int i = 0; i < possUnique; i++) // no tiene que se por todo quiza solo por el numero mas alto
                                         // del array aka el ultimo
    {
        int j = i + 1;
        if (j < nums.size() && nums[j] <= nums[i])
        {
            j++;
        }
    }
    nums.resize(realUnique);

    return realUnique;
}

//Los pointers no siempre se tienen que mover con mas loops
//Aguas con la memoria que todos los elementos sean accessibles
int removeDuplicatesLeetcode(vector<int> &nums)
{

    int j = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}

int main()
{
    vector<int> nums = {1, 1, 2};
    vector<int> nums2 = {1, 1, 2, 2, 2, 2};
    vector<int> nums3 = {1, 1, 2, 2, 3, 5, 6, 6, 7, 7, 7};
    vector<int> nums4 = {1, 1};
    vector<int> nums5 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums6 = {0, 0, 0, 0, 3};
    vector<int> nums7 = {-3, -1, 0, 0};
    vector<int> nums8 = {1};

    int k = removeDuplicatesLeetcode(nums8);
    for (int i = 0; i < k; i++)
    {
        cout << nums8[i] << " ";
    }
    // cout << removeDuplicates() << endl;
    // cout << removeDuplicates() << endl;
    return 0;
};
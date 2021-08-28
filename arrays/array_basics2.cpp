#include <iostream>
#include <queue>
using namespace std;

void changes(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = 10;
    }
}

int main()
{
    int nums[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
    // Before calling changes()
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    /* nums behaves like a pointer because it stores the adress of nums[0]. So if you 
    have passed it to other function as argument, then it is call by reference.*/
    changes(nums, n);
    cout <<"\n"<< nums << endl;
    // after calling changes()
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    // CONCLUSION
    /*So, if you don't want to make changes/modifications in original array, 
    then first decalare another array, copy the original array elements
    in it and then pass the other array as arguments of the function*/
    return 0;
}
#include <iostream>
#include<vector>
using namespace std;
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector <int> temp;
    int left= low;
    int right= mid+1;
    int i;
    while(left<=mid && right<=high)
    {
        if(arr[left]<= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right ++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for( int i= low; i<=high; i++)
    {
        arr[i]= temp[i-low];
    }
}

int mS(vector<int> &arr,int low, int high)
{
    if(low==high) return -1;
    int mid=(low+high)/2;
    mS(arr,low,mid);
    mS(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main()
{
    vector<int> arr = {15,5,24,8,1,3,16,10,20};
    vector <int> temp;
    int i;
    cout<<"Unsorted Array:"<<endl;
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    mS(arr,0,8);
    merge(arr,0,4,8);
    cout<<"\nSorted Array:"<<endl;
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}

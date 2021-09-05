#include<iostream>
using namespace std;

void InterpolationSearch(int a[],int low,int high,int key)
{
    int flag=0;
    while(low<=high)
    {
        int mid=low+(high-low)*((key-a[low])/(a[high]-a[low]));
        if(a[mid]==key)
        {
            flag=1;
            break;
        }
        if(a[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
    if(flag!=1)
    {
        cout<<"Element not found";
    }
    else
    {
        cout<<"Element found ";
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n],i,key;
    cout<<"Enter the elements: ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the element to find: ";
    cin>>key;
    InterpolationSearch(a,0,n,key);
    return 0;
}

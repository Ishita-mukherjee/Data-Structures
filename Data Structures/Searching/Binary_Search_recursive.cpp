#include<iostream>
using namespace std;

int binarySearch(int a[],int low,int high,int key)
{
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
        {
           return mid;
        }
        if(a[mid]<key)
            return binarySearch(a,mid+1,high,key);
        else
            return binarySearch(a,low,mid-1,key);
    }
   return -1;
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
    int flag=binarySearch(a,0,n,key);
    if(flag==-1)
        cout<<"Element not found";
    else
        cout<<"Element found at: "<<flag;
    return 0;
}

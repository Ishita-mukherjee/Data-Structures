#include<iostream>
using namespace std;

void LinearSearch(int a[],int n, int k)
{
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            flag=1;
            cout<<"Element found at: "<<i;
            break;
        }
    }
    if(flag==0)
        cout<<"Element not found";
}

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n],i,key;
    cout<<"Enter array elements: ";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the element to search: ";
    cin>>key;
    LinearSearch(a,n,key);
    return 0;
}

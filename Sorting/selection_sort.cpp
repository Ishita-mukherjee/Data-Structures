#include<iostream>
using namespace std;

void selection(int *a,int n)
{
    int i,j,temp,mini;
    for(i=0;i<n-1;i++)
    {
        mini=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[mini])
            {
                mini=j;
            }
        }
        temp=a[mini];
        a[mini]=a[i];
        a[i]=temp;
    }
    cout<<"\nThe sorted array: \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int n,i;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements: "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"The unsorted array is: ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    selection(a,n);
    return 0;
}


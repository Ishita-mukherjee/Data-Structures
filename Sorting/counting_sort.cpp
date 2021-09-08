#include<iostream>
using namespace std;

void countingSort(int *a,int n,int k)
{
    int c[k+1],b[n],i;
    for(i=0;i<=k;i++)
    {
        c[i]=0;
    }
    for(i=0;i<n;i++)
    {
        c[a[i]]=c[a[i]]+1;
    }
    for(i=1;i<k;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
    cout<<"\nThe sorted array: \n";
    for(i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
}
int main()
{
    int n,i;
    int maxi;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements: "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"The unsorted array is: ";
    maxi=a[0];
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
        maxi=max(a[i],maxi);
    }
    countingSort(a,n,maxi+1);
    return 0;
}


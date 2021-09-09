#include<iostream>
using namespace std;

void insertionSort(int *a,int n)
{
    int i,j,v;
    for(i=0;i<n;i++)
    {
        v = a[i];
        j=i;
        while((a[j-1]>v)&&(j>=1)) //Runs till previous element is greater or j=0
        {
            a[j]=a[j-1]; //Shifting till the previous element is smaller
            j--;
        }
        a[j]=v;
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
    insertionSort(a,n);
    return 0;
}

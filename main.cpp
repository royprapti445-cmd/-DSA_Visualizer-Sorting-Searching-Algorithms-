#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

vector<int> arr;
int comparisons=0,swapsCount=0;

void display()
{
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

void resetCount()
{
    comparisons=0;
    swapsCount=0;
}

void bubbleSort()
{
    resetCount();

    int n=arr.size();

    for(int i=0;i<n-1;i++)
    {
        cout<<"\nPass "<<i+1<<endl;

        for(int j=0;j<n-i-1;j++)
        {
            comparisons++;

            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapsCount++;

                display();
            }
        }
    }

    cout<<"\nComparisons: "<<comparisons;
    cout<<"\nSwaps: "<<swapsCount;
    cout<<"\nComplexity: O(n^2)\n";
}

void selectionSort()
{
    resetCount();

    int n=arr.size();

    for(int i=0;i<n-1;i++)
    {
        int min=i;

        for(int j=i+1;j<n;j++)
        {
            comparisons++;

            if(arr[j]<arr[min])
                min=j;
        }

        swap(arr[i],arr[min]);

        swapsCount++;

        display();
    }

    cout<<"\nComparisons:"<<comparisons;
    cout<<"\nSwaps:"<<swapsCount;
}

void insertionSort()
{
    resetCount();

    int n=arr.size();

    for(int i=1;i<n;i++)
    {
        int key=arr[i];

        int j=i-1;

        while(j>=0 && arr[j]>key)
        {
            comparisons++;

            arr[j+1]=arr[j];

            j--;

            swapsCount++;

            display();
        }

        arr[j+1]=key;
    }

    cout<<"\nComparisons:"<<comparisons;
    cout<<"\nSwaps:"<<swapsCount;
}

void merge(vector<int>&a,int l,int m,int r)
{
    vector<int> temp;

    int i=l;
    int j=m+1;

    while(i<=m && j<=r)
    {
        if(a[i]<a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while(i<=m)
        temp.push_back(a[i++]);

    while(j<=r)
        temp.push_back(a[j++]);

    for(int k=l;k<=r;k++)
        a[k]=temp[k-l];

    display();
}

void mergeSort(vector<int>&a,int l,int r)
{
    if(l>=r)
        return;

    int m=(l+r)/2;

    mergeSort(a,l,m);

    mergeSort(a,m+1,r);

    merge(a,l,m,r);
}

int partition(vector<int>&a,int low,int high)
{
    int pivot=a[high];

    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            i++;

            swap(a[i],a[j]);

            display();
        }
    }

    swap(a[i+1],a[high]);

    return i+1;
}

void quickSort(vector<int>&a,int low,int high)
{
    if(low<high)
    {
        int pi=partition(a,low,high);

        quickSort(a,low,pi-1);

        quickSort(a,pi+1,high);
    }
}

void linearSearch(int x)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<"Checking "<<arr[i]<<endl;

        if(arr[i]==x)
        {
            cout<<"Found at "<<i<<endl;
            return;
        }
    }

    cout<<"Not Found\n";
}

void binarySearch(int x)
{
    int low=0;
    int high=arr.size()-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        cout<<"Low:"<<low
        <<" Mid:"<<mid
        <<" High:"<<high<<endl;

        if(arr[mid]==x)
        {
            cout<<"Found\n";
            return;
        }

        else if(arr[mid]<x)
            low=mid+1;

        else
            high=mid-1;
    }

    cout<<"Not Found\n";
}

int main()
{
    srand(time(0));

    int n;

    cout<<"Enter size:";

    cin>>n;

    arr.resize(n);

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int ch;

    while(true)
    {
        cout<<"\n1 Bubble";
        cout<<"\n2 Selection";
        cout<<"\n3 Insertion";
        cout<<"\n4 Merge";
        cout<<"\n5 Quick";
        cout<<"\n6 Linear Search";
        cout<<"\n7 Binary Search";
        cout<<"\n8 Random Array";
        cout<<"\n0 Exit\n";

        cin>>ch;

        switch(ch)
        {
            case 1:
                bubbleSort();
                break;

            case 2:
                selectionSort();
                break;

            case 3:
                insertionSort();
                break;

            case 4:
                mergeSort(arr,0,n-1);
                display();
                break;

            case 5:
                quickSort(arr,0,n-1);
                display();
                break;

            case 6:
            {
                int x;

                cin>>x;

                linearSearch(x);

                break;
            }

            case 7:
            {
                int x;

                cin>>x;

                binarySearch(x);

                break;
            }

            case 8:
            {
                for(int i=0;i<n;i++)
                    arr[i]=rand()%100;

                display();

                break;
            }

            case 0:
                return 0;
        }
    }
}

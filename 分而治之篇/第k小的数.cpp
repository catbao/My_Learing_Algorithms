#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10002];
int partition(int *a,int left,int right){   //根据快速排序的思想
    int x=a[left];
    while(left<right){
        while(left<right&&a[right]>=x){
            right--;
        }
        a[left]=a[right];
        while(left<right&&a[left]<=x){
            left++;
        }
        a[right]=a[left];
    }
    a[left]=x;
    return left;
}

void find(int *a,int left, int right,int k){
    int temp=partition(a,left,right);
    if(k-1==temp){
        cout<<a[k-1];
    }
    else if(k-1>temp){
        find(a,temp+1,right,k);
    }
    else{
        find(a,left,temp-1,k);
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    find(a,0,n-1,k);
    system("pause");
    return 0;
}
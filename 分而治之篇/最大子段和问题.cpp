#include<cstdio>
#include<iostream>
#include<limits.h>
using namespace std;

int Max2(int a,int b){
    if(a>=b) return a;
    if(b>=a) return b;
}

int CrossingSubArray(int *a,int low,int mid,int high){
    int sum=0;
    int left=INT_MIN;  //等于负无穷
    for(int l=mid;l>=low;--l){
        sum+=a[l];
        left=Max2(left,sum);
    }
    sum=0;
    int right=INT_MIN;
    for(int r=mid+1;r<=high;r++){
        sum+=a[r];
        right=Max2(sum,right);
    }
    int s3=left+right;
    return s3;
}

int Max(int a,int b,int c){
    if(a>=b&&a>=c) return a;
    if(b>=a&&b>=c) return b;
    if(c>=b&&c>=a) return c;
}

int MaxSubArray(int *a,int low,int high){
    if(low==high){
        return a[high];
    }
    else{
        int mid=(low+high)/2;                  //拆分原问题
        int s1=MaxSubArray(a,low,mid);
        int s2=MaxSubArray(a,mid+1,high);      //求解子问题
        int s3=CrossingSubArray(a,low,mid,high);  //合并问题解
        int s=Max(s1,s2,s3);
        return s;
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    int flag=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(a[i]>0){
            flag=1;
        }
    }
    if(flag==1){
        int low=0;
        int high=n-1;
        int max=MaxSubArray(a,low,high);
        cout<<max;
    }
    else{
        cout<<"0";
    }
    system("pause");
    return 0;
}

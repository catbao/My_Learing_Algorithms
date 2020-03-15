#include<cstdio>
#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int sum=0;
int b[1002];
void MergeCount(int *a,int low,int mid,int high){   //归并求解
    int i=low,j=mid+1,k=low;
    while(i<=mid&&j<=high){            //b数组存放排好序的元素，a[i]和a[j]从起点和中间
        if(a[i]<=a[j]){                //向右扫描，如果a[i]<=a[j],无逆序对，直接加入；
            //b.push_back(a[i]);       //
            b[k++]=a[i];
            i++;
        }
        else{                          //否则有逆序对，且个数为mid-i+1,就是左半边数组
            b[k++]=a[j];               //剩下的那些元素。最后得到sum值即为所求。
            sum+=mid-i+1;
            j++;
        }
    }
    if(i<=mid){                        //加入剩余元素
        for(i;i<=mid;++i){
            //b.push_back(a[i]);
            b[k++]=a[i];
        }
    }
    else if(j<=high){
        for(j;j<=high;++j){
            //b.push_back(a[j]);
            b[k++]=a[j];
        }
    }
}

void Count(int *a,int low,int high){
    if(low<high){
        int mid=(low+high)/2;        //拆分原问题
        Count(a,low,mid);
        Count(a,mid+1,high);         //求解子问题
        MergeCount(a,low,mid,high);  //合并问题解
        for(int i=low;i<=high;++i){   //将排好序的b数组送至a数组，在后面计算的时候a
            a[i]=b[i];                //数组就是有序的了。
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    Count(a,0,n-1);
    cout<<sum;
    system("pause");
    return 0;
}

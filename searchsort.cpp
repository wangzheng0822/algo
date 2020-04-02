#include<iostream>
using namespace std;

void searchsort(int A[],int n)
{
    int i,j,low,high,mid;
    for(i=1;i<=n;i++)
    {
        int temp=A[i];
        low=0,high=i-1;
        while(low<=high){
            mid=(low+high)/2;
            if(A[mid]>temp)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        for(j=i-1;j>=high+1;--j){
            A[j+1]=A[j];
        }
        A[high+1]=temp;
    }

    for(int k=0;k<n;k++){
        cout<<A[k]<<endl;
    }
}

int main(){
    int A[9]={9,0,4,3,6,5,8,1,2};
    searchsort(A,9);
    return 0;
}
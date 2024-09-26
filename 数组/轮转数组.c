#include <stdio.h>
void rotate(int* nums, int numsSize, int k){
    k=k%numsSize;
    int temp;
    while(k--)
    {
        temp=nums[numsSize-1];
        for(int i=numsSize-1;i>0;i--)
        {
            nums[i]=nums[i-1];
        }
        nums[0]=temp;
    }
}
int main(){
    int nums[100],n,i,k;
    scanf("%d",&n);
    for(i=0;i<n;++i)
        scanf("%d",&nums[i]);
    scanf("%d",&k);
    rotate(nums,n,k);
    for(i=0;i<n;++i)
        printf("%d ",nums[i]);
    return 0;
}
/*
//高级做法
#include <stdio.h>
void reverse(int *nums,int left,int right)
{
    while(left<right)
    {
        int tmp =nums[left];
        nums[left]=nums[right];
        nums[right]=tmp;
        left++;
        right--;
    }
}
void rotate(int* nums, int numsSize, int k){
    k%=numsSize;
    if(!k)
        return;
    reverse(nums,numsSize-k,numsSize-1);
    reverse(nums,0,numsSize-k-1);
    reverse(nums,0,numsSize-1);
}
int main(){
    int nums[100],n,i,k;
    scanf("%d",&n);
    for(i=0;i<n;++i)
        scanf("%d",&nums[i]);
    scanf("%d",&k);
    rotate(nums,n,k);
    for(i=0;i<n;++i)
        printf("%d ",nums[i]);
    return 0;
}
*/
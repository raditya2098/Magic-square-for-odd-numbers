#include <stdio.h>
#include <math.h>
int sub_i(int m,int max)
{
  int i;
  i=m-1;
  if(i<1)
    i=max;
  return i;
}
int sub_j(int m,int max)
{
  int j;
  j=m+1;
  if(j>max)
    j=1;
  return j;
}

  
int main()
{
  int i,n,n2,j;
  printf("Enter number:\t");
  scanf("%d",&n);
  int a[n][n],sum=0,mid_p,mid_v,pos_i,pos_j;
  n2=pow(n,2);
  for(i=1;i<=n2;i++)
  	sum+=i;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      a[i][j]=0;
  mid_v=(n2/2)+1;
  sum/=n;
  mid_p=(n/2)+1;
  a[mid_p][mid_p]=mid_v;
  a[1][mid_p]=1;
  pos_i=1;
  pos_j=mid_p;
  int count=1,new_i,new_j;
  while(count!=(mid_v-1))
  	{
    new_i=sub_i(pos_i,n);
    new_j=sub_j(pos_j,n);
    if(a[new_i][new_j]!=0)
    	{new_i=pos_i+1;
         new_j=pos_j;
        }
    a[new_i][new_j]=++count;
    pos_i=new_i;
    pos_j=new_j;
  }
  n2+=1;
  for(i=1;i<=n;i++)
  	{for(j=1;j<=n;j++)
    	{if(a[i][j]==0)
        	{a[i][j]=n2-a[n-i+1][n-j+1];
            }
        }
    }
  for(i=1;i<=n;i++)
  	{for(j=1;j<=n;j++)
    	{printf("%d  ",a[i][j]);
        }printf("\n");
    }
	return 0;
}

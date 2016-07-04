#include<iostream>
#include<cmath>
#define INT_MAX 9999//~(1<<(sizeof(int)*8-1))
using namespace std;

void MERGE(int *array, int p, int q, int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int *L=new int[n1+1];
    int *R=new int[n2+1];
    for(int i=0;i!=n1;++i)
    {
	L[i]=*(array+p+i);
    }
    for(int i=0;i!=n2;++i)
    {
	R[i]=*(array+q+1+i);
    }
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    for(int k=p,i=0,j=0;k!=r+1;++k)
    {
		if(L[i]<=R[j])
		{
			*(array+k)=L[i];
			++i;
		}
		else
		{
			*(array+k)=R[j];
			++j;
		}
    }
	delete [] L;
	delete [] R;
}

void MERGE_SORT(int *array, int p, int r)
{
    if(p<r)
    {
	int q=floor((p+r)/2);
	MERGE_SORT(array,p,q);
	MERGE_SORT(array,q+1,r);
	MERGE(array,p,q,r);
    }
}
int main()
{
    int Num[10]={8,12,3,4,1,23,11,9,24,31};
    MERGE_SORT(Num,0,9);
    for(int i=0;i!=10;++i)
    {
	cout<<Num[i]<<"\t"<<flush;
    }
	cin.get();
    return 0;
}

#include<iostream>
#include<cmath>
#define SIZE 10
//#define INT_MAX (~(1<<(sizeof(int)*8-1)))
using namespace std;

void MERGE(int *array, int p, int q, int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int *L=new int[n1];
    int *R=new int[n2];
    for(int i=0;i!=n1;++i)
    {
	L[i]=*(array+p+i);
    }
    for(i=0;i!=n2;++i)
    {
	R[i]=*(array+q+1+i);
    }
    i=0;
	int j=0, k=p;
    while((i!=n1)&&(j!=n2))
    {
		if(L[i]<=R[j])
		{
			*(array+k)=L[i];
			++i;
			++k;
		}
		else
		{
			*(array+k)=R[j];
			++j;
			++k;
		}
    }
    while(i!=n1)
    {
	*(array+k)=L[i];
	++i;
	++k;
    }   
    while(j!=n2)
    {
	*(array+k)=R[j];
	++j;
	++k;
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
    int Num[SIZE]={18,12,9,12,56,23,45,7,9,2};
    MERGE_SORT(Num,0,SIZE-1);
    for(int i=0;i!=SIZE;++i)
    {
	cout<<Num[i]<<"\t"<<flush;
    }
	cin.get();
    return 0;
}

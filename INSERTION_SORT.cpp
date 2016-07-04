#include<iostream>
#include<cstdio>
using namespace std;

void INSERTION_SORT(int *array, int size)
{
    int key;
    for(int i=1;i<size;++i)
    {
	key=*(array+i);
	int j=i-1;
	while((j>=0)&&(*(array+j)>=key))
	{
	    *(array+j+1)=*(array+j);
	    --j;
	}
	*(array+j+1)=key;
    }
}

int main()
{
    int Num[10]={8,12,3,4,1,23,11,9,24,31};
    INSERTION_SORT(Num,10);
    for (int i=0;i<10;++i)
    {
	printf("%d\t",Num[i]);
    }
    cin.get();
    return 0;
}

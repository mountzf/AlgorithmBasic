#include<iostream>
#define SIZE 10
using namespace std;

void INSERT(int *array, int size, int key)
{
	int i=size-1;
	while((i>=0)&&(*(array+i)>key))
	{
		*(array+i+1)=*(array+i);
		--i;
	}
	*(array+i+1)=key;
}

void INSERTION_SORT(int *array, int size)
{
	if(size>1)
	{
		int pSize=size-1;
		INSERTION_SORT(array,pSize);
		INSERT(array, pSize, *(array+pSize));
	}
}

int main()
{
	int Num[SIZE]={78,23,12,34,2,7,9,23,90,22};
	INSERTION_SORT(Num,SIZE);
	for(int i=0;i!=SIZE;++i)
	{
		cout<<Num[i]<<"\t"<<flush;
	}
	return 0;
}
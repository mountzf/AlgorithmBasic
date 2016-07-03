#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int Num[10]={8,12,3,4,1,23,11,9,24,31};
    int key;
    for(int i=1;i<10;++i)
    {
	key=Num[i];
	int j=i-1;
	while((j>=0)&&(Num[j]>key))
	{
	    Num[j+1]=Num[j];
	    --j;
	}
	Num[j+1]=key;
    }
    for (int i=0;i<10;++i)
    {
	printf("%d\t",Num[i]);
    }
    cin.get();
    return 0;
}

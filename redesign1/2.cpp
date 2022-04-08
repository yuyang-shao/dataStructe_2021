//#include <stdio.h>
//int rangeArray[120][5];
//void swap(int *a,int *b)
//{
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;	
//}
//
//void allRange(int *a,int k,int len)     //指针a表示中间点数组,n表示经过中间点个数
//{
//
//	int i;    
//	if(k==len)
//	{
//		static int s_i = 0;
//		for(int j=0;j<=len;j++)
//		{
//			rangeArray[s_i][j] = a[j];
//		}
//		s_i++;
//	}
//	else
//	{
//		for(i=k;i<=len;i++)
//		{
//			swap(a+i,a+k);
//			allRange(a,k+1,len);
//			swap(a+i,a+k);
//		}
//	}
//
//}
//int main()
//{
//
//	
//	int a[5]={1,2,3,4,5};
//	allRange(a,0,4);
//	for(int i=0;i<120;i++)
//	{
//		for(int j=0;j<5;j++)
//		{
//			printf("%d",rangeArray[i][j]);
//		}
//		printf("%5d",i);
//		printf("\n");
//	}
//
//}
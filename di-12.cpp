#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct Arr
{
	int * pBase;
	int len;
	int cnt;
};

void init_arr(struct Arr * pArr,int length);
bool append_arr(struct Arr * pArr,int val);
bool insert_arr(struct Arr * pArr,int pos,int val);//pos��ֵ��1��ʼ������ʾԪ�صĸ����������±� 
bool delete_arr(struct Arr * pArr,int pos,int * pval);
int get();
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
void sort_arr(struct Arr * pArr);
void show_arr(struct Arr * pArr);
void inversion_arr(struct Arr * pArr);


int main (void)
{
	int val;
	struct Arr arr;
	init_arr(&arr,6);
	show_arr(&arr);
	append_arr(&arr,1);
	append_arr(&arr,2);
	append_arr(&arr,3);
	append_arr(&arr,4);
	append_arr(&arr,5);
	inversion_arr(&arr);
	sort_arr(&arr);
 /*   if(append_arr(&arr,8))
	   printf("׷�ӳɹ�\n");
	else
	   printf("׷��ʧ��\n");   //����ֻ��6��ֵ����Ϊ���������Ԫ�ظ�����Ԫ�طŲ���ȥ�� 
*/
	show_arr(&arr);
	//printf("%d\n",arr.pBase);
	return 0;
}

void init_arr(struct Arr * pArr,int length)
{
	pArr->pBase=(int *)malloc(sizeof(int)*length);
	if(NULL==pArr->pBase)
	{
    printf("��̬�ڴ����ʧ��\n");
	exit(-1);
    }
	else
	{
		pArr->len=length;
		pArr->cnt=0;
	}
	return;//��ʾ�������������ֹ�� 
}

bool is_empty(struct Arr * pArr)
{
	if(0 == pArr->cnt)
	 return true;
	else
	 return false; 
	
} 
bool is_full(struct Arr * pArr)
{
	if(pArr->cnt == pArr->len)
	   return true;
	else 
	   return false;
}
void show_arr(struct Arr * pArr)   //���ʱҪ���ǵ������Ƿ�Ϊ�յ���� 
{
	
	if(is_empty(pArr))       //pArr�������*���ͣ������ټ�&���� 
	{
		printf("����Ϊ��");
		printf("\n") ; 
	} 
	else
	{
		for(int i=0;i<pArr->cnt;++i)
		printf("%d",pArr->pBase[i]);                //����дpArr[i],��ΪpArr�����ǽṹ����������֣�����int*���� 
	    printf("\n");
	}
}

bool append_arr(struct Arr * pArr,int val)
{
	if(is_full(pArr))
         return false;                   //��ʱ������Ҫ׷�ӣ�����ʱ����Ҫ׷�� 
    else
	  	pArr->pBase[pArr->cnt]=val;
		(pArr->cnt)++;
		return true; 
	
}
bool insert_arr(struct Arr * pArr,int pos,int val)
{
	int i;
	if(is_full(pArr))
	   return false;
	if(pos<1 || pos>pArr->cnt+1)
	   return false;
    for(i=pArr->cnt-1;i>=pos-1;--i)
    {
    	pArr->pBase[i+1]=pArr->pBase[i];
    }
    pArr->pBase[pos-1]=val;
    (pArr->cnt)++;
} 
bool delete_arr(struct Arr * pArr,int pos,int * pval)
{
	int i;
	if(is_empty(pArr))
	   return false;
	if(pos<1 || pos>pArr->cnt)
	   return false;
	*pval=pArr->pBase[pos-1];                  //�ѱ�ɾ�������������� 
	for(i=pos;i<pArr->cnt;++i)
	{
		pArr->pBase[i-1]=pArr->pBase[i]; 
	}
	(pArr->cnt)--;
	
}
void inversion_arr(struct Arr * pArr)
{
	int i = 0;
	int j = pArr->cnt-1;
	int t;
	while(i<j)
	{
		t=pArr->pBase[i];
		pArr->pBase[i]=pArr->pBase[j];
		pArr->pBase[j]=t;
		++i;
		--j;
	}
	return;
}
void sort_arr(struct Arr * pArr)
{
	int i,j,t;
	for(i=0;i<pArr->cnt;++i)
	{
		for(j=i+1;j<pArr->cnt;++j)
		{
		  t=pArr->pBase[i];
		  pArr->pBase[i]=pArr->pBase[j];
		  pArr->pBase[j]=t;
			
		}
	}
	
}

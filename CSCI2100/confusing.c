#include <stdio.h>
int main()
{
 int a[9],i,j;
 printf("������9������0~9 : \n");
 for(i=0;i<9;i  )
 scanf("%d", &a[i]);

 printf("�������������ȵ���?\n");
 for(i=0;i<8;i  )
 for(j=i 1;j<9;j  )
 {
 if(a[i]==0)
 break;
 if(a[i]==a[j])
 {
 printf("Yes\n");
 return 0;
 }

 printf("No\n");
 return 0;
}

���ߣ���Ы��С��
���ӣ�https://www.zhihu.com/question/68145855/answer/412738796
��Դ��֪��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

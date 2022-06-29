#include <stdio.h>
int main()
{
 int a[9],i,j;
 printf("请输入9个数字0~9 : \n");
 for(i=0;i<9;i  )
 scanf("%d", &a[i]);

 printf("输入的数中有相等的吗?\n");
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

作者：天蝎的小米
链接：https://www.zhihu.com/question/68145855/answer/412738796
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

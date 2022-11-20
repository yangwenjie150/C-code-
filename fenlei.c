#include <stdio.h>

int main ()
{
   char c;
   int a=0;
 int d=0;
 int f=0,w=0;
   printf("请输入字符：");
   while((c = getchar())!='\n')
 {if(c<='z'&&c>='a'||c>='A'&&c<='Z')
 {a++;
 }
 else if(c==' ')
   {
   d++;}
  else if(c>='0'&&c<='9')
   {f++;
   }
   else w++;
}printf("英文字母=%d，空格=%d，数字字符=%d，其它字符=%d\n",a,d,f,w);
   return(0);
}

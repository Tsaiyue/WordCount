#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h> //头文件 

void Countcharacter(char File[])  //字符数计算函数
 {
         int count=0;            
         char ch=' ';
         FILE *f_read=fopen(File,"r");
         if(f_read==NULL){
                 printf("查询文件不存在\n");
                 return ;
         }
         while((ch=fgetc(f_read))!=EOF)
         {
                 if(isspace(ch)==0)
                 ++count;
         }
         fclose(f_read);
         printf("该文件的字符数为%d\n",count);
 }
 
 void Countword(char File[]){
        int count=0;            //英文单词数计数
        char ch=' ';
        FILE *fp=fopen(File,"r");
        if(fp==NULL){
                printf("查询文件不存在\n");
                return ;
        }
        while((ch=fgetc(fp))!=EOF)
        {
                if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
                        while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))       
                        ch=fgetc(fp);
                        ++count;
                }
        }
        fclose(fp);
        printf("文件的单词数为%d\n",count);
}


void Countline(char File[]) //查询文件行数 
{
  FILE *fp;
  int file_row = 0, count = 0;
  char buffer[150];
  if((fp = fopen(File, "r")) == NULL)
   {printf("查询文件不存在\n");
    return ;
  }
  while(fgets(buffer,150,fp)!=NULL)
  {
      count++;
  }
  file_row = count; 
  printf("文件的行数为%d\n", file_row);
  fclose(fp);
  return ;
}
 
int main(int argc, char *argv[])//主函数 
{
    if(argc<2)
    {
        printf("you must input args!");
        return 0;
    }//用户无参数输入 
    if(strcmp(argv[1],"help")==0)//help 
   {
        printf("此程序参数如下：\n");
        printf("-c 查询文件字符数。\n");
        printf("-w 查询文件词数。\n");
        printf("-l 查询文件行数。\n");
		printf("exit为退出。");
        return 0;
   }
    else if(strcmp(argv[1],"-c")==0)
   {
    Countcharacter(argv[2]); 
  }
     else if(strcmp(argv[1],"-w")==0)
   {
    Countword(argv[2]); 
  }
     else if(strcmp(argv[1],"-l")==0)
   {
    Countline(argv[2]); 
  }
  else{printf("参数输入有误");
  }
    return 0;	
	}

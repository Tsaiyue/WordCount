#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h> //ͷ�ļ� 

void Countcharacter(char File[])  //�ַ������㺯��
 {
         int count=0;            
         char ch=' ';
         FILE *f_read=fopen(File,"r");
         if(f_read==NULL){
                 printf("��ѯ�ļ�������\n");
                 return ;
         }
         while((ch=fgetc(f_read))!=EOF)
         {
                 if(isspace(ch)==0)
                 ++count;
         }
         fclose(f_read);
         printf("���ļ����ַ���Ϊ%d\n",count);
 }
 
 void Countword(char File[]){
        int count=0;            //Ӣ�ĵ���������
        char ch=' ';
        FILE *fp=fopen(File,"r");
        if(fp==NULL){
                printf("��ѯ�ļ�������\n");
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
        printf("�ļ��ĵ�����Ϊ%d\n",count);
}


void Countline(char File[]) //��ѯ�ļ����� 
{
  FILE *fp;
  int file_row = 0, count = 0;
  char buffer[150];
  if((fp = fopen(File, "r")) == NULL)
   {printf("��ѯ�ļ�������\n");
    return ;
  }
  while(fgets(buffer,150,fp)!=NULL)
  {
      count++;
  }
  file_row = count; 
  printf("�ļ�������Ϊ%d\n", file_row);
  fclose(fp);
  return ;
}
 
int main(int argc, char *argv[])//������ 
{
    if(argc<2)
    {
        printf("you must input args!");
        return 0;
    }//�û��޲������� 
    if(strcmp(argv[1],"help")==0)//help 
   {
        printf("�˳���������£�\n");
        printf("-c ��ѯ�ļ��ַ�����\n");
        printf("-w ��ѯ�ļ�������\n");
        printf("-l ��ѯ�ļ�������\n");
		printf("exitΪ�˳���");
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
  else{printf("������������");
  }
    return 0;	
	}

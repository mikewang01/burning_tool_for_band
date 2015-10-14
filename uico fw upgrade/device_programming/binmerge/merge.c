#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MERGE_PROGRAM_VERSION 1

void output_file(FILE *fp)
{
    char ch;
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
}

void merge_file(FILE *s1fp,FILE *s2fp,FILE *dfp,int *num)
{
    char ch1,ch2;
    /*��ʼ��ch1��ch2Ϊ�ļ������ַ�*/
    ch1=fgetc(s1fp);
    ch2=fgetc(s2fp);
    /*���ļ��ж�ȡ�ַ���ֱ����һ���ļ�����*/
    while((ch1!=EOF)&&(ch2!=EOF))
        /*�����ַ��ıȽ�*/
        if(ch1<=ch2) {
            fputc(ch1,dfp);
            /*�ַ�������1*/
            *num=*num+1;
            ch1=fgetc(s1fp);
        } else {
            fputc(ch2,dfp);
            /*�ַ�������1*/
            *num=*num+1;
            ch2=fgetc(s2fp);
        }
    /*����ļ�s1fp���������ļ�s2fp��ʣ������д�뵽�ļ�dfp*/
    if(ch1==EOF)
        while((ch2=fgetc(s2fp))!=EOF) {
            fputc(ch2,dfp);
            /*�ַ�������1*/
            *num=*num+1;
        }
    /*����ļ�s2fp���������ļ�s1fp��ʣ������д�뵽�ļ�dfp*/
    else
        while((ch1=fgetc(s1fp))!=EOF) {
            fputc(ch1,dfp);
            /*�ַ�������1*/
            *num=*num+1;
        }
}
#define FIRST_MATCH_CHAR 0X49
#define KEY_STRING  {0x48,0x02, 0xf0, 0x07}
#define MAXLEN 1
#define MAX_UICO_BINARY_SIZE  14 //KB

int file_strstr(FILE *file, unsigned char *strstr_p, int lenth)
{
    int i = 0;
    unsigned char ch;
    /*check out validateion of file*/
    if(file == NULL) {

        return -1;
    }

    for(i = 0; i< lenth ; i++) {
        if(fread(&ch,sizeof(unsigned char), MAXLEN, file) == 0) {
            return -1;
        }
#ifdef _MERGE_DEBUG_
        printf("[file_strstr]0x%02x\r\n",ch);
#endif
        if(ch != strstr_p[i]) {
            return -1;
        }

    }
    lenth = 0-lenth;
    printf("[file_strstr]%d\r\n",lenth);
    /*return to original file pointer*/
    fseek(file, lenth, SEEK_CUR);
    return 0;

}



#define MAX_FILE_LENTH  60
#define MAX_ARG_NUM     2
#define UICO_FRIMWARE_POSITON 0x00012420
#include "stdint.h"
int  main(int argc,char *argv[])
{


    if(argc != MAX_ARG_NUM + 1) {
        printf("error: %s file name 1  file name 2", argv[0]);
        return 0;
    }

	printf("merge program version = %d\n",MERGE_PROGRAM_VERSION);
    char filename[MAX_ARG_NUM][MAX_FILE_LENTH + 1];
    char *s1filename = filename[0];
    char *s2filename = filename[1];
    unsigned char key_string[] = KEY_STRING;
    uint32_t char_positon = 0;
    FILE *s1fp,*s2fp,*dfp;
    unsigned char ch1,ch2,ch;
    int num=0, rc = 0;
    int i = 0;

    for(i = 1; i < argc; i++) {
        if(strlen(argv[i]) > MAX_FILE_LENTH) {
            printf("file path lenth should be shorter than %d chrs\n", MAX_FILE_LENTH);
            return 0;
        }
        memcpy(filename[i -1], argv[i], strlen(argv[i]) + 1);
        printf("%s \r\n", argv[i]);
    }


    if((s1fp=fopen(s1filename,"rb+"))==0) {
        printf("Can't open the file :%s\n",s1filename);
        exit(0);
    }

    if((s2fp=fopen(s2filename,"rb"))==0) {
        printf("Can't open the file :%s\n",s2filename);
        exit(0);
    }


    rewind(s1fp);
    fseek(s1fp, UICO_FRIMWARE_POSITON, SEEK_CUR);
    /*
        while((rc = fread(&ch,sizeof(unsigned char), MAXLEN,s1fp)) != 0 ) {
            char_positon ++;
            if(char_positon == UICO_FRIMWARE_POSITON) {
                printf("0x%02x, 0x12420\n",ch);
                break;
            }
    */

    fseek(s2fp, 0, SEEK_END);
    i = ftell(s2fp);  //�õ���ǰ����ָ��λ��, �����ļ��ĳ���
    rewind(s2fp);    //�ļ�ָ��ָ����ļ�ͷλ��
    if(i > (MAX_UICO_BINARY_SIZE*1024)  ) {
        printf("UICO BINARY SIZE EXXEED MAX FIRMWARE LIMITATION %dKB\r\n", MAX_UICO_BINARY_SIZE);
         exit(0);
		 
    }
//��̬����ռ�, Ϊ�����ַ�����β��־\0, ������һ���ַ��Ŀռ�
    char *pchBuf = (char*) malloc(sizeof(char)*i+1);
    if(!pchBuf) {
        perror("not enough heap!\n");
        exit(0);
    }

//��ȡ�ļ�����//��ȡ�ĳ��Ⱥ�Դ�ļ������п����г��룬�����Զ����� nLen
    i = fread(pchBuf, sizeof(unsigned char), i, s2fp);
    fwrite(pchBuf,sizeof(unsigned char), i, s1fp);

#if 0

    while((rc = fread(&ch,sizeof(unsigned char), MAXLEN, s2fp)) != 0 ) {

        i++;
#if 1

        if(i > (MAX_UICO_BINARY_SIZE*1024)  ) {
            printf("UICO BINARY SIZE EXXEED MAX FIRMWARE LIMITATION %dKB\r\n", MAX_UICO_BINARY_SIZE);
            break;
        }

#endif
        fwrite(&ch,sizeof(unsigned char), MAXLEN, s1fp);

    }
#endif
//i--;
//float kbytes_cy = i/1024.0;
    printf("%d bytes copied\r\n", i);
    free(pchBuf); //�ͷſռ�


    fclose(s1fp);
    fclose(s2fp);

//getch();
    exit(0);
}



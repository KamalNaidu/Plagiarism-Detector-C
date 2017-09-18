/*This block includes all the header files*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<dirent.h>
/*This block converts the upper case to lower case letters*/
void lower(char* str)
{
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]>=65 && str[i]<=90)
        {
            str[i]=str[i]+32;
        }
    }
}
/*This block will calculate the euclidean denominator when the integer array is passed*/
float euclidean(int* counter,int count)
{
    int temp=0;
    int g;
    for(g=0;g<count;g++)
    {
        temp=temp+(counter[g]*counter[g]);
    }
    return sqrt(temp);
}
/*This block will give out the percentage value if we give two filenames at once*/
float plagiarism(char t[25],char p[25])
{
    char* s1[1000];
    int counter1[1000]={0};
    char word1[50];
    int count1=0;
    int g;
    float d1;
    float d2;
    int flag=0;
    int k;                                 // size of words is max of 50
    FILE *fp1;                                           //declaring a p
    FILE *fp2;
    fp1=fopen(t,"r");                          // reading the file
    while(fscanf(fp1,"%s",word1)==1)
    {
        lower(word1);
        for(g=0;g<count1;g++)
    {
        if(strcmp(s1[g],word1)==0)
        {
            flag=1;
            counter1[g]++;
        }
    }
        if(flag!=1)
        {
            s1[count1]=(char*)malloc(100);
            strcpy(s1[count1],word1);
            counter1[g]=1;
            count1++;
        }
    }
    d1=euclidean(counter1,count1);
    char* s2[1000];
    fp2=fopen(p,"r");
    int counter2[1000]={0};
    int count2=0;
    char word2[50];
    flag=0;
    while(fscanf(fp2,"%s",word2)==1)
    {
        lower(word2);
        for(g=0;g<count2;g++)
    {
        if(strcmp(s2[g],word2)==0)
        {
            flag=1;
            counter2[g]++;
        }
    }
        if(flag!=1)
        {
            s2[count2]=(char*)malloc(100);
            strcpy(s2[count2],word2);
            counter2[g]=1;
            count2++;
        }
    }
    d2=euclidean(counter2,count2);
    int sum=0;
    for(g=0;g<count1;g++)
    {
        for(k=0;k<count2;k++)
        {
            if(strcmp(s1[g],s2[k])==0)
            {
                sum=sum+(counter1[g]*counter2[k]);
            }
        }
    }
    float klu;
    klu=(sum*100)/(d1*d2);
    return klu;
}
/*In the main function we are opening the directory and reading all the files in it. we send only two filenames to the upper block at once*/
void bagofwords(char *h)
{
    char c[250];
    char *path=h;
    //scanf("%[^\n]",path);                                                 //taking path from the user
    DIR *d;
    struct dirent *dir;
    chdir(path);
    d=opendir(path);                                                        //opening a directory
    int count=0;
    char namearr[100][100];
    int i=0,j=0;
    if(d)
    {
        while((dir=readdir(d))!=NULL)
        {
            count++;
            if(count>1)                                                     //creating a two dimensional array will file names
            {
                    j=0;
                    while(dir->d_name[j]!='\0')
                    {
                        namearr[i][j]=dir->d_name[j];j++;
                    }namearr[i][j]='\0';i++;
            }
        }
        closedir(d);
    }
    int nofiles=i;
    printf("\t    ");
    for(i=1;i<nofiles;i++)
    {
        printf("%10s",namearr[i]);
    }
    printf("\n");
    for(i=1;i<nofiles;i++)                                                          //we are displaying the output in matrix form
    {
        printf("%10s",namearr[i]);
        for(j=1;j<nofiles;j++)
        {
            printf("%10.2f",plagiarism(namearr[i],namearr[j]));                     //sending two files at once
        }
        printf("\n");
    }
}

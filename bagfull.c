#include<stdio.h>
#include<dirent.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//convert all upper cases of string to lower case
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

//here function finds the euclidean for denominator by passing array
float euc(int* counter,int count)
{
    int temp=0;
    int g;
    for(g=0;g<count;g++)
    {
        temp=temp+(counter[g]*counter[g]);
    }
    return sqrt(temp);
}

//function for performing all calculations for 2 files and it returns the percentage.
float plagiarism(char t[25],char p[25])
{
    int cnt1=0,g,flag=0,k;
    char* s1[1000]; //string array
    char warr1[50]; //word array
    float d1,d2;
    FILE *fp1; //file pointer for first file
    FILE *fp2; //file pointer for second file
    fp1=fopen(t,"r");
    int c1[1000]={0};
    // int flag1=0;                          
    while(fscanf(fp1,"%s",warr1)==1)
    {

        lower(warr1);
        for(g=0;g<cnt1;g++)
    {
        if(strcmp(s1[g],warr1)==0)
        {
            flag=1;
            c1[g]++;
        }
    }
        if(flag!=1)
        {
            s1[cnt1]=(char*)malloc(100);
            strcpy(s1[cnt1],warr1);
            c1[g]=1;
            cnt1++;
        }
    }
    d1=euc(c1,cnt1);
    char* s2[1000];
    fp2=fopen(p,"r");
    int c2[1000]={0};
    int cnt2=0;
    char warr2[50];
    flag=0;
    while(fscanf(fp2,"%s",warr2)==1)
    {
        lower(warr2);
        for(g=0;g<cnt2;g++)
    {
        if(strcmp(s2[g],warr2)==0)
        {
            flag=1;
            c2[g]++;
        }
    }
        if(flag!=1)
        {
            s2[cnt2]=(char*)malloc(100);
            strcpy(s2[cnt2],warr2);
            c2[g]=1;
            cnt2++;
        }
    }
    d2=euc(c2,cnt2);
    int sum=0;
    for(g=0;g<cnt1;g++)
    {
        for(k=0;k<cnt2;k++)
        {
            if(strcmp(s1[g],s2[k])==0)
            {
                sum=sum+(c1[g]*c2[k]);
            }
        }
    }
    float res;
    res=(sum*100)/(d1*d2);
    return res;
}


// in main fucntion only path taking from user
int main()
{
        char path[100];
        scanf("%[^\n]",path);       //taking test files input path from the user
        DIR *d;
        struct dirent *dir;
        chdir(path);
        d=opendir(path);             //for opening the specified directory
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
                            namearr[i][j]=dir->d_name[j];
                            j++;
                        }
                        namearr[i][j]='\0';
                        i++;
                }
            }
            closedir(d);
        }
        int numfls=i; //number of files given by count of i
        printf("\t    ");
        for(i=1;i<numfls;i++)
        {
            printf("%10s",namearr[i]);
        }
        printf("\n");
        for(i=1;i<numfls;i++)                                                          //we are displaying the output in matrix form
        {
            printf("%10s",namearr[i]);
            for(j=1;j<numfls;j++)
            {
                printf("%10.2f",plagiarism(namearr[i],namearr[j]));                     //sending two files at once
            }
            printf("\n");
        }

	// printf("%.2f",plagiarism("f1.txt","f2.txt"));
	return 0;
}
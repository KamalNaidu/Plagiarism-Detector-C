#include <stdio.h>
#include <math.h>
#include <dirent.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE *fp,*fp1,*fp3;
	struct dirent *direc;
  	char ar[100];
  	strcpy(ar,argv[1]);
  	int n=0,i=0;
  	fp3=fopen("output.txt","w");
  	chdir(ar);
  	DIR *d = opendir(ar);
  	while((direc = readdir(d)) != NULL)
  	{
    	if(!strcmp(direc->d_name,".")||!strcmp(direc->d_name,"..")){}
    	else{n++;}
  	}
  	rewinddir(d);

  	char *filesList[n];

  	while((direc=readdir(d)) != NULL)
  	{		//skipping first 2 default files in a directory i.e ".",".."
    	if(!strcmp(direc->d_name,".") || !strcmp(direc->d_name,".."))
    	{}
    	else
    	{		//accepting files only with .txt extension
    		if((direc->d_name[strlen(direc->d_name)-1]=='t')&&(direc->d_name[strlen(direc->d_name)-2]=='x')&&(direc->d_name[strlen(direc->d_name)-3]=='t')&&(direc->d_name[strlen(direc->d_name)-4]=='.'))
    		{
      		filesList[i] = (char*) malloc (strlen(direc->d_name)+1);
      		strncpy (filesList[i],direc->d_name, strlen(direc->d_name) );
      		i++;
      		}
    	}
  	}
  	float z=100.0;
  	rewinddir(d);
  	int l,q;
  	printf("\t  ");
        for(int j=0;j<i;j++)
        {
            printf("%10s   ",filesList[j]);
        }
        printf("\n");
	for(l=0;l<n;l++)
	{
		printf("%10s",filesList[l]);
		for(q=0;q<n;q++)
		{
			fp =fopen(filesList[l],"r");
			fp1=fopen(filesList[q],"r");
			char b1[5000]={'\0'};
			char b2[5000]={'\0'};
			int s1=0;
			int s2=0;
			char ch1,ch2;
			int count=0;
			int max=0;
			int x,y;


			if(l!=q)
			{
				while((ch1=fgetc(fp))!=EOF){
					if(isalpha(ch1))
					{
						if(isupper(ch1))
						{
							ch1=tolower(ch1);
							b1[s1] =ch1;
							s1+=1;
						}
						else
						{
							b1[s1] =ch1;
							s1+=1;
						}

					}
				}
				while((ch2=fgetc(fp1))!=EOF){
					if(isalpha(ch2))
					{
						if(isupper(ch2))
						{
							ch2=tolower(ch2);
							b2[s2] =ch2;
							s2+=1;
						}
						else
						{
							b2[s2] =ch2;
							s2+=1;
						}

					}
				}
					
					int s=0,i,j;
					for(i=0;i<s1;i++)
					{
						int itemp=i,item=i;
						for (j= 0; j<s2;j++)
						{
							if(itemp<s1)
							{
								if(b1[itemp]==b2[j])
								{
									itemp++;
									if((itemp-i)>s)
									{
										s=itemp-i;
									}
								}
								else
								{
									itemp=item;
								}
							}
						}
						max=s;
						if(max<count)
						{
							max=count;
							count=0;
						}
						else
						{
							count=0;
						}
					}


				float x1=(float)max*2/(float)(s1+s2);
				// fprintf(fp3,"%12.2f",x1*100);
				printf("%12.2f",x1*100);
			}
			else
			{
				// fprintf(fp3,"%12.2f",z);
				printf("%12.2f",z);
			}
		}
		// fprintf(fp3,"\n");
		printf("\n");
	}

	return 0;
}

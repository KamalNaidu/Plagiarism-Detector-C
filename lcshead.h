#include <stdio.h>
#include <math.h>
#include <dirent.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>




void lcs(char *h)
{
	FILE *fp,*fp1;
	struct dirent *directory;
  	char *ar=h;
  	//strcpy(ar,argv[1]);
  	int n=0,i=0;
  	chdir(ar);
  	DIR *d = opendir(ar);
  	while((directory = readdir(d)) != NULL)
  	{
    	if(!strcmp(directory->d_name,".")||!strcmp(directory->d_name,"..")){}
    	else{n++;}
  	}
  	rewinddir(d);

  	char *filesList[n];

  	while((directory=readdir(d)) != NULL)
  	{
    	if(!strcmp(directory->d_name,".") || !strcmp(directory->d_name,".."))
    	{}
    	else
    	{
    		if((directory->d_name[strlen(directory->d_name)-1]=='t')&&(directory->d_name[strlen(directory->d_name)-2]=='x')&&(directory->d_name[strlen(directory->d_name)-3]=='t')&&(directory->d_name[strlen(directory->d_name)-4]=='.'))
    		{
      		filesList[i] = (char*) malloc (strlen(directory->d_name)+1);
      		strncpy (filesList[i],directory->d_name, strlen(directory->d_name) );
      		i++;
      		}
    	}
  	}
  	float z=100.0;
  	rewinddir(d);
  	int l,q;
	for(l=0;l<n;l++)
	{
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
				printf("%12.2f",x1*100);
			}
			else
			{
				printf("%12.2f",z);
			}
		}
		printf("\n");
	}

}

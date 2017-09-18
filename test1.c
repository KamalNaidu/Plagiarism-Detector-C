#include <stdio.h>
#include <string.h>
#include "BagOfWords.h"
#include "lcshead.h"

int main(int argc, char const *argv[])
{
    char z[50];
    int f=0,opr;
    strcpy(z,argv[1]);
    printf("Plagiarism Detector\n");
    printf("Choose a method for Plagiarism:\n");
    printf("1. Bag of Words\n");
    printf("2. LCS\n");
    scanf("%d",&opr);
    while(f==0)
    	{
    		switch(opr)
    		{
    			case 1: bagofwords(z);
    			f=1;
                break;
    			case 2: lcs(z);
                f=1;
    			break;
                default: printf("Choose a correct option\n");
                f=1;
                break;
    		}
    	}
    
    
    return 0;
}

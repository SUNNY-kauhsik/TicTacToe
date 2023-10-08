#include<stdio.h>
int tic_tac_toe();
int hangmain();
int main()
{
	int i;
	printf("enter 1 to play tic tac toe\nenter 2 to play hangman\n");
	scanf("%d",&i);
	if(i==1)
	{
		
		tic_tac_toe();
	}
	else if(i==2)
	{
		hangman();
	}
	return 0;
	
}

char arr[3][3];
char z;
void save(int,int,char);
void playerx();
void playero();
void display();
int check_rows();
int check_cols();
int check_diag();
int tic_tac_toe()    
{
	
	int s=0,h=0;
	
	printf("\n\n\nYOU ARE NOW PLAYING TIC TAC TOE\nMIND THAT THIS IS CASE SENSITIVE USE ONLY SMALL CASE LETTERS\n\n\n");
	for(s=0;s<3;s++)
	{
		for(h=0;h<3;h++)
		{
			printf("[]");
		}printf("\n");
	}
	int rows=1;
	int cols=10;
	int diag=12;
	
	int i=1;
	int a=10;
	int b=10;
	for(i=1;i<=9;i++)
	{
		if(i%2==0)
		{
			playerx();
					
		}
		else
		{
			playero();
		}
		rows=check_rows();
		cols=check_cols();
		diag=check_diag();
		if(rows*cols*diag==0)
		{
			printf("%c wins\n",z);
			return 0;
		}		
	}
	printf("IT WAS A DRAW\nBOTH YOUR MUMS SUCK ");
	
}
void playerx()
{
	int a,b,c=10;
	printf("enter the row number followed by the column number you wud like to play x in\n");
	scanf("%d%d",&a,&b);
    save(a,b,'x');

    
}
void playero()
{
	int a,b,c=10;
	printf("enter the row number followed by the column number you wud like to play o in\n");
	scanf("%d%d",&a,&b);
    save(a,b,'o');
    
}
void save(int a, int b,char c)
{
	
	if(arr[a-1][b-1]=='x')
	{
		printf("INVALID BOX ALRDY TAKEN\n");
	    playerx();
	}
	if(arr[a-1][b-1]=='o')
	{
		printf("INVALID BOX ALRDY TAKEN\n");
	    playero();
	}
	arr[a-1][b-1]=c;
	display();
}

void display()
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(arr[i][j]=='x'||arr[i][j]=='o')
			{
				printf(" %c",arr[i][j]);
			}
			else
			{
				printf("[]");
			}
		}
		printf("\n");
	}
}
int check_rows()
{
	if((arr[0][0]==arr[0][1]&&arr[0][0]==arr[0][2])&&(arr[0][0]=='x'||arr[0][0]=='o')&&(arr[0][1]=='x'||arr[0][1]=='o')&&(arr[0][2]=='x'||arr[0][2]=='o'))
	{
		z=arr[0][0];
		return 0;
	}
	else if((arr[1][0]==arr[1][1]&&arr[1][0]==arr[1][2])&&(arr[1][0]=='x'||arr[1][0]=='o')&&(arr[1][1]=='x'||arr[1][1]=='o')&&(arr[1][2]=='x'||arr[1][2]=='o'))
	{
		z=arr[1][0];
		return 0;
	}
	else if((arr[2][0]==arr[2][1]&&arr[2][0]==arr[2][2])&&(arr[2][0]=='x'||arr[2][0]=='o')&&(arr[2][1]=='x'||arr[2][1]=='o')&&(arr[2][2]=='x'||arr[2][2]=='o'))
	{
		z=arr[2][0];
		return 0;
	}
	else 
	return 1;
}
int check_cols()
{
	if((arr[0][0]==arr[1][0]&&arr[0][0]==arr[2][0])&&(arr[0][0]=='x'||arr[0][0]=='o')&&(arr[1][0]=='x'||arr[1][0]=='o')&&(arr[2][0]=='x'||arr[2][0]=='o'))
	{
		z=arr[0][0];
		return 0;
	}
	else if((arr[0][1]==arr[1][1]&&arr[1][1]==arr[2][1])&&(arr[0][1]=='x'||arr[0][1]=='o')&&(arr[1][1]=='x'||arr[1][1]=='o')&&(arr[2][1]=='x'||arr[2][1]=='o'))
	{
		z=arr[0][1];
		return 0;
	}
	else if((arr[0][2]==arr[1][2]&&arr[2][2]==arr[1][2])&&(arr[0][2]=='x'||arr[0][2]=='o')&&(arr[1][2]=='x'||arr[1][2]=='o')&&(arr[2][2]=='x'||arr[2][2]=='o'))
	{
		z=arr[0][2];
		return 0;
	}
	else 
	return 1;
}
int check_diag()
{
	if((arr[0][0]==arr[1][1]&&arr[0][0]==arr[2][2])&&(arr[0][0]=='x'||arr[0][0]=='o')&&(arr[1][1]=='x'||arr[1][1]=='o')&&(arr[2][2]=='x'||arr[2][2]=='o'))
	{
		z=arr[0][0];
		return 0;
	}
	else if((arr[2][0]==arr[1][1]&&arr[1][1]==arr[0][2])&&(arr[2][0]=='x'||arr[2][0]=='o')&&(arr[1][1]=='x'||arr[1][1]=='o')&&(arr[0][2]=='x'||arr[0][2]=='o'))
	{
		z=arr[2][1];
		return 0;
	}
	else 
	return 1;
	
}









#include<time.h>
#include<string.h>	
#include<stdlib.h>
void word_size(int a);
void guess(int a);
int hangman()
{
	printf("\n\n\nyour are now playing hangman!!\nMIND THAT THIS IS CASE SENSITIVE USE ONLY SMALL CASE LETTERS\n\n\n");
	int i=0,j=1,length;
	char ch,word[100];
	FILE *fharry,*fdoraemon,*ftelmovie,*fbolmovie,*fholmovie,*fyoutubers;
	int file,file_word;
	srand(time(0));
	file=(rand()%6)+1;
	file=1;
	if(file==1)
	{
		printf("your word belongs to harry potter universe");
		srand(time(0));
	   file_word=(rand()%8)+1;
		fharry=fopen("harrypotter","r");
		if(file_word==1)
		{
			while((ch=fgetc(fharry))!='\n')
			{
				word[i]=ch;
				i++;
			}
			word[i]='\0';
		}
		else
		{
				while((ch=fgetc(fharry))!='EOF')
	            {
		           if(ch=='\n')
		           {
		           	  j++;
		           	  if(file_word==j)
		           	  {
		           	  	while((ch=fgetc(fharry))!='\n')
		           	  	{
		           	  		word[i]=ch;
				            i++;
						}
						word[i]='\0';
						fclose(fharry);
						break;

					  }
			
		           }
	            }
		}
	}
 else if(file==2)
	{
		printf("your word belongs to doraemon universe\n");
		srand(time(0));
	   file_word=(rand()%8)+1;
		fdoraemon=fopen("doraemon","r");		
		if(file_word==1)
		{
			while((ch=fgetc(fharry))!='\n')
			{
				word[i]=ch;
				i++;
			}
			word[i]='\0';
		}
		else 
		{
			while((ch=fgetc(fdoraemon))!='$')
	            {
		           if(ch=='\n')
		           {
		           	  j++;
		           	  if(file_word==j)
		           	  {
		           	  	i=0;
		           	  	while((ch=fgetc(fdoraemon))!='\n')
		           	  	{
		           	  		word[i]=ch;
				            i++;
						}
						word[i]='\0';
						fclose(fdoraemon);
						break;				
					  }
			
		           }
	            }
		
			
		}
		
	}
	else if(file==3)
	{
		printf("your word belongs to tollywood universe\n");
		srand(time(0));
	    file_word=(rand()%8)+1;
		ftelmovie=fopen("telmovie","r");
		if(file_word==1)
		{
			while((ch=fgetc(ftelmovie))!='\n')
			{
				word[i]=ch;
				i++;
			}
			word[i]='\0';
		}
		else
		{
				while((ch=fgetc(ftelmovie))!='EOF')
	            {
		           if(ch=='\n')
		           {
		           	  j++;
		           	  if(file_word==j)
		           	  {
		           	  	while((ch=fgetc(ftelmovie))!='\n')
		           	  	{
		           	  		word[i]=ch;
				            i++;
						}
						word[i]='\0';
						fclose(ftelmovie);
					break;

					  }
			
		           }
	            }
		}
	}
	else if(file==4)
	{
		printf("your word belongs to bollywood universe\n");
		srand(time(0));
	    file_word=(rand()%8)+1;
		fbolmovie=fopen("bolmovie","r");
		if(file_word==1)
		{
			while((ch=fgetc(fbolmovie))!='\n')
			{
				word[i]=ch;
				i++;
			}
			word[i]='\0';
		}
		else
		{
				while((ch=fgetc(fbolmovie))!='EOF')
	            {
		           if(ch=='\n')
		           {
		           	  j++;
		           	  if(file_word==j)
		           	  {
		           	  	while((ch=fgetc(fbolmovie))!='\n')
		           	  	{
		           	  		word[i]=ch;
				            i++;
						}
						word[i]='\0';
						fclose(fbolmovie);
						break;

					  }
			
		           }
	            }
		}
	}
	else if(file==5)
	{
		printf("your word belongs to hollywood universe\n");
		srand(time(0));
	    file_word=(rand()%8)+1;
		fholmovie=fopen("holmovie","r");
		if(file_word==1)
		{
			while((ch=fgetc(fholmovie))!='\n')
			{
				word[i]=ch;
				i++;
			}
			word[i]='\0';
		}
		else
		{
				while((ch=fgetc(fholmovie))!='EOF')
	            {
		           if(ch=='\n')
		           {
		           	  j++;
		           	  if(file_word==j)
		           	  {
		           	  	while((ch=fgetc(fholmovie))!='\n')
		           	  	{
		           	  		word[i]=ch;
				            i++;
						}
						word[i]='\0';
						fclose(fholmovie);
						break;

					  }
			
		           }
	            }
		}
	}
	else
	{
		printf("your word is a youtube channel name or a youtuber\n");
		srand(time(0));
	    file_word=(rand()%8)+1;
		fyoutubers=fopen("youtubers","r");
		if(file_word==1)
		{
			while((ch=fgetc(fyoutubers))!='\n')
			{
				word[i]=ch;
				i++;
			}
			word[i]='\0';
		}
		else
		{
				while((ch=fgetc(fyoutubers))!='EOF')
	            {
		           if(ch=='\n')
		           {
		           	  j++;
		           	  if(file_word==j)
		           	  {
		           	  	while((ch=fgetc(fyoutubers))!='\n')
		           	  	{
		           	  		word[i]=ch;
				            i++;
						}
						word[i]='\0';
						fclose(fyoutubers);
						break;

					  }
			
		           }
	            }
		}
	}
	i=0;
	while(word[i]!='\0')
	{
		i++;
		
	}
	printf("\n");
	length=i;	
	printf("your word consists of %d characters\n",length);
		int k=0,flag=0,x,t=0,win=0;
	char c;
	printf("enter your guess\n");
    while(k<8)
	{
		flag=0;
		scanf("%c",&c);
		if(c!='\n')
		{
			for(x=0;x<length;x++)
	    {
	    	if(word[x]==c)
	    	{
	    		
	    		printf("your guess was right it is present in the position %d\n",x+1);
	    		printf("enter your guess\n");
	    		flag++;
	    		win++;
	    		if(win==length)
	    		{
	    			printf("you won!!");
	    			printf("the word was\n");
	    				i=0;
	                while(word[i]!='\0')
	                {
		               printf("%c",word[i]);
		               i++;
		
	                }
	    			return 0;
	    			
				}
			}
		}
		if(flag==0)
		{
			k++;
			printf("your guess is wrong\n");
			printf("you have %d guess left\n",8-k);
			printf("enter your guess\n");
			if(k==8)
	       {
		        printf("you have lost u suck!!\n");
		        	printf("the word was\n");
	    				i=0;
	                while(word[i]!='\0')
	                {
		               printf("%c",word[i]);
		               i++;
		
	                }
	                return 0;
	       }
		}
		t++;
		}
	    
		
	}
	
	
	}



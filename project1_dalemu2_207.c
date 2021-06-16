/*
 *Daniel Alemu G00884794
 *CS 262, Lab Section 207
 *Project 1
 *
 */
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
/*definition of macros for
 ** char set,
 *  key word and 
 *  encripte/decript text size
 */
#define STRING_LENGTH 44
#define KEY_LENGTH 22
#define MESSAGE_LENGTH 252

/*
 *  * A funcion prototypes
 *   * constat char set declaration
 */

void menu();
int integerInput();
char *userMessageInput();
char *userkeyInput();
char *shuffle();
char (*tabulaRecta())[STRING_LENGTH];
char *keyWord();
char *message();
void Encription(char tRecta[STRING_LENGTH][STRING_LENGTH],char kyWord[KEY_LENGTH]);//
void Decription(char tRecta[STRING_LENGTH][STRING_LENGTH],char kyWord[KEY_LENGTH]);//,char eMessage[MESSAGE_LENGTH]);

const char CHARSET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,;!-'?";
/*main funcction
 * calls integer input, menu,tabula recta, key word,
 *  * encription and decription functions
 */

int main()
{


int  option;
char (*tRecta)[STRING_LENGTH];
char *kWord;

do{	
menu();

option=integerInput();
	switch(option)
	{	
		case 1:
		tRecta=tabulaRecta();
		break;

		case 2:
		kWord=keyWord();
		break;

		case 3:
		Encription(tRecta,kWord);
		break;

		case 4:
		Decription(tRecta,kWord);
		break;

		case 5:
		printf("program exit...\n");
		exit(0);
		break;
	
		default:
		printf("Invalid  Input choose 1 to 5 \n");
	}

}while(1);
	return 0;
}

/*
 *  *a void  menu() function 
 *   * displayes menu list this function called in main() function
*/


void menu()
{
	
	printf("Choose from the following menu options:\n");
	printf("1 - Enter a random number seed to generate the Tabula Recta\n");
	printf("2 - Enter the Keyword\n");
	printf("3 - Enter a message to encrypt\n");
	printf("4 - Enter a message to decrypt\n");
	printf("5 - Exit the program\n");	
	printf("Enter your choice :  ");
}
/*
 *  * integerInput() function
 *  return integer value
 *  no parameter
 * it allow the user to enter intger input 
 *this function used to enter option in main() function and  seed value in shuffle() function 
 */

int  integerInput()
{

        int intInput;
	char buffer[100];

        fgets(buffer,100,stdin);
        sscanf(buffer,"%d",&intInput);

        return intInput;
}
/*
 * function userKeyInput()
 * it returns a character string
 * used for reading user key word input
 * has no parameter
 *     */

char *userKeyInput()
{
	
        static char keyInput[KEY_LENGTH];
        fgets(keyInput,KEY_LENGTH,stdin);
        sscanf(keyInput,"%c",keyInput);

	return keyInput;

}
/* function userMessageInput()
 * it returns a character strin
 *  used for reading user text input 
 *  for encription/decription
 *  has no parameter
 */

char *userMessageInput()
{

        static char messageInput[MESSAGE_LENGTH];
        fgets(messageInput,MESSAGE_LENGTH,stdin);
        sscanf(messageInput,"%c",messageInput);

        return messageInput;

}
/* shuffle function() 
 *  * it shuffles the original character set
 *   *has no parameter and returns a
 *    *character string
 *     */

char *shuffle()
{


	static char shuffleCHARSET[STRING_LENGTH];
	int seed;
	for(int f=0;f<STRING_LENGTH;f++)
        {
        shuffleCHARSET[f]=CHARSET[f];
	}

	printf("Enter a random number seed  : ");
	seed = integerInput(); // read seed input integerInput returns int value
	srandom(seed);

	for (int order = STRING_LENGTH - 1; order> 0; order--)
	{
    	char temp;
    	int  index = random()%(order+1);
	temp=shuffleCHARSET[index];
	shuffleCHARSET[index]=shuffleCHARSET[order];
	shuffleCHARSET[order]=temp;
   	
	}	
	return shuffleCHARSET;
}
/* tabulaRecta function()
 *  *  has no parameter
 *   * make a tabula recta table and 
 *    *returns a character string 
 *     */

char (*tabulaRecta())[STRING_LENGTH]
{
	
	static char tRecta[STRING_LENGTH][STRING_LENGTH];
	char *sCHARSET;
	
	int  col,row;

	sCHARSET=shuffle();// accept a shuffled character set 
for(row=0;row<=STRING_LENGTH;row++)
	{
		int count=0;
		for(col=0;col<=STRING_LENGTH;col++)
		{
			if(col+row>= STRING_LENGTH)
			{
				tRecta[row][col]=sCHARSET[count];
				count=count+1;
			}
			else
				tRecta[row][col]=sCHARSET[row+col];
		}
	}

	return tRecta;
}

/* keyWord() function has no parameter
 *  * returns a key word after changing to 
 *   * upper case and the last character to null value 
 *    * returns a character string
 *     */

char *keyWord()
{

	static char *kWord;

	printf("Enter the keyword to use  : ");
	kWord=userKeyInput(); //call and take the key word from userkeyInput() function

	int index=0;
	
	while(kWord[index])
	{
		kWord[index]=toupper(kWord[index]);
		index++;
	}
	
	kWord[strlen(kWord)-1]='\0';
	
	return kWord;

}
/*
 *  *message() function has no parameter
 *   * returns a key word after changing to
 *    * upper case and the last character to null value
 *     * returns a character string
 *      */

char *message()
{
	
	static char *textMessage;        
	int index=0;
	textMessage=userMessageInput();

	while(textMessage[index])
	{
		textMessage[index]=toupper(textMessage[index]);
		index++;
	}
	
	textMessage[strlen(textMessage)-1]='\0';

	return textMessage;
}

/*
 *  *returns a specific position index from the set of character string
 *   *has two parameters a constant string and and single character
 *    * 
 *     */

int GetPosition(const char *str, const char c)
{
  int retVal = -1;
  char *pos = strchr(str, c);

  if (pos != NULL)
  {
    retVal = pos - str;
  }

  return retVal;
}
/*encription function is a void function 
 *  *has two parameters tabulaRecta and a keyword
 *   * call message() function to get a text for encription
 *    * a getPositon function to get a character index from set
 *     */

void  Encription(char tabulaRecta[][STRING_LENGTH], char keWord[KEY_LENGTH])

{
	char *tMessage;

	int count=0;
	int keyIndex;
	int tMessageIndex;

	if((tabulaRecta != NULL) &&(strlen(keWord)-1)!=0)   // condition to check the tabula and keyword are existed 
	{
		printf("Enter the message to encrypt : ");
		tMessage=message();
		char encriptedMessage[strlen(tMessage)];
		printf("The message you entered is :%s \n",tMessage);
		for(int i=0;i<strlen(tMessage);i++)
		{
		
			if(count==strlen(keWord))
			{
			count=0;
			}
			if(count<strlen(keWord))
			{
			keyIndex=GetPosition(CHARSET,keWord[count]);
			count++;
			}
	
			tMessageIndex=GetPosition(CHARSET,tMessage[i]);
			encriptedMessage[i]=tabulaRecta[tMessageIndex][keyIndex];

		}
		encriptedMessage[strlen(tMessage)]='\0';
		printf(" The Encripted Messege is  :%s \n",encriptedMessage);
	}
	else
		printf("Either Tabula or key word is not exist.\n");
}
/*
 *  ** decription function is a void function
 *   * has two parameters tabulaRecta and a keyword
 *    * call message() function to get a text for decription
 *     * a getPositon function to get a character index from set
 *      */



void  Decription(char tabulaRecta[][STRING_LENGTH], char keWord[KEY_LENGTH])

{
	char *eMessage;
	char shuffledCharSet[STRING_LENGTH];
 
      	int count=0;
	int keyIndex;
	int eMessageIndex;

	if((tabulaRecta != NULL) &&(strlen(keWord)-1)!=0)   // if conditon to check tabula and keyword are existed
	{
		printf("Enter the message to decrypt :  ");
		eMessage=message();   // get text to be decripted
		printf("The message you entered is:%s \n",eMessage);
		char decriptedMessage[strlen(eMessage)];
		for(int i=0;i<strlen(eMessage);i++)
		{
		
			if(count==strlen(keWord))
			{
			count=0;
			}
			if(count<strlen(keWord))
			{
			keyIndex=GetPosition(CHARSET,keWord[count]);
			count++;
			}
			
			for(int j=0;j<STRING_LENGTH;j++)  // copy targeted raw tabula content
			{
			shuffledCharSet[j]=tabulaRecta[keyIndex][j];
			}
					
			eMessageIndex=GetPosition(shuffledCharSet,eMessage[i]);
			decriptedMessage[i]=CHARSET[eMessageIndex];

		}
			decriptedMessage[strlen(decriptedMessage)]='\0';
			printf(" The Decripted Messege is :%s \n",decriptedMessage);

	}
	else
		printf("Either tabula or key word is not exist.\n"); 
}

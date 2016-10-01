#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "inputlib.h"
/*
 * Author: Jefferson Vivanco
 * Program: This is a simple encryption/decryption program. The program encrypts/decrypts by shifting each character in the 
 * 			in the string by the value that the user enters. For example, the character 'A' would be shifted to 'C' if the user
 * 			enters a value of 2. 
 * Functions: The functions used in this program are: main, encrypt, and decrypt. The main reads the user input and calls the 
 * 			  proper functions. The functions do as their name says encrypt and decrypt. 
 */
void encrypt(char *str, int value);
void decrypt(char *str, int value);
/*
 * main: This functions does not return anything. This function is responsible for reading the user's input and checking whether
 * 		 the user's input is valid or not. 
 */
int main()
{
    //--------------------------------------//Making program title
    printf("======================\n");
    printf("Encrypt/Decrypt Tool\n");
    printf("======================\n\n");
    //--------------------------------------//Asking user if Encrypt or Decrypt
    printf("What would you like to do? (E)ncrypt or (D)ecrypt?  ");
    char userChoice1 = getChar();
    if(userChoice1=='e' || userChoice1=='E'|| userChoice1=='d' || userChoice1=='D');
    else {
        printf("ERROR: INVALID CHOICE\n");
        exit(0);
    }
    printf("\n");
    //--------------------------------------//Asking for encryption key
    printf("Enter your encryption key: ");
    int userKey = getInt();
    printf("\n");
    //--------------------------------------//Asking user for message
    printf("Enter your message: ");
    char *str1 = getString();
    printf("\n");
    //--------------------------------------//Printing final results
    if(userChoice1 == 'e' || userChoice1=='E')
        encrypt(str1, userKey);
    else
        decrypt(str1,userKey);
        
    printf("Your decrypted message is: %s\n", str1);
}
/*
 * encrypt: This function takes in a string pointer and an int as its parameters. The string pointer "str" contains the string
 * 			the user entered. The int "value" is the number of shifts the user entered to be performed for each char in the
 * 			string. In this function, the chars are shifted to the right, in other words to the letters in front of the char in the alphabet
 * return: This function does not return anything but it does change the string using pointers. 
 */ 
void encrypt(char *str, int value){
    //ITERATING THROUGH STRING POINTER AND INCREMENTING EACH CHAR BY "value"
    while((*str)!='\0')//If it reaches this, it means its the end of the string
    {
        if(isalpha(*str)) {
            if(islower(*str)){ //Lower case range [97,122]
                int numRepLower = (int)(*str);//converting char to int
                numRepLower += value; //increasing the char int by the value the user entered
                int keep;
                while(numRepLower>122)//In this loop, we check if the char int is out of the range of chars, if it is, then 
									  //this loop resets it back to the first char in the range and adds the remaining value to it
                {
                    keep = numRepLower-122;
                    numRepLower =96;
                    numRepLower+=keep;
                }
                *str = numRepLower;//Here is where we update the char in the string with the new char 
            }
            else{//[65,90] 
				//Same as above except for lower case letters 
                int numRepUpper = (int)(*str);
                numRepUpper += value;
                int keep2;
                while(numRepUpper>90)
                {
                    keep2 = numRepUpper-90;
                    numRepUpper = 64;
                    numRepUpper+=keep2;
                }
                *str = numRepUpper;
            }
        }
        str++;//incrementing the string pointer to point to the next char
    }
}
/*
 * decrypt: This function takes in a string pointer and an int as its parameters. The string pointer "str" contains the string
 * 			the user entered. The int "value" is the number of shifts the user entered to be performed for each char in the
 * 			string. In this function, the chars are shifted to the left, in other words, to the previous letters of the char in the alphabet
 * return: This function does not return anything but it does change the string using pointers. 
 */ 
void decrypt(char *str, int value){
    //ITERATING THROUGH STRING POINTER AND DECREMENTING EACH CHAR BY VALUE
    //Same algorithm as encrypt except that we decrement the value of each char instead of increment 
    while((*str)!='\0')
    {
        if(isalpha(*str)) {
            if(islower(*str)){ //Lower case range [97,122]
                int numRepLower = (int)(*str);
                numRepLower -= value;
                int keep;
                while(numRepLower<97)
                {
                    keep = 97-numRepLower;
                    numRepLower =123;
                    numRepLower-=keep;
                }
                *str= numRepLower;//updating the char to the new char
            }
            else{//[65,90]
                int numRepUpper = (int)(*str);
                numRepUpper -= value;
                int keep2;
                while(numRepUpper<65)
                {
                    keep2 = 90-numRepUpper;
                    numRepUpper = 91;
                    numRepUpper-=keep2;
                }
                *str = numRepUpper;
            }
        }
        str++;//incrementing the string pointer so it can point to the next character 
    }
}

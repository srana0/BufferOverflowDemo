#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>
#include <stdio.h>

#define MAX_BUFFER_SIZE 20
void static PrintBuffer(unsigned char *startAdress, int bufferSize);


int main(int argc, char* argv[])
{

  char first_Name_UserInput[10];
  char last_name_UserInput[10];

 unsigned char *start_address=(unsigned char *) malloc(MAX_BUFFER_SIZE);
 // Organization decided that, out of total available buffer, first 5 Letter will be reserved for First Name
 // And last 5 letter will be reserved for Last Name
 unsigned char *first_Name=start_address;
 unsigned char *last_name=start_address+6;


  printf("\n\nEnter the First Name\n");
  scanf("%s",&first_Name_UserInput);
  printf("Enter the Last Name\n");
  scanf("%s",&last_name_UserInput);
  int lenght_of_firstName=strlen(first_Name_UserInput)+1;
  int lenght_of_lastName=strlen(last_name_UserInput)+1;


//__________________________________________________________________________
// CODE VULNERABLE TO BUFFER OVERFLOW
//_________________________________________________________________________

// // Copy First Name and Last Name to their respective places
//  memcpy(last_name,last_name_UserInput,strlen(last_name_UserInput)+1);
//  memcpy(first_Name,first_Name_UserInput,strlen(first_Name_UserInput)+1);
//  PrintBuffer(start_address,MAX_BUFFER_SIZE);

//__________________________________________________________________________
// CODE MITIGATION OF BUFFER OVERFLOW
//_________________________________________________________________________

 if( (lenght_of_firstName>6)|| (lenght_of_lastName>6) )
 {    printf("You are trying to enter the first name or last name larger than the available buffer.\n\n");
 }
 else if( (lenght_of_firstName<=6)|| (lenght_of_lastName<=6) )
 {
   memcpy(last_name,last_name_UserInput,strlen(last_name_UserInput)+1);
   memcpy(last_name,first_Name_UserInput,strlen(first_Name_UserInput)+1);
   PrintBuffer(start_address,MAX_BUFFER_SIZE);
 }

}


void static PrintBuffer(unsigned char *startAdress, int bufferSize)
 {
  int i=0;
  for(i=0;i<bufferSize;i++)
  {

      printf("\n|\t%c\t| Address: %ld\n",*(startAdress+i),(startAdress+i));

  }

 }


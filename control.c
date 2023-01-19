#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void horizontal();



int main()
{

int choice = 0;
   do
   {
    printf("\n");
    printf(" ####################################\n");
     printf(" #      MicroProgrammed Control    #\n ");
      printf("####################################\n");

      printf("\n");
      printf("Choose Implementation technique\n");
      printf("1. Vertical\n");
      printf("2. Horizontal\n");
      scanf("%d" ,&choice);
      switch(choice)
      {
      case 1:
       // vertical();
        break;
      case 2:
        horizontal();
        break;
      case 3:
      default:
        printf("Invalid Choice\n");
        break;


        printf("\n");


      }


     }while(choice == 1 || choice == 2);


return (0);
}



void horizontal()
{
    //allowing the user to choose the number of register
    int add = 0;

    int random = rand() % 50;
    int Reg[3] = {};
    printf("Choose the Register Numbers  (i.e up to 3 is enough)\n");
   scanf("%d" , &add);

    for (int i = 0; i < add; i++)
    {
     Reg[i] = random % i;
     printf("Registers with the value 0x%x are created\n" , Reg[i]);
    }

}




#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/* This project consist of the demonstration of MicroProgrammed
 * Control in a Computer .
 * Consist of two implementation method which are
 * Vertical  Implementation &
 * Horizontal Implementation
 * Control Memory has the instruction for Arithmetic and
 * Logic unit.
 */



void horizontal();

struct c_memory
{
    int memory[32];
    int *address[32];
};
struct c_memory alu();
int sum(int x , int y);
int sub(int x , int y);
int mul(int x , int y);
int divide(int x , int y);
int mod(int x , int y);
int or(int x , int y);
int not(int x );
int and(int x , int y);



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
          alu();
       // vertical();
        break;
      case 2:
           alu();
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

struct c_memory alu()
{
    int m_instructions[] = {000 ,001 ,010 ,011 ,100 ,101 ,110 ,111};


       int select = 0;
   printf("How many ALU functions do u want ( i.e up to 8 max with 2**n)\n");
   scanf("%d" , &select);
   struct c_memory inst;
   printf("     Control Memory\n");
   printf("Address          MicroInstructions\n");
   for (int i = 0; i < select; i++)
   {
       inst.memory[i] = m_instructions[i];
       inst.address[i] = &inst.memory[i];

    printf("0x%x             0x%x \n" , inst.address[i] , inst.memory[i]);
   }

return inst;
}




void horizontal()
{
    //allowing the user to choose the number of register
    int add = 0;
   srand(time(NULL));
    int random = rand() % 100;
    int Reg[3] = {};
    printf("Choose the Register Numbers  (i.e up to 3 is enough)\n");
   scanf("%d" , &add);

    for (int i = 0; i < add; i++)
    {
     Reg[i] = random % (i + 10);
     printf("Registers with the value 0x%x is created\n" , Reg[i]);

    }
    printf("\n");
    //choosing the type of operation to perform
     int operation = 0;
    int operand = 0;
    int bit1[3] = {};
    int bit2[3] = {};
    int bit3[3] = {};
    int bit4[3] = {};
    int bit5[3] = {};
    int bit6[3] = {};
    int bit7[3] = {};
    int bit8[3] = {};
    for (int i = 0; i < add; i++)
        {
    printf("Inform the Processor which kind of operation is applied in register %d\n" , i);
    printf(" 1.add\n 2.substract\n 3.multiply\n 4.divide\n 5.modulus\n 6.Logic not\n 7. Logic or\n 8.Logic and\n");
    scanf("%d" ,&operation);
    printf("Enter the operand\n");
    scanf("%d" , &operand);
    if (operation == 1)
    {
        Reg[i] = sum(Reg[i] , operand);
        bit1[i] = 1;

    }
  else if(operation == 2)
    {
        Reg[i] = sub(Reg[i] , operand);
        bit2[i] = 1;
    }
   else if(operation == 3)
    {
      Reg[i] = mul(Reg[i] , operand);
      bit3[i] = 1;
    }
  else  if(operation == 4)
    {
     Reg[i] =   divide(Reg[i] , operand);
     bit4[i] = 1;
    }
  else if(operation == 5)
  {
    Reg[i] =   mod(Reg[i] ,operand);
    bit5[i] = 1;
  }
  else if(operation == 6)
  {
    Reg[i] = not(Reg[i]);
    bit6[i] = 1;
  }
  else if(operation == 7)
  {
   Reg[i] = or(Reg[i] , operand);
   bit7[i] = 1;
  }
  else if(operation == 8)
  {
     Reg[i] = and(Reg[i] , operand);
     bit8[i] = 1;
  }

    }


    for(int i = 0; i < add; i++)
    {
         printf("                 Register %x  = %x                \n" , i , Reg[i]);
         printf("    |       |        |        |        |       |      |      |    \n");
         printf(" add(%x)   sub(%x)   mul(%x)   div(%x)   mod(%x)  not(%x) or(%x)  and(%x)    \n" , bit1[i] ,bit2[i] ,bit3[i] , bit4[i],bit5[i] ,bit6[i],bit7[i],bit8[i]);
         printf("\n");
    }
    printf("\n");
    printf("for each Register their is corresponding Control Words bit to update the value\n");

     printf("\n");


}



int sum(int x , int y)
{
            return (x + y);
            }
int sub(int x ,int y)
{
    return x - y;
    }
int mul(int x , int y)
{
                return x * y;
                }
int divide(int x , int y)
{
                 return x / y;
                 }
int mod(int x , int y)
{
                 return x % y;
}
int not(int x)
{
         return ~x;
         }
int and(int x , int y)
{
                   return x & y;
}
int or(int x , int y)
{
               return x | y;
               }





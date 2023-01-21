#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"shell.h"


/* This project consist of the demonstration of MicroProgrammed
 * Control in a Computer .
 * Consist of two implementation method which are
 * Vertical  Implementation &
 * Horizontal Implementation
 * Control Memory has the instruction for Arithmetic and
 * Logic unit.
 * In addition we did not include the address bits in control word for simplicity
 */






int main()
{

int choice = 0;


   do
   {
    printf("\n");
    printf(" ####################################\n");
     printf(" #      MicroProgrammed Control     #\n ");
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
        vertical();
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
    int m_instructions[] = {0b000 ,0b001 ,0b010 ,0b011 ,0b100 ,0b101 ,0b110 ,0b111};


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

    printf("0x%x             0x%x \n" , inst.address[i] , (inst.memory[i]));
   }

return inst;
}




void horizontal()
{
    printf("\n");
    printf("Horizontal Implementation\n");
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

    do
        {
    for (int i = 0; i < add; i++)
        {
    printf("Inform the Processor which kind of operation is applied in Register %d with a value 0x%x\n" , i , Reg[i]);
    printf(" 1.add\n 2.substract\n 3.multiply\n 4.divide\n 5.modulus\n 6.Logic not\n 7. Logic or\n 8.Logic and\n 9. End\n");
    scanf("%d" ,&operation);
    if (operation < 9 && operation > 0 && operation != 6)
        {
    printf("Enter the operand\n");
    scanf("%d" , &operand);
      }

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
  else
    continue;
        }
    }while(operation <=8);


    for(int i = 0; i < add; i++)
    {
         printf("                      Register %x  = 0x%x (hex value)               \n" , i , Reg[i]);
         printf("    |       |        |        |        |       |      |       |    \n");
         printf(" add(%x)   sub(%x)   mul(%x)   div(%x)   mod(%x)  not(%x)  or(%x)  and(%x)    \n" , bit1[i] ,bit2[i] ,bit3[i] , bit4[i],bit5[i] ,bit6[i],bit7[i],bit8[i]);
         printf("\n");
    }
    printf("\n");
    printf("for each Register their is corresponding Control Words bit to update the value\n");

     printf("\n");


}
void vertical()
{
    printf("\n");
    printf("Vertical Implementation\n");
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

    //vertically implementing

    int vertical = 0;
    int operand = 0;
   int bit1[3] = {};
    int bit2[3] = {};
    int bit3[3] = {};
    int bit4[3] = {};
    int bit5[3] = {};
    int bit6[3] = {};
    int bit7[3] = {};
    int bit8[3] = {};

     int input1,input2,input3;

    for(int i = 0; i < add; i++)
        {
     printf("Enter 3 bit number in decimal to decode in to Control Word in Register %d with a value 0x%x\n" , i , Reg[i] );
    printf(" 0.add\n 1.substract\n 2.multiply\n 3.divide\n 4.modulus\n 5.Logic not\n 6.Logic or\n 7.Logic and\n 8. End\n");
    scanf("%d" ,&vertical);
    if (vertical < 8 && vertical != 5)
        {
    printf("Enter the operand\n");
    scanf("%d" , &operand);
      }

    if ((vertical | 0) == 0 )
    {
       Reg[i] = sum(Reg[i] , operand);
       bit1[i] = 1;
       input1 = input2 = input3 = 0;

    }
  else if((vertical | 0b0001) == 1)
    {
        Reg[i] = sub(Reg[i] , operand);
        bit2[i] = 1;
         input1 = input2 = 0;
         input3 = 1;

    }
  else if((vertical | 0b0010) == 2)
    {
        Reg[i] = mul(Reg[i] , operand);
        bit3[i] = 1;
      input1 = input3 = 0;
      input2 = 1;
    }
  else if((vertical | 0b0011) == 3)
    {
        Reg[i] = divide(Reg[i] , operand);
        bit4[i] = 1;
        input1 = 0;
        input2 = input3 = 1;
    }
   else if((vertical | 0b0100) == 4)
    {
        Reg[i] = mod(Reg[i] , operand);
        bit5[i] = 1;
         input1 = 1;
         input2 = input3 = 0;
    }
   else  if((vertical | 0b0101) == 5)
    {
        Reg[i] = not(Reg[i]);
        bit6[i] = 1;
         input1 = input3 = 1;
         input2  = 0;
    }
   else if((vertical | 0b0110) == 6)
    {
        Reg[i] = or(Reg[i] , operand);
        bit7[i] = 1;
         input1 = input2 = 1;
         input3 = 0;
    }
  else if((vertical | 0b0111) == 7)
    {
        Reg[i] = and(Reg[i] , operand);
        bit8[i] = 1;
         input1 = input2 = input3 = 1;
    }
    else
        {
      printf("Process ended\n");
        break;
    }


            printf("    ______________________\n");
               printf("  %d_|                    |_ add (%d) _______________\n" ,input1 , bit1[i]);
                  printf("    |                    |_ substract (%d)____|  R  |\n", bit2[i]);
                    printf("  %d_|                    |_ multiply (%d)_____|     |\n" , input2 , bit3[i]);
                      printf("    |    3 to            |_ divide (%d)_______|  E  |\n" ,bit4[i]);
                         printf("  %d_|       8 Decoder    |_ modulus (%d)______|     |\n" , input3 , bit5[i]);
                          printf("    |                    |_ Logic not (%d)____|  G  |\n" , bit6[i]);
                             printf("    |                    |_ Logic or (%d)_____|     |\n" ,bit7[i]);
                               printf("    |____________________|_ Logic and (%d)____|__%d__|\n" , bit8[i] , i);
                               printf("\n");
                               printf("Register %d = 0x%x \n" , i  ,Reg[i]);


        }
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
    int a  = ~x;
         return a;
}
int and(int x , int y)
{
                   return x & y;
}
int or(int x , int y)
{
               return x | y;
}







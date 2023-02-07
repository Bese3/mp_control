#include"shell.h"


/* This project consist of the demonstration of how MicroProgrammed
 * Control generate a control signal in a Computer .
 * Have an assumption of 3 bus system.
 * Consist of two implementation method which are
 * Vertical  Implementation &
 * Horizontal Implementation
 * Control Memory has the instruction for Arithmetic and
 * Logic unit.
 * In addition we did not include the address bits and Read or write bit in
 * control word for simplicity.
 */





int select = 0;

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



   printf("How many ALU functions do u want ( I. up to 8 Max )\n");
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
     int source[3][5] = {};
     int source1[3][5] = {};
     int source2[3][5] = {};


    for (int i = 0; i < add; i++)
    {
     Reg[i] = random % (i + 10);
     printf("Registers with the value 0x%x is created\n" , Reg[i]);

    }
    printf("\n");
    //choosing the type of operation to perform
     int operation = 0;
    int operand = 0;
    int operand1 = 0;
    int operand2 = 0;
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
    printf("Inform the Processor which kind of operation is applied \n" , i);
    printf(" 1.add\n 2.substract\n 3.multiply\n 4.divide\n 5.clear\n 6.Logic not\n 7. Logic or\n 8.Logic and\n 9. End\n");
    scanf("%d" ,&operation);

    while(operation < 9 && select < operation)
    {
        printf("This function is not added in ALU enter again\n");
         scanf("%d" ,&operation);
    }
    if (operation < 9 && operation > 0)   // choosing the register operation
        {
    printf("Enter the Register for the operation\n");
    scanf("%d" , &operand);
     if(operand == 0)
        source[0][i] = 1;

        else if(operand == 1)
            source1[0][i] = 1;
        else if(operand == 2)
            source2[0][i] = 1;


   if (operation != 5 || operation != 6 )
    {
    printf("Enter the 2nd Register for the operation\n");
    scanf("%d" , &operand1);

      if(operand1 == 0)
        source[1][i + 1] = 1;

        else if(operand1 == 1)
            source1[1][i + 1] = 1;
        else if(operand1 == 2)
            source2[1][i + 1] = 1;
            }
    printf("Enter storing register\n");
    scanf("%d"  ,&operand2);
     if(operand2 == 0)
        source[2][i + 2] = 1;

        else if(operand2 == 1)
            source1[2][i + 2] = 1;
        else if(operand2 == 2)
            source2[2][i + 2] = 1;


      }

    if (operation == 1)
    {
        printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
        Reg[operand2] = sum(Reg[operand] , Reg[operand1]);
        printf("Register %d is updated to %x \n", operand2 , Reg[operand2]);
        bit1[i] = 1;

    }
  else if(operation == 2)
    {
         printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
        Reg[operand2] = sub(Reg[operand] , Reg[operand1]);
         printf("Register %d is updated to %x \n", operand2 , Reg[operand2]);
        bit2[i] = 1;
    }
   else if(operation == 3)
    {
         printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
      Reg[operand2] = mul(Reg[operand] , Reg[operand1]);
       printf("Register %d is updated to %x \n", operand2 , Reg[operand2]);
      bit3[i] = 1;
    }
  else  if(operation == 4)
    {
         printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
     Reg[operand2] =   divide(Reg[operand] , Reg[operand1]);
      printf("Register %d is updated to %x \n", operand2 , Reg[operand2]);
     bit4[i] = 1;
    }
  else if(operation == 5)
  {
       printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
    Reg[operand2] =   clr(Reg[operand]);
     printf("Register %d is updated to %x \n", operand2 , Reg[operand2]);
    bit5[i] = 1;
  }
  else if(operation == 6)
  {
       printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
    Reg[operand2] = not(Reg[operand]);
     printf("Register %d is updated to %x \n", operand2 , Reg[operand2]);
    bit6[i] = 1;
  }
  else if(operation == 7)
  {
       printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
   Reg[operand2] = or(Reg[operand] , Reg[operand1]);
    printf("Register %d is updated to %x \n", operand2 , Reg[operand2]);
   bit7[i] = 1;
  }
  else if(operation == 8)
  {
       printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
     Reg[operand2] = and(Reg[operand] , Reg[operand1]);
      printf("Register %d is updated to %x \n", operand2 , Reg[operand2]);
     bit8[i] = 1;
  }
  else if(operation == 9)
     break;
        }
    }while(operation <= 8);

        printf("Register value of Reg[%d] updated  to 0x%x\n" , operand2 , Reg[operand2]);
        printf("MicroInstruction        Source1     Source2      Destination\n");

    for(int i = 0; i < add; i++)
    {


        printf("%d%d%d%d%d%d%d%d                   %d%d%d       %d%d%d          %d%d%d\n" , bit1[i] ,bit2[i] ,bit3[i] , bit4[i],bit5[i] ,bit6[i],bit7[i],bit8[i] , source[0][i] , source1[0][i] , source2[0][i] , source[1][i + 1] ,source1[1][i + 1]  ,source2[1][ i + 1]  ,source[2][i + 2] , source1[2][i + 2] , source2[2][i + 2] );

    }
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
     int source[3][5] = {};
     int source1[3][5] = {};



    for (int i = 0; i < add; i++)
    {
     Reg[i] = random % (i + 10);
     printf("Registers with the value 0x%x is created\n" , Reg[i]);

    }
    printf("\n");

    //vertically implementing

    int vertical = 0;
    int operand = 0;
    int operand1 = 0;
    int operand2 = 0;
   int bit1[3] = {};
    int bit2[3] = {};
    int bit3[3] = {};
    int bit4[3] = {};
    int bit5[3] = {};
    int bit6[3] = {};
    int bit7[3] = {};
    int bit8[3] = {};
    int input1[3] = {};
    int input2[3] = {};
    int input3[3] = {};
  do
    {
    for(int i = 0; i < add; i++)
        {
     printf("Enter 3 bit number in decimal to decode in to Control Word \n");
    printf(" 0.add\n 1.substract\n 2.multiply\n 3.divide\n 4.clear\n 5.Logic not\n 6.Logic or\n 7.Logic and\n 8. End\n");
    scanf("%d" ,&vertical);
    while(select < vertical && vertical < 8 || (vertical | select) == 0)
    {
        printf("This function is not added in ALU enter again\n");
         scanf("%d" ,&vertical);
    }
     if (vertical < 8 && vertical >= 0)
        {
    printf("Enter the Register for the operation\n");
    scanf("%d" , &operand);
     if(operand == 0)
        source[0][i] = 0;

        else if(operand == 1)
            source1[0][i] = 1;
        else if(operand == 2)
            source[0][i] = 1;


 if(vertical != 4)
    {
    printf("Enter the 2nd Register for the operation\n");
    scanf("%d" , &operand1);

      if(operand1 == 0)
        source[1][i] = 0;

        else if(operand1 == 1)
            source1[1][i] = 1;
        else if(operand1 == 2)
            source[1][i] = 1;
 }
    printf("Enter storing register\n");
    scanf("%d"  ,&operand2);
     if(operand2 == 0)
        source[2][i] = 0;

        else if(operand2 == 1)
            source1[2][i] = 1;
        else if(operand2 == 2)
            source[2][i] = 1;


      }

    if ((vertical | 0) == 0 )
    {
          printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
       Reg[operand2] = sum(Reg[operand] , Reg[operand1]);
       bit1[i] = 1;
       input1[i] = input2[i] = input3[i] = 0;

    }
  else if((vertical | 0b0001) == 1)
    {
          printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
        Reg[operand2] = sub(Reg[operand] , Reg[operand1]);
        bit2[i] = 1;
         input1[i] = input2[i] = 0;
         input3[i] = 1;

    }
  else if((vertical | 0b0010) == 2)
    {
          printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
        Reg[operand2] = mul(Reg[operand] , Reg[operand1]);
        bit3[i] = 1;
      input1[i] = input3[i] = 0;
      input2[i] = 1;
    }
  else if((vertical | 0b0011) == 3)
    {
          printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
        Reg[operand2] = divide(Reg[operand] , Reg[operand1]);
        bit4[i] = 1;
        input1[i] = 0;
        input2[i] = input3[i] = 1;
    }
   else if((vertical | 0b0100) == 4)
    {
          printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
        Reg[operand2] = clr(Reg[operand]);
        bit5[i] = 1;
         input1[i] = 1;
         input2[i] = input3[i] = 0;
    }
   else  if((vertical | 0b0101) == 5)
    {
          printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
        Reg[operand2] = not(Reg[operand]);
        bit6[i] = 1;
         input1[i] = input3[i] = 1;
         input2[i] = 0;
    }
   else if((vertical | 0b0110) == 6)
    {
        printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
        Reg[operand2] = or(Reg[operand] , Reg[operand1]);
        bit7[i] = 1;
         input1[i] = input2[i] = 1;
         input3[i] = 0;
    }
  else if((vertical | 0b0111) == 7)
    {
          printf("Loading from Registers.....\n");
        sleep(2);
        printf("Storing the value back to Register %d\n" ,operand2);
        sleep(1);
        Reg[operand2] = and(Reg[operand] , Reg[operand1]);
        bit8[i] = 1;
         input1[i] = input2[i] = input3[i] = 1;
    }
    else if((vertical | 0b1000) == 8)
        {
      printf("Process ended\n");
        break;
        }


            printf("    ______________________\n");
               printf("  %d_|                    |_ add (%d)\n" ,input1[i], bit1[i]);
                  printf("    |                    |_ substract (%d)\n", bit2[i]);
                    printf("  %d_|                    |_ multiply (%d)\n" , input2[i] , bit3[i]);
                      printf("    |    3 to            |_ divide (%d)\n" ,bit4[i]);
                         printf("  %d_|       8 Decoder    |_ clear (%d)\n" , input3[i] , bit5[i]);
                          printf("    |                    |_ Logic not (%d)\n" , bit6[i]);
                             printf("    |                    |_ Logic or (%d)\n" ,bit7[i]);
                               printf("    |____________________|_ Logic and (%d)\n" , bit8[i]);
                               printf("\n");
                                printf("Register value of Reg[%d] updated  to 0x%x\n" , operand2 , Reg[operand2]);
                                printf("\n");



        }
   }while(vertical != 8);

        printf("MicroInstruction        Source1     Source2      Destination\n");

    for(int i = 0; i < add; i++)
    {


        printf("%d%d%d                     %d%d         %d%d            %d%d\n" , input1[i] , input2[i] , input3[i] , source[0][i] , source1[0][i] , source[1][i] , source1[1][i] ,source[2][i]  ,source1[2][i]);

    }
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
           if(y != 0)
                  return x / y;
}
int clr(int x)
{
     x = 0b000 ;
      return x;
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







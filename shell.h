#ifndef SHELL_H
#define SHELL_H


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void horizontal();
void vertical();


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
int clr(int x);
int or(int x , int y);
int not(int x );
int and(int x , int y);
#endif /*SHELL_H*/

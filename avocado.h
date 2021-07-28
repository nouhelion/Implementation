//
// Created by HP Omen on 28/07/2021.
//
//Type Defined in header file <stdarg.h>

//va_list (type)
//holds the information needed by macros va_start, va_arg, va_end, and va_copy

//Macros Defined in header file <stdarg.h>

//va_start (macro)
//start of iterations in the variadic function arguments

//va_arg (macro)
//get the next variadic function argument

//va_copy (macro)
//makes a copy of the variadic function arguments
//(Available only in C99)

//va_end (macro)
//ends of iteration in the variadic function arguments

#ifndef PHALLUS_AVOCADO_H
#define PHALLUS_AVOCADO_H

#endif //PHALLUS_AVOCADO_H

#include <stdio.h>
#include <stdarg.h>

void avocado(char *,...); //my printf implementation
char* change(unsigned int,int); //changeing ints to some other shitty conversion aka octal / bin / hex ...

void avocado(char* body,...)
{
    char *road;
    unsigned int index;
    char *string;

    //initializing arguments
    va_list arg;
    va_start(arg,body);

    for(road=body;*road!='\0';road++)
    {
            while (*road!='%')
            {
                putchar(*road);
                road++;
            }

            road++;

            //fetching and executing arguments

            switch(*road)
            {
                case 'c':
                    {
                    index = va_arg(arg,int); //getting the next char argument
                    putchar(index);
                    break;
                    }

                case 'd':
                {
                    index = va_arg(arg,int); //getting the next decimal/integer argument
                          if(index<0)
                          {
                              index=-index;
                              putchar('-');
                          }
                          puts(change(index,10));
                    break;
                }

                case 'o':
                {
                    index = va_arg(arg,unsigned int); //getting the next octal representation
                    puts(change(index,8));
                    break;
                }

                case 's':
                {
                    string = va_arg(arg,char *); //getting the next string
                    puts(string);
                    break;
                }

                case 'x':
                {
                    index = va_arg(arg,unsigned int); //getting the next hexadecimal representation
                    puts(change(index,16));
                    break;
                }
            }
    }
    // closing the argument list
            va_end(arg);
}


char *change(unsigned  int number, int base){

    static char representation[]="0123456789ABCDEF";
    static char buffer[50];

    char *pointer;

    pointer=&buffer[49];
    *pointer='\0';

    do
    {
        *--pointer=representation[number%base];
        number/=base;
    }while(number!=0);

    return (pointer);
}
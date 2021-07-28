//
// Created by HP Omen on 28/07/2021.
//
//Type Defined in header file <stdarg.h>

//va_list (type)
//holds the inbodyion needed by macros va_start, va_arg, va_end, and va_copy

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


#include <stdio.h>
#include <stdarg.h>

void avocado(char *,...); 				//Our printf function
char* change(unsigned int, int); 		//change integer number into octal, hex, etc.




void avocado(char* body,...)
{
    char *road;
    unsigned int index;
    char *string;

    //Module 1: Initializing Myprintf's arguments
    va_list arg;
    va_start(arg, body);

    for(road = body; *road != '\0'; road++)
    {
        while( *road != '%' )
        {
            putchar(*road);
            road++;
        }

        road++;

        //Module 2: Fetching and executing arguments
        switch(*road)
        {
            case 'c' : index = va_arg(arg,int);		//Fetch char argument
                putchar(index);
                break;

            case 'd' : index = va_arg(arg,int); 		//Fetch Decimal/Integer argument
                if(index < 0)
                {
                    index = -index;
                    putchar('-');
                }
                puts(change(index,10));
                break;

            case 'o': index = va_arg(arg,unsigned int); //Fetch Octal representation
                puts(change(index,8));
                break;

            case 's': string = va_arg(arg,char *); 		//Fetch string
                puts(string);
                break;

            case 'x': index = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                puts(change(index,16));
                break;
        }
    }

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg);
}

char *change(unsigned int number, int base)
{
    static char Representation[]= "0123456789ABCDEF";
    static char buffer[50];
    char *pointer;

    pointer = &buffer[49];
    *pointer = '\0';

    do
    {
        *--pointer = Representation[number%base];
        number /= base;
    }while(number != 0);

    return(pointer);
}
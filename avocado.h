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

#ifndef PHALLUS_AVOCADO_H
#define PHALLUS_AVOCADO_H

#endif //PHALLUS_AVOCADO_H

#include "general.h"

//prototypes of the functions
void avocado(char *,...); 				//Our printf function
char* change(unsigned int, int); 		//change integer number into octal, hex, etc.
int puppy(char *,...);                  //personal scanf


//definions of the functions
void avocado(char* body,...)//body represents the body fo the print function called avocado hehe
{
    char *road; //its an index that we gonna use to travel in the string inside the avocado
    unsigned int index;
    char *string;
    //Etape 1 => Initializing avocado arguments by using standard argument library
    //we gonna use the variable "arg" to manipulate the arguments list
    va_list arg;
    //we be using the va_start to see when the arguments start
    va_start(arg, body);

    for(road = body; *road != '\0'; road++)//a string ends with '\0'
    {   //as long as the character isnt equal to % it means its not argument ,therefore we will print it with putchar
        while( *road != '%' && *road != '\0')
        {
            putchar(*road);
            road++;
        }

        road++;

        //Etape 2 => Fetching and executing arguments
        switch(*road)
        {   //var_arg will get the next argument and store it in arg as for the thing next to it , it represents the data type

            //%c
            case 'c' :
                {
                index = va_arg(arg, int);                          //Fetch char argument
                putchar(index); //we gonna print strings with putchar
                }
                break;

            //%d
            case 'd' :
                {
                index = va_arg(arg, int);                     //Fetch Decimal/Integer argument
                if (index < 0)//if the integer is negative
                    {
                    index = -index;
                    putchar('-');//we gonna print a character '-' before we print it then the number
                    }
                puts(change(index, 10));//converting the decimal number to a char to print it with puts
                }
                break;

            //%o
            case 'o':
                {
                index = va_arg(arg, unsigned int);             //Fetch Octal representation
                puts(change(index, 8));//converting the octal number to a char to print it with puts
                }
                break;

            //%s
            case 's':
                {
                string = va_arg(arg, char *);                   //Fetch string
                puts(string);
                }
                break;

            //%x
            case 'x':
                {
                index = va_arg(arg, unsigned int);           //Fetch Hexadecimal representation
                puts(change(index, 16));//converting the hexadecimal number to a char to print it with puts
                }
                break;
        }
    }

    //Module 3: Closing argument list
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


int puppy (char * str, ...)
{
    va_list vl;
    int index = 0, jojo=0, retonia = 0;
    char buffer[100] = {0}, tmp[20], c;
    char *out_loki;
    while(c != '\n') {
        if (fread(&c, 1, 1, stdin)) {
            buffer[index] = c;
            index++;
        }
    }
            va_start( vl, str );
    index = 0;
    while (str && str[index]) {
        if (str[index] == '%') {
            index++;
            switch (str[index]) {
                case 'c': {
                    * (char *)va_arg( vl, char* ) = buffer[jojo];
                    jojo++;
                    retonia ++;
                    break;
                }
                case 'd': {
                    * (int *)va_arg( vl, int* ) = \
          strtol(&buffer[jojo], &out_loki, 10);
                    jojo += out_loki -&buffer[jojo];
                    retonia++;
                    break;
                }
                case 'x': {
                    * (int *)va_arg( vl, int* ) = \
          strtol(&buffer[jojo], &out_loki, 16);
                    jojo += out_loki -&buffer[jojo];
                    retonia++;
                    break;
                }
                case 'o': {
                    * (int *)va_arg( vl, int* ) = \
          strtol(&buffer[jojo], &out_loki, 8);
                    jojo += out_loki -&buffer[jojo];
                    retonia++;
                    break;
                }
                case 's': {
                    out_loki = (char *)va_arg( vl, char* );
                    strcpy(out_loki, &buffer[jojo]);
                    jojo += strlen(&buffer[jojo]);
                    retonia++;
                    break;
                }
            }
        } else {
            buffer[jojo] =str[index];
            jojo++;
        }
        index++;
    }
            va_end(vl);
    return retonia;
}
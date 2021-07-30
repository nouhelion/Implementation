#include "avocado.h"


int main(){

    char c;
    int i;
    int h;
    int o;
    char str_buff[20];
    int ret = 0;
    printf("Enter a  char , int , hex , oct , string\n");
    ret = puppy("%c %d %x %o %s", &c, &i, &h, &o, str_buff);
    printf("C = %c, I = %d, H = %d, O = %d, S = %s returns %d", c, i, h, o, str_buff, ret);
    return 0;
}

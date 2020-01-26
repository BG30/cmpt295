#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer, size_t);
void show_bits(int);
void show_int(int);
void show_float(float);
void show_pointer(void *) ;
int  mask_LSbits(int);

int main() {
    int ival = 12345;
    float fval = (float) ival;
    int *pval = &ival;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);

/* Add your test cases here in order
   to test your new functions. */
    printf("\nTesting for show_bits\n");

    //testing for show_bytes

    //testing for int type
    show_bytes( (byte_pointer)pval, sizeof(int));
    
    //tesing for float type

    //creating float pointer
    float *fpval = &fval; 
    show_bytes( (byte_pointer)fpval, sizeof(float));


    //testing for show_bits
    printf("Testing for show_bits\n");

    //testing if number at positive 32-bit capacity number can be executed
    printf("\nTesting 2147483647");
    show_bits(2147483647);

    //testing if number at negative 32-bit capacity can be executed
    printf("\nTesting -2147483648");
    show_bits(-2147483648);

    //testing positive numbers within bounds
   	printf("\nTesting positive numbers within bounds with show_bits()\n");
    printf("Decimal 12345 to binary\t");
    show_bits(12345);
    
    printf("Decimal 5484 to binary\t");
    show_bits(5484);
    
    printf("Decimal 1 to binary\t");
    show_bits(1);
    
    printf("Decimal 0 to binary\t");
    show_bits(0);


    //testing negative numbers within bounds
    printf("\nTesting negative numbers within bounds with show_bits()\n");
    printf("Decimal -12345 to binary\t");
    show_bits(-12345);

    printf("Decimal -1 to binary\t");
    show_bits(-1);

    printf("Decimal -50 to binary\t");
    show_bits(-50);

    printf("Decimal -400095 to binary\t");
    show_bits(-400095);



    //testing for mask_LSbits()

    	//testing with valid test cases
    	printf("\nTesting valid test cases for mask_LSbits()\n");
    	printf("2 ->  %d\n", mask_LSbits(2));
    	printf("14 ->  %d\n", mask_LSbits(14));
    	printf("73 ->  %d\n", mask_LSbits(73));
    	printf("4 ->  %d\n", mask_LSbits(4));
    	printf("15 ->  %d\n", mask_LSbits(15));

    	//testing invalid cases
    	printf("\nTesting invalid test cases for mask_LSbits\n");
    	printf("0 ->  %d\n", mask_LSbits(0));
    	printf("-62 ->  %d\n", mask_LSbits(-62));









}
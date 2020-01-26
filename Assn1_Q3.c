/*
 * Name: Balrick Gill
 * Student number: 301309400
*/


#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;




void show_bytes(byte_pointer start, size_t len) {
    size_t i;

    for (i = 0; i < len; i++){
        
        printf("%p\t", &*(start+i));   //prints memory address
        printf(" 0x%.2x", *(start+i));    //prints content of byte    
        
        printf("\n");
    }

    printf("\n");
}

void show_int(int x) {
	printf("\nival = %d\n", x); 
    show_bytes((byte_pointer) &x, sizeof(int)); 
}

void show_float(float x) {
    printf("fval = %f\n", x); 	
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
	printf("pval = %p\n", x); 
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_bits(int num) {      
    //Note: function's input has max size of 32 bits signed
    
    //variable declarations
    int bin[31];     // collects the binary representation of numbers
    int counter = 0; // counts the number of calculated digits

    
    if(num > 2147483647){ //unable to convert because beyond positive limitation
        printf("Unable to show bits because number is beyond positive limitation\n");
    }
    else if(num < -2147483648){ //unable to convert because beyond negative limitation
        printf("Unable to show bits becasue number is beyond negative limitation\n");
    }
    else if (num >= 0){  //converting a positive number within bounds      
        //getting the binary number without leading 0's
        for (int i = 0; num > 0; i++){
            bin[i] = num%2;
            num = num / 2;
            counter++;
        }

        //displaying leading 0's
        for (int i = 32 - counter; i > 0; i--){
            printf("%d", 0);
        }

        //displaying the binary number
        for (int i = counter-1; i >= 0; i--){
            printf("%d", bin[i]);
        }
        printf("\n");
    }
    else if (num < 0){  //converting a negative number
        counter = 0;

        //Step 1:   convert integer to binary

        //get only integer
        num *= -1;

        //convert num to binary
        for (int i = 0; num > 0; i++){
            bin[i] = num%2;
            num = num / 2;
            counter++;
        }

        //add leading zeros
        for (int i = counter; i < 32; i++){
            bin[i] = 0;
        }


        //Step 2:   flip the bits
        for (int i = 0; i < 32; i++){
            if (bin[i] == 0){
                bin[i] = 1;
            }
            else{
                bin[i] = 0;
            }
        }

        //Step 3:   add 1  (from left to right since array is still inverted)
        

        //if adding 1 doesn't cause a carry, continue to printing the integer
        if( (bin[0] + 1) == 1 ){
            bin[0] = 1;
        }
        else { //will need to carry
            //manually carry the first bit
            bin[0] = 0;

            //loop carry for the rest of the bits
            for (int i = 1; i < 33; i){
                
                //situation 1+1
                if( (bin[i] + 1) == 2 ){
                    bin[i] = 0;
                }

                //situation 1+0 or 0+1
                else if( (bin[i] + 1) == 1 ){
                    bin[i] = 1;
                    break;
                }
            }
        }
  
        //Step 4: display results
        for (int i = 31; i >= 0; i--){
            printf("%d", bin[i]);
        }
        printf("\n");
    }
    else{ // Invalid Input
        printf("Invalid input\n");
    }
}


int  mask_LSbits(int n){
    //using 32-bit size
    if(n == 0){
        n = 1;
    }
    else if(n < 0){
        n = 1;
    }
    else if(n > 32){
        n = 2<<31;
    }
    else{
        n = 2<<(n - 1);
    }
    

    return (n - 1);
}
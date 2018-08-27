
#include <stdio.h>
#include <stdlib.h> 

/* This program is part of problem 1 exercise on project 2.
 * 
 * In order to answer the questions, you need to run this program
 * in the gdb debugger and provide a command line argument
 * that is equal to the last four digits of your N number.
 * For example: if my N number is N12345678, I would run this program
 * with an command line argument of 5678. 
 * 
 */ 


/* This function converts the last four digits
 * of your N number to an alternative notation. 
 * You will discover what it does exactly as part of this
 * exercise. 
 */ 
int convert( long num, char * hex ) ;


/* The inline comment indicate where you should 
 * set the breakpoints. 
 */

int main( int argc, char ** argv ) {
    if (argc < 2) {
        printf("ERROR: this program needs a command line argument\n");
        printf("\tUsage: %s id_number\n\n", argv[0] ); 
        exit(1); 
    }
    // BREAKPOINT A  
    // set a breakpoint on the line below 
    long id = strtol(argv[1], NULL, 10); 
    
    printf("%ld\n\n", id); 
    
    // BREAKPOINT B
    // set a breakpoint on the line below 
    char * hex_string = (char * ) calloc(1, 20); 
    
    // BREAKPOINT C
    // set a breakpoint on the line below 
    convert( id, hex_string ); 
    
    
    // BREAKPOINT I
    // set a breakpoint on the line below 
    printf("%s\n\n", hex_string); 
    
    free (hex_string);

}
 
int  convert( long num , char * hex) {

    // BREAKPOINT D
    // set a breakpoint on the line below 
	if (num >=0 && num < 10 ) {
        hex[0] = (char)(num + '0');

        // BREAKPOINT E
        // set a breakpoint on the line below 
        return 1; 
    }
    else if (num >=10 && num < 16 ) {
        hex[0] = (char)( num - 10 + 'A' ); 
        
        // BREAKPOINT F
        // set a breakpoint on the line below 
        return 1; 
    }
    else {
        int current = num % 16;
        
        int size = convert ( num / 16, hex);
        
        if (current >=0 && current < 10 ) {
            hex[size] = (char)(current + '0');
        
            // BREAKPOINT G
            // set a breakpoint on the line below 
            return size + 1; 
        }
        else  {
            hex[size] = (char)( current - 10 + 'A' ); 
        
            // BREAKPOINT H
            // set a breakpoint on the line below 
            return size + 1; 
        } 
    }
} 

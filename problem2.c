
#include <stdio.h>
#include <stdlib.h>

/*
 * Template for problem 1.
 */

int main ( int argc, char ** argv ) { 
    
    if (argc < 4){
        printf("ERROR: this program needs three command line arguments\n");
        printf("\tUsage: %s e|d input_file_path output_file_path\n\n", argv[0] ); 
        exit(1); 
    }
    //open the file for reading
    FILE * in_file = fopen (argv[2], "r" ); 
    
    //open the file for writing 
    FILE * out_file = fopen (argv[3], "w" );
    
    int c1 = '\0';
    int end_in_newline = 0; 
    
    //read digits one by one and write them to the output file
    while ( EOF != (c1 = fgetc(in_file)) ) {
        //if newline is found before the end of file, it is not a valid input file
        if (end_in_newline){ 
            printf("ERROR: invalid character detected: only one newline "
                    "allowed at the end of a file\n");
            exit(1);
        }
        //if newline found, the next char should be end of file (EOF)
        if (c1 == '\n') {
            end_in_newline = 1; 
            continue;
        }  
        if (c1 <'0' || c1 >'9') {
            printf("ERROR: invalid character detected c1: %c \n\n", c1);
            exit(1);
        }
                
        fputc(c1, out_file); 
    } 
    
    if (end_in_newline){ 
        fputc('\n',out_file);
    }
    
    //close both files 
    fclose ( in_file); 
    fclose ( out_file); 
    
}


# Project 2

__Due date: Friday, March 30 at 11:55pm.__

---
**You may discuss any of the assignments with your classmates and instructors (or anyone else) but
all work for all assignments must be entirely your own. 
Any sharing or copying of assignments will be considered cheating (this includes posting of partial or complete solutions on
Piazza, GitHub public repositories or any other public forum). If you get significant help 
from anyone, you should acknowledge it in your submission (and your grade will be proportional to the part 
that you completed on your own).
You are responsible for every line in your program: you need to know what it does and why.**

## Programming requirements:

- The programs should be leak-free: any memory that is allocated should be freed before the program terminates.
- The programs have to be documented! Any file that you edit should have preamble including 
your name as the author, description of the purpose of the program and inline comments
in the functions that you implement. 
- The code has to follow C programming conventions.
- The code has to be formatted properly.
- The C code has to look like a high level programming language: it should not be accessing
the registers directly, it should not name variables using names of registers, it should simply 
all calculations as much as possible (for example, `( x + 2* x) << 2` should be simplified to `12*x`). 

In addition, you are required to make at least 5 commits to your repository. Each time you make a significant change/improvement to your solutions, you should commit and push the changes to the remote repository. This way, if there are any problems with your local copy of the files, you have a recent version of the code available.
Your commits should be distributed over time - they should not be all made within an hour before the due date.



## Problem 1

Compile the attached `problem1.c` program using 

```
gcc -Og -g problem1.c -o problem1
```

Make sure that you are using the class virtual machine (different versions of gcc and libraries may result in different answers for this question). 

This program takes as an argument a number. To complete both parts of this problem you should run the program
using the last four digits of your N-number as the command line argument. For example: if my N number is N12345678, I would run this program with an command line argument of 5678:

```
./problem1 5678
```

Complete the tables for Parts 1 and 2 in the file problem1_answers.md (make sure that the answers are actually formatted as tables when you preview them). 


__Part 1:__ 

In the code for `problem1.c` there are comments indicating where you should place breakpoints.
Setup all of the breakpoints before starting the program.
Your task is to record values of some of the registers at the breakpoints. 

You can move from one breakpoint to the next using `continue` command in GDB. 

Due to the nature of the program and your input, some of the breakpoints may be visited several times, others may
never be visited. Modify the rows of the table below so that they refect the actual order of visited breakpoints
while your code is executing. If a breakpoint is visited more than once, then the first entry in the row should
be numbered, for example: BREAKPOINT E1 and then BREAKPOINT E2 (instead of just a single entry for BREAKPOINT E). Remove any rows corresponding to breakpoints that are never visited. 


breakpoint | %rax | %rdi | %rsi | %rbx | %rsp | %rip 
---|---|---|---|---|---|---
BREAKPOINT A  |  |  |   |   |   |   
BREAKPOINT B  |  |  |   |   |   |   
BREAKPOINT C  |  |  |   |   |   |   
BREAKPOINT D  |  |  |   |   |   |   
BREAKPOINT E  |  |  |   |   |   |   
BREAKPOINT F  |  |  |   |   |   |   
BREAKPOINT G  |  |  |   |   |   |   
BREAKPOINT H  |  |  |   |   |   |   
BREAKPOINT I  |  |  |   |   |   |   
BREAKPOINT J  |  |  |   |   |   |   



__Part 2:__ 

Look at the assembly instructions for `problem1.c`. There may be some instructions that you are not
familiar with - this is ok. Try to identify the instructions corresponding to the breakpoints from problem 1.
Repeat the run of the program, but this time use `nexti` and `stepi` instructions to advance the program
one assembly instruction at a time. At the point of the instructions that you identified as breakpoints, record
the values of the specified registers. HINT: they are not going to be exactly the same as in the table in Part 1.


breakpoint | corresponding instruction | instruction's memory address 
---|---|---
BREAKPOINT A  |  |  
BREAKPOINT B  |  |  
BREAKPOINT C  |  |  
BREAKPOINT D  |  |  
BREAKPOINT E  |  |  
BREAKPOINT F  |  |  
BREAKPOINT G  |  |  
BREAKPOINT H  |  |  
BREAKPOINT I  |  |  
BREAKPOINT J  |  |  



breakpoint | %rax | %rdi | %rsi | %rbx | %rsp | %rip 
---|---|---|---|---|---|---
BREAKPOINT A  |  |  |   |   |   |   
BREAKPOINT B  |  |  |   |   |   |   
BREAKPOINT C  |  |  |   |   |   |   
BREAKPOINT D  |  |  |   |   |   |   
BREAKPOINT E  |  |  |   |   |   |   
BREAKPOINT F  |  |  |   |   |   |   
BREAKPOINT G  |  |  |   |   |   |   
BREAKPOINT H  |  |  |   |   |   |   
BREAKPOINT I  |  |  |   |   |   |   
BREAKPOINT J  |  |  |   |   |   |   



## Problem 2

The International Pi Day happens every year on March 14. 
This problem is inspired by an article I read this year titled [Pi Day: 12 fun facts and ways to celebrate](https://enterprisersproject.com/article/2018/3/pi-day-12-fun-facts-and-ways-celebrate?utm_medium=Email&utm_campaign=&sc_cid=701f2000000tyL0AAI) by  Carla Rudder.
There is a claim in the article that the 22 trillion known digits of pi take nearly 9 terabytes when stored in a file.
Well, this means that we should be able to store 22\*10^12 digits in 9\*10^12 bytes (assuming we are using powers of 10 instead of powers of 2 to calculate a terabyte). 
This means that we are able to store 2.4 digits in a single byte. If we store each digit as individual character in a text file, than we are using 1 byte for each 
digit/character. 

Your task for this problem is to write a program that reads in a text file containing digits of pi (each digit is a single 1 byte character) and create a new file
that contains the same digits but saved in a more efficient/compact way (you need to figure out how you wish to store those digits). The solution that reduces the space by half
should be fairly simple (and will earn you most of the credit for this problem, if implemented correctly). You should try to reduce the space even further, though. 

In order to verify that your code actually saves the digits (instead of throwing half of them away), your program should provide _conversion_ in both ways (from the
text representation to the compact representation and from the compact representation to the text representation). For that purpose the program should take three command line arguments:

- a single letter `c` or `e` to indicate if the program should _compress_,`c`, the text 
into more compact representation, or _extract_, `e`, the text from the more compact representation. 
- name of the input file
- name of the output file 

In particular, when the program is run as follows:

```
./problem2 c pi_1000 pi_1000_short
./problem2 e pi_1000_short pi_1000_extracted
```

then the two files: `pi_1000` and `pi_1000_extracted`  should be identical. 

You can assume that any valid input file will contain only digits. The last character in the file might be a newline character. 

The provided source code for `problem2.c` produces an output file that is identical to the input file. You should modify that file to achieve
the goals of this problem. You may use other ways of reading and writing to files (you are not obligated to use the methods that
are currently in `problem2.c`). You should explore functions mentioned in the "See Also" section in the manual page for `fputs` and `fgets` functions. 

## Problem 3

You are given two object files `problem3.o` and `p3_given.o`. The first one contains the `main` function, the second contains another function. Your
task is to write C code for the function in `p3_given.o`. Your function may not end up being identical to the one in the given file, but it should
be equivalent (i.e., given the same inputs, it should produce the same output). 

The `main()` function executes a few tests of the function implemented in `p3_given.o`. These are not exhaustive tests and passing them does not 
guarantee correctness, but it should be a pretty good indicator that your code is on the right track. 

Building and running the given code:

```
gcc -o problem3_given p3_given.o problem3.o` 
./problem3_given
```

Your own function should be implemented in the file `p3.c`. In order to build the object file, run :

``` 
gcc -c p3.c
```

In order to build and run your code:

```
gcc -o problem3 p3.o problem3.o` 
./problem3
```

If there is no output produced by the code, the function passed the simple tests in `main`. 




#include<stdio.h> 
#include<setjmp.h> 
jmp_buf buf; 
void func() 
{ 
    printf("Welcome to GeeksforGeeks\n"); 
  
    // Jump to the point setup by setjmp 
    longjmp(buf, 1); 
  
    printf("Geek2\n"); 
} 
  
int main() 
{ 
    // Setup jump position using buf and return 0 
    if (setjmp(buf)) 
        printf("Geek3\n"); 
    else
    { 
        printf("Geek4\n"); 
        func(); 
    } 
    return 0; 
} 

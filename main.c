/**
   Sub Set C compiler
   
   This is sub set C compiler (sscc) which support C89 subset.
   This compiler is made with very simple and fundamental technology 
   for studying compiler technology.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
   main function
*/
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Not correct number of argument.\n");
    return 1;
  }
  
  int v = atoi(argv[1]);

  /* assembler main */
  printf("	.globl	_main\n");
  printf("_main:\n");
  printf("	movl	$%d, %%eax\n", v);
  printf("	retq\n");
  
  return 0;
}

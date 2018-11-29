/**
   Assembler code generator
 */

#include "sscc.h"
#include "reg.h"


/**
   Generate assembler code
 */
void generate(Node *node) {
  generate_main();

  generate_node(node);
  
  generate_return();
}


/**
   Generate assembler to traversal node
*/
void generate_node(Node *node) {
  if (node->type == NODE_NUMBER) {
    generate_number(node);
    return;
  }

  generate_node(node->left);
  generate_node(node->right);
  
  generate_op(node);

  return;
}


/**
   Generate assembler of op-code
 */
void generate_op(Node *node) {
  printf("	pop %%rdi\n");
  printf("	pop %%rax\n");
  if (node->type == NODE_PLUS) {
    printf("	add %%edi, %%eax\n");
  }
  else if (node->type == NODE_MINUS) {
    printf("	sub %%edi, %%eax\n");
  }
  printf("	push %%rax\n");
  
  return;
}

/**
   Generate assembler of constant number
*/
void generate_number(Node *node) {
  printf("	push $%d\n", node->value);
  
  return;
}


/**
   Generate assembler 'return' code
 */
void generate_return(void) {
  printf("	pop %%rax\n");
  printf("	ret\n");
  
  return;
}


/**
   Generate main function header
 */
void generate_main(void) {
  printf("	.globl	_main\n");
  printf("_main:\n");

  return;
}

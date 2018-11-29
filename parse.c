#include "sscc.h"

/**
   This is a recursive-descent parser which make abstract syntax tree
   from program tokens array.
 */

#include "sscc.h"


/**
   Program parser (Syntax analyzer)
 */
Node *parse(void) {
  return expr();
}


/**
   Expression parser
   expr	 : number {'+' number}
         | number {'-' number}
*/
Node *expr(void) {
  Node *left = number();
  
  while (tokens[tp].type == '+' || tokens[tp].type == '-') {
    left = make_op_node(&tokens[tp++], left, number());
    tp++;
  }

  return left;
}


/**
   Number parser
 */
Node *number(void) {
  Node *node;
  
  if (tokens[tp].type == TOKEN_NUMBER) {
    node = make_number_node(&tokens[tp]);
    tp++;
  }
  else
    node = NULL;
  
  return node;
}

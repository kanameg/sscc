/**
   This is a operating function for abstract syntax tree node.
 */

#include "sscc.h"

/**
   make number node
 */
Node *make_number_node(Token *token) {
  Node *node = malloc(sizeof(Node));

  node->type = NODE_NUMBER;
  node->value = token->value;
  node->left = NULL;
  node->right = NULL;
  
  return node;
}


/**
   make operator node
*/
Node *make_op_node(Token *token, Node *left, Node *right) {
  Node *node = malloc(sizeof(Node));

  if (token->type == '+') {
    node->type = NODE_PLUS;
  }

  if (token->type == '-') {
    node->type = NODE_MINUS;
  }
  
  node->value = token->value;  
  node->left = left;
  node->right = right;
    
  return node;
}

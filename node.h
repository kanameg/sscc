#ifndef _NODE_H_
#define _NODE_H_

#include "token.h"

/**
   type of node
*/
enum {
      NODE_NUMBER = 256,
      NODE_PLUS,
      NODE_MINUS,
};


/**
   ndoe data type
 */
typedef struct node {
  int  type;           // type of node
  int  value;          // node value
  struct node *left;   // left hand node
  struct node *right;  // right hand node
} Node;


/**
 *  Declare function
 */
Node *make_number_node(Token *token);
Node *make_op_node(Token *token, Node *left, Node *right);


#endif // _NODE_H_

#ifndef _SSCC_H_
#define _SSCC_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
   type of token
*/
enum {
      TOKEN_NUMBER = 256,  // integer token
      TOKEN_EOT,           // end of token
};


/**
   token data type
*/
typedef struct token {
  int   type;   // type of token
  int   value;  // token value
} Token;


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
 *  Declare global data
 */
extern int tp;
extern Token tokens[20];  // result of tokenized


/**
 *  Declare function
 */
void tokenizer(char *s);

Node *make_number_node(Token *token);
Node *make_op_node(Token *token, Node *left, Node *right);

Node *parse(void);
Node *expr(void);
Node *number(void);

void generate(Node *node);
void generate_node(Node *node);
void generate_op(Node *node);
void generate_number(Node *node);
void generate_return(void);
void generate_main(void);

#endif /* _SSCC_H_ */

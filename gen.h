#ifndef _GEN_H_
#define _GEN_H_

#include "node.h"

/**
 *  Declare function
 */
void generate(Node *node);
void generate_node(Node *node);
void generate_op(Node *node);
void generate_number(Node *node);
void generate_return(void);
void generate_main(void);

#endif // _GEN_H_

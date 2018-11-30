#ifndef _TOKEN_H_
#define _TOKEN_H_

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
 *  Declare global data
 */
extern int tp;
extern Token tokens[20];  // result of tokenized


/**
 *  Declare function
 */
void tokenizer(char *s);

#endif // _TOKEN_H_

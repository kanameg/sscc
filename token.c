/**
   Tokenizer functions
   
 */

#include "sscc.h"

int   tp = 0;      /* token index point */
Token tokens[20];  /* token buffer */


/**
   Tokenizer
*/
void tokenizer(char *s) {
  while (*s) {
    /* skip space character */
    if (isspace(*s)) {
      s++;
      continue;
    }

    /* check if token is number */
    if (isdigit(*s)) {
      tokens[tp].type = TOKEN_NUMBER;
      tokens[tp].value = strtol(s, &s, 10);
      tp++;
      continue;
    }

    /* check op-code */
    if (*s == '+' || *s == '-') {
      tokens[tp].type = *s;
      tokens[tp].value = *s;
      s++;
      tp++;
      continue;
    }
  }
  
  return;
}




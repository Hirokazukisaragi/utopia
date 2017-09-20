#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "lexer.h"

typedef enum{
  ID,NUM,SYM
}TOKEN;

typedef struct CELL{
  TOKEN tkn;
  char name[1024];
  union{
    int number;
    char *string;
  };
  struct CELL *next;
}cell;
    

int main(int argc,char *argv[]){
  FILE *src;
  src = fopen(argv[1],"r");
  char *retok;
  cell *token;
  token = malloc(sizeof(cell));
  retok = malloc(65554);
  while(*retok != EOF){

    strcpy(token->name,lexer(src,retok));
    if(isalpha(*retok)){
      strcpy(token->name,retok);
      token->tkn = ID;
      printf("ID:%s\n",token->name);
    }else if(isdigit(*retok)){
      strcpy(token->name,retok);
      token->tkn = NUM;
      printf("NUM:%s\n",token->name);
    }else{
      strcpy(token->name,retok);
      token->tkn = SYM;
      printf("SYM:%s\n",token->name);
    }
  }
  return 0;
}

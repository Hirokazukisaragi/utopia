#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char *lexer(FILE *fp,char *retok){
  int i = 0;
  while(!feof(fp)){
    retok[i] = fgetc(fp);
    if(feof(fp)){
      break;
    }
    if(retok[i] == '\0'){
      return retok;
    }
    if(isspace(retok[i])){
      continue;
    }
    if(isalpha(retok[i])){
      i++;
      while(isalnum(retok[i] = fgetc(fp))){
	i++;
      }
      ungetc(retok[i],fp);
      retok[i] = '\0';
      return retok;
    }else if(isdigit(retok[i])){
      //retok[i] = fgetc(fp);
      i++;
      while(isdigit(retok[i] = fgetc(fp))){
	i++;
      }
      ungetc(retok[i],fp);
      //printf("NUM:%s\n",retok);
      return retok;
    }else{
      //printf("SYM:%s\n",retok);
      return retok;
    }
    i++;
  }
  return "\0";
}

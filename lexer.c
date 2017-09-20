#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char *lexer(FILE *fp,char *retok){
  int i = 0;
  while((retok[i] = fgetc(fp)) != EOF){
    if(feof(fp)){
      break;
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
      //printf("ID:%s\n",retok);
      return retok;
    }else if(isdigit(retok[i])){
      //retok[i] = fgetc(fp);
      while(isdigit(retok[i])){
	i++;
      }
      ungetc(retok[i],fp);
      //printf("NUM:%s\n",retok);
      return retok;
    }else{
      //printf("SYM:%s\n",retok);
      return retok;
    }
  }
  return retok;
}

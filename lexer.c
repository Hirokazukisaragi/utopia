#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char *lexer(int argc,char *argv[]){
  char ch[65554];
  int i = 0;
  while((ch[i] = fgetc(stdin)) != EOF){
    if(isspace(ch[i])){
      continue;
    }
    if(isalpha(ch[i])){
      i++;
      while(isalnum(ch[i] = fgetc(stdin))){
	i++;
      }
      //ungetc(ch[i],stdin);
      printf("ID:%s\n",ch);
    }else if(isdigit(ch[i])){
      while(isdigit(ch[i] = fgetc(stdin))){
	i++;
      }
      //ungetc(ch,stdin);
      printf("NUM:%s\n",ch);
    }
  }
  return ch;
}

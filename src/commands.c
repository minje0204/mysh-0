#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1; 
  chdir(argv[1]);  

  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
 	return -1;
  char buff[255];
  getcwd(buff,255);
  printf("%s\n",buff);
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  if(argc == 1 || 
     strcmp(argv[0], "cd") ||
	 argc > 2)//(argc == 3 && !strcmp(argv[1], ".") && !strcmp(argv[1],".")))
	 return 0;
  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
   if(argc > 1 || strcmp(argv[0], "pwd"))
   	return 0;
   return 1;
  }

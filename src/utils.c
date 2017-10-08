#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	char *real_command = command;
	while(isspace(*(real_command++)));
	real_command--;
	char *end = strchr(real_command,'\n');
	if(end)
		*end = '\0';
	*argc=0;
	*argv=(char**)malloc(sizeof(*argv)*100);
	char **temp=*argv;
	if(*real_command != '\0')
	{
		*temp = strdup(strtok(strdup(real_command)," "));
		while (*temp!=NULL)
		{
			*temp = strdup(*temp);
			*(++temp)=strtok(NULL," ");
			(*argc)++;
		}
	}
	else
	{
		**argv = strdup("");
		*argc = 1;
	}
	realloc(*argv,sizeof(*argv)*(*argc));
}

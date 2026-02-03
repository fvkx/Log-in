#include <stdio.h>
#include <string.h>


int main () {
	char enter_Password[50];
	const char * password = "kauhgdiuaw";
	
	scanf("%s",enter_Password);


	if (strcmp (enter_Password, password ) == 0 ){
		printf("correct_password");
	}
	else 
	{
		printf("incorrect_password");
	}

return 0;
}

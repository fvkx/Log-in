#include <stdio.h> 
#include <ctype.h>


int main () {
	char input[100];
	printf(":");
	scanf("%s", input );


	int result = 0;
	int i = 0;
	char op = '+';
	
	while (input[i] !='\0'){
		if (isdigit(input[i])){
			int num = 0;
			while (isdigit(input[i])) {
				num = num * 10 +  (input[i++] - '0');
			}
			switch (op){
				case '+': result += num; break;
				case '-': result -= num; break;
				case '*': result *= num; break;
				case '/': result /= num; break;
			}
		

		}else{
			op = input[i];
		} 
		i++;

		

	}
	printf("result: %d\n", result);
	return 0;
}

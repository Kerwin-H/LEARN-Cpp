#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse_string(char* arr){
	int len = strlen(arr);
	char p = *arr;              
	*arr = (*arr + len - 1);	
	*(arr + len - 1) = '\0';	
	if (strlen(arr + 1) >= 2)	 
		reverse_string(arr + 1);
	*(arr + len - 1) = p;
}


int main(){
	char arr[] = "abcdefgh";
	reverse_string(arr);		 
	printf("%s\n", arr);
	system("pause");
	return 0;
}
 
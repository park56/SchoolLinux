#include <stdio.h>
#include "add.h"

void main(){
	int a;
	int b;
// shift + v -> choice block, y copy, p cpinsert
	printf("What is a value?");
	scanf("%d",&a);
	printf("What is b value?");
	scanf("%d",&b);
	add(a,b);
}

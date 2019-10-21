#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *func_print(void *ptr);

int main()
{
	pthread_t thread1,thread2;
	const char *message1 = "thread 1";
	const char *message2 = "thread 2";
	int iret1,iret2;
	iret1 = pthread_create(&thread1,NULL,func_print,(void*)message1);
	if(iret1)
	{
		printf("Error_pthread create return code : %d\n",iret1);
		exit(EXIT_FAILURE);
	}

	iret2 = pthread_create(&thread2,NULL,func_print,(void*)message2);
	
	if(iret2)
	{
		printf("Error_pthread create return code : %d\n",iret2);
		exit(EXIT_FAILURE);
	}
	printf("pthread_create() for thread 1 returns: %d\n",iret1);
	printf("pthread_create() for thread 2 returns: %d\n",iret2);

	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL);
	exit(EXIT_SUCCESS);
}


void *func_print(void *ptr)
{
	char *message;
	message = (char *)ptr;
	printf("%s \n",message);
}

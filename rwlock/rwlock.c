#include <stdio.h>
#include <pthread.h>

pthread_rwlock_t rwlock;   //define rwlock
int buf = 0;               //common resource

void* read(void* arg)
{
	while(1){
		if(pthread_rwlock_rdlock(&rwlock) == 0){//read lock success
		printf("read the data is: %d\n",buf);
		pthread_rwlock_unlock(&rwlock);
		}else{//failed
		printf("writer is writing,reader is waiting...\n");
		}
		sleep(1);
	}
}

void* write(void* arg)
{
	while(1){
		if(pthread_rwlock_wrlock(&rwlock) == 0){//write lock success
			buf++;
			printf("write the data is: %d\n",buf);
			pthread_rwlock_unlock(&rwlock);
		}else{//failed
		printf("reader is reading,writer is waiting...\n");
		}
		sleep(2);
	}
}

int main()
{
	pthread_t reader,writer;

	pthread_rwlock_init(&rwlock,NULL);

	pthread_create(&reader,NULL,read,NULL);
	pthread_create(&writer,NULL,write,NULL);

	pthread_join(reader,NULL);
	pthread_join(writer,NULL);

	pthread_rwlock_unlock(&rwlock);

	return 0;
}

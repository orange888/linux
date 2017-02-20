#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void *thread_run(void *_val)
{
	pthread_detach(pthread_self());
	printf("%s : pid is : %d, tid is: %d\n",(char *)_val,(int)getpid(),(unsigned long long)pthread_self());
	return NULL;
}

int main()
{
	pthread_t tid;
	int tret = pthread_create(&tid,NULL,thread_run,"thread1 run...");

	if(tret != 0){
		printf("cerate thread error!.info is:%s\n",strerror(tret));
		exit(tret);
	}
	printf("main thread run : pid is :%d,tid is : %d\n",(int)getpid(),(unsigned long long)pthread_self());
	//wait
	//int ret = 0;
	sleep(1);
//	if(0 == pthread_join(tid,NULL))
//	{
//		printf("pthread wait success!\n");
//		ret = 0;
//	}
//	else
//	{
//		printf("pthread wait failed!\n");
//		ret = 1;
//	}
	return 0;
}














//#include<stdio.h>
//#include<string.h>
//#include<pthread.h>
//
//void *create_pthread(void* arg)
//{
//	int count=0;
//	while(1)
//	{
//		sleep(1);
//		printf("this is a new thread,thread_id is %lu\n",pthread_self());
//		count++;
//		if(count>5)
//		{
//		//	return (void*)255;//method 1
//		//	pthread_exit((void*)88);//method 2
//		}
//	}
//}
//int main()
//{
//	pthread_t pthread_id;
//	int code=pthread_create(&pthread_id,NULL,create_pthread,(void*)1);
//	if(code!=0)
//	{
//		printf("pthread_create failed,code=%d,%s\n",code,strerror(code));
//		return 1;
//	}
//	int count=0;
//	int flag=1;
//	while(1)
//	{
//		sleep(1);
//		printf("this is main thread\n");
//		count++;
//		if(count>5&&flag)
//		{
//			pthread_cancel(pthread_id);//method 3
//			flag=0;
//		}
//		if(count>10)
//		{
//			break;
//		}
//	}
//	void* status=NULL;//create_pthread exit code
//	code=pthread_join(pthread_id,&status);
//	if(code!=0)
//	{
//		printf("join failed.code=%d,%s\n",code,strerror(code));
//		return 2;
//	}
//	printf("join success! code exit:%d\n",(int)status);
//	return 0;
//}

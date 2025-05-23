#include<bits/stdc++.h>
#include<unistd.h>
#include<pthread.h>
using namespace std;

#define size 5;
int buf[size];
int in=0,out=0;
int count=0;
pthread_mutex_t mutax;
void *producer();
void *consumer();

int main()
{
	pthread_t t1,t2;
	pthread_mutex_init(&mutax,NULL);
	pthread_create(&t1,NULL,producer,NULL);
	pthread_create(&t2,NULL,consumer,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_mutex_destroy(&mutax);
}
void *producer()
{
	int item;
	for(int i=0;i<10;i++)
	{
		pthread_mutex_lock(&mutax);
		if(count==size)
        {
            cout<<"Buffer is full & producer waits"<<endl;
        }
		item=rand()%100;
        buf[in]=item;
        in=(in+1)%size;
        count++;
		pthread_mutex_unlock(&mutax);
	}
}
void *consumer()
{
    int item;
	for(int i=0;i<10;i++)
	{
		pthread_mutex_lock(&mutax);
		if(count==0)
        {
            cout<<"Buffer is empty & consumer waits"<<endl;
        }
        item=buf[out];
        out=(out+1)%size;
        count--;
		pthread_mutex_unlock(&mutax);
	}
}
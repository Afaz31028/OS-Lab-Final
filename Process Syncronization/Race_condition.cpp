#include<bits/stdc++.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
using namespace std;
void *fun1();
void *fun2();
int shared=1;
sem_t s;

int main()
{
	sem_init(&s,0,1);
	pthread_t t1,t2;
	pthread_create(&t1,NULL,fun1,NULL);
	pthread_create(&t2,NULL,fun2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	cout<<"the final value of shared: "<<shared<<endl;
}
void *fun1()
{
	int x;
	sem_wait(&s);
	x=shared;
	cout<<"t1 reads value: "<<x<<endl;
	x++;
	cout<<"local update of; "<<x<<endl;
	sleep(1);
	shared=x;
	cout<<"update value of shared bt t1 :"<<shared<<endl;
	sem_post(&s);
}
void *fun2()
{
        int y;
	    sem_wait(&s);
        y=shared;
        cout<<"t2 reads value :"<<x<<endl;
        y--;
        cout<<"local update of :"<<x<<endl;
        sleep(1);
        shared=y;
        cout<<"update value of shared bt t2 :"<<shared<<endl;
	    sem_post(&s);
}
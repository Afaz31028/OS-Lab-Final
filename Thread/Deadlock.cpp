#include<bits/stdc++.h>
#include<unistd.h>
#include<pthread.h>
using namespace std;

void *fun1();
void *fun2();
pthread_mutex_t first_mutex,second_mutex;

int main()
{
	pthread_mutex_init(&first_mutex,NULL);
	pthread_mutex_init(&second_mutex,NULL);

	pthread_t p1,p2;
    pthread_create(&p1,NULL,fun1,NULL);
	pthread_create(&p2,NULL,fun2,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
}
void *fun1()
{
	cout<<"p1 trying aquire first mutex"<<endl;
	pthread_mutex_lock(&first_mutex);
	cout<<"p1 aquired first mutex"<<endl;
    sleep(1);

	cout<<"p1 trying second mutex"<<endl;
	pthread_mutex_lock(&second_mutex);
    cout<<"p1 aquired second mutex"<<endl;
	pthread_mutex_unlock(&first_mutex);
}
void *fun2()
{
  	cout<<"p2 trying aquire second mutex"<<endl;
	pthread_mutex_lock(&second_mutex);
	cout<<"p2 aquired second mutex"<<endl;
	sleep(1);
    
	cout<<"p2 trying aquire first mutex"<<endl;
	pthread_mutex_lock(&first_mutex);
	cout<<"p2 aquired second mutex"<<endl;
	pthread_mutex_unlock(&second_mutex);
}
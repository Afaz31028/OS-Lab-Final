#include<bits/stdc++.h>
#include<unistd.h>
#include<pthread.h>
using namespace std;

void *thread_function();
int main()
{
	pthread_t a_thread;
	pthread_create(&a_thread,NULL,thread_function,NULL);
	pthread_join(a_thread,NULL);
	
	cout<<"Inside main program:"<<endl;
	for(int i=1;i<=5;i++)
	  {
		cout<<i<<endl;
		sleep(1);
	  }
	
}
void *thread_function()
{
	cout<<"Inside the thread:"<<endl;
	for(int j=101;j<=105;j++)
	 {
		cout<<j<<endl;
		sleep(1);
	 }
}
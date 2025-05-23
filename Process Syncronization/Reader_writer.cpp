#include<bits/stdc++.h>
#include<unistd.h>
#include<pthread.h>

using namespace std;
int readCount = 0;
pthread_mutex_t mutax;
pthread_mutex_t writeLock;
void *reader();
void *writer();

int main() {
    pthread_t r1, r2, w1;
    pthread_mutax_init(&mutax,NULL);
    pthread_mutax_init(&writeLock,NULL);
    pthread_create(&r1,NULL, reader, NULL);
    pthread_create(&r2,NULL, reader, NULL);
    pthread_create(&w1,NULL, writer, NULL);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);
    pthread_mutex_destroy(&mutax);
    pthread_mutex_destroy(&writeLock);

    return 0;
}
void *reader() 
{
    while (true) 
    {
        pthread_mutex_lock(&mutax);
        readCount++;
        if (readCount == 1)
            pthread_mutex_lock(&writeLock);
        pthread_mutex_unlock(&mutax);
        cout << "Reader is reading"<<endl;
        sleep(1);

        pthread_mutex_lock(&mutax);
        readCount--;
        if (readCount == 0)
            pthread_mutex_unlock(&writeLock);
        pthread_mutex_unlock(&mutax);
        sleep(1);
    }
}
void *writer() 
{
    while (true) 
    {
        pthread_mutex_lock(&writeLock);
        cout << "Writer is writing"<<endl;
        sleep(2);
        pthread_mutex_unlock(&writeLock);
        sleep(2);
    }
}
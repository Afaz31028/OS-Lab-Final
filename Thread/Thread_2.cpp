#include <bits/stdc++.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;

void *thread_function(void *arg);
int num[5] = {3, 5, 1, 2, 3};

int main()
{
    pthread_t a_thread;
    void *result;
    pthread_create(&a_thread, NULL, thread_function, (void *)num);
    pthread_join(a_thread, &result);
    cout << "Inside the main process" << endl;
    cout << "Thread returned" << (char *)result << endl;
}
void *thread_function(void *arg)
{
    int *x = arg;
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += x[i];
    }
    cout << "The sum is: " << sum << endl;
}
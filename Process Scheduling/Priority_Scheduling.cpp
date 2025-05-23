#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid,AT,BT,CT,TT,WT,RT,priority;
};
bool cmp( process a, process b)
{
    if(a.AT < b.AT)
        return true;
    return false;
}
void findCT(process proc[],int n)
{
    int cur_time=0;
    bool ok[n]={false};
    int completed=0;
    while(completed<n)
    {
        int idx=-1;
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(!ok[i] && proc[i].AT <=cur_time && proc[i].priority > mx)
            {
                mx=proc[i].priority;
                idx=i;
            }
        }
        if(idx != -1)
        {
            proc[idx].CT = proc[idx].BT + cur_time;
            cur_time = proc[idx].CT;
            ok[idx]=true;
            completed++;
        }
    }
}
void findTT(process proc[],int n)
{
    for(int i=0;i<n;i++)
    {
        proc[i].TT= proc[i].CT - proc[i].AT;
    }
}
void findWT(process proc[],int n)
{
    proc[0].WT=0;
    for(int i=1;i<n;i++)
    {
        proc[i].WT = proc[i].TT - proc[i].BT;
    }
}
void findRT(process proc[],int n)
{
    for(int i=0; i<n ;i++)
    {
        proc[i].RT = proc[i].WT;
    }
}
void printPriorityScheduling(process proc[],int n)
{
    cout<<"PID\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TT\t"<<"WT\t"<<"RT\t"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<proc[i].pid<<"\t"<<proc[i].AT<<"\t"<<proc[i].BT<<"\t"<<proc[i].CT<<"\t"<<proc[i].TT<<"\t"<<proc[i].WT<<"\t"<<proc[i].RT<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    process proc[n];
    for(int i=0;i<n;i++)
    {
        cin>>proc[i].pid>>proc[i].priority>>proc[i].AT>>proc[i].BT;
    }
    sort(proc,proc+n,cmp);
    findCT(proc,n);
    findTT(proc,n);
    findWT(proc,n);
    findRT(proc,n);

    printPriorityScheduling(proc,n);

    return 0;
}
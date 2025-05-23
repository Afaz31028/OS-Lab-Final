#include <bits/stdc++.h>
using namespace std;
map<int,int>track;
struct process
{
    int pid,AT,BT,CT,TT,WT,RT;
};
bool cmp( process a, process b)
{
    if(a.AT < b.AT)
        return true;
    return false;
}
void findCT(process proc[],int n,int TQ)
{
    deque<int>ready;
    deque<int>::iterator it;
    ready.push_back(0);
    int rem_time[n];
    for(int i=0;i<n;i++)
    {
        rem_time[i]=proc[i].BT;
        track[i]=-1;
    }
    int cur_time=0;
    while(!ready.empty())
    {
        int idx=ready.front();
        ready.pop_front();
        if(rem_time[idx] > 0 && proc[idx].AT <= cur_time)
        {
            if(rem_time[idx] > TQ)
            {
                if(track[idx]==-1) track[idx]=cur_time;
                cur_time+=TQ;
                rem_time[idx]-=TQ;
                for(int i=idx+1;i<n;i++)
                {
                    if(proc[i].AT <= cur_time)
                    {
                        it=find(ready.begin(),ready.end(),i);
                        if(it==ready.end())
                            ready.push_back(i);
                    }
                }
                ready.push_back(idx);
            }
            else
            {
                if(track[idx]==-1) track[idx]= cur_time;
                cur_time+=rem_time[idx];
                rem_time[idx]=0;
                proc[idx].CT= cur_time;
                for(int i=idx+1;i<n;i++)
                {
                    if(proc[i].AT <= cur_time)
                    {
                        it=find(ready.begin(),ready.end(),i);
                        if(it==ready.end())
                            ready.push_back(i);
                    }
                }
                
            }
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
    for(int i=0;i<n;i++)
    {
        proc[i].WT = proc[i].TT - proc[i].BT;
        if(proc[i].WT<0)
            proc[i].WT=0;
    }
}
void findRT(process proc[],int n)
{
    for(int i=0;i<n;i++)
    {
        proc[i].RT = track[i] - proc[i].AT;
    }
}
void printRoundRobin(process proc[],int n)
{
    cout<<"PID\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TT\t"<<"WT\t"<<"RT\t"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<proc[i].pid<<"\t"<<proc[i].AT<<"\t"<<proc[i].BT<<"\t"<<proc[i].CT<<"\t"<<proc[i].TT
        <<"\t"<<proc[i].WT<<"\t"<<proc[i].RT<<endl;
    }
}
int main()
{
    int n,TQ;
    cin>>n>>TQ;
    process proc[n];
    for(int i=0;i<n;i++)
    {
        cin>>proc[i].pid>>proc[i].AT>>proc[i].BT;
    }
    sort(proc,proc+n,cmp);

    findCT(proc,n,TQ);
    findTT(proc,n);
    findWT(proc,n);
    findRT(proc,n);
    
    printRoundRobin(proc,n);

    return 0;
}
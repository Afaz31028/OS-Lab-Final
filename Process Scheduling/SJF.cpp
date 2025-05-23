#include <bits/stdc++.h>
using namespace std;

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
void findCT(process proc[],int n)
{
    proc[0].CT= proc[0].BT + proc[0].AT;
    int com_process_id=0;
    int idx=0;
    bool ok[n]={false};
    for(int i=1;i<n;i++)
    {
        int mn= 1e9;
        for(int j=1;j<n;j++)
        {
            if(proc[com_process_id].CT>= proc[j].AT && ok[j]==false)
            {
                if(proc[j].BT<mn)
                {
                    mn=proc[j].BT;
                    idx=j;
                }
            }
        }
        proc[idx].CT= proc[com_process_id].CT + proc[idx].BT;
        ok[idx]=true;
        com_process_id=idx;
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
void printSJF(process proc[],int n)
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
        cin>>proc[i].pid>>proc[i].AT>>proc[i].BT;
    }
    sort(proc,proc+n,cmp);
    
    findCT(proc,n);
    findTT(proc,n);
    findWT(proc,n);
    findRT(proc,n);

    printSJF(proc,n);

    return 0;
}
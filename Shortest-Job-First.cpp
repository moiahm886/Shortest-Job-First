#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct SJF
{
    int arrival_time=0;
    int wait_time=0;
    int burst_time=0;
    int turnaround_time=0;
    bool executed=false;
};
int main(int argc, char** argv)
{
    int time=0;
    int average_wait=0;
    int average_turntime=0;
    vector<SJF>vect;
    SJF P1,P2,P3,P4,P5;
    vect.push_back(P1);
    vect.push_back(P2);
    vect.push_back(P3);
    vect.push_back(P4);
    vect.push_back(P5);
    int y=1;
    for(SJF &x:vect)
    {
        cout<<"Enter Arrival Time for process "<<y<<endl;
        cin>>x.arrival_time;
        cout<<"Enter Burst Time for process "<<y<<endl;
        cin>>x.burst_time;
        y++;
    }
    for(int i=0;i<vect.size()-1;i++)
    {
        for(int j=0;j<vect.size()-i-1;j++)
        {
            if(vect[j].arrival_time>vect[j+1].arrival_time)
            {
                swap(vect[j],vect[j+1]);
            }
        }
        
    }
   for(SJF &x:vect)
   {
        if(time<x.arrival_time)
        {
            vector<int>burst;
            for(SJF &y:vect)
            {
                if(time<y.arrival_time&&y.executed==false)
                {
                    burst.push_back(y.burst_time);
                }
            }
            int min = *min_element(burst.begin(),burst.end());
            for(SJF &z:vect)
            {
                if(min==z.burst_time&&time<z.arrival_time&&z.executed==false)
                {
                    time=z.arrival_time+z.burst_time;
                    z.wait_time=0;
                    z.turnaround_time=z.burst_time;
                    z.executed=true;
                }
            }
        }
        else
        {
            vector<int>burst;
            for(SJF &y:vect)
            {
                if(y.arrival_time<=time&&y.executed==false)
                {
                    burst.push_back(y.burst_time);
                }
            }
            int min = *min_element(burst.begin(),burst.end());
            for(SJF &z:vect)
            {
                if(min==z.burst_time&&z.arrival_time<=time&&z.executed==false)
                {
                    z.wait_time=time-z.arrival_time;
                    time+=z.burst_time;
                    z.turnaround_time=time-z.arrival_time;
                    z.executed=true;
                }
            }
        }
   }
    for(SJF &z:vect)
    {
        cout<<z.wait_time<<"\t"<<z.turnaround_time<<endl;
    }
}
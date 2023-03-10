#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using  namespace std;


class Process{
    private:
        int burst;
        int arival;
        string name;
        static int order;
    public:
        Process(int burst,int arival){
            this->burst=burst;
            this->arival=arival;
            name='P'+to_string(order++);
        }
        int getArival(){
            return arival;
        }
        int getBurst(){
            return burst;
        }
        string getName(){
            return name;
        }
        bool operator <(const Process& p){
            if(p.burst==burst){
                return this->arival<p.arival;
            }
            return this->burst<p.burst;
        }
        bool operator >(const Process &p){
            if (p.burst==burst)
            {
                return this->arival>p.burst;;
            }
            return this->burst>p.burst;
        }

};

void Remove_Process(vector<Process> &p,Process key){
    
    for (int i = 0; i < p.size(); i++)
    {
        if (p.at(i).getName()==key.getName())
        {
            p.erase(p.begin()+i);
        }
    }
}



int Process::order=1;

int main(){
    Process p1(6,2);
    Process p2(2,5);
    Process p3(8,1);
    Process p4(3,0);
    Process p5(4,4);

    vector<Process> Pvec={p1,p2,p3,p4,p5};
    sort(Pvec.begin(),Pvec.end());
    // for (int i = 0; i <Pvec.size(); i++)
    // {
    //     cout<<Pvec.at(i).getName()<<" "<<Pvec.at(i).getArival()<<"  "<<Pvec.at(i).getBurst()<<" "<<endl;
    // }
    int timer=0;
    int process_done=0;
    vector<int> completion_time;
    vector<Process> completed_Process;
    // map<int ,string> completion_time;
    while (process_done!=5)
    {
        vector<Process> temp;
        for (int i = 0; i <Pvec.size(); i++)
        {
            if (Pvec.at(i).getArival()<=timer)
            {
                temp.push_back(Pvec.at(i));
            }
        }
        if(temp.size()!=0){
            timer+=temp.front().getBurst();
            completion_time.push_back(timer);
            completed_Process.push_back(temp.front());
            Remove_Process(Pvec,temp.front());
            process_done++;       
        }else{
           timer++;
        }
    }
    for (int i = 0; i < completion_time.size(); i++)
    {
        cout<<"ct : "<<completion_time.at(i)<<endl;
    }
    
    int tat=0;
    vector<int> tat_vec;
    for (int i = 0; i < completed_Process.size(); i++)
    {
        tat+=completion_time.at(i)-completed_Process.at(i).getArival();
        tat_vec.push_back(completion_time.at(i)-completed_Process.at(i).getArival());
    }

    int wt=0;
    for (int i = 0; i < completed_Process.size(); i++)
    {
        wt+=tat_vec[i]-completed_Process.at(i).getBurst();
    }
    
    float average_tat,average_wt;
    average_tat=tat/5.0;
    cout<<"Average Total Around time : "<<average_tat<<" \n";
    average_wt=wt/5.0;
    cout<<"Average Waiting time : "<<average_wt<<" ";



    

    

    return 0;
}
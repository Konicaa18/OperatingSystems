#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

//this is priority non preemptive

class process{
    static int kk;

string name ="P"+to_string(kk);

int arrival_time;
int burst_time;
int pnum;

public:
   int getArrival(){
       return arrival_time;}
       
   int getprinum(){
       return pnum;
   }    

   int getBurst(){
     return burst_time;}

     process(int p,int a,int b){
         pnum=p;
        arrival_time= a;
        burst_time=b;
        kk++;
     }

     void print(){
     cout<<name<<"  "<<"arrival :"<<arrival_time<<"burst time :"<<burst_time<<endl;}


       bool operator<(const process &r) const
    {
         if(pnum == r.pnum){
            return arrival_time <= r.arrival_time;
   }
        return pnum < r.pnum;

    }

    // overload the operator> (if required)
    bool operator>(const process &r) const
    {
         if(pnum == r.pnum){
            return arrival_time <= r.arrival_time;
}
        return pnum< r.pnum;
    }
    bool equals(process b){
        if(name == b.name){
            
            return true;
        }else{
            return false;
        }
    }

};


void removeElement(vector<process> &v ,process p){

    for(int i=0;i<v.size();++i){
        if(v.at(i).equals(p)){
            v.erase(v.begin()+i);
        }
    }

}

int process::kk = 1;

int main()
{

    process p1(2,0,3);
    process p2(6,2,5);
    process p3(3,1,4);
    process p4(5,4,2);
    process p5(7,6,9);
    process p6(4,5,4);
    process p7(10,7,10);
    
    


    vector<process> v ;
    vector<process> temp;

      v.push_back(p1);
      v.push_back(p2);
      v.push_back(p3);
      v.push_back(p4);
      v.push_back(p5);
      v.push_back(p6);
      v.push_back(p7);
    
   
   

    vector<int> arr;
    vector<int> tracking;
    int process_done=0;

  


    list<process> que;


    int timer=0;
    
    
    


    for(int i=0;i<7;i++){
        if(v.at(i).getArrival() <=timer){  // 0
            que.push_back(v.at(i));
        }
    }
    que.sort();


    bool flag=false;
    
    
    
     arr.push_back(0);   
   while(process_done != 7){


   if(que.size()==0){
    timer++;                                  //4 5
     for(int z=0;z<v.size();z++){
        if(v.at(z).getArrival() <=timer){
            que.push_back(v.at(z));
        }
    }
    que.sort();
    flag = true;

   }else{
       
       //also remove that process which is done
       
  if(flag){
     tracking.push_back(0);
     arr.push_back(timer);
   }
 tracking.push_back(1);

    arr.push_back( que.front().getBurst()+arr.at(arr.size()-1));

    timer += que.front().getBurst();   //right

 
flag=false;
process_done++;

temp.push_back(que.front());
removeElement(v,que.front());

que.clear();
              for(int i=0;i<v.size();i++){
        if(v.at(i).getArrival() <=timer){
            que.push_back(v.at(i));
        }
    }
    que.sort();

   }

}
//calculating waiting time
int result=0;



for(int i=0;i<8;++i){
    cout<<arr.at(i)<< "|   |";
}
cout<<endl;


for(int i=0,j=0;i<7;){
    if(tracking.at(j)){
        result +=  arr.at(j) - temp.at(i).getArrival();
        cout<<arr.at(j)<<" - "<<temp.at(i).getArrival()<<endl;
        i++;
        j++;
        
    }else{
        j++;
        
    }
}
cout<<"waiting time is : "<<result/7.0<<endl;

//calculating total around time
int total=0;

for(int i=0,j=0;i<7;){
    if(tracking.at(j)){
        total +=  arr.at(j+1) - temp.at(i).getArrival();
        cout<<arr.at(j+1)<<" - "<<temp.at(i).getArrival()<<endl;
        i++;
        j++;
        
    }else{
        j++;
        
    }
}
cout<<"total turn around time is : "<<total/7.0<<endl;


    return 0;
}
// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class process{
   static int kk;
   
   string str ="p"+to_string(kk);
    int arrival_time;
    int burst_time;
    
public:
    
    int getArrival(){
        return arrival_time;
    }
     int getBurst(){
        return burst_time;
    }
    process (int a,int b){
        kk++;
        arrival_time= a;
        burst_time=b;
    }
    
    void print(){
        cout<<str<<"  "<<"arrival :"<<arrival_time<<" burst time :"<<burst_time<<endl;
    }
    
      bool operator<(const process &r) const
    {
         if(arrival_time == r.arrival_time){
            return burst_time < r.burst_time;
}
        return arrival_time < r.arrival_time;

    }
 
    // overload the operator> (if required)
    bool operator>(const process &r) const
    {
         if(arrival_time == r.arrival_time){
            return burst_time < r.burst_time;
}
        return arrival_time > r.arrival_time;
    }
};

int process::kk = 1; //initializing the static int



int main() {
    // Write C++ code here
    process p1(5,10);
    process p2(0,5);
    process p3(5,3);
    process p4(2,1);
    
    vector<process> v ;
    
      v.push_back(p1);
      v.push_back(p2);
      v.push_back(p3);
      v.push_back(p4);

    sort(v.begin(),v.end());
    
    for (int i=0;i<4;++i)
    {
        v.at(i).print();
    }
    
    vector<int> arr;
    vector<int> tracking;
    
    
    
    if(v.at(0).getArrival() ==0){
    arr.push_back(0);
    tracking.push_back(1);
    
    arr.push_back( v.at(0).getBurst());
    
    
    
    }else{
          arr.push_back(0);
          tracking.push_back(0);
          
          
          
    arr.push_back(v.at(0).getArrival());
  
    arr.push_back( v.at(0).getBurst()+arr.at(1));
    
    
    tracking.push_back(1);
        
    }
    
    
    for(int i=arr.size()-1,j=1;j<4;j++)
    {
        int pre= arr.at(i);  //3
        int curr =v.at(j).getArrival();  //3
        int curr_burst= v.at(j).getBurst();  //4

        if(pre>=curr){
            //good
            arr.push_back( pre+curr_burst);
            tracking.push_back(1);
            i++;
            
        }else{
            //wait
            arr.push_back( curr);
            tracking.push_back(0);
            j--;
            i++;
            
        }
        
    }    
     for (int i=0;i<arr.size();++i)
    {
       cout<<"| "<<arr.at(i)<<" |";
    }
    cout<<endl;
    
    int result=0;
       for (int i=0,k=0;i<tracking.size();++i)
    {
      if(tracking.at(i)){
          int a =  v.at(k).getArrival();
          int b= arr.at(i+1);
          result +=b-a;
          cout<<b<<" - "<<a<<endl;
          k++;
          
      }
    }
    cout<<"Avg T.T : "<<result/4.0<<endl;
    
     int result2=0;
       for (int i=0,k=0;i<tracking.size();++i)
    {
      if(tracking.at(i)){
          int a =  v.at(k).getArrival();
          int b= arr.at(i);
          result2 +=b-a;
          cout<<b<<" - "<<a<<endl;
          k++;
          
      }
    }
    cout<<"Avg W.T : "<<result2/4.0<<endl;
    
    
    
    
    
     
    
    

    return 0;
}
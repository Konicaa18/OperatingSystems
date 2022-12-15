//first fit
#include <iostream>
#include <string>

using namespace std;

//first bit

class process{
public:


string block_assigned;
int process_no;
int process_size;

process(int siz){
    process_size = siz;
    process_no = ++var;
    block_assigned="Not Allocated";
}

void print(){
    cout<<"process no. : "<<process_no<<" process size : "<<process_size<<" kb "<<endl;
}

static int var ;

};
int process::var=0;


int main()
{
    cout<<"Enter the number of processes : ";
    int no_of_processes=0;
    cin>>no_of_processes;

    process **objects = new process*[no_of_processes];

    cout<<"<----- enter the process sizes ------>"<<endl;

    for(int i=0;i<no_of_processes;++i){

    cout<<i+1<<". process size : ";
    int x=0;
    cin>>x;
    objects[i] = new process(x);
    }

    cout<<"<-----Enter the number of Memory Blocks ----> "<<endl;
    int no_of_Mblocks;
    cin>>no_of_Mblocks;

    int *memoryBlocks = new int[no_of_Mblocks];
    int *memoryStatus = new int[no_of_Mblocks];

     for(int i=0;i<no_of_Mblocks;++i){
    cout<<i+1<<". block size : ";
    int x=0;
    cin>>x;
    memoryBlocks[i] = x;
    memoryStatus[i]=i+1;
    }

    for(int i=0,j=0;i<no_of_processes;i++){     //j will account for memory number // 300, 100    100,300


   int k=0;
   while(objects[i]->process_size>memoryBlocks[k]){
    k++;
    if(k==no_of_Mblocks){
        break;
    }
   }

   if(k != no_of_Mblocks){
   objects[i]->block_assigned =" in block "+to_string(memoryStatus[k]);

      cout<<"  =  "<<memoryBlocks[k]<<" - "<<(objects[i]->process_size )<<endl;
   memoryBlocks[k] = memoryBlocks[k] - (objects[i]->process_size );


   }
   }

cout<<endl;
cout<<"---------------------------------------------------------------------------------"<<endl;
   for(int i=0;i<no_of_processes;++i){
    cout<<objects[i]->process_no<<" . "<< objects[i]->block_assigned<<endl;
   }



    return 0;
}
//////////////////////////////////////////////////////////---------------BEST FIT------------------///////////////////////////
#include <iostream>
#include <string>

using namespace std;

//best fit

class process{
public:


string block_assigned;
int process_no;
int process_size;

process(int siz){
    process_size = siz;
    process_no = ++var;
    block_assigned="Not Allocated";
}
void print(){
    cout<<"process no. : "<<process_no<<" process size : "<<process_size<<" kb "<<endl;
}

static int var ;

};

int process::var=0;


int main()
{
    cout<<"Enter the number of processes : ";
    int no_of_processes=0;
    cin>>no_of_processes;

    process **objects = new process*[no_of_processes];

    cout<<"<----- enter the process sizes ------>"<<endl;

int prev=0;
    for(int i=0;i<no_of_processes;++i){ //will sort while taking input
    cout<<i+1<<". process size : ";
    int x=0;
    cin>>x;
       objects[i] = new process(x);
    }





     for(int i=0;i<no_of_processes;++i){
    objects[i]->print();
    cout<<endl;
     }



    cout<<"<-----Enter the number of Memory Blocks ----> "<<endl;
    int no_of_Mblocks;
    cin>>no_of_Mblocks;

    int *memoryBlocks = new int[no_of_Mblocks];
    int *memoryStatus = new int[no_of_Mblocks];

     for(int i=0;i<no_of_Mblocks;++i){
    cout<<i+1<<". block size : ";
    int x=0;
    cin>>x;
    memoryBlocks[i] = x;
    memoryStatus[i] = i+1;

     }
     //sorting
  for(int i=0;i<no_of_Mblocks;++i){
    for(int j=0;j<no_of_Mblocks-1;++j){

        if(memoryBlocks[j] > memoryBlocks[j+1]){

   int temp = memoryBlocks[j];
   int temp2 =    memoryStatus[j];
   memoryBlocks[j] = memoryBlocks[j+1];
   memoryStatus[j] = memoryStatus[j+1];
   memoryBlocks[j+1] = temp;
   memoryStatus[j+1]= temp2;

        }
    }
  }



      for(int i=0;i<no_of_Mblocks;++i){
    cout<<i+1<<" . "<<memoryBlocks[i]<<endl;
     }


   for(int i=0,j=0;i<no_of_processes;i++){     //j will account for memory number // 300, 100    100,300


   int k=0;
   while(objects[i]->process_size>memoryBlocks[k]){
    k++;
    if(k==no_of_Mblocks){
        break;
    }
   }
   if(k !=no_of_Mblocks){
   objects[i]->block_assigned =" in block "+to_string(memoryStatus[k]);

      cout<<"  =  "<<memoryBlocks[k]<<" - "<<(objects[i]->process_size )<<endl;
   memoryBlocks[k] = memoryBlocks[k] - (objects[i]->process_size );
   }


   }

cout<<endl;
cout<<"---------------------------------------------------------------------------------"<<endl;
   for(int i=0;i<no_of_processes;++i){
    cout<<objects[i]->process_no<<" . "<< objects[i]->block_assigned<<endl;
   }



    return 0;
}
////////////////////////////////////////////---- worst fit--- /////////////////////////////////


#include <iostream>
#include <string>

using namespace std;

class process{
public:


string block_assigned;
int process_no;
int process_size;

process(int siz){
    process_size = siz;
    process_no = ++var;
    block_assigned="Not Allocated";
}
void print(){
    cout<<"process no. : "<<process_no<<" process size : "<<process_size<<" kb "<<endl;
}

static int var ;

};

int process::var=0;


int main()
{
    cout<<"Enter the number of processes : ";
    int no_of_processes=0;
    cin>>no_of_processes;

    process **objects = new process*[no_of_processes];

    cout<<"<----- enter the process sizes ------>"<<endl;

int prev=0;
    for(int i=0;i<no_of_processes;++i){ //will sort while taking input
    cout<<i+1<<". process size : ";
    int x=0;
    cin>>x;
       objects[i] = new process(x);
    }





     for(int i=0;i<no_of_processes;++i){
    objects[i]->print();
    cout<<endl;
     }



    cout<<"<-----Enter the number of Memory Blocks ----> "<<endl;
    int no_of_Mblocks;
    cin>>no_of_Mblocks;

    int *memoryBlocks = new int[no_of_Mblocks];
    int *memoryStatus = new int[no_of_Mblocks];

     for(int i=0;i<no_of_Mblocks;++i){
    cout<<i+1<<". block size : ";
    int x=0;
    cin>>x;
    memoryBlocks[i] = x;
    memoryStatus[i] = i+1;

     }
     //sorting
  for(int i=0;i<no_of_Mblocks;++i){
    for(int j=0;j<no_of_Mblocks-1;++j){

        if(memoryBlocks[j] < memoryBlocks[j+1]){

   int temp = memoryBlocks[j];
   int temp2 =    memoryStatus[j];
   memoryBlocks[j] = memoryBlocks[j+1];
   memoryStatus[j] = memoryStatus[j+1];
   memoryBlocks[j+1] = temp;
   memoryStatus[j+1]= temp2;

        }
    }
  }



      for(int i=0;i<no_of_Mblocks;++i){
    cout<<i+1<<" . "<<memoryBlocks[i]<<endl;
     }


   for(int i=0,j=0;i<no_of_processes;i++){     //j will account for memory number // 300, 100    100,300


   int k=0;
   while(objects[i]->process_size>memoryBlocks[k]){
    k++;
    if(k==no_of_Mblocks){
        break;
    }
   }
   if( k != no_of_Mblocks){
   objects[i]->block_assigned =" in block "+to_string(memoryStatus[k]);

      cout<<"  =  "<<memoryBlocks[k]<<" - "<<(objects[i]->process_size )<<endl;
   memoryBlocks[k] = memoryBlocks[k] - (objects[i]->process_size );


   }
   }

cout<<endl;
cout<<"---------------------------------------------------------------------------------"<<endl;
   for(int i=0;i<no_of_processes;++i){
    cout<<objects[i]->process_no<<" . "<< objects[i]->block_assigned<<endl;
   }



    return 0;
}
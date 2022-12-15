#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
using namespace std;


void work(int x, int *arr,int& ans);


int main(int argc, char *argv[]){


cout<<"in main thread "<<endl;

int ans=0;
int x=0;

int *arr = new int[argc-1];
x=( argc-1);


for(int i=0;i<(argc-1);++i){
arr[i]= atoi(argv[i+1]);

}

auto th = thread(work,x,arr,ref(ans));


th.join();
cout<<"joined to main thread"<<endl;
cout<<endl;
cout<<"ANSWER #SUM "<<ans<<endl;

return 0;
}

void work(int x,int *arr,int& ans){
cout<<"inside the worker thread"<<endl;

for(int i=0;i<x;++i){
ans += arr[i];
}
cout<<"work done"<<endl;
}
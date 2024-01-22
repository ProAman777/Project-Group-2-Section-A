#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  int size,i,j,k,copy;
  label:
    cout<<"Enter the maximum sizes of the pattern : ";
     cin>>size;
  copy=size;
  if(size>=0){
    for(i=0;i<size;++i){
           for(j=0;j<=i;j++){
      cout<<setw(3)<<" ";
    }
    
    k=copy--;
          for(j=0;j<=k;j++){
      cout<<setw(3)<<j;
      
       }
    
         for(j=k-1;j>=0;j--){
      cout<<setw(3)<<j;
         }
      cout<<endl;
    }

 for(i=0;i<=size;++i){
     for(j=size;j>=i;j--){
               cout<<setw(3)<<" ";
                }
      
       for(j=0;j<=i;j++){
                 cout<<setw(3)<<j;
                 }
 
      for(j=i-1;j>=0;j--){
          cout<<setw(3)<<j;
            }
  
    
    cout<<endl;
    }
  }
  else
  {
    cout<<"ERROR "<<endl;
    cout<<"please enter the positive number try again"<<endl;
    goto label;
  }

    return 0;
}
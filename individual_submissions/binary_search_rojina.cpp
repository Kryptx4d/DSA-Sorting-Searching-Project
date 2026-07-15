#include <iostream>
using namespace std;
int main(){
    
    int a[100];
    srand (time (NULL));
    for (int i=0; i<100; i++){
        a[i]= rand() %100;
    }
    
    for (int i=0; i< 100; i++){
        cout <<a[i] <<endl;
    }
   
    return 0;
}



#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
    
    int a[100];
     int i,j, temp;

    srand (time (NULL));
    for (int i=0; i<100; i++){
        a[i]= rand() %100;
    }
    
    for (int i=0; i< 100; i++){
        cout <<a[i] <<endl;
    }
    cout << "After Sorting" <<endl;
    
    for (int i= 0; i<100; i++)
         for (int j = 0; j < 100 - i - 1; j++)
            if (a[j]>a[j+1]){
                temp = a[j];
                a[j] =a[j+1];
                a[j+1] = temp;}
    for (i = 0; i < 100; i++){
        cout << a[i] << endl;
    }
    
    

        
    return 0;
}
    



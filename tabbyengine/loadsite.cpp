#include<iostream>    
#include<cstdlib>    
#include<pthread.h>

using namespace std;

#define NUM_THREADS 5

struct thread_data
{
  int  thread_id;
  char *message;
};


void *PrintHello(void *threadarg)
{
   struct thread_data *my_data;   

   my_data = (struct thread_data *) threadarg;

   cout << "Thread ID : " << my_data->thread_id ;

   cout << " Message : " << my_data->message << endl;

   pthread_exit(NULL);
}

int main ()
{
   pthread_t threads[NUM_THREADS];

   struct thread_data td[NUM_THREADS];

   int rc, i;


   for( i=0; i < NUM_THREADS; i++ )    
   {

      cout <<"main() : creating thread, " << i << endl;

      td[i].thread_id = i;

      td[i].message = "Created a thread!";

      rc = pthread_create(&threads[i], NULL,

                          PrintHello, (void *)&td[i]);
// We would need to create threads, but if it doesnt work give this message
      if (rc){

         cout << "Error:unable to create thread," << rc << endl;

         exit(-1);    
      }    
   }    
   pthread_exit(NULL);    
}
// We would multithread here

// Define a lambda expression
auto f = [](params)
{
    Statements;
};

// Pass f and its parameters to thread
// object constructor as
std::thread thread_object(f, params);

// We can now launch the thread

// defining class
class Base {
public:
    // static member function
    static void foo(param) { Statements; }
}

// object of Base Class
Base b;
// first parameter is the reference to the function
// and rest are arguments
std::thread thread_obj(&Base::foo, params);

#include <boost/thread/thread.hpp>
#include <iostream>
#include <string>
using namespace std;

const string EMPTY_QUEUE="empty queue! can not dequeue!!";

template<typename T>
class Queue
{
    public:
      Queue(){}
      ~Queue(){}

      void enQueue(const T& x)
      {
      	//lock the mutex for this queue, and the scope_lock
      	//is automatically destory after it goes out of range
      	 boost::mutex::scoped_lock lock(_mutex);
      	_list.push_back(x);
      }

      T deQueue()
      {
      	boost::mutex::scoped_lock lock(_mutex);
      	if(_list.empty())
      	{
      		throw EMPTY_QUEUE;
      	}
      	T tmp=_list.front();
      	_list.pop_front();
      	return (tmp);
      }

    private:
      std::list<T> _list;
      boost::mutex _mutex;
};

Queue<string> strQueue;

void send()
{
  string s="Yan";
  for(int i=0;i<10;i++)
  {
  	strQueue.enQueue(s);
  	cout<<"enter "<<s<<" to queue."<<endl;
  }
}

void recv()
{
  string tmpstr;
  for(int i=0;i<10;i++)
  {
  	try
  	{
  		tmpstr=strQueue.deQueue();
  		cout<<"remove "<<tmpstr<<" from the queue."<<endl;
  	}
  	catch(string es)
  	{
  		cout<<es<<endl;
  	}
  }
}

int main()
{
    //only throguh one-by-one way can they
    //conduct in an order
	boost::thread thr1(send);
	thr1.join();

	boost::thread thr2(recv);
	thr2.join();

	return 0;
}

// #include <iostream>
// #include <string>
// #include <vector>
// #include <boost/thread/thread.hpp>
// #include <boost/thread/xtime.hpp>
// using namespace std;

// template<typename T>
// class Queue;

// void add_to_queue(const string& s, Queue & q);
// void remove_from_queue(string[] s,Queue & q);

// struct ThreadFunction;
// static int count=0;
// const string EMPTY_QUEUE="empty queue! can not dequeue!!";

// int main()
// {
//   boost::thread aThread(threadFunction);
//   //sleep the current thread
//   boost::thread::yield();
//   //tell the call thread to wait for the end of called thread
//   aThread.join();
//   std::cout<<"print from the main thread."<<std::endl;

//   //create a series of thread
//   boost::thread_group grt;

//   //the first method to add a thread to the group
//   boost::thread* p=new boost::thread(threadFunction);
//   grt.add_thread(p);

//   //the second method to manage a thread group
//   grt.create_thread(threadFunction);
//   grt.create_thread(threadFunction);

//   //join all thread
//   grt.join_all();

//   //find and delet the thread pointer pointed object
//   grt.remove_thread(p);

//   //test for mutex
//   Queue<std::string> strQueue;
//   string instr="Yan";
//   string[12] outstr;
//   boost::thread write(add_to_queue(instr));
//   boost::thread read(remove_from_queue());

//   write.join();
//   read.join();
//   return 0;
// }

// template<typename T>
// class Queue
// {
//     public:
//       Queue(){}
//       ~Queue(){}

//       void enQueue(const T& x)
//       {
//       	//lock the mutex for this queue, and the scope_lock
//       	//is automatically destory after it goes out of range
//       	boost::mutex::scoped_lock;
//       	_list.push_back(x);
//       }

//       T deQueue()
//       {
//       	if(_list.empty())
//       	{
//       		throw EMPTY_QUEUE;
//       	}
//       	//T tmp=_lish.front();
//       	return _list.pop_front();
//       }

//     private:
//       std::list<T> _list;
//       boost::mutex _mutex;
// };

// void add_to_queue(const string& s,Queue & q)
// {
// 	for(int i=0;i<10;i++)
// 	{
// 		q.enQueue(s);
// 	}
// }

// void remove_from_queue(string[] s,Queue & q)
// {
// 	for(int i=10;i>0;i--)
// 	{
// 		try
// 		{
// 			s[i]=q.deQueue();
// 			//immediatly output the contents
// 			cout<<s[i]<<endl;
// 		}
// 		catch(string es)
// 		{
// 			cout<<es<<endl;
// 		}
// 	}
// }

// struct ThreadFunction
// {
//    void operator()()
//    {
//    	 std::cout<<"print from the "<<count++<<" sub thread."<<std::endl;
//    }
// } threadFunction;



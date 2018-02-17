#include <iostream>
#include <thread>
#include <cstdlib>
#include <mutex>
using namespace std;

mutex m;

void share_print(string msg, string id) {
  lock_guard<mutex> guard(m);
  //m.lock();
  cout << "from "<< id << ": " << msg << endl;
  //m.unlock();
}

void f()
{
  for (int i = 100; i < 200; i++) {
    share_print(to_string(i), "f");
  }
}

class Fctor {
public:
   void operator()(string msg) {
      for (int i = 100; i < 200; i++) {
        cout << "from t1: "<< i << " " << msg << endl;
      }
  }
};

int main()
{
  thread t1(f);
  //t1.join(); // main thread waits for t1 to finish
  //t1.detach(); // t1 will freely on its own -- daemon process
  /*  string s = "hello wolrd!";
  //Fctor fct;
  std::thread t1((Fctor()), std::move(s));
  try {
    for (int i = 0; i < 100; i++) {
      cout << "from main: " << i << " " << std::this_thread::get_id() << endl;
    }
  } catch(...) {
    t1.join();
    //throw;
  }
  t1.join(); */
  //cout << thread::hardware_concurrency() << endl;
  for (int i = 0; i < 100; i++)
    share_print(to_string(i), "main");
  t1.join();
  return 0;
}

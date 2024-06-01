#include <iostream> 
#include <thread>
using namespace std;
void hello() {
	cout<<"hello concurrent world"<<endl;
}
int main() {
	thread t(hello); //thread对象拥有函数hello()作为其初始函数 
	t.join();
}

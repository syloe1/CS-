#include <iostream> 
#include <thread>
using namespace std;
void hello() {
	cout<<"hello concurrent world"<<endl;
}
int main() {
	thread t(hello); //thread����ӵ�к���hello()��Ϊ���ʼ���� 
	t.join();
}

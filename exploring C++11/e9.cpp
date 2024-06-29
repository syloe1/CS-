//设计一个类， 我们只能生成该类的一个实例  （单例模式）
#include <iostream>
#include <mutex>
using namespace std;
class Singleton {
	private:
		static once_flag once_flag;
		static Singleton* instance ;
		
		//私有构造函数 ， 防止 外部创建实例 
		Singleton() {
			cout<<"Singleton instance created" << endl;
		}
		//避免复制和赋值
		Singleton(const Singleton&)  = delete;
		Singleton& operator = (const Singleton&) = delete;
	public:
		//公共静态方法， 用于获取实例
		static Singleton* getInstance()  {
			call_once(once_flag, []() {
				instance = new Singleton();
			});
			return instance;
		}
		
		~Singleton() {
			cout<<"Singleton instance destroyed"<<endl;
		}
		
		static void destroyInstance() {
			delete instance;
			instance = nullptr;
		}
};

// 初始化静态成员变量
Singleton* Singleton::instance = nullptr;
std::once_flag Singleton::once_flag;

int main() {
    // 获取单例的实例
    Singleton* singleton = Singleton::getInstance();

    // 其他代码...

    // 销毁单例的实例（通常在程序结束前调用）
    Singleton::destroyInstance();

    return 0;
}

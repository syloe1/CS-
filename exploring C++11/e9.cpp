//���һ���࣬ ����ֻ�����ɸ����һ��ʵ��  ������ģʽ��
#include <iostream>
#include <mutex>
using namespace std;
class Singleton {
	private:
		static once_flag once_flag;
		static Singleton* instance ;
		
		//˽�й��캯�� �� ��ֹ �ⲿ����ʵ�� 
		Singleton() {
			cout<<"Singleton instance created" << endl;
		}
		//���⸴�ƺ͸�ֵ
		Singleton(const Singleton&)  = delete;
		Singleton& operator = (const Singleton&) = delete;
	public:
		//������̬������ ���ڻ�ȡʵ��
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

// ��ʼ����̬��Ա����
Singleton* Singleton::instance = nullptr;
std::once_flag Singleton::once_flag;

int main() {
    // ��ȡ������ʵ��
    Singleton* singleton = Singleton::getInstance();

    // ��������...

    // ���ٵ�����ʵ����ͨ���ڳ������ǰ���ã�
    Singleton::destroyInstance();

    return 0;
}

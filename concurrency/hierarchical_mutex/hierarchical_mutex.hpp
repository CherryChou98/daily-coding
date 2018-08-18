#pragma
#include<exception>
#include<mutex>

#define UNLONG_MAX (0-1)

static thread_local unsigned long this_thread_hier_value(UNLONG_MAX);
class hierarchical_mutex
{
public:
	explicit hierarchical_mutex(unsigned long value) :
		hier_value(value),
		pre_hier_value(0)
	{}

	void lock()
	{
		check_for_hier_violation();
		internal_mutex.lock();
		update_hier_value();
	}
	void unlock(){
		if (this_thread_hier_value != hier_value) {
			throw std::logic_error("��֤ʧ��");
		}
		this_thread_hier_value = pre_hier_value;
		internal_mutex.unlock();
		//��Ϊ��prepre_hier_value���޷���ֵ��-1��Ϊȡ���
		pre_hier_value = 0 - 1;
	}
	bool try_lock(){
		check_for_hier_violation();
		if (!internal_mutex.try_lock())
			return false;
		update_hier_value();
		return true;
	}
private:
	std::mutex internal_mutex;
	unsigned long const hier_value;
	unsigned long pre_hier_value;
	static thread_local unsigned long this_thread_hier_value;
	//���ݲ���ֱ��д��ͷ�ļ���
	void check_for_hier_violation(){
		if (this_thread_hier_value < hier_value) {
			throw std::logic_error("���̳еȼ�����");
		}
	}
	void update_hier_value() {
		pre_hier_value = this_thread_hier_value;
		this_thread_hier_value = hier_value;
	}

};


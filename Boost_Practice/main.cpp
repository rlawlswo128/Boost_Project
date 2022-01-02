// Boost_Practice_Client(�Ӽ�) -> ��Ŀ -> �Ϲ� -> �߰� ���̺귯�� ���͸� -> boost�� ���̺귯��(C:\boost_1_78_0\stage\lib) �߰�
// Boost_Practice_Client(�Ӽ�) -> ���� �Ӽ� -> VC++ ���͸� -> ���� ���͸� -> boost�� ���̺귯��(C:\boost_1_78_0\stage\lib)�� ��Ʈ ���͸�(C:\boost_1_78_0)�� �߰�

#include<iostream>
#include<boost/asio.hpp>
#include<boost/date_time/posix_time/posix_time.hpp>

int main(void) {
	boost::asio::io_service io;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	t.wait();

	std::cout << "Hello, World!" << std::endl;

	system("pause");
	return 0;
}
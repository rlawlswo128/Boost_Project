// Boost_Practice_Client(�Ӽ�) -> ��Ŀ -> �Ϲ� -> �߰� ���̺귯�� ���͸� -> boost�� ���̺귯��(C:\boost_1_78_0\stage\lib) �߰�
// Boost_Practice_Client(�Ӽ�) -> ���� �Ӽ� -> VC++ ���͸� -> ���� ���͸� -> boost�� ���̺귯��(C:\boost_1_78_0\stage\lib)�� ��Ʈ ���͸�(C:\boost_1_78_0)�� �߰�

// Server

#define _CRT_SECURE_NO_WARNINGS
#include<ctime>
#include<iostream>
#include<string>
#include<boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace std;

// ���� ��ǻ���� ��¥ �� �ð� ������ ��ȯ�մϴ�.
string make_daytime_string() {
	time_t now = time(0);
	return ctime(&now);
}

int main() {
	try {
		boost::asio::io_service io_service;
		//�⺻������ Boost Asio ���α׷��� �ϳ��� IO Service ��ü�� ������.
		tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));
		//TCP ���������� 13�� ��Ʈ�� ������ �޴� ���� ������ �����Ѵ�.
		while (1) {
			tcp::socket socket(io_service);
			acceptor.accept(socket);
			// ���� ��ü�� ������ ������ ��ٸ���.

			string message = make_daytime_string();
			// ������ �Ϸ�Ǹ� �ش� Ŭ���̾�Ʈ���� ���� �޽����� �����Ѵ�.

			boost::system::error_code ignored_error;
			boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
			// �ش� Ŭ���̾�Ʈ�� �޽����� ��� �����Ѵ�.

		} // ��� Ŭ���̾�Ʈ�� ���� ������ �ݺ� �����Ѵ�.
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
	}
	return 0;
}
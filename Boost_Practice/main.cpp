// Boost_Practice_Client(속성) -> 링커 -> 일반 -> 추가 라이브러리 디렉터리 -> boost의 라이브러리(C:\boost_1_78_0\stage\lib) 추가
// Boost_Practice_Client(속성) -> 구속 속성 -> VC++ 디렉터리 -> 포함 디렉터리 -> boost의 라이브러리(C:\boost_1_78_0\stage\lib)의 루트 디렉터리(C:\boost_1_78_0)를 추가

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
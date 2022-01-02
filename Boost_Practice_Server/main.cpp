// Boost_Practice_Client(속성) -> 링커 -> 일반 -> 추가 라이브러리 디렉터리 -> boost의 라이브러리(C:\boost_1_78_0\stage\lib) 추가
// Boost_Practice_Client(속성) -> 구속 속성 -> VC++ 디렉터리 -> 포함 디렉터리 -> boost의 라이브러리(C:\boost_1_78_0\stage\lib)의 루트 디렉터리(C:\boost_1_78_0)를 추가

// Server

#define _CRT_SECURE_NO_WARNINGS
#include<ctime>
#include<iostream>
#include<string>
#include<boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace std;

// 서버 컴퓨터의 날짜 및 시간 정보를 반환합니다.
string make_daytime_string() {
	time_t now = time(0);
	return ctime(&now);
}

int main() {
	try {
		boost::asio::io_service io_service;
		//기본적으로 Boost Asio 프로그램은 하나의 IO Service 객체를 가진다.
		tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));
		//TCP 프로토콜의 13번 포트로 연결을 받는 수동 소켓을 생성한다.
		while (1) {
			tcp::socket socket(io_service);
			acceptor.accept(socket);
			// 소켓 객체를 생성해 연결을 기다린다.

			string message = make_daytime_string();
			// 연결이 완료되면 해당 클라이언트에게 보낼 메시지를 생성한다.

			boost::system::error_code ignored_error;
			boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
			// 해당 클라이언트에 메시지를 담아 전송한다.

		} // 모든 클라이언트에 대해 무한정 반복 수행한다.
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
	}
	return 0;
}
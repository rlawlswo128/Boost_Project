// Boost_Practice_Client(속성) -> 링커 -> 일반 -> 추가 라이브러리 디렉터리 -> boost의 라이브러리(C:\boost_1_78_0\stage\lib) 추가
// Boost_Practice_Client(속성) -> 구속 속성 -> VC++ 디렉터리 -> 포함 디렉터리 -> boost의 라이브러리(C:\boost_1_78_0\stage\lib)의 루트 디렉터리(C:\boost_1_78_0)를 추가

// Client

#include<iostream>
#include<boost/array.hpp>
#include<boost/asio.hpp>
//#include<boost/date_time/posix_time/posix_time.hpp>

using boost::asio::ip::tcp;
using namespace std;

int main(void) {
	/*boost::asio::io_service io;
	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
	t.wait();
	std::cout << "Hello, World!" << std::endl;*/

	try {
		// 기본적으로 Boost Asio 프로그램은 하나의 IO Service 객체를 가진다.
		boost::asio::io_service io_service;
		// 도메인 이름을 TCP 종단점으로 바꾸기 위해 Resolver를 사용한다.
		tcp::resolver resolver(io_service);
		// 서버로는 로컬 서버, 서비스는 Daytime 프로토콜을 적어준다.
		tcp::resolver::query query("localhost", "daytime");
		// DNS를 거쳐 IP 주소 및 포트 번호를 얻어온다.
		tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
		// 소켓 객체를 초기화하여 서버에 연결한다.
		tcp::socket socket(io_service);
		boost::asio::connect(socket, endpoint_iterator);

		while (1) {
			// 버퍼 및 오류 처리 변수를 선언한다.
			boost::array<char, 128> buf;
			boost::system::error_code error;
			// 버퍼를 이용해 서버로부터 데이터를 받아온다.
			size_t len = socket.read_some(boost::asio::buffer(buf), error);
			if (error == boost::asio::error::eof)
				break;
			else if (error)
				throw boost::system::system_error(error);
			// 버퍼에 담신 데이터를 화면에 출력한다.
			cout.write(buf.data(), len);
		}
	} 
	catch (exception& e) {
		cerr << e.what() << endl;
	}
	system("pause");
	return 0;
}
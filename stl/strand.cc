#define BOOST_DATE_TIME_NO_LIB
#define BOOST_REGEX_NO_LIB

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include <iostream>

boost::mutex global_stream_lock;

void WorkerThread(boost::shared_ptr<boost::asio::io_service> iosvc, int counter) {
    global_stream_lock.lock();
    std::cout << "Thread " << std::this_thread::get_id() << ", " << counter << " Start.\n";
    global_stream_lock.unlock();

    iosvc->run();

    global_stream_lock.lock();
    std::cout << "Thread " << counter << " End.\n";
    global_stream_lock.unlock();
}

void async_send_handler(int number) {
    std::cout << "Number: " << number << ", threadID: " << std::this_thread::get_id() << std::endl;
}

int main(void) {
    boost::shared_ptr<boost::asio::io_service> io_svc(
        new boost::asio::io_service
    );

    boost::shared_ptr<boost::asio::io_service::work> worker(
        new boost::asio::io_service::work(*io_svc)
    );

    boost::asio::io_service::strand strand(*io_svc);

    global_stream_lock.lock();
    std::cout << "The program will exit once all work has finished.\n";
    global_stream_lock.unlock();

    boost::thread_group threads;
    for( int i = 1; i <= 5; i++ )
        threads.create_thread(boost::bind(&WorkerThread, io_svc, i));

    boost::this_thread::sleep(boost::posix_time::milliseconds(500));

    // Imagine you are invoking async_send on tcp or udp socket several times
    // and you want the handlers of this async_send call to be invoked sequentially

    // This code is almost equal to calling handlers of socket.async_send.
    // The handlers are invoked concurently and the order might be arbitrary
    io_svc->post(boost::bind(&async_send_handler, 1));
    io_svc->post(boost::bind(&async_send_handler, 2));
    io_svc->post(boost::bind(&async_send_handler, 3));
    io_svc->post(boost::bind(&async_send_handler, 4));
    io_svc->post(boost::bind(&async_send_handler, 5));

    // This code will do what you exactly want;
    // It will execute the handlers sequentially in that order
    strand.post(boost::bind(&async_send_handler, 1));
    strand.post(boost::bind(&async_send_handler, 2));
    strand.post(boost::bind(&async_send_handler, 3));
    strand.post(boost::bind(&async_send_handler, 4));
    strand.post(boost::bind(&async_send_handler, 5));

    worker.reset();

    threads.join_all();

    return 0;
}

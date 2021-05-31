#include <iostream>
#include <future>
#include <thread>
#include <mutex>
#include <vector>

class ThreadedTime{
public:
    ThreadedTime(int n){
        n_ = n;
        ans_ = 0;
    }

    int runInThread(){
        auto start = std::chrono::system_clock::now();
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start).count();
    }

    void process(){
        std::vector<std::future<int> > futures;
        for (int i = 0; i < n_; i++){
            auto fut = std::async(std::launch::async, std::bind(&ThreadedTime::runInThread, this));
            futures.push_back(std::move(fut));
        }
        long ans = 0;
        for (int i = 0; i < n_; i++)
        {
            ans += futures[i].get();
        }
        std::cout << "total time: " << ans << std::endl;
    }

private:
    int n_;
    int ans_;
};

int main(){
    ThreadedTime t(20);
    t.process();
    return 0;
}
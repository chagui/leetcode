class Foo {
   public:
    Foo() : m {}, cv1 {}, cv2 {}, firstPrinted {false}, secondPrinted {false} {}

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstPrinted = true;
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(m);
        cv1.wait(lk, [&ready = firstPrinted]() { return ready.load(); });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondPrinted = true;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(m);
        cv2.wait(lk, [&ready = secondPrinted]() { return ready.load(); });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

   private:
    std::mutex m;
    std::condition_variable cv1;
    std::condition_variable cv2;
    std::atomic<bool> firstPrinted;
    std::atomic<bool> secondPrinted;
};

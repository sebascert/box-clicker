#ifndef UTILS_SINGLETON_HPP
#define UTILS_SINGLETON_HPP

template <typename T>
class Singleton
{
   public:
    // guards for copying and moving
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    static T& instance()
    {
        static T instance;
        return instance;
    }

   protected:
    Singleton() = default;
    virtual ~Singleton() = default;
};

#endif  // !UTILS_SINGLETON_HPP

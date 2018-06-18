#ifndef SC_CPP_STACK_H
#define SC_CPP_STACK_H

#include <vector>

template <typename T>
class Stack
{
public:
    void push (const T& t)
    {
        _stack.push_back(t);
    }

    T pop ()
    {
        if (_stack.empty()) {
            throw std::exception();
        }
        T tmp(_stack.back());
        _stack.pop_back();
        return tmp;
    }

private:
    std::vector<T> _stack;
};

#endif //SC_CPP_STACK_H

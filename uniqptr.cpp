#include "uniqptr.h"
#include <utility>

UniquePtr::UniquePtr() {
    _ptr = nullptr;
}

UniquePtr::UniquePtr(ValueType* ptr): _ptr(ptr) {}

UniquePtr::UniquePtr(UniquePtr&& other) noexcept {
    _ptr = std::exchange(other._ptr, nullptr);
}

UniquePtr& UniquePtr::operator=(UniquePtr&& other) noexcept {
    if (this != &other) {
        reset();
        _ptr = std::exchange(other._ptr, nullptr);
    }
    return *this;
}

UniquePtr& UniquePtr::operator=(ValueType* ptr) {
    // подозрительный метод
    return *this;
}

void UniquePtr::reset() {
    delete[] _ptr;
    _ptr = nullptr;
}

void UniquePtr::reset(ValueType* ptr) {
    delete[] _ptr;
    _ptr = ptr;
}

void UniquePtr::release() {
    _ptr = nullptr;
}

UniquePtr::operator bool() const {
    return _ptr != nullptr;
}

ValueType& UniquePtr::operator*() const {
    return *_ptr;
}

ValueType* UniquePtr::operator->() const {
    return _ptr;
}

ValueType* UniquePtr::get() const {
    return _ptr;
}
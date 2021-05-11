#pragma once
#include <iostream>

using ValueType = int;


class UniquePtr {
private:
    ValueType* _ptr;
public:
    // Конструктор
    UniquePtr();
    // Конструктор из указателя
    explicit UniquePtr(ValueType* ptr);

    // Конструктор перемещения
    UniquePtr(UniquePtr&& other) noexcept ;

    // Конструктор копирования
    UniquePtr(const UniquePtr& other) = delete;

    // оператор присваивания через перемещение
    UniquePtr& operator=(UniquePtr&& other) noexcept ;

    // оператор присваивания через копирование
    UniquePtr& operator=(const UniquePtr& other) = delete;

    // оператор присваивания - присвоить новый указатель
    // Не забывать про старую память
    UniquePtr& operator=(ValueType* ptr);
    // сбрасывает _ptr в nullptr
    // не забыть почистить память память память!
    void reset();

    // reset + присвоение нового указателя
    void reset(ValueType* ptr);

    // "Освобождение" указателя
    // без удаления памяти
    void release();

    // возвращает, внутри nullptr или нет
    explicit operator bool() const;

    // разыменовывание
    ValueType& operator*() const;

    // оператор стрелочки
    ValueType* operator->() const;

    // возвращает указатель
    ValueType* get() const;


};

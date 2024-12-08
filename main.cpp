#include <initializer_list>
#include <stdexcept>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
namespace sdj {
    template<class _Ty>
    class vec_iter {
        _Ty* ptr;
    public:
        using size_type = size_t;
        using value_type = _Ty;
        using difference_type = ptrdiff_t;
        using reference = _Ty&;
        using pointer = _Ty*;
        using iterator_category = std::random_access_iterator_tag;
        vec_iter() {ptr = nullptr;}
        vec_iter(_Ty* __pointer): ptr(__pointer) {}
        vec_iter(const vec_iter& __pointer): ptr(__pointer.ptr) {}
        void operator=(_Ty* __pointer) {
            ptr = __pointer;
        }
        void operator=(const vec_iter& __pointer) {
            ptr = __pointer.operator->();
        }
        bool operator<(const vec_iter& __right)noexcept {
            return ptr < __right.ptr;
        }
        const bool operator<(const vec_iter& __right)const noexcept {
            return ptr < __right.ptr;
        }
        bool operator<=(const vec_iter& __right)noexcept {
            return ptr <= __right.ptr;
        }
        const bool operator<=(const vec_iter& __right)const noexcept {
            return ptr <= __right.ptr;
        }
        bool operator>(const vec_iter& __right)noexcept {
            return ptr > __right.ptr;
        }
        const bool operator>(const vec_iter& __right)const noexcept {
            return ptr > __right.ptr;
        }
        bool operator>=(const vec_iter& __right)noexcept {
            return ptr >= __right.ptr;
        }
        const bool operator>=(const vec_iter& __right)const noexcept {
            return ptr >= __right.ptr;
        }
        bool operator==(const vec_iter& __right)noexcept {
            return ptr == __right.ptr;
        }
        const bool operator==(const vec_iter& __right)const noexcept {
            return ptr == __right.ptr;
        }
        bool operator!=(const vec_iter& __right)noexcept {
            return ptr != __right.ptr;
        }
        const bool operator!=(const vec_iter& __right)const noexcept {
            return ptr != __right.ptr;
        }
        _Ty& operator*()const noexcept {
            return *ptr;
        }
        _Ty* operator->()const noexcept {
            return ptr;
        }
        vec_iter& operator++() {
            ptr++;
            return *this;
        }
        vec_iter operator++(int) {
            vec_iter ret = *this;
            ptr++;
            return ret;
        }
        vec_iter& operator--() {
            ptr--;
            return *this;
        }
        vec_iter operator--(int) {
            vec_iter ret = *this;
            ptr--;
            return ret;
        }
        vec_iter& operator+=(difference_type _Off) {
            ptr += _Off;
            return *this;
        }
        vec_iter& operator-=(difference_type _Off) {
            ptr -= _Off;
            return *this;
        }
        vec_iter operator+(difference_type _Off) const {
            return vec_iter(*this) += _Off;
        }
        vec_iter operator-(difference_type _Off) const {
            return vec_iter(*this) -= _Off;
        }
        difference_type operator-(const vec_iter& right) const {
            return vec_iter(*this).operator->() - right.operator->();
        }
        _Ty& operator[](difference_type _Off) const {
            return (_Ty&)*(*this + _Off);
        }
        friend ostream& operator<<(ostream& os, vec_iter<_Ty> it) {
            cout << (_Ty*)(it.operator->());
            return os;
        }
    };
    template<class _Ty>
    class vec_citer {
        const _Ty* ptr;
    public:
        using size_type = size_t;
        using value_type = _Ty;
        using difference_type = ptrdiff_t;
        using reference = const _Ty&;
        using pointer = const _Ty*;
        using iterator_category = std::random_access_iterator_tag;
        vec_citer() {ptr = nullptr;}
        vec_citer(const vec_citer& __pointer): ptr(__pointer.ptr) {}
        vec_citer(_Ty* __pointer): ptr(__pointer) {}
        void operator=(_Ty* __pointer) {
            ptr = __pointer;
        }
        void operator=(const vec_citer& __pointer) {
            ptr = __pointer.operator->();
        }
        bool operator<(const vec_citer& __right)noexcept {
            return ptr < __right.ptr;
        }
        const bool operator<(const vec_citer& __right)const noexcept {
            return ptr < __right.ptr;
        }
        bool operator<=(const vec_citer& __right)noexcept {
            return ptr <= __right.ptr;
        }
        const bool operator<=(const vec_citer& __right)const noexcept {
            return ptr <= __right.ptr;
        }
        bool operator>(const vec_citer& __right)noexcept {
            return ptr > __right.ptr;
        }
        const bool operator>(const vec_citer& __right)const noexcept {
            return ptr > __right.ptr;
        }
        bool operator>=(const vec_citer& __right)noexcept {
            return ptr >= __right.ptr;
        }
        const bool operator>=(const vec_citer& __right)const noexcept {
            return ptr >= __right.ptr;
        }
        bool operator==(const vec_citer& __right)noexcept {
            return ptr == __right.ptr;
        }
        const bool operator==(const vec_citer& __right)const noexcept {
            return ptr == __right.ptr;
        }
        bool operator!=(const vec_citer& __right)noexcept {
            return ptr != __right.ptr;
        }
        const bool operator!=(const vec_citer& __right)const noexcept {
            return ptr != __right.ptr;
        }
        const _Ty& operator*()const noexcept {
            return *ptr;
        }
        const _Ty* operator->()const noexcept {
            return ptr;
        }
        const vec_citer& operator++() {
            ptr++;
            return *this;
        }
        const vec_citer operator++(int) {
            vec_citer ret = *this;
            ptr++;
            return ret;
        }
        const vec_citer& operator--() {
            vec_citer ret = *this;
            ptr--;
            return ret;
        }
        const vec_citer operator--(int) {
            ptr--;
            return *this;
        }
        const vec_citer& operator+=(difference_type _Off) {
            ptr += _Off;
            return *this;
        }
        const vec_citer& operator-=(difference_type _Off) {
            ptr -= _Off;
            return *this;
        }
        const vec_citer operator+(difference_type _Off) const {
            return vec_citer(*this) += _Off;
        }
        const vec_citer operator-(difference_type _Off) const {
            return vec_citer(*this) -= _Off;
        }
        difference_type operator-(const vec_citer& right) const {
            return vec_citer(*this).operator->() - right.operator->();
        }
        const _Ty& operator[](difference_type _Off) const {
            return (_Ty&)*(*this + _Off);
        }
        friend ostream& operator<<(ostream& os, vec_citer<_Ty> it) {
            cout << (_Ty*)(it.operator->());
            return os;
        }
    };
    template<class _Ty>
    class vec_riter {
        _Ty* ptr;
    public:
        using size_type = size_t;
        using value_type = _Ty;
        using difference_type = ptrdiff_t;
        using reference = _Ty&;
        using pointer = _Ty*;
        using iterator_category = std::random_access_iterator_tag;
        vec_riter() {ptr = nullptr;}
        vec_riter(const vec_riter& __pointer): ptr(__pointer.ptr) {}
        vec_riter(_Ty* __pointer): ptr(__pointer) {}
        void operator=(_Ty* __pointer) {
            ptr = __pointer;
        }
        void operator=(const vec_riter& __pointer) {
            ptr = __pointer.operator->();
        }
        bool operator<(const vec_riter& __right)noexcept {
            return ptr > __right.ptr;
        }
        const bool operator<(const vec_riter& __right)const noexcept {
            return ptr > __right.ptr;
        }
        bool operator<=(const vec_riter& __right)noexcept {
            return ptr >= __right.ptr;
        }
        const bool operator<=(const vec_riter& __right)const noexcept {
            return ptr >= __right.ptr;
        }
        bool operator>(const vec_riter& __right)noexcept {
            return ptr < __right.ptr;
        }
        const bool operator>(const vec_riter& __right)const noexcept {
            return ptr < __right.ptr;
        }
        bool operator>=(const vec_riter& __right)noexcept {
            return ptr <= __right.ptr;
        }
        const bool operator>=(const vec_riter& __right)const noexcept {
            return ptr <= __right.ptr;
        }
        bool operator==(const vec_riter& __right)noexcept {
            return ptr == __right.ptr;
        }
        const bool operator==(const vec_riter& __right)const noexcept {
            return ptr == __right.ptr;
        }
        bool operator!=(const vec_riter& __right)noexcept {
            return ptr != __right.ptr;
        }
        const bool operator!=(const vec_riter& __right)const noexcept {
            return ptr != __right.ptr;
        }
        _Ty& operator*()const noexcept {
            return *ptr;
        }
        _Ty* operator->()const noexcept {
            return ptr;
        }
        vec_riter& operator++() {
            ptr--;
            return *this;
        }
        vec_riter operator++(int) {
            vec_riter ret = *this;
            ptr--;
            return ret;
        }
        vec_riter& operator--() {
            ptr++;
            return *this;
        }
        vec_riter operator--(int) {
            vec_riter ret = *this;
            ptr++;
            return ret;
        }
        vec_riter& operator+=(difference_type _Off) {
            ptr -= _Off;
            return *this;
        }
        vec_riter& operator-=(difference_type _Off) {
            ptr += _Off;
            return *this;
        }
        vec_riter operator+(difference_type _Off) const {
            return vec_riter(*this) += _Off;
        }
        vec_riter operator-(difference_type _Off) const {
            return vec_riter(*this) -= _Off;
        }
        difference_type operator-(const vec_riter& right) const {
            return vec_riter(*this).operator->() - right.operator->();
        }
        _Ty& operator[](difference_type _Off) const {
            return (_Ty&)*(*this + _Off);
        }
        friend ostream& operator<<(ostream& os, vec_riter<_Ty> it) {
            cout << (_Ty*)(it.operator->());
            return os;
        }
    };
    template<class _Ty>
    class vec_criter {
        const _Ty* ptr;
    public:
        using size_type = size_t;
        using value_type = _Ty;
        using difference_type = ptrdiff_t;
        using reference = const _Ty&;
        using pointer = const _Ty*;
        using iterator_category = std::random_access_iterator_tag;
        vec_criter() {ptr = nullptr;}
        vec_criter(const vec_criter& __pointer): ptr(__pointer.ptr) {}
        vec_criter(_Ty* __pointer): ptr(__pointer) {}
        void operator=(_Ty* __pointer) {
            ptr = __pointer;
        }
        void operator=(const vec_criter& __pointer) {
            ptr = __pointer.operator->();
        }
        bool operator<(const vec_criter& __right)noexcept {
            return ptr > __right.ptr;
        }
        const bool operator<(const vec_criter& __right)const noexcept {
            return ptr > __right.ptr;
        }
        bool operator<=(const vec_criter& __right)noexcept {
            return ptr >= __right.ptr;
        }
        const bool operator<=(const vec_criter& __right)const noexcept {
            return ptr >= __right.ptr;
        }
        bool operator>(const vec_criter& __right)noexcept {
            return ptr < __right.ptr;
        }
        const bool operator>(const vec_criter& __right)const noexcept {
            return ptr < __right.ptr;
        }
        bool operator>=(const vec_criter& __right)noexcept {
            return ptr <= __right.ptr;
        }
        const bool operator>=(const vec_criter& __right)const noexcept {
            return ptr <= __right.ptr;
        }
        bool operator==(const vec_criter& __right)noexcept {
            return ptr == __right.ptr;
        }
        const bool operator==(const vec_criter& __right)const noexcept {
            return ptr == __right.ptr;
        }
        bool operator!=(const vec_criter& __right)noexcept {
            return ptr != __right.ptr;
        }
        const bool operator!=(const vec_criter& __right)const noexcept {
            return ptr != __right.ptr;
        }
        const _Ty& operator*()const noexcept {
            return *ptr;
        }
        const _Ty* operator->()const noexcept {
            return ptr;
        }
        const vec_criter& operator++() {
            ptr--;
            return *this;
        }
        const vec_criter operator++(int) {
            vec_criter ret = *this;
            ptr--;
            return ret;
        }
        const vec_criter& operator--() {
            ptr++;
            return *this;
        }
        const vec_criter operator--(int) {
            vec_criter ret = *this;
            ptr++;
            return ret;
        }
        const vec_criter& operator+=(difference_type _Off) {
            ptr -= _Off;
            return *this;
        }
        const vec_criter& operator-=(difference_type _Off) {
            ptr += _Off;
            return *this;
        }
        const vec_criter operator+(difference_type _Off) const {
            return vec_criter(*this) += _Off;
        }
        const vec_criter operator-(difference_type _Off) const {
            return vec_criter(*this) -= _Off;
        }
        difference_type operator-(const vec_criter& right) const {
            return vec_criter(*this).operator->() - right.operator->();
        }
        const _Ty& operator[](difference_type _Off) const {
            return (_Ty&)*(*this + _Off);
        }
        friend ostream& operator<<(ostream& os, vec_criter<_Ty> it) {
            cout << (_Ty*)(it.operator->());
            return os;
        }
    };
    template<class T>
    class Vector {
    public:
        using value_type = T;
        using size_type = size_t;
        using pointer = T*;
        using const_pointer = const T*;
        using reference = T&;
        using const_reference = const T&;
        using iterator = vec_iter<T>;
        using const_iterator = vec_citer<T>;
        using reverse_iterator = vec_riter<T>;
        using const_reverse_iterator = vec_criter<T>;
    private:
        T* m_data;
        size_type m_size;
        size_type m_capacity;
    public:
        Vector() {
            m_data = new T[10], m_size = 0, m_capacity = 10;
        }
        explicit Vector(size_t __size) {
            m_data = new T[__size]{}, m_size = __size, m_capacity = __size;
        }
        Vector(size_t __size, const T& val) {
            m_data = new T[__size], m_size = __size, m_capacity = __size;
            for (size_type i = 0; i < m_size; ++i) m_data[i] = val;
        }
        Vector(const Vector& __right) {
            m_size = __right.m_size;
            m_capacity = __right.m_capacity;
            m_data = new T[m_capacity];
            for (size_type i = 0; i < m_size; ++i) m_data[i] = __right.m_data[i];
        }
        Vector(Vector&& __right) {
            m_size = __right.m_size;
            m_capacity = __right.m_capacity;
            m_data = new T[m_capacity];
            for (size_type i = 0; i < m_size; ++i) m_data[i] = __right.m_data[i];
        }
        template <class InputIterator>
        Vector(InputIterator __left, InputIterator __right) {
            size_type __size = __right - __left;
            m_data = new T[__size], m_size = __size, m_capacity = __size;
            size_type i = 0;
            while (__left != __right) {
                m_data[i] = *__left;
                ++__left;
                ++i;
            }
        }
        Vector(const initializer_list<T>& init_list) {
            size_type __size = init_list.size();
            auto __left = init_list.begin(), __right = init_list.end();
            m_data = new T[__size], m_size = __size, m_capacity = __size;
            size_type i = 0;
            while (__left != __right) {
                m_data[i] = *__left;
                ++__left;
                ++i;
            }
        }
        ~Vector() {
            delete[] m_data;
        }
        void clear() {
            delete[] m_data;
            m_size = 0;
            m_capacity = 0;
        }
        void assign(size_type count, const T& value) {
            clear();
            Vector(count, value);
        }
        template <class InputIterator>
        void assign(InputIterator __left, InputIterator __right) {
            clear();
            size_type __size = __right - __left;
            m_data = new T[__size], m_size = __size, m_capacity = __size;
            size_type i = 0;
            while (__left != __right) {
                m_data[i] = *__left;
                ++__left;
                ++i;
            }
        }
        void assign(initializer_list<T> init_list) {
            clear();
            size_type __size = init_list.size();
            auto __left = init_list.begin(), __right = init_list.end();
            m_data = new T[__size], m_size = __size, m_capacity = __size;
            size_type i = 0;
            while (__left != __right) {
                m_data[i] = *__left;
                ++__left;
                ++i;
            }
        }
        Vector& operator=(Vector<T>&& __right) {
            clear();
            m_size = __right.m_size;
            m_capacity = __right.m_capacity;
            m_data = new T[m_capacity];
            for (size_type i = 0; i < m_size; ++i) m_data[i] = __right.m_data[i];
            return *this;
        }
        Vector& operator=(const Vector<T>& __right) {
            clear();
            m_size = __right.m_size;
            m_capacity = __right.m_capacity;
            m_data = new T[m_capacity];
            for (size_type i = 0; i < m_size; i++) m_data[i] = __right.m_data[i];
            return *this;
        }
        const size_type size(void)const noexcept {
            return m_size;
        }
        const size_type capacity(void)const noexcept {
            return m_capacity;
        }
        bool empty()const noexcept {
            return m_size == 0;
        }
        void resize(size_type __size) {
            if (__size == m_capacity) {
                m_size = __size;
                return ;
            }
            T* new_data = new T[__size];
            size_type copy_size = min(__size, m_size);
            for(size_type i = 0; i < copy_size; ++i){
                new_data[i] = m_data[i];
            }
            delete[] m_data;
            m_data = new_data;
            m_size = __size;
            m_capacity = __size;
        }
        void resize(size_type __size, const T& val) {
            resize(__size);
            for (size_type i = 0; i < m_capacity; i++) m_data[i] = val;
        }
        void shrink_to_fit() {
            resize(m_size);
        }
        reference at(size_type __pos) {
            if (__pos < 0 || __pos >= m_size) throw std::runtime_error("Invalid position!");
            return m_data[__pos];
        }
        const_reference at(size_type __pos)const {
            if (__pos < 0 || __pos >= m_size) throw std::runtime_error("Invalid position!");
            return m_data[__pos];
        }
        reference operator[](size_type __pos) {
            if (__pos < 0 || __pos >= m_size) throw std::runtime_error("Invalid position!");
            return m_data[__pos];
        }
        const_reference operator[](size_type __pos)const {
            if (__pos < 0 || __pos >= m_size) throw std::runtime_error("Invalid position!");
            return m_data[__pos];
        }
        reference front() {
            return at(0);
        }
        const_reference front()const {
            return at(0);
        }
        reference back() {
            return at(m_size - 1);
        }
        const_reference back()const {
            return at(m_size - 1);
        }
        void push_back(const T& val)noexcept {
            if (m_size + 1 > m_capacity) {
                /*
                // int a[m_capacity];
                T* a = new T[m_capacity];
                // memcpy(a,m_data,sizeof(a));
                for (size_type i = 0; i < m_capacity; i++) a[i] = m_data[i];
                delete[] m_data;
                m_data = new T[m_capacity += 10];
                // memcpy(m_data,a,sizeof(a));
                for (size_type i = 0; i < m_capacity - 10; i++) m_data[i] = a[i];
                delete[] a;
                */
                resize(m_capacity + 10);
                m_size -= 10;
            }
            m_data[m_size++] = val;
        }
        void pop_back() {
            if (empty()) throw std::runtime_error("The vector is empty!");
            m_data[--m_size] = T();
            if (m_size + (size_type)20 < m_capacity) {
                resize(m_capacity - 10);
            }
        }
        iterator begin()noexcept {
            return m_data;
        }
        const_iterator begin()const noexcept {
            return m_data;
        }
        const_iterator cbegin()const noexcept {
            return m_data;
        }
        iterator end()noexcept {
            return m_data + m_size;
        }
        const_iterator end()const noexcept {
            return m_data + m_size;
        }
        const_iterator cend()const noexcept {
            return m_data + m_size;
        }
        reverse_iterator rbegin()noexcept {
            return m_data + m_size - 1;
        }
        const_reverse_iterator rbegin()const noexcept {
            return m_data + m_size - 1;
        }
        const_reverse_iterator crbegin()const noexcept {
            return m_data + m_size - 1;
        }
        reverse_iterator rend()noexcept {
            return m_data - 1;
        }
        const_reverse_iterator rend()const noexcept {
            return m_data - 1;
        }
        const_reverse_iterator crend()const noexcept {
            return m_data - 1;
        }
        const_pointer data()const noexcept {
            return m_data;
        }
        pointer data()noexcept {
            return m_data;
        }
        iterator erase(const_iterator position) {
            if (position < cbegin() || position >= cend()) throw std::runtime_error("Invalid position!");
            size_type pos = position.operator->() - m_data;
            for (size_type i = pos; i < m_size - 1; i++) m_data[i] = m_data[i + 1];
            m_data[--m_size] = 0;
            if (m_size + (size_type)20 < m_capacity) {
                resize(m_capacity - 10);
            }
            if (pos == m_size) return end();
            else return begin() + pos;
        }
        iterator erase(iterator position) {
            const_iterator input = position.operator->();
            return erase(input);
        }
        iterator erase(const_iterator __left, const_iterator __right) {
            if (__left < cbegin() || __left >= cend()) std::runtime_error("Invalid position!");
            else if (__right < cbegin() || __right >= cend()) std::runtime_error("Invalid position!");
            size_type len = __right.operator->() - __left.operator->();
            size_type pos = __left.operator->() - m_data;
            size_type i = pos;
            for (; i < m_size - len; i++) m_data[i] = m_data[i + len];
            for (; i < m_size; i++) m_data[i] = 0;
            m_size -= len;
            if (m_size + (size_type)20 < m_capacity) {
                resize(m_capacity - 10);
            }
            if (pos >= m_size) return end();
            else return begin() + pos;
        }
        iterator erase(iterator __left, iterator __right) {
            const_iterator input_left = __left.operator->();
            const_iterator input_right = __right.operator->();
            return erase(input_left, input_right);
        }
        void swap(Vector<T>& right) {
            int* tmp_data;
            size_type tmp_size, ctmp_size;
            tmp_data = right.m_data;
            tmp_size = right.m_size;
            ctmp_size = right.m_capacity;
            right.m_data = m_data;
            right.m_size = m_size;
            right.m_capacity = m_capacity;
            m_data = tmp_data;
            m_size = tmp_size;
            m_capacity = ctmp_size;
        }
        friend void swap(Vector<T>& left, Vector<T>& right) {
            left.swap(right);
        }
        iterator insert(const_iterator position, const T& val) {
            if (m_size + 1 > m_capacity) {
                size_type tmp = position.operator->() - m_data;
                resize(m_capacity + 10);
                position = cbegin() + tmp;
                m_size -= 10;
            }
            m_size++;
            size_type pos = position.operator->() - m_data;
            const size_type last = m_size - 1;
            size_type i = last - 1;
            for (; i >= pos; i--) m_data[i + 1] = m_data[i];
            m_data[pos] = val;
            return begin() + pos;
        }
        iterator insert(iterator position, const T& val) {
            const_iterator input = position.operator->();
            return insert(input, val);
        }
        iterator insert(const_iterator position, T&& val) {
            if (m_size + 1 > m_capacity) {
                size_type tmp = position.operator->() - m_data;
                resize(m_capacity + 10);
                position = cbegin() + tmp;
                m_size -= 10;
            }
            m_size++;
            size_type pos = position.operator->() - m_data;
            const size_type last = m_size - 1;
            size_type i = last - 1;
            for (; i >= pos; i--) m_data[i + 1] = m_data[i];
            m_data[pos] = val;
            return begin() + pos;
        }
        iterator insert(iterator position, T&& val) {
            const_iterator input = position.operator->();
            return insert(input, val);
        }
        void insert(const_iterator position, size_type count, const T& val) {
            if (m_size + count > m_capacity) {
                size_type tmp = position.operator->() - m_data;
                resize(m_capacity + 10 + count);
                position = cbegin() + tmp;
                m_size -= count + 10;
            }
            m_size += count;
            size_type pos = position.operator->() - m_data;
            const size_type last = m_size - count;
            size_type i = last - 1;
            for (; i >= pos; i--) m_data[i + count] = m_data[i];
            for (size_type j = 0; j < count; j++) m_data[pos + j] = val;
        }
        void insert(iterator position, size_type count, const T& val) {
            if (m_size + count > m_capacity) {
                size_type tmp = position.operator->() - m_data;
                resize(m_capacity + 10 + count);
                position = begin() + tmp;
                m_size -= count + 10;
            }
            m_size += count;
            size_type pos = position.operator->() - m_data;
            const size_type last = m_size - count;
            size_type i = last - 1;
            for (; i >= pos; i--) m_data[i + count] = m_data[i];
            for (size_type j = 0; j < count; j++) m_data[pos + j] = val;
        }
        void insert(const_iterator position, const int* a, const int* b) {
            size_type len = b - a;
            if (m_size + len > m_capacity) {
                size_type tmp = position.operator->() - m_data;
                resize(m_capacity + 10 + len);
                position = cbegin() + tmp;
                m_size -= 10 + len;
            }
            int* tmp = new int[len];
            //int *ptr=a;
            for (int i = 0; i < len; a++, i++) tmp[i] = *a;
            size_type pos = position - cbegin();
            size_type last = m_size;
            m_size += len;
            for (size_type i = last; i > pos; i--) m_data[i + len - 1] = m_data[i - 1];
            for (size_type j = 0; j < len; j++) m_data[pos + j] = tmp[j];
            delete[] tmp;
        }
        void insert(iterator position, const int* a, const int* b) {
            const_iterator input = position.operator->();
            insert(input, a, b);
        }
    };
    template<typename T>
    bool operator==(const Vector<T>& left, const Vector<T>& right) {
        if (left.size() != right.size()) return false;
        auto src = left.cbegin();
        auto cmp = right.cbegin();
        while (src != left.cend()) {
            if (*src != *cmp) return false;
            src++, cmp++;
        }
        return true;
    }
    template<typename T>
    bool operator!=(const Vector<T>& left, const Vector<T>& right) {
        return !(left == right);
    }
    template<typename T>
    bool operator<(const Vector<T>& left, const Vector<T>& right) {
        if (left.size() < right.size()) return true;
        if (left.size() > right.size()) return false;
        auto src = left.cbegin();
        auto cmp = right.cbegin();
        while (*src == *cmp && src != left.cend()) src++, cmp++;
        return *src < *cmp;
    }
    template<typename T>
    bool operator<=(const Vector<T>& left, const Vector<T>& right) {
        return (left == right) || (left < right);
    }
    template<typename T>
    bool operator>(const Vector<T>& left, const Vector<T>& right) {
        if (left.size() > right.size()) return true;
        if (left.size() < right.size()) return false;
        auto src = left.cbegin();
        auto cmp = right.cbegin();
        while (*src == *cmp && src != left.cend()) src++, cmp++;
        return *src > *cmp;
    }
    template<typename T>
    bool operator>=(const Vector<T>& left, const Vector<T>& right) {
        return (left == right) || (left > right);
    }
}
int main() {
    using namespace sdj;

    int a[6] = {1, 1, 4, 5, 1, 4};
    Vector <int> v(a, a + 2);
    for (const auto& i : v) {
        cout << i << ' ';
    }
    cout << endl;

    v.assign(a, a + 6);
    Vector <int> v1 = v;
    for (const auto& i : v1) {
        cout << i << ' ';
    }
    cout << endl;
    cout << "v1.capacity()=" << v1.capacity() << endl;

    Vector <int> Ilist = {1, 9, 1};
    Ilist.push_back(0);
    Ilist.insert(Ilist.begin() + 2, 8);
    Ilist.shrink_to_fit();
    int tmp[2] = {1, 9};
    Ilist.insert(Ilist.begin(), tmp, tmp + 2);
    for (const auto& i : Ilist) {
        cout << i << ' ';
    }
    cout << endl;
    cout << "Ilist.capacity()=" << Ilist.capacity() << endl;

    v1.erase(v1.begin(), v1.begin() + 2);
    for (const auto& i : v1) {
        cout << i << ' ';
    }
    cout << endl;

    v1.insert(v1.begin() + 2, 114);
    /*
    for (const auto& i : v1) {
        cout << i << ' ';
    }
    cout << endl;
    */

    vec_iter<int> it = v1.begin();
    for (; it != v1.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;

    vector <int> v2, v3;
    v2.push_back( 1 );
    v2.push_back( 3 );
    v2.push_back( 1 );

    v3.push_back( 1 );
    v3.push_back( 2 );
    v3.push_back( 2 );

    if ( v2 >= v3 ) {
        cout << "Vector v2 is greater than or equal to vector v3." << endl;
    }
    else {
        cout << "Vector v2 is less than vector v3." << endl;
    }

    return 0;
}

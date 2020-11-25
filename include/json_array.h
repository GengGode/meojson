#pragma once

#include <string>
#include <vector>
#include <initializer_list>

namespace json
{
    class value;

    class array
    {
    public:
        using raw_array = std::vector<value>;
        using iterator = raw_array::iterator;
        using const_iterator = raw_array::const_iterator;
        using reverse_iterator = raw_array::reverse_iterator;
        using const_reverse_iterator = raw_array::const_reverse_iterator;

        array() = default;
        array(const array &rhs) = default;
        array(array &&rhs) noexcept = default;
        array(const raw_array &arr);
        array(raw_array &&arr) noexcept;
        array(std::initializer_list<raw_array::value_type> init_list);

        ~array() noexcept = default;

        bool empty() const noexcept { return _array_data.empty(); }
        size_t size() const noexcept { return _array_data.size(); }
        const value &at(size_t pos) const;
        std::string to_string() const;
        std::string format(std::string shift_str = "    ", size_t basic_shift_count = 0) const;

        void clear() noexcept;
        void push_back(const value &val);
        void push_back(value &&val);
        void emplace_back(const value &val);
        void emplace_back(value &&val);
        // void earse(size_t pos);

        iterator begin() noexcept;
        iterator end() noexcept;
        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;

        reverse_iterator rbegin() noexcept;
        reverse_iterator rend() noexcept;
        const_reverse_iterator crbegin() const noexcept;
        const_reverse_iterator crend() const noexcept;

        const value &operator[](size_t pos) const;
        value &operator[](size_t pos);

        array &operator=(const array &) = default;
        array &operator=(array &&) noexcept = default;

        // const raw_array &raw_data() const;

    private:
        raw_array _array_data;
    };

    std::ostream &operator<<(std::ostream &out, const array &arr);

} // namespace json
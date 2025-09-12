#include <bits/stdc++.h>

namespace debug {
        int db_level = 0;

        // ANSI color codes with meaningful names
        constexpr const char* RESET = "\033[0m";
        constexpr const char* BRACKET_COLOR = "\033[38;5;208m";  // Orange
        constexpr const char* VARIABLE_COLOR = "\033[38;5;117m"; // Light blue
        constexpr const char* VALUE_COLOR = "\033[38;5;255m";    // White
}

// https://quangloc99.github.io/posts/my-CP-debugging-template.html

#define print_op(...)                   std::ostream& operator<<(std::ostream& out, const __VA_ARGS__& u)

#define CONCAT_(x, y)                   x##y
#define CONCAT(x, y)                    CONCAT_(x, y)

#define clog                            std::cerr << std::setw(debug::db_level * 8) << std::setfill(' ') << "" << std::setw(0)
#define DB()                            debug_block CONCAT(dbbl, __LINE__)

#define dbg(val)                        debug::BRACKET_COLOR << "[" << debug::VARIABLE_COLOR << #val << debug::BRACKET_COLOR << ": " << debug::VALUE_COLOR << (val) << debug::BRACKET_COLOR << "] " << debug::RESET

struct debug_block {
        debug_block() { clog << "{" << std::endl; ++debug::db_level; }
        ~debug_block() { --debug::db_level; clog << "}" << std::endl; }
};

template<class U, class V> print_op(std::pair<U, V>) {
        return out << "(" << u.first << ", " << u.second << ")";
}

template<class Con, class = decltype(std::begin(std::declval<Con>()))>
typename std::enable_if<!std::is_same<Con, std::string>::value, std::ostream&>::type
operator<<(std::ostream& out, const Con& con) {
        out << "{";
        for (auto beg = con.begin(), it = beg; it != con.end(); ++it) out << (it == beg ? "" : ", ") << *it;
        return out << "}";
}

template<size_t i, class T> std::ostream& print_tuple_utils(std::ostream& out, const T& tup) {
        if constexpr(i == std::tuple_size<T>::value) return out << ")";
        else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}

template<class ...U> print_op(std::tuple<U...>) {
        return print_tuple_utils<0, std::tuple<U...>>(out, u);
}

struct time_taken {
        std::chrono::_V2::system_clock::time_point begin;

        void Start() {
                begin = std::chrono::high_resolution_clock::now();
        }

        void End() {
                auto end = std::chrono::high_resolution_clock::now();
                clog << std::fixed << std::setprecision(15) << "\n";
                auto Execution_Time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-9;
                clog << dbg(Execution_Time) << "\n";
        }
} Timer;

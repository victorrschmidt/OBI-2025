#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <type_traits>

#define DEBUG_MODE
#ifdef DEBUG_MODE

void debug_init(const std::string& name = "") {
    std::cout << "[DEBUG] " << name << " = ";
}
void debug_string(const std::string& value) {
    std::cout << "\"" << value << "\"";
}
template<typename Container>
void debug_container(const Container& container) {
    std::cout << "{";
    if (container.empty()) {
        std::cout << "}";
        return;
    }
    using T = typename Container::value_type;
    int i = 0;
    if constexpr (std::is_same<T, std::string>::value) {
        for (auto it = container.begin(); it != container.end(); it++) {
            debug_string(*it);
            std::cout << (i++ < (int) container.size() - 1 ? ", " : "}");
        }
    }
    else {
        for (auto it = container.begin(); it != container.end(); it++) {
            std::cout << *it << (i++ < (int) container.size() - 1 ? ", " : "}");
        }
    }
}
template<typename K, typename V>
void debug_map(const std::map<K, V>& mp) {
    std::cout << "{";
    if (mp.empty()) {
        std::cout << "}";
        return;
    }
    std::cout << "\n";
    for (const auto& [key, value] : mp) {
        std::cout << "  ";
        if constexpr (std::is_same<K, std::string>::value) {
            debug_string(key);
        }
        else {
            std::cout << key;
        }
        std::cout << ": ";
        if constexpr (std::is_same<V, std::string>::value) {
            debug_string(value);
        }
        else {
            std::cout << value;
        }
        std::cout << "\n";
    }
    std::cout << "}";
}

template<typename T>
typename std::enable_if<!std::is_same<T, std::string>::value && !std::is_class<T>::value>::type
debug(const T& value, const std::string& name = "") {
    debug_init(name);
    std::cout << value << "\n";
}
void debug(const std::string& value, const std::string& name = "") {
    debug_init(name);
    debug_string(value);
    std::cout << "\n";
}
template<typename T>
void debug(const std::vector<T>& vec, const std::string& name = "vector") {
    debug_init(name);
    debug_container(vec);
    std::cout << "\n";
}
template<typename T>
void debug(const std::set<T>& st, const std::string& name = "set") {
    debug_init(name);
    debug_container(st);
    std::cout << "\n";
}
template<typename K, typename V>
void debug(const std::map<K, V>& mp, const std::string& name = "map") {
    debug_init(name);
    debug_map(mp);
    std::cout << "\n";
}

#else

template<typename T>
void debug(const T&, const std::string& = "") {}

template<typename K, typename V>
void debug(const std::map<K, V>&, const std::string& = "") {}

#endif

#endif

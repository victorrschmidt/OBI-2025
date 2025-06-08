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

template<typename T>
typename std::enable_if<!std::is_same<T, std::string>::value && !std::is_class<T>::value>::type
debug(const T& value, const std::string& name = "") {
    std::cout << "[DEBUG] " << name << " = " << value << "\n";
}

void debug(const std::string& value, const std::string& name = "") {
    std::cout << "[DEBUG] " << name << " = \"" << value << "\"\n";
}

template<typename T>
void debug(const std::vector<T>& vec, const std::string& name = "vector") {
    std::cout << "[DEBUG] " << name << " = {";
    if constexpr (std::is_same<T, std::string>::value) {
        for (int i = 0; i < (int) vec.size(); i++) {
            std::cout << "\"" << vec[i] << "\"" << (i < (int) vec.size() - 1 ? ", " : "}\n");
        }
    }
    else {
        for (int i = 0; i < (int) vec.size(); i++) {
            std::cout << vec[i] << (i < (int) vec.size() - 1 ? ", " : "}\n");
        }
    }
}

template<typename T>
void debug(const std::set<T>& st, const std::string& name = "set") {
    std::cout << "[DEBUG] " << name << " = {";
    int i = 0;
    for (const auto& val : st) {
        if constexpr (std::is_same<T, std::string>::value) {
            std::cout << "\"";
        }
        std::cout << val;
        if constexpr (std::is_same<T, std::string>::value) {
            std::cout << "\"";
        }
        std::cout << (i++ < (int) st.size() - 1 ? ", " : "}\n");
    }
}

template<typename K, typename V>
void debug(const std::map<K, V>& mp, const std::string& name = "map") {
    std::cout << "[DEBUG] " << name << " = {\n";
    for (const auto& [key, value] : mp) {
        std::cout << "  ";
        if constexpr (std::is_same<K, std::string>::value) {
            std::cout << "\"" << key << "\"";
        }
        else {
            std::cout << key;
        }
        std::cout << ": ";
        if constexpr (std::is_same<V, std::string>::value) {
            std::cout << "\"" << value << "\"";
        }
        else {
            std::cout << value;
        }
        std::cout << "\n";
    }
    std::cout << "}\n";
}

#else

template<typename T>
void debug(const T&, const std::string& = "") {}

template<typename K, typename V>
void debug(const std::map<K, V>&, const std::string& = "") {}

#endif

#endif

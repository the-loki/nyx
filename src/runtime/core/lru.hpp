//
// Created by loki on 24-4-26.
//

#pragma once

#include <iostream>
#include <optional>
#include <unordered_map>

namespace nyx::runtime::core {

template<typename K, typename T>
class LRUCache {
public:
	LRUCache() {
		std::cout << "LRUCache init" << std::endl;
	}

public:
	static LRUCache<K, T> &getInstance();

	std::optional<T> get(const K &key);

	void put(const K &key, const T &value);

private:
	std::unordered_map<K, T> cache_;
	inline static LRUCache<K, T> *instance_ = {};
};

template<typename K, typename T>
LRUCache<K, T> &LRUCache<K, T>::getInstance() {
	return *instance_;
}

template<typename K, typename T>
void LRUCache<K, T>::put(const K &key, const T &value) {
	cache_.insert({key, value});
}

template<typename K, typename T>
std::optional<T> LRUCache<K, T>::get(const K &key) {
	if (auto it = cache_.find(key); it != cache_.end()) {
		return it->second;
	}

	return std::nullopt;
}

}// namespace nyx::runtime::core

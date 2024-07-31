#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0) {
        return cities.size() * 5;
    }

    list<string> cache;
    unordered_map<string, list<string>::iterator> cache_map;
    int time = 0;

    for (auto& city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        if (cache_map.find(city) != cache_map.end()) {
            // Cache hit
            time += 1;
            cache.erase(cache_map[city]);
            cache.push_front(city);
            cache_map[city] = cache.begin();
        } else {
            // Cache miss
            time += 5;
            if (cache.size() == cacheSize) {
                // Remove the least recently used item
                cache_map.erase(cache.back());
                cache.pop_back();
            }
            // Add the new city to the cache
            cache.push_front(city);
            cache_map[city] = cache.begin();
        }
    }

    return time;
}
// 1302.cpp
#include <algorithm>
#include <iostream>
#include <unordered_map>

struct movie {
    int id, hear, look;
    bool operator<(movie const &b) const {
        return hear > b.hear || (hear == b.hear && look > b.look);
    }
} movies[200005];

std::unordered_map<int, int> ms;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n;
    for (int i = 0, t; i < n; i++)
        std::cin >> t, ms[t]++;
    std::cin >> m;
    for (int i = 0, lang; i < m; i++) {
        std::cin >> lang;
        movies[i].id = i;
        if (ms.count(lang))
            movies[i].hear = ms[lang];
    }
    for (int i = 0, sub; i < m; i++) {
        std::cin >> sub;
        if (ms.count(sub))
            movies[i].look = ms[sub];
    }
    std::sort(movies, movies + m);
    std::cout << movies[0].id + 1 << '\n';
    return 0;
}
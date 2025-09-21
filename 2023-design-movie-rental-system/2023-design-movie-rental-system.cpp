#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
private:
    // (shop,movie) -> price
    unordered_map<long long, int> priceMap;
    
    // For each movie: set of (price, shop) for unrented copies
    unordered_map<int, set<pair<int,int>>> unrented;
    
    // Global rented set: (price, shop, movie)
    set<tuple<int,int,int>> rented;

    // helper to encode (shop,movie) as unique key
    long long encode(int shop, int movie) {
        return ((long long)shop << 32) | movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[encode(shop, movie)] = price;
            unrented[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        int count = 0;
        for (auto &p : unrented[movie]) {
            res.push_back(p.second); // shop id
            if (++count == 5) break;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = priceMap[encode(shop, movie)];
        unrented[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = priceMap[encode(shop, movie)];
        rented.erase({price, shop, movie});
        unrented[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        for (auto &t : rented) {
            auto [price, shop, movie] = t;
            res.push_back({shop, movie});
            if (++count == 5) break;
        }
        return res;
    }
};


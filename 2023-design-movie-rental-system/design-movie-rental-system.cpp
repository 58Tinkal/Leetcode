class MovieRentingSystem {
public:
    unordered_map<int, set<pair<int, int>>> avalible; // movie ->{price,shop}
    unordered_map<int, set<pair<int, int>>>movieToShop; // movie -> {shop,price}
    int n;
    set<tuple<int, int, int>> rented;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        this->n = n;
        for (auto& it : entries) {
            avalible[it[1]].insert({it[2], it[0]});
            movieToShop[it[1]].insert({it[0], it[2]});
        }
    }

    vector<int> search(int movie) {
        int count = 0;
        vector<int> result;
        if (avalible.count(movie)) {
            for (auto& it : avalible[movie]) {
                result.push_back(it.second);
                count++;
                if (count >= 5) {
                    break;
                }
            }
        }
        return result;
    }

    void rent(int shop, int movie) {
        if (movieToShop.count(movie)) {
            auto it = movieToShop[movie].lower_bound({shop, INT_MIN});
            int price = it->second;
            avalible[movie].erase({price, shop});
            rented.insert({price, shop, movie});
        }
    }

    void drop(int shop, int movie) {
        auto it = movieToShop[movie].lower_bound({shop, INT_MIN});
        int price = it->second;

        avalible[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (auto& [price, shop, movie] : rented) {
            result.push_back({shop, movie});
            count++;
            if (count >= 5) {
                break;
            }
        }
        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
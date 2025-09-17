class FoodRatings {
private:
    map<string, int> m;
    map<string, vector<int>> mp;
    vector<int> ratings;
    vector<string> foods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            m[foods[i]] = i;
        }
        for (int i = 0; i < cuisines.size(); i++) {
            mp[cuisines[i]].push_back(i);
        }
        this->ratings = ratings;
        this->foods = foods;
    }

    void changeRating(string food, int newRating) {
        ratings[m[food]] = newRating;
    }

    string highestRated(string cuisine) {
        string ans = "";
        int maxi = -1e9;
        for (auto& it : mp[cuisine]) {
            if (ratings[it] > maxi) {
                maxi = ratings[it];
                ans = foods[it];
            } else if (ratings[it] == maxi) {
                if (ans > foods[it]) {
                    ans = foods[it];
                }
            }
        }
        return ans;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
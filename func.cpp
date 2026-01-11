#include "func.hpp"
using namespace std;

unordered_map<tuple<string, string, long long>, int, tuple_hash> make_M(const Dataset &data){
    unordered_map<tuple<string, string, long long>, int, tuple_hash> M;

    for(size_t i = 0; i < data.sale.size(); i++){
        tuple<string, string, long long> temp = make_tuple(data.user_id[i], data.product_id[i], data.click_timestamp[i]);
        M[temp] = data.sale[i];
    }

    return M;
}

unordered_map<string, vector<struct product_info>> make_purchased(const Dataset &data){
    unordered_map<string, vector<struct product_info>> purchased;
    unordered_map<string, bool> is_in_users;
    vector<string> users;

    for(size_t i = 0; i < data.sale.size(); i++){
        if(!is_in_users[data.user_id[i]]){
            is_in_users[data.user_id[i]] = true;
            users.push_back(data.user_id[i]);
        }

        struct product_info temp;
        temp.product_id = data.product_id[i];
        temp.click_timestamp = data.click_timestamp[i];
        temp.product_price = data.product_price[i];
        temp.product_age_group = data.product_age_group[i];
        temp.product_gender = data.product_gender[i];

        purchased[data.user_id[i]].push_back(temp);
    }

    for(size_t i = 0; i < users.size(); i++){
        sort(purchased[users[i]].begin(), purchased[users[i]].end(), [](const product_info &a, const product_info &b){
            if(a.product_id != b.product_id)
                return a.product_id < b.product_id;

            return a.click_timestamp < b.click_timestamp;
        });
    }

    return purchased;
}


class Solution {
public:
    int get_id(string id_string){
        return stoi(id_string.substr(2, id_string.size() - 2));
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers);
        sort(events.begin(), events.end(), [](vector<string> a, vector<string> b){
            return (a[1] == b[1]) ? (a[0] == "OFFLINE") : (stoi(a[1]) < stoi(b[1]));
        });
        
        vector<bool> is_online(numberOfUsers, true);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> offline_users;
        int all_mention = 0;
        
        for(vector<string> event: events){
            int timestamp = stoi(event[1]);
            
            while(!offline_users.empty() && offline_users.top().first <= timestamp){
                is_online[offline_users.top().second] = true;
                offline_users.pop();
            }
            
            if(event[0] == "MESSAGE"){
                if(event[2] == "ALL"){
                    ++all_mention;
                }
                else if(event[2] == "HERE"){
                    for(int user = 0; user < numberOfUsers; ++user){
                        if(is_online[user]){
                            ++mentions[user];
                        }
                    }
                }
                else{
                    stringstream ids(event[2]);
                    int num_ids = count(event[2].begin(), event[2].end(), ' ') + 1;
                    for(int i = 0; i < num_ids; ++i){
                        string id_string;
                        ids >> id_string;
                        int id = get_id(id_string);
                        ++mentions[id];
                    }
                }
            }
            else{
                int id = stoi(event[2]);
                is_online[id] = false;
                offline_users.push({timestamp + 60, id});
            }
        }
        for(int &user: mentions){
            user += all_mention;
        }
        return mentions;
    }
};
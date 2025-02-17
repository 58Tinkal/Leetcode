class Solution {
public:
   int ans = 0;
   void solve(string &tiles, vector<bool> &visited, string s){
          //if(idx>=tiles.size()) return;
       for(int i=0;i<tiles.size();i++){
           if (visited[i]) continue;
            if (i > 0 && tiles[i] == tiles[i - 1] && !visited[i - 1]) continue; 
            visited[i] = true;
            ans++;
            solve(tiles, visited, s + tiles[i]);
            visited[i] = false;
       }
   }
    int numTilePossibilities(string tiles) {
         sort(tiles.begin(), tiles.end()); 
        vector<bool> visited(tiles.size(), false);
        solve(tiles, visited, "");
        return ans;
    }
};
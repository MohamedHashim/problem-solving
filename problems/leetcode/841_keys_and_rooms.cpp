class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> keys;
      for (int i = 0; i < rooms.size(); i++)
        {
          bool found = false;
          for(int k=0;k<keys.size();k++){
                   if(i==0||i==keys[k]){
                        found =true;
                        break;
                   }
            }
          if(found){
            for (int j = 0; j < rooms[i].size(); j++)
            {
                if (rooms[i][j] != i && rooms[i][j] != 0 )
                {
                    keys.insert(rooms[i][j]);
                }
            }
          }
        }
        if(keys.size()==rooms.size()-1)
            return true;
        else
            return false;
        return true;
    }
};
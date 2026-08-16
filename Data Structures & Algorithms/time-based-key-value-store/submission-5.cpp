class TimeMap {

private:
    unordered_map<string,vector<pair<string,int>>> timeMap_dict;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<string,int> p = {value,timestamp};
        timeMap_dict[key].push_back(p);
    }
    
    string get(string key, int timestamp) {
        

        int n = timeMap_dict[key].size();

        if(n==0)return "";
      

        int index=-1;

        int time_stamp = INT_MIN;

        int left = 0;
        int right = n-1;

        int middle;

       


        while(left<=right){

            middle = (left+right)/2;

            if(timestamp < timeMap_dict[key][middle].second){

                right = middle - 1;



            }else if(timestamp > timeMap_dict[key][middle].second){

                left = middle + 1;

                if(time_stamp<timeMap_dict[key][middle].second && timeMap_dict[key][middle].second<=timestamp){
                    time_stamp = timeMap_dict[key][middle].second;
                    index=middle;
                }

            }else{
                return timeMap_dict[key][middle].first;
            }


        }

        if(index==-1)return "";

        


        return timeMap_dict[key][index].first;
    }
};

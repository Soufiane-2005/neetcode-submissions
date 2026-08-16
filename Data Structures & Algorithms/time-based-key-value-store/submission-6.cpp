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
        

        const auto& v = timeMap_dict[key];

        int n = v.size();



        if(n==0)return "";
      

        int index=-1;

        int time_stamp = INT_MIN;

        int left = 0;
        int right = n-1;

        int middle;

       


        while(left<=right){

            middle = (left+right)/2;

            if(timestamp < v[middle].second){

                right = middle - 1;



            }else if(timestamp > v[middle].second){

                left = middle + 1;

                if(time_stamp<v[middle].second && v[middle].second<=timestamp){
                    time_stamp = v[middle].second;
                    index=middle;
                }

            }else{
                return v[middle].first;
            }


        }

        if(index==-1)return "";

        


        return v[index].first;
    }
};

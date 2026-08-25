class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<double,int>> pq;
        int c = 0;
        for(vector<int> point : points){

            pair<double,int> p;
            p.first = distance(point);
            p.second = c;
            c++;
            pq.push(p);
            if(c>k){
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while(k!=0){
            pair<double,int> p = pq.top();
            res.push_back(points[p.second]);
            pq.pop();
            k--;
        }

        return res;
        
    }

    double distance(vector<int> coord){
        int x = coord[0];
        int y = coord[1];
        return sqrt(pow(x,2)+pow(y,2));
    }
};

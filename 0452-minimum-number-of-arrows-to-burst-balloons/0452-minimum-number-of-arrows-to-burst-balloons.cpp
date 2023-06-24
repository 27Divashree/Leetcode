class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        return a.second < b.second;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>> v;
        int n = points.size();
        for(int i=0;i<n;i++)
        {
            pair<int,int> p = make_pair(points[i][0],points[i][1]);
            v.push_back(p);
        }

        sort(v.begin(),v.end(),cmp);
        int count=1, ansEnd = v[0].second;

        for(int i=1;i<n;i++)
        {
            if(v[i].first > ansEnd)
            {
                count++;
                ansEnd = v[i].second;
            }
        }

        return count;
    }
};
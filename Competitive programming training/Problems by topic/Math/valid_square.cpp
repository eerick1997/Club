//https://leetcode.com/problems/valid-square/submissions/
class Solution {
public:
    
    double distance(const vector<int> p1, const vector<int> p2) {
        double X = (p1[0] - p2[0]);
        double Y = (p1[1] - p2[1]);
        double ans = sqrt(X*X + Y*Y);
        return ans;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<double, int> distances;
        vector<vector<int>> points{p1, p2, p3, p4};

        for(int first = 0; first < 4; first++)
            for(int second = first + 1; second < 4; second++)
                    distances[distance(points[first], points[second])]++;
            
        //Candidate to be the answer
        if(distances.size() == 2) {
            for(const auto dist : distances)
                if(dist.second == 4)
                    return true;
        }
        return false;
    }
};
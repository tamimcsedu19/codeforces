#include <iostream>
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> ii;

class convex_hull{
    enum point_compare {greater,smaller,equal};
    vector<ii> points;
    vector<ii> convexHull;
    ii p0;
public:
    bool compar(ii p1,ii p2){
        if(p1.y == p2.y)
            return p1.x<p2.x;
        return p1.y<p2.y;

    }
    convex_hull(vector<ii> init)
    {
        sort(init.begin(),init.end(),bind(&convex_hull::compar,this,placeholders::_1,placeholders::_2));
        points = init;
        p0 = init[0];
    }
    int cross_product(ii p1,ii p2,ii p0)
    {
        return ((p1.x-p0.x)*(p2.y-p0.y))-((p1.y-p0.y)*(p2.x-p0.x));
    }
    point_compare compare(ii p1,ii p2,ii p0)
    {
        int d = cross_product(p1,p2,p0);
        if(d>0)
            return smaller;
        else if(d<0)
            return greater;
        else
            return equal;
    }
    bool sort_compare(ii p1,ii p2)
    {
        point_compare x = compare(p1,p2,p0);
        if(x == smaller)
            return true;
        else if(x == equal)
            return p1>p2;
        return false;
    }
ii nextToTop(stack<ii> &S)
{
    ii p = S.top();
    S.pop();
    ii res = S.top();
    S.push(p);
    return res;
}
    stack<ii> find_convex_hull()
    {
        vector<ii> polar_sorted = points;
        sort(polar_sorted.begin()+1,polar_sorted.end(),bind(&convex_hull::sort_compare,this,placeholders::_1,placeholders::_2));
        stack<ii> res;
        res.push(p0);
        res.push(polar_sorted[1]);
        res.push(polar_sorted[2]);
        for(int i=3;i<polar_sorted.size();++i)
        {

            while((compare(polar_sorted[i],res.top(),nextToTop(res)) ) != greater)
            {
                res.pop();
            }
            res.push(polar_sorted[i]);
        }
        return res;
    }
};


class max_dist_calc{
public:

    vector<ii> convex_hulls;
    int n;
    max_dist_calc(stack<ii> s,int n)
    {
        this->n = n;
        while(!s.empty())
        {
            convex_hulls.push_back(s.top());
            s.pop();

        }

    }
    vector<ii> ans;
    vector<ii> tmpres;
    int cur=0;
    int maxv = 0;
    void max_dist(int idx,int points_taken,int sum_x,int sum_y,int sum_sqrd_x,int sum_sqrd_y)
    {

        if(points_taken == n)
        {
            if(cur>maxv)
            {
                maxv = cur;
                ans = tmpres;

            }
            return;
        }


        for(int i=idx;i<convex_hulls.size();++i)
        {
            int _x = convex_hulls[i].x,_y = convex_hulls[i].y;
            int cur_x = points_taken*(_x*_x) - 2*(sum_x)*_x + sum_sqrd_x;
            int cur_y = points_taken*(_y*_y) - 2*(sum_y)*_y + sum_sqrd_y;
            cur+=(cur_x+cur_y);
            tmpres.push_back(convex_hulls[i]);
            max_dist(i,points_taken+1,sum_x+_x,sum_y+_y,sum_sqrd_x+_x*_x,sum_sqrd_y+_y*_y);
            tmpres.pop_back();
            cur-=(cur_x+cur_y);
        }
    }


};

int main()
{
    freopen("in.txt","r",stdin);

    vector<ii> st;
    set<ii> points;
    int n,r;
    cin>>n>>r;
    for(int i=0;i<=r;++i)
    {
        for(int j=0;j<=r;++j)
        {
            int cmp = i*i + j*j - r*r;
            if(cmp <= 0)
            {
                points.insert({i,j});
               // if(i!=0)
                    points.insert({-i,j});
                //if(j!=0)
                    points.insert({i,-j});
                //if(i!=0 && j!=0)
                points.insert({-i,-j});

            }
        }
    }
    for(auto x:points)
    {
        //cout<<x.x<<" "<<x.y<<endl;
        st.push_back(x);
    }
    //cout<<endl;
    convex_hull A(st);
    stack<ii> res = A.find_convex_hull();
//    while(!res.empty())
//    {
//        cout<<res.top().x<<" "<<res.top().y<<endl;
//        res.pop();
//
//    }


    max_dist_calc B(res,n);
    B.max_dist(0,0,0,0,0,0);
    cout<<B.maxv<<"\n";
    for(int i=0;i<B.ans.size();++i)
    {
        cout<<B.ans[i].x<<" "<<B.ans[i].y<<"\n";

    }
}

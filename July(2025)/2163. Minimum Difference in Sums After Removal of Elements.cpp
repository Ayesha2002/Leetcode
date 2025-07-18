#define ll long long
class Solution {
public:
    long long minimumDifference(vector<int>& a) {
        ll n = a.size();
        ll len = n / 3;

        //  First part
        //  1. Make sum and fill in pq
        priority_queue<ll> pq;
        vector<ll> fi;
        ll sum = 0;
        for (ll i = 0; i < len; i++) {
            pq.push(a[i]);
            sum += a[i];
        }
        fi.push_back(sum);

        for (ll i = len; i < len * 2; i++) {
            sum -= pq.top();
            pq.pop();
            sum += a[i];
            fi.push_back(min(sum, fi[fi.size() - 1])); 
//  I got wrong bcuz I forgot to use min and max(for suffix array) (:
            pq.push(a[i]);
        }

        //  Second part
        pq = priority_queue<ll> (); //  Reset pq
        vector<ll> se;
        sum = 0;
        for (ll i = n - 1; i >= len * 2; i--) {
            pq.push(a[i] * -1);
            sum += a[i];
        }
        se.push_back(sum);

        for (ll i = n - len - 1; i >= len; i--) {
            sum -= pq.top() * -1;
            pq.pop();
            sum += a[i];
            se.push_back(max(sum, se[se.size() - 1]));
            pq.push(a[i] * -1);
        }
        reverse(se.begin(), se.end());

        ll mn = LLONG_MAX;
        ll si = fi.size();
        for (ll i = 0; i < si; i++) {
            mn = min(mn, fi[i] - se[i]);
        }
        return mn;
    }
};

/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 46450
 * Submitted at:  2017-12-15 22:37:16
 *
 * User ID:       335
 * Username:      54780828
 * Problem ID:    755
 * Problem Name:  Stock Market
 */


#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
int max(int i, int j)
{
	return i>j ? i:j;
}

long long largestRectangleArea(vector<long long>& heights) 
{
    long long res = 0;
    stack<long long> s;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); ++i)
	{
		while(1)
		{
			if(s.empty())
				break;
			if(heights[s.top()] < heights[i])
				break;
            int cur = s.top(); s.pop();
            res = max(res, heights[cur] * (s.empty() ? i : (i - s.top() - 1)));
        }
        s.push(i);
    }
    return res;
}

int main()
{

	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		vector<long long> v;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			long long x;
			scanf("%lld",&x);
			v.push_back(x);
		}
		printf("%lld\n",largestRectangleArea(v));
	}
}
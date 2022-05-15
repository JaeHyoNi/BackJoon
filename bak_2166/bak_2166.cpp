#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};
vector<point> POINT;
inline double CCW(point &a,point &b,point &c) {return (a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x)/2;}

int main() {
	int n; scanf("%d",&n);
	vector<point> POINT(n);
	double ans = 0;
	for (int i = 0; i < n; i++) scanf("%lf %lf", &POINT[i].x, &POINT[i].y);
	for (int i = 1; i < n-1; i++) ans += CCW(POINT[0],POINT[i],POINT[i+1]);
	printf("%.1lf", abs(ans));
	return 0;
}

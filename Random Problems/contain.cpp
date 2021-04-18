 #include <iostream> 
using namespace std; 

#define INF 10000 

struct Point 
{ 
	long int x; 
	long int y; 
}; 

bool onSegment(Point p, Point q, Point r) 
{ 
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
			q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
		return true; 
	return false; 
} 

int orientation(Point p, Point q, Point r) 
{ 
	long int val = (q.y - p.y) * (r.x - q.x) - 
			(q.x - p.x) * (r.y - q.y); 

	if (val == 0) return 0;  
	return (val > 0)? 1: 2; 
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
	long int o1 = orientation(p1, q1, p2); 
	long int o2 = orientation(p1, q1, q2); 
	long int o3 = orientation(p2, q2, p1); 
	long int o4 = orientation(p2, q2, q1); 
	if (o1 != o2 && o3 != o4) 
		return true; 
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;  
	if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
	if (o3 == 0 && onSegment(p2, p1, q2)) return true;  
	if (o4 == 0 && onSegment(p2, q1, q2)) return true; 

	return false;
} 
bool isInside(Point polygon[], long int i,long int n, Point p) 
{ 
	if (n < 3) return false; 
	Point extreme = {INF, p.y}; 
	long int count = 0; 
	do
	{ 
		long int next = (i+1)%n; 

		
		if (doIntersect(polygon[i], polygon[next], p, extreme)) 
		{ 
			if (orientation(polygon[i], p, polygon[next]) == 0) 
			return onSegment(polygon[i], p, polygon[next]); 

			count++; 
		} 
		i = next; 
	} while (i != 0); 
	return count&1; 
} 

int main() 
{ 
	 int t;
   cin>>t;
   while(t--)
   {
   		long int n,q;
   		cin>>n>>q;
   		long int i,j;
   		long int count=0;
   		Point polygon[n] ;
   		for(i=0;i<n;i++)
   		{
   			cin>>polygon[i].x>>polygon[i].y;
   		}
   		Point p;
   		for(int l=0;l<q;l++)
   		{
   			cin>>p.x>>p.y;
   			int flag=1;
   			for(i=0;i<n;i++)
   			{
   				for(j=i;j<n;j++)
   				{
   					 if(isInside(polygon,i, j, p))
   					 {
   					 		count++;
   					 }
   				}

   			}
   		}
   		cout<<count<<endl;
   }
	return 0; 
}



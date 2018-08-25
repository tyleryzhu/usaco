#include <iostream>
#include <vector> 
#include <map> 
#include <string>
#include <stdlib.h>
#include <stack> 

using namespace std;

struct PT {
	double x, y;  //coordinates 
    string ID; 
	PT () {};  //empty constructor 
	PT (double x, double y) : x(x), y(y) {}	 //constructor
	PT (const PT &p) : x(p.x), y(p.y) {}

	bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }  //for sorting
	bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); } //for unique

	PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
	PT operator * (double c) const { return PT(x*c, y*c ); } 
	PT operator / (double c) const { return PT(x/c, y/c ); }
};

ostream &operator<<(ostream &os, const PT &p) {
	os << "(" << p.x << "," << p.y << ")";
}

// Is the rotation CCW? 1 if CCW, -1 if CW, 0 if collinear 
int ccw (PT a, PT b, PT c){ //equiv to (b-a)x(c-a)
	double a2 = 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (c.x - a.x) * (b.y - a.y); 
	if (a2 > 0) return +1; 
	else if (a2 < 0) return -1; 
	else return 0; 
}

bool LinesIntersect (PT a, PT b, PT c, PT d){
    return ccw(a, b, c) * ccw(a, b, d) == -1
        && ccw(c, d, a) * ccw(c, d, b) == -1;
}

bool contained_in(PT cow, const vector<PT> &poly){ //receive a cow, and the vertices of a polygon    
    //Pick (-1, cow.y+1) so that Probability of bad cases is = 0 (since all points on this line seg. are non-integer)
    PT cow2 = PT(-1, cow.y+1); 
    int tot = 0; 
    for (int i = 0; i<poly.size()-1; i++){
        if (LinesIntersect(cow, cow2, poly[i], poly[i+1])) tot++; 
    }
    if (tot % 2 == 1) return true; 
    return false; 
}

int main() {
    /** Step 0: Receive input by using maps so that we can trace the polygons and find out the vertices 
     *          We have be careful of directions though, b/c if we have (a,b,c,d) but a->b and c->b, then 
     *          c -> d won't work b/c a->b is screwed then, so we'll need to do some iffy stuff to account for it **/ 
    /**         One way of accounting for this is to check the tail of every arrow we insert into our map 
     *          and see if it's the tail of some other arrow. If so, we backpropagate until all the arrows 
     *          are the right direction. Kinda adhoc-y but its really not too bad           **/ 
    int N, C; 
    cin >> N >> C; 
    map<PT, PT> mymap;  //first use a map to store points
    for (int i = 0; i<N; i++){
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;    
        /** Only case I need to check is if something is coming out of the arrow's tail **/ 
        PT tail, head; 
        tail = PT(x1, y1); 
        stack<PT> reverse;  
        while (mymap.count(tail) == 1) { //while the direction is still backwards 
            head = tail; 
            tail = mymap[tail];  
            mymap.erase(head); //erase arrow
            reverse.push(head); //push into stack for reversing 
        }
        while (!reverse.empty()){
            head = reverse.top(); 
            reverse.pop(); 
            mymap[tail] = head; 
            tail = head; 
        }
        mymap[PT(x1, y1)] = PT(x2, y2); //create a map there 
    }
   
    /** Step 1: Create a vector of vectors of polygons; first index is polygon #, next index is pt # **/ 
    vector<vector<PT> > poly(N); //initialize to N polygonas b/c why not 
    int polyCt = 0; //counter for polygon #
    while (mymap.size() != 0){ //while map is not empty
        PT start, one, two; //one, two are just dummy variables for the 1st & 2nd pts of a line
        map<PT, PT>::iterator it = mymap.begin(); //get first value 
        start = it->first; 
        one = it->first;
        two = it->second; 
        poly[polyCt].push_back(one); //first vertex
        mymap.erase(one); //erasing so that I don't write polygons twice 
        while (!(mymap[two] == start)){ //while we haven't gone around to full circle yet
            one = two; 
            two = mymap[two]; //get next linesegment
            poly[polyCt].push_back(one); 
            mymap.erase(one); 
        }
        poly[polyCt].push_back(two); //final vertex
        poly[polyCt].push_back(start); //make calculations easier 
        mymap.erase(two);  
        polyCt++; //increment
    }
	
    /** Step 2: Receive cows, and create an ID for each based on if it is contained in polygon i **/
    vector<PT> cows(C); 
    for (int i = 0; i<C; i++){
        int x, y; 
        cin >> x >> y; 
        cows[i] = PT(x,y); 
        for (int p = 0; p < polyCt; p++){ //iterating through polygons
            if (contained_in(cows[i], poly[p])){
                cows[i].ID += "1"; 
            }
            else cows[i].ID += "0"; 
        }
    }
    
    /** Step 3: Create a count of the # of cows in the same community by mapping based on ID **/ 
    map<string, int> com; 
    int best = 0; 
    for (int i = 0; i<C; i++){
        if (com.count(cows[i]) == 0) { //not in map yet
            com[cows[i].ID = 0; 
        }
        best = max(best, com[cows[i].ID]++); 
    }
    
    /** Step 4: Output Answer **/ 
    cout << best << endl; 
}


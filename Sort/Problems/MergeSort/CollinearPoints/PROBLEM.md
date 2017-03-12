# `Collinear Points`

###    `Category:` `Merge Sort`
###    `Level:` `MEDIUM`

Given a set of n distinct points in the plane, find every (maximal) line segment that connects a subset of 4 or more of the points.

**Point Data Type** : Create an immutable data type Point thar represents a point in the plane by implementing the following API  
&nbsp;&nbsp;&nbsp;&nbsp; Point  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  Point(int x, int y)      
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  int compare(Point that)    &nbsp;&nbsp;&nbsp;&nbsp; *// compare two points by co-ordinates, breaking ties by x-coordinates*  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  double slope(Point that)    &nbsp;&nbsp;&nbsp;&nbsp; *// slope between this point and that point*  

Formulae:  
* Comparison of two points: y2 < y1; if (y2 == y1) then (x2 - x1)
* Slope: (y2 - y1)/(x2 - x1)  

&nbsp;&nbsp;&nbsp;&nbsp; LineSegment  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  LineSegment(Point pt1, Point pt2)    &nbsp;&nbsp;&nbsp;&nbsp;




    
        
    

Problem Statement : [__Collinear Points__](http://coursera.cs.princeton.edu/algs4/assignments/collinear.html)
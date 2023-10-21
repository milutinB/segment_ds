Segment Data Structure
======================

An implementation of the data stucture for reporting segment intersections described in chapter 10 of
_Computational Geometry: Algorithms and Applications 3rd Edition by Mark de Berg, Otfried Cheong, Marc van Krevel, Mark Overmars_

Prerequisites
============
<ul>
    <li><a href="https://www.cgal.org/"> CGAL </a></li>
    <li><a href="https://www.boost.org/"> Boost </a></li>
</ul>

Description
===========

The data structure takes as input as set of line segments $S$.
Given a vertical segment $q$, a query method reports the segments in $S$ which intersect $q$.

Note that for this implementation, the segments in $S$ must be in _general_ _position_, i.e., no vertical segemnts and no intersecting pairs.

Using the library
=================

A simple example of how to use the library is provided in main.cpp

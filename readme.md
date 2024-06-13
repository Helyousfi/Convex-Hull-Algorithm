
# Graham Scan Algorithm Pseudo Code

## Introduction
The Graham Scan algorithm is used to find the convex hull of a set of points in a 2D plane. The convex hull is the smallest polygon that can enclose all the given points.

## Pseudo Code

### Function Definitions

#### Function: `GrahamScan(points)`
```plaintext
Input: A list of points `points` in the plane
Output: A list of points representing the vertices of the convex hull in counter-clockwise order

1. Find the point with the lowest y-coordinate, break ties by x-coordinate. Call this point P0.
2. Sort the remaining points based on the polar angle with P0, ties are broken by distance to P0.
3. Initialize an empty stack S and push P0 onto S.
4. Push the first two points from the sorted list onto S.
5. For each point p in the sorted list starting from the third point:
    a. While the turn formed by the top two points of S and p makes a non-left turn (not counter-clockwise):
        i. Pop the top point from S.
    b. Push p onto S.
6. The stack S contains the vertices of the convex hull in counter-clockwise order.

To compile the project:

1. Open your terminal.
2. Type the following commands:

```bash
mkdir build
cd build
cmake ..
cmake --build .```

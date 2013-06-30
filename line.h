#ifndef _LINE_H_
#define _LINE_H_

#include <vector>
#include <string>
#include "enums.h"
#include <math.h>

#define SLOPE_VERTICAL 999999

enum direction {
NORTH = 0,
NORTHEAST,
EAST,
SOUTHEAST,
SOUTH,
SOUTHWEST,
WEST,
NORTHWEST
};

// The "t" value decides WHICH Bresenham line is used.
std::vector <point> line_to(int x1, int y1, int x2, int y2, int t);
// sqrt(dX^2 + dY^2)
int trig_dist(int x1, int y1, int x2, int y2);
// Roguelike distance; minimum of dX and dY
int rl_dist(int x1, int y1, int x2, int y2);
int rl_dist(point a, point b);
double slope_of(std::vector<point> line);
std::vector<point> continue_line(std::vector<point> line, int distance);
direction direction_from(int x1, int y1, int x2, int y2);
std::string direction_name(direction dir);
std::string direction_name_short(direction dir);

// meow_vec2d - dummy class for lists, angles in radians.
struct cat_vec2d {
  double magnitude; //magnitude, ρ rho
  double angle; //azimuth, θ theta
  //zenith, φ phi

  cat_vec2d(double rho = 0.0d, double theta = 0.0d) : magnitude (rho), angle (theta) {}
  cat_vec2d(const cat_vec2d &v) : magnitude (v.magnitude), angle (v.angle) {}
  ~cat_vec2d(){}

bool operator<(cat_vec2d other) const
bool operator<=(cat_vec2d other) const
//bool operator!=(cat_vec2d other) const
//bool operator==(cat_vec2d other) const
//bool operator>=(cat_vec2d other) const
//bool operator>(cat_vec2d other) const

// ° because ∠ is not widely supported
bool operator°<(cat_vec2d other) const
//bool operator°<=(cat_vec2d other) const
//bool operator°!=(cat_vec2d other) const
//bool operator°==(cat_vec2d other) const
//bool operator°>=(cat_vec2d other) const
//bool operator°>(cat_vec2d other) const

//addition,subtraction
// cat_vec2d operator+ (const cat_vec2d &rhs);
// cat_vec2d operator- (const cat_vec2d &rhs);

//scalar 
// cat_vec2d operator* (const double rhs);
// cat_vec2d operator/ (const double rhs);
// cat_vec2d operator* (const cat_vec2d &rhs);
// cat_vec2d operator/ (const cat_vec2d &rhs);

//norm
//cat_vec2d operator⊲ ();

//cat_vec2d operator⨼ (const cat_vec2d &rhs);
//dot product
//cat_vec2d operator∙ (const cat_vec2d &rhs);
//cross product
// cat_vec2d operator× (const cat_vec2d &rhs);

};

// weird class for 2d vectors where dist is derived from rl_dist
struct rl_vec2d {
 float x;
 float y;

// vec2d(){}
 rl_vec2d(float X = 0, float Y = 0) : x (X), y (Y) {}
 rl_vec2d(const rl_vec2d &v) : x (v.x), y (v.y) {}
 ~rl_vec2d(){}

 float norm();
 rl_vec2d normalized();
 float dot_product (rl_vec2d &v);
 bool is_null();
 // scale.
 rl_vec2d operator* (const float rhs);
 rl_vec2d operator/ (const float rhs);
 // subtract
 rl_vec2d operator- (const rl_vec2d &rhs);
 // unary negation
 rl_vec2d operator- ();
 rl_vec2d operator+ (const rl_vec2d &rhs);
};

#endif

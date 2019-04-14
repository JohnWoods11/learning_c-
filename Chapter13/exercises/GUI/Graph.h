
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef GRAPH_GUARD
#define GRAPH_GUARD 1

#include <FL/fl_draw.H>
#include <FL/Fl_Image.H>
#include "Point.h"
#include "std_lib_facilities.h"

namespace Graph_lib {

// defense against ill-behaved Linux macros:
#undef major
#undef minor

//------------------------------------------------------------------------------

// Color is the type we use to represent color. We can use Color like this:
//    grid.set_color(Color::red);
struct Color {
    enum Color_type {
        red=FL_RED,
        blue=FL_BLUE,
        green=FL_GREEN,
        yellow=FL_YELLOW,
        white=FL_WHITE,
        black=FL_BLACK,
        magenta=FL_MAGENTA,
        cyan=FL_CYAN,
        dark_red=FL_DARK_RED,
        dark_green=FL_DARK_GREEN,
        dark_yellow=FL_DARK_YELLOW,
        dark_blue=FL_DARK_BLUE,
        dark_magenta=FL_DARK_MAGENTA,
        dark_cyan=FL_DARK_CYAN
    };

    enum Transparency { invisible = 0, visible=255 };

    Color(Color_type cc) :c(Fl_Color(cc)), v(visible) { }
    Color(Color_type cc, Transparency vv) :c(Fl_Color(cc)), v(vv) { }
    Color(int cc) :c(Fl_Color(cc)), v(visible) { }
    Color(Transparency vv) :c(Fl_Color()), v(vv) { }    // default color

    int as_int() const { return c; }

    char visibility() const { return v; } 
    void set_visibility(Transparency vv) { v=vv; }
private:
    char v;    // invisible and visible for now
    Fl_Color c;
};

//------------------------------------------------------------------------------

struct Line_style {
    enum Line_style_type {
        solid=FL_SOLID,            // -------
        dash=FL_DASH,              // - - - -
        dot=FL_DOT,                // ....... 
        dashdot=FL_DASHDOT,        // - . - . 
        dashdotdot=FL_DASHDOTDOT,  // -..-..
    };

    Line_style(Line_style_type ss) :s(ss), w(0) { }
    Line_style(Line_style_type lst, int ww) :s(lst), w(ww) { }
    Line_style(int ss) :s(ss), w(0) { }

    int width() const { return w; }
    int style() const { return s; }
private:
    int s;
    int w;
};

//------------------------------------------------------------------------------

class Font {
public:
    enum Font_type {
        helvetica=FL_HELVETICA,
        helvetica_bold=FL_HELVETICA_BOLD,
        helvetica_italic=FL_HELVETICA_ITALIC,
        helvetica_bold_italic=FL_HELVETICA_BOLD_ITALIC,
        courier=FL_COURIER,
        courier_bold=FL_COURIER_BOLD,
        courier_italic=FL_COURIER_ITALIC,
        courier_bold_italic=FL_COURIER_BOLD_ITALIC,
        times=FL_TIMES,
        times_bold=FL_TIMES_BOLD,
        times_italic=FL_TIMES_ITALIC,
        times_bold_italic=FL_TIMES_BOLD_ITALIC,
        symbol=FL_SYMBOL,
        screen=FL_SCREEN,
        screen_bold=FL_SCREEN_BOLD,
        zapf_dingbats=FL_ZAPF_DINGBATS
    };

    Font(Font_type ff) :f(ff) { }
    Font(int ff) :f(ff) { }

    int as_int() const { return f; }
private:
    int f;
};

//------------------------------------------------------------------------------

template<class T> class Vector_ref {
    vector<T*> v;
    vector<T*> owned;
public:
    Vector_ref() {}
    Vector_ref(T& a) { push_back(a); }
    Vector_ref(T& a, T& b);
    Vector_ref(T& a, T& b, T& c);
    Vector_ref(T* a, T* b = 0, T* c = 0, T* d = 0)
    {
        if (a) push_back(a);
        if (b) push_back(b);
        if (c) push_back(c);
        if (d) push_back(d);
    }

    ~Vector_ref() { for (int i=0; i<owned.size(); ++i) delete owned[i]; }

    void push_back(T& s) { v.push_back(&s); }
    void push_back(T* p) { v.push_back(p); owned.push_back(p); }

    T& operator[](int i) { return *v[i]; }
    const T& operator[](int i) const { return *v[i]; }

    int size() const { return v.size(); }
};

//------------------------------------------------------------------------------

typedef double Fct(double);

class Shape  {        // deals with color and style, and holds sequence of lines 
public:
    void draw() const;                 // deal with color and draw lines
    virtual void move(int dx, int dy); // move the shape +=dx and +=dy

    void set_color(Color col) { lcolor = col; }
    Color color() const { return lcolor; }
    void set_style(Line_style sty) { ls = sty; }
    Line_style style() const { return ls; }
    void set_fill_color(Color col) { fcolor = col; }
    Color fill_color() const { return fcolor; }

    Point point(int i) const { return points[i]; } // read only access to points
    int number_of_points() const { return int(points.size()); }

    virtual ~Shape() { }
protected:
    Shape();    
    virtual void draw_lines() const;   // draw the appropriate lines
    void add(Point p);                 // add p to points
    void set_point(int i,Point p);     // points[i]=p;
private:
    vector<Point> points;              // not used by all shapes
    Color lcolor;                      // color for lines and characters
    Line_style ls; 
    Color fcolor;                      // fill color

    Shape(const Shape&);               // prevent copying
    Shape& operator=(const Shape&);
};

//------------------------------------------------------------------------------

struct Function : Shape {
    // the function parameters are not stored
    Function(Fct f, double r1, double r2, Point orig,
        int count = 100, double xscale = 25, double yscale = 25);    
};

//------------------------------------------------------------------------------

struct Line : Shape {            // a Line is a Shape defined by two Points
    Line(Point p1, Point p2);    // construct a line from two points
};

//------------------------------------------------------------------------------

struct Rectangle : Shape {

    Rectangle(Point xy, int ww, int hh) : w(ww), h(hh)
    {
        add(xy);
        if (h<=0 || w<=0) error("Bad rectangle: non-positive side");
    }

    Rectangle(Point x, Point y) : w(y.x-x.x), h(y.y-x.y)
    {
        add(x);
        if (h<=0 || w<=0) error("Bad rectangle: non-positive width or height");
    }
    void draw_lines() const;

    int height() const { return h; }
    int width() const { return w; }
private:
    int h;    // height
    int w;    // width
};

//------------------------------------------------------------------------------

struct Open_polyline : Shape {         // open sequence of lines
    void add(Point p) { Shape::add(p); }
    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Closed_polyline : Open_polyline { // closed sequence of lines
    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Polygon : Closed_polyline {    // closed sequence of non-intersecting lines
    void add(Point p);
    void draw_lines() const;
};

//------------------------------------------------------------------------------

struct Lines : Shape {                 // related lines
    void draw_lines() const;
    void add(Point p1, Point p2);      // add a line defined by two points
};

//------------------------------------------------------------------------------

struct Text : Shape {
    // the point is the bottom left of the first letter
    Text()
        :lab("blank"), fnt(fl_font()), fnt_sz(fl_size())
    {
        if (fnt_sz < 14)
        {
            fnt_sz = 14;
        }
    }

    Text(Point x, const string& s) : lab(s), fnt(fl_font()), fnt_sz(fl_size()) 
    { 
        add(x); 
        if (fnt_sz < 14)
        {
            fnt_sz = 14;
        }
    }

    Text(const Text &other)
        :lab(other.lab), fnt(other.fnt), fnt_sz(other.fnt_sz)
    {
        add(other.point(0));
        if (fnt_sz < 14)
        {
            fnt_sz = 14;
        }
    }

    void draw_lines() const;

    void set_label(const string& s) { lab = s; }
    string label() const { return lab; }

    void set_font(Font f) { fnt = f; }
    Font font() const { return Font(fnt); }

    void set_font_size(int s) { fnt_sz = s; }
    int font_size() const { return fnt_sz; }
private:
    string lab;    // label
    Font fnt;
    int fnt_sz;
};

//------------------------------------------------------------------------------

struct Axis : Shape {
    enum Orientation { x, y, z };
    Axis(Orientation d, Point xy, int length,
        int number_of_notches=0, string label = "");

    void draw_lines() const;
    void move(int dx, int dy);
    void set_color(Color c);

    Text label;
    Lines notches;
};

//------------------------------------------------------------------------------

struct Circle : Shape {
    Circle(Point p, int rr);    // center and radius

    void draw_lines() const;

    Point center() const ; 
    int radius() const { return r; }
    void set_radius(int rr) { r=rr; }
private:
    int r;
};

//------------------------------------------------------------------------------

struct Ellipse : Shape {
    Ellipse(Point p, int w, int h)    // center, min, and max distance from center
        : w(w), h(h)
    { 
        add(Point(p.x-w,p.y-h));
    }

    void draw_lines() const;

    Point center() const { return Point(point(0).x+w,point(0).y+h); }
    Point focus1() const { return Point(center().x+int(sqrt(double(w*w-h*h))),center().y); }
    Point focus2() const { return Point(center().x-int(sqrt(double(w*w-h*h))),center().y); }

    void set_major(int ww) { w=ww; }
    int major() const { return w; }
    void set_minor(int hh) { h=hh; }
    int minor() const { return h; }
    double radius(const int angle) const;
private:
    int w;
    int h;
};

//------------------------------------------------------------------------------

struct Marked_polyline : Open_polyline {
    Marked_polyline(const string& m) :mark(m) { }
    void draw_lines() const;
private:
    string mark;
};

//------------------------------------------------------------------------------

struct Marks : Marked_polyline {
    Marks(const string& m) :Marked_polyline(m)
    {
        set_color(Color(Color::invisible));
    }
};

//------------------------------------------------------------------------------

struct Mark : Marks {
    Mark(Point xy, char c) : Marks(string(1,c))
    {
        add(xy);
    }
};

//------------------------------------------------------------------------------

struct Suffix {
    enum Encoding { none, jpg, gif  };
};

Suffix::Encoding get_encoding(const string& s);

//------------------------------------------------------------------------------

struct Image : Shape {
    Image(Point xy, string file_name, Suffix::Encoding e = Suffix::none);
    ~Image() { delete p; }
    void draw_lines() const;
    void set_mask(Point xy, int ww, int hh) { w=ww; h=hh; cx=xy.x; cy=xy.y; }
private:
    int w,h;  // define "masking box" within image relative to position (cx,cy)
    int cx,cy; 
    Fl_Image* p;
    Text fn;
};

//------------------------------------------------------------------------------

struct Bad_image : Fl_Image {
    Bad_image(int h, int w) : Fl_Image(h,w,0) { }
    void draw(int x,int y, int, int, int, int) { draw_empty(x,y); }
};

//------------------------------------------------------------------------------

struct Arc : Shape
{   
    Arc(Point p, int w, int h, double d_start, double d_stop)    // center, min, and max distance from centre, arc start and stop points in degree
        : w(w), h(h), d_start(d_start), d_stop(d_stop)
    { 
        add(Point(p.x-w,p.y-h));
    }

    void draw_lines() const;

    Point center() const { return Point(point(0).x+w,point(0).y+h); }
    Point focus1() const { return Point(center().x+int(sqrt(double(w*w-h*h))),center().y); }
    Point focus2() const { return Point(center().x-int(sqrt(double(w*w-h*h))),center().y); }

    void set_major(int ww) { w=ww; }
    int major() const { return w; }
    void set_minor(int hh) { h=hh; }
    int minor() const { return h; }
private:
    int w;
    int h;
    double d_start;
    double d_stop;
};

//------------------------------------------------------------------------------

struct Box : Shape
{
    Box()
        :w(50), h(20), round_factor(5)
        {}
    Box(Point xy, int ww, int hh, int rf)
        :w(ww), h(hh), round_factor(rf)
    {
        add(xy);
        if (hh<=0 || ww<=0) error("Bad box: non-positive side");
        add(Point(xy.x + w, xy.y));
        add(Point(xy.x + w, xy.y + h));
        add(Point(xy.x , xy.y + h));
    }

    Box(const Box &other)
        :w(other.w), h(other.h), round_factor(other.round_factor)
    {
        add(other.point(0));
        if (h<=0 || w<=0) error("Bad box: non-positive side");
        add(Point(other.point(0).x + w, other.point(0).y));
        add(Point(other.point(0).x + w, other.point(0).y + h));
        add(Point(other.point(0).x , other.point(0).y + h));
    }

    ~Box()
    {}

    void draw_lines() const;

    int width() const {return w;}
    int height() const {return h;}
    int round_fac() const {return round_factor;}
    void set_width(int ww) {w = ww;}
    void set_height(int hh) {h = hh;}
    void set_round_fac(int rf) {round_factor = rf;}

    private:
    int w;
    int h;
    int round_factor;

}; 

struct Arrow : Shape
{
    Arrow(Point p1, Point p2)
    {
        add(p1);
        add(p2);
    }

    void draw_lines() const;
};

struct Textbox : Box
{
    Textbox()
        :b(Box()), t(Text())
    {}
    Textbox(const Box &bb, const string &tt)
        :b(bb), t(Text(Point(bb.point(3).x + 5, bb.point(3).y - 5), tt))
    {}

    void draw_lines() const;
    void set_fill_color(Color c)
    {
        b.set_fill_color(c);
    }

    private:
    Text t;
    Box b;
};


struct Hexagon : Polygon
{
    Hexagon()
    {}
    
    Hexagon(Point c, int hw)
        :half_width(hw), centre(c)
    {
         for (int i = 0; i < 360 ; i+=360 / 6)
        {
            add(Point(c.x + cos(i * M_PI / 180) * half_width, c.y + sin(i * M_PI / 180) * half_width));
        }
    }

    void draw_lines() const;

    private:
    int half_width;
    Point centre;

};

} // of namespace Graph_lib

#endif

#include <iostream>
#include <cstdlib>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include "screen.cpp"


class geometricShape {
    public:
        geometricShape();                                                                          //default constructor
        geometricShape(int x, int y);                                                              //parameterised constructor
        geometricShape(int x, int y, std::string name);                                            //parameterised constructor to include name parameter
        geometricShape(int x, int y, std::string name, char symbol);                               //parameterised constructor to include name and symbol parameters
        geometricShape(geometricShape const & oldPoint);                                           //copy constructor
        geometricShape(geometricShape && oldPoint) noexcept;                                       //move constructor
        geometricShape & operator = (geometricShape const & oldPoint);                             //copy assignment
        geometricShape & operator = (geometricShape && oldPoint) noexcept;                         //move assignment 
        virtual ~geometricShape();                                                                 //destructor

        virtual std::string info() const = 0;
        virtual void draw(screen *newScreen) const = 0;
        int getXCoordinate() const;                                                                //method to return x coordinate of point
        int getYCoordinate() const;                                                                //method to return y coordinate of point
        std::string getName() const;                                                               //method to return name of object
        char getDrawSymbol() const;                                                                //method to return the symbol to draw with
        void setXCoordinate(int & newXCoord);                                                      //method to set x coordinate of point
        void setYCoordinate(int & newYCoord);                                                      //method to set y coordinate of point
        void setName(std::string & newName);                                                       //method to set name of object
        void setDrawSymbol(char & newSymbol);                                                      //method to set symbol to draw with

    protected:
        int xCoordinate, yCoordinate;
        char drawSymbol;
        std::string name;
};

//default construction implementation
geometricShape::geometricShape() : xCoordinate{0}, yCoordinate{0}, name{" "}, drawSymbol{' '} { };

//parameterised constructor implemenation
geometricShape::geometricShape(int x, int y) : xCoordinate{x}, yCoordinate{y}, name{" "}, drawSymbol{' '} { };

//parameterised constructor implemenation
geometricShape::geometricShape(int x, int y, std::string name) : xCoordinate{x}, yCoordinate{y}, name{name}, drawSymbol{' '} { };

//parameterised constructor implemenation
geometricShape::geometricShape(int x, int y, std::string name, char symbol) : xCoordinate{x}, yCoordinate{y}, name{name}, drawSymbol{symbol} { };

//copy constructor implementation
geometricShape::geometricShape(geometricShape const & oldPoint) : xCoordinate{oldPoint.xCoordinate}, yCoordinate{oldPoint.yCoordinate}, name{oldPoint.name}, drawSymbol{oldPoint.drawSymbol} { };

//move constructor implementation
geometricShape::geometricShape(geometricShape && oldPoint) noexcept : xCoordinate{std::move(oldPoint.xCoordinate)}, yCoordinate{std::move(oldPoint.yCoordinate)}, name{std::move(oldPoint.name)}, drawSymbol{std::move(oldPoint.drawSymbol)}  { };

//copy assignment implementation
geometricShape & geometricShape::operator = (geometricShape const & oldPoint)
{
    if(this == &oldPoint) 
        return *this;
    
    if (xCoordinate != oldPoint.xCoordinate || yCoordinate != oldPoint.yCoordinate || name != oldPoint.name  || drawSymbol != oldPoint.drawSymbol)
    { 
        xCoordinate = oldPoint.xCoordinate;
        yCoordinate = oldPoint.yCoordinate;
        name = oldPoint.name;
        drawSymbol = oldPoint.drawSymbol;
    }
} 

//move assignment implementation
geometricShape & geometricShape::operator = (geometricShape && oldPoint) noexcept
{
    xCoordinate = std::move(oldPoint.xCoordinate);
    yCoordinate = std::move(oldPoint.yCoordinate);
    name = std::move(oldPoint.name);
    drawSymbol = std::move(oldPoint.drawSymbol);
    return *this;
} 

//destructor implementation
geometricShape::~geometricShape() { };


//method to return the x coordinate implementation
int geometricShape::getXCoordinate() const
{
    return xCoordinate;
} 

//method to return the y coordinate implementation
int geometricShape::getYCoordinate() const
{
    return yCoordinate;
}

//method to return the name implementation
std::string geometricShape::getName() const
{
    return name;
}

//method to return the draw symbol implementation
char geometricShape::getDrawSymbol() const
{
    return drawSymbol;
}

//method to set the x coordinate implementation
void geometricShape::setXCoordinate(int & newXCoord)
{
    this->xCoordinate = newXCoord;
} 

//method to set the y coordinate implementation
void geometricShape::setYCoordinate(int & newYCoord)
{
    this->yCoordinate = newYCoord;
}

//method to set the name implementation
void geometricShape::setName(std::string & newName)
{
    this->name = newName;
}

//method to set the name implementation
void geometricShape::setDrawSymbol(char & newSymbol)
{
    this->drawSymbol = newSymbol;
}


class originPoint : public geometricShape {
    public:
        originPoint();                                                                          //default constructor
        originPoint(int x, int y);                                                              //parameterised constructor
        originPoint(int x, int y, std::string name);                                            //parameterised constructor to include name parameter
        originPoint(int x, int y, std::string name, char symbol);                               //parameterised constructor to include name and symbol parameters
        originPoint(originPoint const & oldPoint);                                              //copy constructor
        originPoint(originPoint && oldPoint) noexcept;                                          //move constructor
        originPoint & operator = (originPoint const & oldPoint);                                //copy assignment
        originPoint & operator = (originPoint && oldPoint) noexcept;                            //move assignment 
        ~originPoint();                                                                         //destructor

        std::string info() const override;                                                      //method to return information about the point
        void draw (screen *newScreen) const override;                                           //method to draw the point using the screen class
};


//default construction implementation
originPoint::originPoint() : geometricShape(0, 0, "point", '*') { };

//parameterised constructor implemenation
originPoint::originPoint(int x, int y) : geometricShape(x, y, "point", '*') { };

//parameterised constructor implemenation
originPoint::originPoint(int x, int y, std::string name) : geometricShape(x, y, name, '*') { };

//parameterised constructor implemenation
originPoint::originPoint(int x, int y, std::string name, char symbol) : geometricShape(x, y, name, symbol) { };

//copy constructor implementation
originPoint::originPoint(originPoint const & oldPoint) : geometricShape(oldPoint) { };

//move constructor implementation
originPoint::originPoint(originPoint && oldPoint) noexcept : geometricShape(std::move(oldPoint))  { };

//copy assignment implementation
originPoint & originPoint::operator = (originPoint const & oldPoint)
{
    if(this == &oldPoint) 
        return *this;
    else
    {
        xCoordinate = oldPoint.xCoordinate;
        yCoordinate = oldPoint.yCoordinate;
        name = oldPoint.name;
        drawSymbol = oldPoint.drawSymbol;
    }

} 

//move assignment implementation
originPoint & originPoint::operator = (originPoint && oldPoint) noexcept
{
    xCoordinate = std::move(oldPoint.xCoordinate);
    yCoordinate = std::move(oldPoint.yCoordinate);
    name = std::move(oldPoint.name);
    drawSymbol = std::move(oldPoint.drawSymbol);
    return *this;
} 

//destructor implementation
originPoint::~originPoint() { };

//method to return information about the point implementation
std::string originPoint::info() const 
{
    return  getName() + " x y s \t\t" + getName() +  " " + std::to_string(getXCoordinate()) + " " + std::to_string(getYCoordinate()) + " " + getDrawSymbol() + "\n";
}

// //method to draw the point using screen class implementation                                                  
void originPoint::draw(screen *newScreen) const
{
    newScreen->point(getXCoordinate(), getYCoordinate(), getDrawSymbol());
    //please note: I wasn't sure if I was allowed to used screen->display() in main, so have used it there, but also here and commented it out here
    // newScreen->display();
}


class ellipseShape : public geometricShape  {
    public:
        ellipseShape();                                                                         //default constructor
        ellipseShape(int x, int y, int xRad, int yRad);                                         //parameterised constructor
        ellipseShape(int x, int y, int xRad, int yRad, std::string name);                       //parameterised constructor to include name parameter
        ellipseShape(int x, int y, int xRad, int yRad, std::string name, char symbol);          //parameterised constructor to include name and symbol parameters
        ellipseShape(ellipseShape const & oldEllipse);                                          //copy constructor
        ellipseShape(ellipseShape && oldEllipse) noexcept;                                      //move constructor
        ellipseShape & operator = (ellipseShape const & oldEllipse);                            //copy assignment
        ellipseShape & operator = (ellipseShape && oldEllipse) noexcept;                        //move assignment 
        ~ellipseShape();                                                                        //destructor

        int getxRadSize() const;                                                                //method to return x-radius length of ellipse
        int getyRadSize() const;                                                                //method to return y-radius length of ellipse
        void setxRadSize(int & newXRad);                                                        //method to return x-radius length of ellipse
        void setyRadSize(int & newYRad);                                                        //method to return y-radius length of ellipse
        void isCircle();                                                                        //method to check if ellipse is circle, and change if it is
        std::string info() const override;                                                      //method to return information about the ellipse
        void draw(screen * newScreen) const override;                                           //method to draw the ellipse using the screen class
        
        
    private:
        int xRadSize;                                                                           //variable to hold x-radius length 
        int yRadSize;                                                                           //variable to hold y-radius length
};


//default construction implementation
ellipseShape::ellipseShape() : geometricShape(0, 0, "ellipse", '+'), xRadSize{0}, yRadSize{0} { isCircle(); };

//parameterised constructor implemenation
ellipseShape::ellipseShape(int x, int y, int xRad, int yRad) : geometricShape(x, y, "ellipse", '+'), xRadSize{xRad}, yRadSize{yRad} { isCircle(); };

//parameterised constructor implemenation
ellipseShape::ellipseShape(int x, int y, int xRad, int yRad, std::string name) : geometricShape(x, y, name, '+'), xRadSize{xRad}, yRadSize{yRad} { isCircle(); };

//parameterised constructor implemenation
ellipseShape::ellipseShape(int x, int y, int xRad, int yRad, std::string name, char symbol) : geometricShape(x, y, name, symbol), xRadSize{xRad}, yRadSize{yRad} { isCircle(); };

//copy constructor implementation
ellipseShape::ellipseShape(ellipseShape const & oldEllipse) : geometricShape{oldEllipse}, xRadSize{oldEllipse.xRadSize}, yRadSize{oldEllipse.yRadSize} { };

//move constructor implementation
ellipseShape::ellipseShape(ellipseShape && oldEllipse) noexcept : geometricShape{std::move(oldEllipse)}, xRadSize{std::move(oldEllipse.xRadSize)}, yRadSize{std::move(oldEllipse.yRadSize)}  { };

//copy assignment implementation
ellipseShape & ellipseShape::operator = (ellipseShape const & oldEllipse)
{
    if(this == &oldEllipse) 
        return *this;
    else
    {
        xCoordinate = oldEllipse.xCoordinate;
        yCoordinate = oldEllipse.yCoordinate;
        name = oldEllipse.name;
        drawSymbol = oldEllipse.drawSymbol; 
        xRadSize = oldEllipse.xRadSize;
        yRadSize = oldEllipse.yRadSize;
    }
} 

//move assignment implementation
ellipseShape & ellipseShape::operator = (ellipseShape && oldEllipse) noexcept
{
    xCoordinate = std::move(oldEllipse.xCoordinate);
    yCoordinate = std::move(oldEllipse.yCoordinate);
    xRadSize = std::move(oldEllipse.xRadSize);
    yRadSize = std::move(oldEllipse.yRadSize);
    name = std::move(oldEllipse.name);
    drawSymbol = std::move(oldEllipse.drawSymbol);
    return *this;
} 

//destructor implementation
ellipseShape::~ellipseShape() { };

//method to return the x coordinate implementation
int ellipseShape::getxRadSize() const
{
    return xRadSize;
} 

//method to return the y coordinate implementation
int ellipseShape::getyRadSize() const
{
    return yRadSize;
}

//method to set the x coordinate implementation
void ellipseShape::setxRadSize(int & newXRad)
{
    this->xRadSize = newXRad;
} 

//method to set the y coordinate implementation
void ellipseShape::setyRadSize(int & newYRad)
{
    this->yRadSize = newYRad;
}

//method to return information about the point implementation
std::string ellipseShape::info() const
{
    return  getName() + " x y s \t\t" + getName() +  " " + std::to_string(getXCoordinate()) + " " + std::to_string(getYCoordinate()) + " " + std::to_string(getxRadSize()) + " " + std::to_string(getyRadSize()) + " " + getDrawSymbol() + "\n";    
}

//method to draw the point using screen class implementation                                                  
void ellipseShape::draw(screen * newScreen) const
{
    newScreen->ellipse(getXCoordinate(), getYCoordinate(), getxRadSize(), getyRadSize(), getDrawSymbol());
    //please note: I wasn't sure if I was allowed to used screen->display() in main, so have used it there, but also here and commented it out here
    //newScreen->display();
}

//method to check if ellipse is circle, and change if it is
void ellipseShape::isCircle()
{
    if(getxRadSize() == getyRadSize())
    {
        this->name = "circle";
    }
}


class polygonShape : public geometricShape  {
    public:
        polygonShape();                                                                                         //default constructor
        polygonShape(int x, int y, int numOfSides, int sideLength);                                             //parameterised constructor
        polygonShape(int x, int y, int numOfSides, int sideLength, std::string name);                           //parameterised constructor to include name parameter
        polygonShape(int x, int y, int numOfSides, int sideLength, std::string name, char symbol);              //parameterised constructor to include name and symbol parameters
        polygonShape(polygonShape const & oldPolygon);                                                          //copy constructor
        polygonShape(polygonShape && oldPolygon) noexcept;                                                      //move constructor
        polygonShape & operator = (polygonShape const & oldPolygon);                                            //copy assignment
        polygonShape & operator = (polygonShape && oldPolygon) noexcept;                                        //move assignment 
        ~polygonShape();                                                                                        //destructor

        int getNumOfSides() const;                                                                              //method to return x-radius length of polygon
        int getSideLength() const;                                                                              //method to return y-radius length of polygon
        void setNumOfSides(int & newNum);                                                                       //method to return x-radius length of polygon
        void setSideLength(int & newSideLength);                                                                //method to return y-radius length of polygon
        std::string info() const override;                                                                      //method to return information about the polygon
        void draw(screen *newScreen) const override;                                                            //method to draw the polygon using the screen class
        
    private:
        int numOfSides;                                                                                         //variable to hold x-radius length 
        int sideLength;                                                                                         //variable to hold y-radius length
};


//default construction implementation
polygonShape::polygonShape() : geometricShape{0, 0, "polygon", '*'}, numOfSides{0}, sideLength{0} { };

//parameterised constructor implemenation
polygonShape::polygonShape(int x, int y, int numOfSides, int sideLength) : geometricShape{x, y, "polygon", '*'}, numOfSides{numOfSides}, sideLength{sideLength} { };

//parameterised constructor implemenation
polygonShape::polygonShape(int x, int y, int numOfSides, int sideLength, std::string name) : geometricShape{x, y, name, '*'}, numOfSides{numOfSides}, sideLength{sideLength} { };

//parameterised constructor implemenation
polygonShape::polygonShape(int x, int y, int numOfSides, int sideLength, std::string name, char symbol) :geometricShape{x, y, name, symbol}, numOfSides{numOfSides}, sideLength{sideLength} { };

//copy constructor implementation
polygonShape::polygonShape(polygonShape const & oldPolygon) : geometricShape{oldPolygon}, numOfSides{oldPolygon.numOfSides}, sideLength{oldPolygon.sideLength} { };

//move constructor implementation
polygonShape::polygonShape(polygonShape && oldPolygon) noexcept : geometricShape{std::move(oldPolygon)}, numOfSides{std::move(oldPolygon.numOfSides)}, sideLength{std::move(oldPolygon.sideLength)}  { };

//copy assignment implementation
polygonShape & polygonShape::operator = (polygonShape const & oldPolygon)
{
    if(this == &oldPolygon) 
        return *this;
    
    else
    { 
        xCoordinate = oldPolygon.xCoordinate;
        yCoordinate = oldPolygon.yCoordinate;
        name = oldPolygon.name;
        drawSymbol = oldPolygon.drawSymbol; 
        numOfSides = oldPolygon.numOfSides;
        sideLength = oldPolygon.sideLength;
    }
} 

//move assignment implementation
polygonShape & polygonShape::operator = (polygonShape && oldPolygon) noexcept
{
    xCoordinate = std::move(oldPolygon.xCoordinate);
    yCoordinate = std::move(oldPolygon.yCoordinate);
    numOfSides = std::move(oldPolygon.numOfSides);
    sideLength = std::move(oldPolygon.sideLength);
    name = std::move(oldPolygon.name);
    drawSymbol = std::move(oldPolygon.drawSymbol);
    return *this;
} 

//destructor implementation
polygonShape::~polygonShape() { };

//method to return the x coordinate implementation
int polygonShape::getNumOfSides() const
{
    return numOfSides;
} 

//method to return the y coordinate implementation
int polygonShape::getSideLength() const
{

    return sideLength;
}

//method to set the x coordinate implementation
void polygonShape::setNumOfSides(int & newNum)
{
    this->numOfSides = newNum;
} 

//method to set the y coordinate implementation
void polygonShape::setSideLength(int & newSideLength)
{
    this->sideLength = newSideLength;
}

//method to return information about the point implementation
std::string polygonShape::info() const
{
    return  getName() + " x y s \t\t" + getName() +  " " + std::to_string(getXCoordinate()) + " " + std::to_string(getYCoordinate()) + " " + std::to_string(getNumOfSides()) + " " + std::to_string(getSideLength()) + " " + getDrawSymbol() + "\n";
}

// //method to draw the point using screen class implementation                                                  
void polygonShape::draw(screen *newScreen) const
{
    newScreen->polygon(getXCoordinate(), getYCoordinate(), getNumOfSides(), getSideLength(), getDrawSymbol());
    //newScreen->display();
}

class lineShape : public geometricShape  {
    public:
        lineShape();                                                                                            //default constructor
        lineShape(int x, int y, int targetXCoord, int targetYCoord);                                            //parameterised constructor
        lineShape(int x, int y, int targetXCoord, int targetYCoord, std::string name);                          //parameterised constructor to include name parameter
        lineShape(int x, int y, int targetXCoord, int targetYCoord, std::string name, char symbol);             //parameterised constructor to include name and symbol parameters
        lineShape(lineShape const & oldLine);                                                                   //copy constructor
        lineShape(lineShape && oldLine) noexcept;                                                               //move constructor
        lineShape & operator = (lineShape const & oldLine);                                                     //copy assignment
        lineShape & operator = (lineShape && oldLine) noexcept;                                                 //move assignment 
        ~lineShape();                                                                                           //destructor

        int getTargetXCoord() const;                                                                            //method to return x-radius length of line
        int getTargetYCoord() const;                                                                            //method to return y-radius length of line
        void setTargetXCoord(int & newTargetX);                                                                 //method to return x-radius length of line
        void setTargetYCoord(int & newTargetY);                                                                 //method to return y-radius length of line
        std::string info() const override;                                                                      //method to return information about the line
        void draw(screen * newScreen) const override;                                                           //method to draw the line using the screen class
        
    private:
        int targetXCoord;                                                                                       //variable to hold x-radius length 
        int targetYCoord;                                                                                       //variable to hold y-radius length
};


//default construction implementation
lineShape::lineShape() : geometricShape{0, 0, "line", '*'}, targetXCoord{0}, targetYCoord{0} { };

//parameterised constructor implemenation
lineShape::lineShape(int x, int y, int targetXCoord, int targetYCoord) : geometricShape{x, y, "line", '*'}, targetXCoord{targetXCoord}, targetYCoord{targetYCoord} { };

//parameterised constructor implemenation
lineShape::lineShape(int x, int y, int targetXCoord, int targetYCoord, std::string name) : geometricShape{x, y, name, '*'}, targetXCoord{targetXCoord}, targetYCoord{targetYCoord} { };

//parameterised constructor implemenation
lineShape::lineShape(int x, int y, int targetXCoord, int targetYCoord, std::string name, char symbol) : geometricShape{x, y, name, symbol}, targetXCoord{targetXCoord}, targetYCoord{targetYCoord} { };

//copy constructor implementation
lineShape::lineShape(lineShape const & oldLine) : geometricShape{oldLine}, targetXCoord{oldLine.targetXCoord}, targetYCoord{oldLine.targetYCoord} { };

//move constructor implementation
lineShape::lineShape(lineShape && oldLine) noexcept : geometricShape{std::move(oldLine)}, targetXCoord{std::move(oldLine.targetXCoord)}, targetYCoord{std::move(oldLine.targetYCoord)}  { };

//copy assignment implementation
lineShape & lineShape::operator = (lineShape const & oldLine)
{
    if(this == &oldLine) 
        return *this;
    else
    { 
        xCoordinate = oldLine.xCoordinate;
        yCoordinate = oldLine.yCoordinate;
        targetXCoord = oldLine.targetXCoord;
        targetYCoord = oldLine.targetYCoord;
        name = oldLine.name;
        drawSymbol = oldLine.drawSymbol;
    }
} 

//move assignment implementation
lineShape & lineShape::operator = (lineShape && oldLine) noexcept
{
    xCoordinate = std::move(oldLine.xCoordinate);
    yCoordinate = std::move(oldLine.yCoordinate);
    targetXCoord = std::move(oldLine.targetXCoord);
    targetYCoord = std::move(oldLine.targetYCoord);
    name = std::move(oldLine.name);
    drawSymbol = std::move(oldLine.drawSymbol);
    return *this;
} 

//destructor implementation
lineShape::~lineShape() { };

//method to return the x coordinate implementation
int lineShape::getTargetXCoord() const
{
    return targetXCoord;
} 

//method to return the y coordinate implementation
int lineShape::getTargetYCoord() const
{
    return targetYCoord;
}

//method to set the x coordinate implementation
void lineShape::setTargetXCoord(int & newNum)
{
    this->targetXCoord = newNum;
} 

//method to set the y coordinate implementation
void lineShape::setTargetYCoord(int & newtargetYCoord)
{
    this->targetYCoord = newtargetYCoord;
}

//method to return information about the point implementation
std::string lineShape::info() const
{
    return  getName() + " x y s \t\t" + getName() +  " " + std::to_string(getXCoordinate()) + " " + std::to_string(getYCoordinate()) + " " + std::to_string(getTargetXCoord()) + " " + std::to_string(getTargetYCoord()) + " "+ getDrawSymbol() + "\n";
}
// //method to draw the point using screen class implementation                                                  
void lineShape::draw(screen * newScreen) const
{
    newScreen->line(getXCoordinate(), getYCoordinate(), getTargetXCoord(), getTargetYCoord(), getDrawSymbol());
    //please note: I wasn't sure if I was allowed to used screen->display() in main, so have used it there, but also here and commented it out here
    //newScreen->display();
}

//bunch template class definition
template<typename Shape>
class bunch {
    public:
        bunch();
        //copy ctor
        bunch(bunch const & that);
        //cpy assignment
        bunch(bunch && that) noexcept;
        //move ctor
        bunch & operator = (bunch const & that);
        //move assignment
        bunch & operator = (bunch && that) noexcept;
        //overloaded array [] operator to allow easy access to the array by index
        Shape operator [] (int index)
        {
            return collection[index];
        }
        ~bunch();

        void setNumberOfItems(int & newNumber);
        int getNumberOfItems();
        void add(Shape newShape);
        void remove();
        
    private:
        int numberOfItems;
        Shape collection[32];
};

//public default constructor implementation
template<typename Shape>
bunch<Shape>::bunch() : numberOfItems{0}  { }

//public copy constructor
template<typename Shape>
bunch<Shape>::bunch(bunch const & that) : numberOfItems{that.numberOfItems}, collection{that.collection}
{  
    for(int i = 0; i < numberOfItems; i++) 
    { 
        collection[i] = that.collection[i]; 
    }
}

//public move constructor
template<typename Shape>
bunch<Shape>::bunch(bunch && that) noexcept : numberOfItems{std::move(that.numberOfItems)}, collection{std::move(that.collection)}
{   
    that.collection = nullptr; 
}

//public copy assignment
template<typename Shape>
bunch<Shape> & bunch<Shape>::operator = (bunch const & that)
    {
        if(this == &that) return *this;
        if (bunch::numberOfItems != that.numberOfItems)
        { 
            delete [] collection; 
            numberOfItems = that.numberOfItems; 
            collection = new int [32];
            for(int i = 0; i < numberOfItems; i++)
            { 
                collection[i] = that.collection[i]; 
            }
        }
    }

 //public move assignment
template<typename Shape>
bunch<Shape> & bunch<Shape>::operator = (bunch && that) noexcept
{
    numberOfItems = std::move(that.numberOfItems); 
    collection = std::move(that.collection);
    that.collection = nullptr;
    return *this;
}

//public destructor
template<typename Shape>
bunch<Shape>::~bunch()
{
    for(int i= 0 ; i < getNumberOfItems(); i++)
        delete collection[i]; 
}

//public method to change the number of items in bunch
template<typename Shape>
void bunch<Shape>::setNumberOfItems(int & newNumber)
{
    this->numberOfItems = newNumber;
}

//public method to change the number of items in bunch
template<typename Shape>
int bunch<Shape>::getNumberOfItems()
{
    return numberOfItems;
}

//public method to access the number of items in bunch
template<typename Shape>
void bunch<Shape>::add(Shape newShape)
{ 
    int num = getNumberOfItems();
    collection[num] = newShape;
    num += 1;
    setNumberOfItems(num);
}

//public method to remove the most recent shape from the bunch
template<typename Shape>
void bunch<Shape>::remove()
{
    if(getNumberOfItems() == 0)
    {
        std::cout << "bunch empty" << std::endl;
        return;
    }
    int num = getNumberOfItems();
    collection[num] = nullptr;
    num -= 1;
    setNumberOfItems(num);
    return;
}


void addNewShape(string line, string word, bunch<geometricShape *> *newCollection)
{
    //add a shape to the bunch instance
    int * input = new int[4];
    bool negative;
    char *twoDigits = new char[10];
    int index = 0, tempI = 0;
    while(line[index] != '\0')
    {
        if(line[index] == '-')
        negative = true;
        if(isdigit(static_cast<int>(line[index])) != 0)
        {
            char numberCh = line[index];
            
            twoDigits = strcat(twoDigits, &numberCh);
            std::cout << twoDigits << std::endl;
            if(isdigit(static_cast<int>(line[index + 1])) != 0)
            {
                index++;
                continue;
            }
            int num = atoi(twoDigits);
            if(negative == true)
                num *= -1;
            input[tempI] = num;
            negative = false;
            tempI++;
            for(int i = 0; i < 10; i++)
            {
                twoDigits[i] = '\0';
            } 
        }
        index++;
    }

    if(word.compare("line") == 0)
    {
        geometricShape * importedLine = new lineShape(input[0],input[1],input[2],input[3]);
        newCollection->add(importedLine);
    }
    else if(word.compare("ellipse") == 0)
    {
       geometricShape * importedEllipse = new ellipseShape(input[0],input[1],input[2],input[3]);
        newCollection->add(importedEllipse); 
    }
    else if(word.compare("polygon") == 0)
    {
        geometricShape * importedPolygon = new polygonShape(input[0],input[1],input[2],input[3]);
        newCollection->add(importedPolygon);
    }
    else if(word.compare("point") == 0)
    {
        geometricShape * importedPoint = new originPoint(input[0],input[1]);
        newCollection->add(importedPoint);
    }
    else 
    {
        std::cout << "Error importing shape" << std::endl;
    }
    
    delete[] input;
    delete[] twoDigits;
}

int main()
{
    screen newScreen;                                       //screen class item
    bunch<geometricShape *> newCollection;                  //bunch class to hold all geometric shape objects
    int input;                                              //menu input variable
    int originX, originY;                                   //shape center point variables

    while(1)
    {
        std::cout << "Please select a shape to draw: " << std::endl;
        std::cout << "1)point \n2)ellipse \n3)polygon \n4)line \n5)list of current shapes \n6)paint shapes \n7)Show Happy face\n8)Show angry face\n9)Show unsure face\n10)Save current shapes\n11)Import saved shapes\n12)clear shapes\n0)exit" << std::endl; 
        std::cin >> input;

        if(!cin)
        {   
            std::cout << "not a valid option, please select again" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            continue;
        }

        switch(input) {
            case 1:
            {
                std::cout << "You have selected Point" << std::endl;
                std::cout << "Please enter (x, y) for point: " << std::endl;
                std::cin >> originX >> originY;
                geometricShape * point = new originPoint(originX, originY);
                newCollection.add(point);
                break;
            }
                
            case 2:
            {
                int xRadLength, yRadLength;
                std::cout << "You have selected Ellipse" << std::endl;
                std::cout << "Please enter (x, y) for center point of ellipse: " << std::endl;
                std::cin >> originX >> originY;
                std::cout << "Please enter x-axis radius length, and y-axis radius length: " << std::endl;
                std::cin >> xRadLength >> yRadLength;
                geometricShape * ellipse = new ellipseShape(originX, originY, xRadLength, yRadLength);
                newCollection.add(ellipse);
                break;
            }
            case 3:
            {
                int numOfSides, sideLength;
                std::cout << "You have selected Polygon" << std::endl;
                std::cout << "Please enter (x, y) for center point of polygon: " << std::endl;
                std::cin >> originX >> originY;
                std::cout << "Please enter number of sides and length of sides of polygon: " << std::endl;
                std::cin >> numOfSides >> sideLength;
                geometricShape * polygon = new polygonShape(originX, originY, numOfSides, sideLength);
                newCollection.add(polygon);
                break;
            }
            case 4:
            {
                int targetX, targetY;
                std::cout << "You have selected Line" << std::endl;
                std::cout << "Please enter (x, y) for start point of line: " << std::endl;
                std::cin >> originX >> originY;
                std::cout << "Please enter (x, y) for end point of line: " << std::endl;
                std::cin >> targetX >> targetY;
                geometricShape * line = new lineShape(originX, originY, targetX, targetY);
                newCollection.add(line);
                break;
            }
            case 5:
            {
                for(int i = 0; i < newCollection.getNumberOfItems(); i++)
                {
                    std::cout << newCollection[i]->info();              
                }
                break;
            }
            case 6:
            {
                int shapeIndex;
                std::cout << "Enter an index from the collection to paint: " << std::endl;
                std::cin >> shapeIndex;
                std::cout << newCollection.getNumberOfItems() << std::endl;

                for(int i = 0; i < newCollection.getNumberOfItems(); i++)
                {
                    if(shapeIndex == newCollection.getNumberOfItems() || i == shapeIndex)
                            newCollection[i]->draw(&newScreen);           
                }
                newScreen.display();
                newScreen.clear();            
                break;
            }
            case 7:
            {
                //happy face
                geometricShape * face = new ellipseShape(0, 0, 10, 12);
                geometricShape * rEye = new ellipseShape(5, 5, 2, 1);
                geometricShape * lEye = new ellipseShape(-5, 5, 2, 1);
                geometricShape * nose = new polygonShape(0, 0, 7, 2);
                geometricShape * leftSmile = new lineShape(-7,-1, -4, -6);
                geometricShape * midSmile = new lineShape(-4,-6, 4, -6);
                geometricShape * rightSmile = new lineShape(4, -6, 7, -1);

                newCollection.add(face);
                newCollection.add(rEye);
                newCollection.add(lEye);
                newCollection.add(nose);
                newCollection.add(leftSmile);
                newCollection.add(midSmile); 
                newCollection.add(rightSmile);

                std::ofstream out("happy.txt");
                if (!out)
                {
                    std::cerr << "Failed to open output stream for confused" << std::endl;
                    out.close();
                    return EXIT_FAILURE;
                }
                
                for(int i = 0; i < newCollection.getNumberOfItems(); i++)
                {
                    newCollection[i]->draw(&newScreen);
                    out << newCollection[i]->info();
                }
                    
                out.close();
                newScreen.display();
                newScreen.clear();
                break;
            }
            case 8:
            {
                //angry face
                geometricShape * face = new ellipseShape(0, 0, 10, 12);
                geometricShape * rEye = new ellipseShape(5, 5, 2, 1);
                geometricShape * lEye = new ellipseShape(-5, 5, 2, 1);
                geometricShape * nose = new polygonShape(0, 0, 7, 2);
                geometricShape * leftSmile = new lineShape(-6,-6, -2, -3);
                geometricShape * midSmile = new lineShape(-2,-3, 2, -3);
                geometricShape * rightSmile = new lineShape(2, -3, 6, -6);
                geometricShape * rightEyeBrow = new lineShape(4, 8, 2, 6);
                geometricShape * leftEyeBrow = new lineShape(-4, 8, -2, 6);

                newCollection.add(face);
                newCollection.add(rEye);
                newCollection.add(lEye);
                newCollection.add(nose);
                newCollection.add(leftSmile);
                newCollection.add(midSmile);
                newCollection.add(rightSmile);
                newCollection.add(rightEyeBrow);
                newCollection.add(leftEyeBrow);

                std::ofstream out("angry.txt");
                if (!out)
                {
                    std::cerr << "Failed to open output stream for confused" << std::endl;
                    out.close();
                    return EXIT_FAILURE;
                }
                
                for(int i = 0; i < newCollection.getNumberOfItems(); i++)
                {
                    newCollection[i]->draw(&newScreen);
                    out << newCollection[i]->info();
                }
                    
                out.close();
                newScreen.display();
                newScreen.clear();
                break;
            }
            case 9:
            {
                //unsure face
                geometricShape * face = new ellipseShape(0, 0, 10, 12);
                geometricShape * rEye = new ellipseShape(5, 5, 2, 1);
                geometricShape * lEye = new ellipseShape(-5, 5, 2, 1);
                geometricShape * nose = new polygonShape(0, 0, 7, 2);
                geometricShape * leftSmile = new lineShape(-6,-6, -2, -3);
                geometricShape * midSmile = new lineShape(-2,-3, 2, -6);
                geometricShape * rightSmile = new lineShape(2, -6, 6, -3);
                geometricShape * qMarkPoint = new originPoint(0, 13);
                geometricShape * qMarkBase = new lineShape(0, 15, 0, 16);
                geometricShape * qMarkSide = new lineShape(0, 16, 2, 18);
                geometricShape * qMarkCurve = new lineShape(2, 18, 2, 20);
                geometricShape * qMarkTop = new lineShape(2, 20, -2, 20);
                geometricShape * qMarkHang = new lineShape(-2, 20, -2, 19);

                newCollection.add(face);
                newCollection.add(rEye);
                newCollection.add(lEye);
                newCollection.add(nose);
                newCollection.add(leftSmile);
                newCollection.add(midSmile);
                newCollection.add(rightSmile);
                newCollection.add(qMarkBase);
                newCollection.add(qMarkSide);
                newCollection.add(qMarkCurve);
                newCollection.add(qMarkTop);
                newCollection.add(qMarkHang);
                newCollection.add(qMarkPoint);

                std::ofstream out("unsure.txt");
                if (!out)
                {
                    std::cerr << "Failed to open output stream for confused" << std::endl;
                    out.close();
                    return EXIT_FAILURE;
                }
                   
                for(int i = 0; i < newCollection.getNumberOfItems(); i++)
                {
                    newCollection[i]->draw(&newScreen);
                    out << newCollection[i]->info();
                }
                out.close();
                    
                newScreen.display();
                newScreen.clear();
                break;
            }
            case 10:
            {
                //save current shapes to file
                std::ofstream output("shapes.txt");
                if (!output)
                {
                    std::cerr << "Failed to open output stream for confused" << std::endl;
                    output.close();
                    return EXIT_FAILURE;
                }
                for(int i = 0; i < newCollection.getNumberOfItems(); i++)
                    output << newCollection[i]->info();
                output.close();
                std::cout << "Current Shapes have been saved to file." << std::endl;
               break;
            }
            case 11:
            {
                //import shapes from file
                std::ifstream input("shapes.txt");
                if (!input)
                {
                    std::cerr << "Failed to open output stream for confused" << std::endl;
                    input.close();
                    return EXIT_FAILURE;
                }
                std::string line;
                std::string word;

                while(getline(input, line))
                {
                    std::istringstream ss(line);
                    do {
                        string word;
                        ss >> word;
                        addNewShape(line, word, &newCollection);
                        break;
                        
                    } while(ss);
                }
               
                std::cout << "Shapes have been imported from file." << std::endl;
                break;
            }
            case 12:
            {
                while(newCollection.getNumberOfItems() > 0)
                {
                    newCollection.remove();
                }
                std::cout << "All current shapes have been deleted." << std::endl;
                break;
            }
            case 0:
            {
                return EXIT_SUCCESS;
            }        
            default:
            {
                std::cout << "not a valid option, please select again" << std::endl;
                std::cin.clear();
                break;
            }
        }
    } 
}
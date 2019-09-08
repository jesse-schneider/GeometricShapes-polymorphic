#include <iostream>
#include <cstdlib>
#include <utility>
#include <string>
#include "screen.cpp"
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstring>
#include <cstdlib>

class originPoint {
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

        int getXCoordinate();                                                                   //method to return x coordinate of point
        int getYCoordinate();                                                                   //method to return y coordinate of point
        std::string getName();                                                                  //method to return name of object
        char getDrawSymbol();                                                                   //method to return the symbol to draw with
        void setXCoordinate(int newXCoord);                                                     //method to set x coordinate of point
        void setYCoordinate(int newYCoord);                                                     //method to set y coordinate of point
        void setName(std::string newName);                                                      //method to set name of object
        void setDrawSymbol(char newSymbol);                                                     //method to set symbol to draw with
        std::string info();                                                                            //method to return information about the point
        void draw(screen *newScreen);                                                            //method to draw the point using the screen class
        
    private:
        int xCoord, yCoord;                                                                     //variables to hold point coordinates
        char drawSymbol;                                                                        //variable to hold the symbol used in the draw method
        std::string name;                                                                       //variable to hold the current name of the point 
};


//default construction implementation
originPoint::originPoint() : xCoord{0}, yCoord{0}, name{"point"}, drawSymbol{'*'} { };

//parameterised constructor implemenation
originPoint::originPoint(int x, int y) : xCoord{x}, yCoord{y}, name{"point"}, drawSymbol{'*'} { };

//parameterised constructor implemenation
originPoint::originPoint(int x, int y, std::string name) : xCoord{x}, yCoord{y}, name{name}, drawSymbol{'*'} { };

//parameterised constructor implemenation
originPoint::originPoint(int x, int y, std::string name, char symbol) : xCoord{x}, yCoord{y}, name{name}, drawSymbol{symbol} { };

//copy constructor implementation
originPoint::originPoint(originPoint const & oldPoint) : xCoord{oldPoint.xCoord}, yCoord{oldPoint.yCoord}, name{oldPoint.name}, drawSymbol{oldPoint.drawSymbol} { };

//move constructor implementation
originPoint::originPoint(originPoint && oldPoint) noexcept : xCoord{std::move(oldPoint.xCoord)}, yCoord{std::move(oldPoint.yCoord)}, name{std::move(oldPoint.name)}, drawSymbol{std::move(oldPoint.drawSymbol)}  { };

//copy assignment implementation
originPoint & originPoint::operator = (originPoint const & oldPoint)
{
    if(this == &oldPoint) 
        return *this;
    
    if (xCoord != oldPoint.xCoord || yCoord != oldPoint.yCoord || name != oldPoint.name  || drawSymbol != oldPoint.drawSymbol)
    { 
        xCoord = oldPoint.xCoord;
        yCoord = oldPoint.yCoord;
        name = oldPoint.name;
        drawSymbol = oldPoint.drawSymbol;
    }
} 

//move assignment implementation
originPoint & originPoint::operator = (originPoint && oldPoint) noexcept
{
    xCoord = std::move(oldPoint.xCoord);
    yCoord = std::move(oldPoint.yCoord);
    name = std::move(oldPoint.name);
    drawSymbol = std::move(oldPoint.drawSymbol);
    return *this;
} 

//destructor implementation
originPoint::~originPoint() { };

//method to return the x coordinate implementation
int originPoint::getXCoordinate()
{
    return xCoord;
} 

//method to return the y coordinate implementation
int originPoint::getYCoordinate()
{
    return yCoord;
}

//method to return the name implementation
std::string originPoint::getName()
{
    return name;
}

//method to return the draw symbol implementation
char originPoint::getDrawSymbol()
{
    return drawSymbol;
}

//method to set the x coordinate implementation
void originPoint::setXCoordinate(int newXCoord)
{
    this->xCoord = newXCoord;
} 

//method to set the y coordinate implementation
void originPoint::setYCoordinate(int newYCoord)
{
    this->yCoord = newYCoord;
}

//method to set the name implementation
void originPoint::setName(std::string newName)
{
    this->name = newName;
}

//method to set the name implementation
void originPoint::setDrawSymbol(char newSymbol)
{
    this->drawSymbol = newSymbol;
}


//method to return information about the point implementation
std::string originPoint::info()
{
    return  getName() + " x y s \t\t" + getName() +  " " + std::to_string(getXCoordinate()) + " " + std::to_string(getYCoordinate()) + " " + getDrawSymbol() + "\n";
}

// //method to draw the point using screen class implementation                                                  
void originPoint::draw(screen *newScreen)
{
    newScreen->point(getXCoordinate(), getYCoordinate(), getDrawSymbol());
    //please note: I wasn't sure if I was allowed to used screen->display() in main, so have used it there, but also here and commented it out here
    // newScreen->display();
}


class ellipseShape {
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

        int getXCoordinate();                                                                   //method to return x coordinate of point
        int getYCoordinate();                                                                   //method to return y coordinate of point
        std::string getName();                                                                  //method to return name of object
        char getDrawSymbol();                                                                   //method to return the symbol to draw with
        void setXCoordinate(int newXCoord);                                                     //method to set x coordinate of point
        void setYCoordinate(int newYCoord);                                                     //method to set y coordinate of point
        void setName(std::string newName);                                                      //method to set name of object
        void setDrawSymbol(char newSymbol);                                                     //method to set symbol to draw with
        int getxRadSize();                                                                      //method to return x-radius length of ellipse
        int getyRadSize();                                                                      //method to return y-radius length of ellipse
        void setxRadSize(int newXRad);                                                          //method to return x-radius length of ellipse
        void setyRadSize(int newYRad);                                                          //method to return y-radius length of ellipse
        std::string info();                                                                     //method to return information about the ellipse
        void draw(screen * newScreen);                                                          //method to draw the ellipse using the screen class
        void isCircle();                                                                        //method to check if ellipse is circle, and change if it is
        
    private:
        int xRadSize;                                                                           //variable to hold x-radius length 
        int yRadSize;                                                                           //variable to hold y-radius length
        int xCoord, yCoord;                                                                     //variables to hold point coordinates
        char drawSymbol;                                                                        //variable to hold the symbol used in the draw method
        std::string name;                                                                       //variable to hold the current name of the point
};


//default construction implementation
ellipseShape::ellipseShape() : xCoord{0}, yCoord{0}, name{"ellipse"}, drawSymbol{'+'}, xRadSize{0}, yRadSize{0} { isCircle(); };

//parameterised constructor implemenation
ellipseShape::ellipseShape(int x, int y, int xRad, int yRad) : xCoord{x}, yCoord{y}, name{"ellipse"}, drawSymbol{'+'}, xRadSize{xRad}, yRadSize{yRad} { isCircle(); };

//parameterised constructor implemenation
ellipseShape::ellipseShape(int x, int y, int xRad, int yRad, std::string name) : xCoord{x}, yCoord{y}, name{name}, drawSymbol{'+'}, xRadSize{xRad}, yRadSize{yRad} { isCircle(); };

//parameterised constructor implemenation
ellipseShape::ellipseShape(int x, int y, int xRad, int yRad, std::string name, char symbol) : xCoord{x}, yCoord{y}, name{name}, drawSymbol{symbol}, xRadSize{xRad}, yRadSize{yRad} { isCircle(); };

//copy constructor implementation
ellipseShape::ellipseShape(ellipseShape const & oldEllipse) : xCoord{oldEllipse.xCoord}, yCoord{oldEllipse.yCoord}, name{oldEllipse.name}, drawSymbol{oldEllipse.drawSymbol}, xRadSize{oldEllipse.xRadSize}, yRadSize{oldEllipse.yRadSize} { };

//move constructor implementation
ellipseShape::ellipseShape(ellipseShape && oldEllipse) noexcept : xCoord{std::move(oldEllipse.xCoord)}, yCoord{std::move(oldEllipse.yCoord)}, name{std::move(oldEllipse.name)}, drawSymbol{std::move(oldEllipse.drawSymbol)}, xRadSize{std::move(oldEllipse.xRadSize)}, yRadSize{std::move(oldEllipse.yRadSize)}  { };

//copy assignment implementation
ellipseShape & ellipseShape::operator = (ellipseShape const & oldEllipse)
{
    if(this == &oldEllipse) 
        return *this;
    
    if (xCoord != oldEllipse.xCoord || yCoord != oldEllipse.yCoord || xRadSize != oldEllipse.xRadSize || yRadSize != oldEllipse.yRadSize || name != oldEllipse.name  || drawSymbol != oldEllipse.drawSymbol)
    { 
        xCoord = oldEllipse.xCoord;
        yCoord = oldEllipse.yCoord;
        xRadSize = oldEllipse.xRadSize;
        yRadSize = oldEllipse.yRadSize;
        name = oldEllipse.name;
        drawSymbol = oldEllipse.drawSymbol;
    }
} 

//move assignment implementation
ellipseShape & ellipseShape::operator = (ellipseShape && oldEllipse) noexcept
{
    xCoord = std::move(oldEllipse.xCoord);
    yCoord = std::move(oldEllipse.yCoord);
    xRadSize = std::move(oldEllipse.xRadSize);
    yRadSize = std::move(oldEllipse.yRadSize);
    name = std::move(oldEllipse.name);
    drawSymbol = std::move(oldEllipse.drawSymbol);
    return *this;
} 

//destructor implementation
ellipseShape::~ellipseShape() { };

//method to return the x coordinate implementation
int ellipseShape::getXCoordinate()
{
    return xCoord;
} 

//method to return the y coordinate implementation
int ellipseShape::getYCoordinate()
{
    return yCoord;
}

//method to return the name implementation
std::string ellipseShape::getName()
{
    return name;
}

//method to return the draw symbol implementation
char ellipseShape::getDrawSymbol()
{
    return drawSymbol;
}

//method to set the x coordinate implementation
void ellipseShape::setXCoordinate(int newXCoord)
{
    this->xCoord = newXCoord;
} 

//method to set the y coordinate implementation
void ellipseShape::setYCoordinate(int newYCoord)
{
    this->yCoord = newYCoord;
}

//method to set the name implementation
void ellipseShape::setName(std::string newName)
{
    this->name = newName;
}

//method to set the name implementation
void ellipseShape::setDrawSymbol(char newSymbol)
{
    this->drawSymbol = newSymbol;
}

//method to return the x coordinate implementation
int ellipseShape::getxRadSize()
{
    return xRadSize;
} 

//method to return the y coordinate implementation
int ellipseShape::getyRadSize()
{
    return yRadSize;
}

//method to set the x coordinate implementation
void ellipseShape::setxRadSize(int newXRad)
{
    this->xRadSize = newXRad;
} 

//method to set the y coordinate implementation
void ellipseShape::setyRadSize(int newYRad)
{
    this->yRadSize = newYRad;
}

//method to return information about the point implementation
std::string ellipseShape::info()
{
    return  getName() + " x y s \t\t" + getName() +  " " + std::to_string(getXCoordinate()) + " " + std::to_string(getYCoordinate()) + " " + std::to_string(getxRadSize()) + " " + std::to_string(getyRadSize()) + " " + getDrawSymbol() + "\n";    
}

//method to draw the point using screen class implementation                                                  
void ellipseShape::draw(screen * newScreen)
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



class polygonShape {
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

        int getXCoordinate();                                                                                   //method to return x coordinate of point
        int getYCoordinate();                                                                                   //method to return y coordinate of point
        std::string getName();                                                                                  //method to return name of object
        char getDrawSymbol();                                                                                   //method to return the symbol to draw with
        void setXCoordinate(int newXCoord);                                                                     //method to set x coordinate of point
        void setYCoordinate(int newYCoord);                                                                     //method to set y coordinate of point
        void setName(std::string newName);                                                                      //method to set name of object
        void setDrawSymbol(char newSymbol);                                                                     //method to set symbol to draw with
        int getNumOfSides();                                                                                    //method to return x-radius length of polygon
        int getSideLength();                                                                                    //method to return y-radius length of polygon
        void setNumOfSides(int newNum);                                                                         //method to return x-radius length of polygon
        void setSideLength(int newSideLength);                                                                  //method to return y-radius length of polygon
        std::string info();                                                                                     //method to return information about the polygon
        void draw(screen *newScreen);                                                                           //method to draw the polygon using the screen class
        
    private:
        int numOfSides;                                                                                         //variable to hold x-radius length 
        int sideLength;                                                                                         //variable to hold y-radius length
        int xCoord, yCoord;                                                                                     //variables to hold point coordinates
        char drawSymbol;                                                                                        //variable to hold the symbol used in the draw method
        std::string name;                                                                                       //variable to hold the current name of the point 
};


//default construction implementation
polygonShape::polygonShape() : xCoord{0}, yCoord{0}, name{"polygon"}, drawSymbol{'*'}, numOfSides{0}, sideLength{0} { };

//parameterised constructor implemenation
polygonShape::polygonShape(int x, int y, int numOfSides, int sideLength) : xCoord{x}, yCoord{y}, name{"polygon"}, drawSymbol{'*'}, numOfSides{numOfSides}, sideLength{sideLength} { };

//parameterised constructor implemenation
polygonShape::polygonShape(int x, int y, int numOfSides, int sideLength, std::string name) : xCoord{x}, yCoord{y}, name{name}, drawSymbol{'*'}, numOfSides{numOfSides}, sideLength{sideLength} { };

//parameterised constructor implemenation
polygonShape::polygonShape(int x, int y, int numOfSides, int sideLength, std::string name, char symbol) : xCoord{x}, yCoord{y}, name{name}, drawSymbol{symbol}, numOfSides{numOfSides}, sideLength{sideLength} { };

//copy constructor implementation
polygonShape::polygonShape(polygonShape const & oldPolygon) : xCoord{oldPolygon.xCoord}, yCoord{oldPolygon.yCoord}, name{oldPolygon.name}, drawSymbol{oldPolygon.drawSymbol}, numOfSides{oldPolygon.numOfSides}, sideLength{oldPolygon.sideLength} { };

//move constructor implementation
polygonShape::polygonShape(polygonShape && oldPolygon) noexcept : xCoord{std::move(oldPolygon.xCoord)}, yCoord{std::move(oldPolygon.yCoord)}, name{std::move(oldPolygon.name)}, drawSymbol{std::move(oldPolygon.drawSymbol)}, numOfSides{std::move(oldPolygon.numOfSides)}, sideLength{std::move(oldPolygon.sideLength)}  { };

//copy assignment implementation
polygonShape & polygonShape::operator = (polygonShape const & oldPolygon)
{
    if(this == &oldPolygon) 
        return *this;
    
    if (xCoord != oldPolygon.xCoord || yCoord != oldPolygon.yCoord || numOfSides != oldPolygon.numOfSides || sideLength != oldPolygon.sideLength || name != oldPolygon.name  || drawSymbol != oldPolygon.drawSymbol)
    { 
        xCoord = oldPolygon.xCoord;
        yCoord = oldPolygon.yCoord;
        numOfSides = oldPolygon.numOfSides;
        sideLength = oldPolygon.sideLength;
        name = oldPolygon.name;
        drawSymbol = oldPolygon.drawSymbol;
    }
} 

//move assignment implementation
polygonShape & polygonShape::operator = (polygonShape && oldPolygon) noexcept
{
    xCoord = std::move(oldPolygon.xCoord);
    yCoord = std::move(oldPolygon.yCoord);
    numOfSides = std::move(oldPolygon.numOfSides);
    sideLength = std::move(oldPolygon.sideLength);
    name = std::move(oldPolygon.name);
    drawSymbol = std::move(oldPolygon.drawSymbol);
    return *this;
} 

//destructor implementation
polygonShape::~polygonShape() { };

//method to return the x coordinate implementation
int polygonShape::getXCoordinate()
{
    return xCoord;
} 

//method to return the y coordinate implementation
int polygonShape::getYCoordinate()
{
    return yCoord;
}

//method to return the name implementation
std::string polygonShape::getName()
{
    return name;
}

//method to return the draw symbol implementation
char polygonShape::getDrawSymbol()
{
    return drawSymbol;
}

//method to set the x coordinate implementation
void polygonShape::setXCoordinate(int newXCoord)
{
    this->xCoord = newXCoord;
} 

//method to set the y coordinate implementation
void polygonShape::setYCoordinate(int newYCoord)
{
    this->yCoord = newYCoord;
}

//method to set the name implementation
void polygonShape::setName(std::string newName)
{
    this->name = newName;
}

//method to set the name implementation
void polygonShape::setDrawSymbol(char newSymbol)
{
    this->drawSymbol = newSymbol;
}

//method to return the x coordinate implementation
int polygonShape::getNumOfSides()
{
    return numOfSides;
} 

//method to return the y coordinate implementation
int polygonShape::getSideLength()
{
    return sideLength;
}

//method to set the x coordinate implementation
void polygonShape::setNumOfSides(int newNum)
{
    this->numOfSides = newNum;
} 

//method to set the y coordinate implementation
void polygonShape::setSideLength(int newSideLength)
{
    this->sideLength = newSideLength;
}

//method to return information about the point implementation
std::string polygonShape::info()
{
    return  getName() + " x y s \t\t" + getName() +  " " + std::to_string(getXCoordinate()) + " " + std::to_string(getYCoordinate()) + " " + std::to_string(getNumOfSides()) + " " + std::to_string(getSideLength()) + " " + getDrawSymbol() + "\n";
}

// //method to draw the point using screen class implementation                                                  
void polygonShape::draw(screen *newScreen)
{
    newScreen->polygon(getXCoordinate(), getYCoordinate(), getNumOfSides(), getSideLength(), getDrawSymbol());
    //newScreen->display();

}

class lineShape {
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

        int getXCoordinate();                                                                                   //method to return x coordinate of point
        int getYCoordinate();                                                                                   //method to return y coordinate of point
        std::string getName();                                                                                  //method to return name of object
        char getDrawSymbol();                                                                                   //method to return the symbol to draw with
        void setXCoordinate(int newXCoord);                                                                     //method to set x coordinate of point
        void setYCoordinate(int newYCoord);                                                                     //method to set y coordinate of point
        void setName(std::string newName);                                                                      //method to set name of object
        void setDrawSymbol(char newSymbol);                                                                     //method to set symbol to draw with
        int getTargetXCoord();                                                                                  //method to return x-radius length of line
        int getTargetYCoord();                                                                                  //method to return y-radius length of line
        void setTargetXCoord(int newTargetX);                                                                   //method to return x-radius length of line
        void setTargetYCoord(int newTargetY);                                                                   //method to return y-radius length of line
        std::string info();                                                                                     //method to return information about the line
        void draw(screen * newScreen);                                                                          //method to draw the line using the screen class
        
    private:
        int targetXCoord;                                                                                       //variable to hold x-radius length 
        int targetYCoord;                                                                                       //variable to hold y-radius length
        int xCoord, yCoord;                                                                                     //variables to hold point coordinates
        char drawSymbol;                                                                                        //variable to hold the symbol used in the draw method
        std::string name;                                                                                       //variable to hold the current name of the point 
};


//default construction implementation
lineShape::lineShape() : xCoord{0}, yCoord{0}, name{"line"}, drawSymbol{'*'}, targetXCoord{0}, targetYCoord{0} { };

//parameterised constructor implemenation
lineShape::lineShape(int x, int y, int targetXCoord, int targetYCoord) : xCoord{x}, yCoord{y}, name{"line"}, drawSymbol{'*'}, targetXCoord{targetXCoord}, targetYCoord{targetYCoord} { };

//parameterised constructor implemenation
lineShape::lineShape(int x, int y, int targetXCoord, int targetYCoord, std::string name) : xCoord{x}, yCoord{y}, name{name}, drawSymbol{'*'}, targetXCoord{targetXCoord}, targetYCoord{targetYCoord} { };

//parameterised constructor implemenation
lineShape::lineShape(int x, int y, int targetXCoord, int targetYCoord, std::string name, char symbol) : xCoord{x}, yCoord{y}, name{name}, drawSymbol{symbol}, targetXCoord{targetXCoord}, targetYCoord{targetYCoord} { };

//copy constructor implementation
lineShape::lineShape(lineShape const & oldLine) : xCoord{oldLine.xCoord}, yCoord{oldLine.yCoord}, name{oldLine.name}, drawSymbol{oldLine.drawSymbol}, targetXCoord{oldLine.targetXCoord}, targetYCoord{oldLine.targetYCoord} { };

//move constructor implementation
lineShape::lineShape(lineShape && oldLine) noexcept : xCoord{std::move(oldLine.xCoord)}, yCoord{std::move(oldLine.yCoord)}, name{std::move(oldLine.name)}, drawSymbol{std::move(oldLine.drawSymbol)}, targetXCoord{std::move(oldLine.targetXCoord)}, targetYCoord{std::move(oldLine.targetYCoord)}  { };

//copy assignment implementation
lineShape & lineShape::operator = (lineShape const & oldLine)
{
    if(this == &oldLine) 
        return *this;
    
    if (xCoord != oldLine.xCoord || yCoord != oldLine.yCoord || targetXCoord != oldLine.targetXCoord || targetYCoord != oldLine.targetYCoord || name != oldLine.name  || drawSymbol != oldLine.drawSymbol)
    { 
        xCoord = oldLine.xCoord;
        yCoord = oldLine.yCoord;
        targetXCoord = oldLine.targetXCoord;
        targetYCoord = oldLine.targetYCoord;
        name = oldLine.name;
        drawSymbol = oldLine.drawSymbol;
    }
} 

//move assignment implementation
lineShape & lineShape::operator = (lineShape && oldLine) noexcept
{
    xCoord = std::move(oldLine.xCoord);
    yCoord = std::move(oldLine.yCoord);
    targetXCoord = std::move(oldLine.targetXCoord);
    targetYCoord = std::move(oldLine.targetYCoord);
    name = std::move(oldLine.name);
    drawSymbol = std::move(oldLine.drawSymbol);
    return *this;
} 

//destructor implementation
lineShape::~lineShape() { };

//method to return the x coordinate implementation
int lineShape::getXCoordinate()
{
    return xCoord;
} 

//method to return the y coordinate implementation
int lineShape::getYCoordinate()
{
    return yCoord;
}

//method to return the name implementation
std::string lineShape::getName()
{
    return name;
}

//method to return the draw symbol implementation
char lineShape::getDrawSymbol()
{
    return drawSymbol;
}

//method to set the x coordinate implementation
void lineShape::setXCoordinate(int newXCoord)
{
    this->xCoord = newXCoord;
} 

//method to set the y coordinate implementation
void lineShape::setYCoordinate(int newYCoord)
{
    this->yCoord = newYCoord;
}

//method to set the name implementation
void lineShape::setName(std::string newName)
{
    this->name = newName;
}

//method to set the name implementation
void lineShape::setDrawSymbol(char newSymbol)
{
    this->drawSymbol = newSymbol;
}

//method to return the x coordinate implementation
int lineShape::getTargetXCoord()
{
    return targetXCoord;
} 

//method to return the y coordinate implementation
int lineShape::getTargetYCoord()
{
    return targetYCoord;
}

//method to set the x coordinate implementation
void lineShape::setTargetXCoord(int newNum)
{
    this->targetXCoord = newNum;
} 

//method to set the y coordinate implementation
void lineShape::setTargetYCoord(int newtargetYCoord)
{
    this->targetYCoord = newtargetYCoord;
}

//method to return information about the point implementation
std::string lineShape::info()
{
    return  getName() + " x y s \t\t" + getName() +  " " + std::to_string(getXCoordinate()) + " " + std::to_string(getYCoordinate()) + " " + std::to_string(getTargetXCoord()) + " " + std::to_string(getTargetYCoord()) + " "+ getDrawSymbol() + "\n";
}
// //method to draw the point using screen class implementation                                                  
void lineShape::draw(screen * newScreen)
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
        Shape * operator [] (int index)
        {
            return collection[index];
        }
        ~bunch();

        void setNumberOfItems(int newNumber);
        int getNumberOfItems();
        void add(Shape newShape);
        void remove();
        
    private:
        int numberOfItems;
        Shape *collection[32];
};

//public default constructor implementation
template<typename Shape>
bunch<Shape>::bunch() : numberOfItems{0}, collection{new Shape[32]} { }

//public copy constructor
template<typename Shape>
bunch<Shape>::bunch(bunch const & that) : numberOfItems{that.numberOfItems}, collection{new Shape[32]} 
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
void bunch<Shape>::setNumberOfItems(int newNumber)
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
    collection[getNumberOfItems()] = new Shape (newShape);
    setNumberOfItems(getNumberOfItems() + 1);
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
    collection[getNumberOfItems()] = nullptr;
    setNumberOfItems(getNumberOfItems() - 1);
    return;
}




void addNewLine(string line, bunch<lineShape> *lineBunch)
{
    //add to line bunch instance
    int * input = new int[4];
    bool negative;
    int index = 0, tempI = 0;
    while(line[index] != '\0')
    {
        if(line[index] == '-')
        negative = true;
        if(isdigit(static_cast<int>(line[index])) != 0)
        {
            char numberCh = line[index];
            int num = atoi(&numberCh);
            if(negative == true)
                num *= -1;
            input[tempI] = num;
            negative = false;
            tempI++;
        }
        index++;
    }
    lineShape newLine(input[0],input[1],input[2],input[3]);
    newLine.info();
    lineBunch->add(newLine);
    delete[] input; 
}

void addNewEllipse(string line, bunch<ellipseShape> *ellipseBunch)
{
    //add to line bunch instance
    int * input = new int[4];
    bool negative;
    int index = 0, tempI = 0;
    while(line[index] != '\0')
    {
        if(line[index] == '-')
        negative = true;
        if(isdigit(static_cast<int>(line[index])) != 0)
        {
            char numberCh = line[index];
            int num = atoi(&numberCh);
            if(negative == true)
                num *= -1;
            input[tempI] = num;
            negative = false;
            tempI++;
        }
        index++;
    }
    ellipseShape newEllipse(input[0],input[1],input[2],input[3]);
    newEllipse.info();
    ellipseBunch->add(newEllipse);
    delete[] input; 
}

void addNewPolygon(string line, bunch<polygonShape> *polygonBunch)
{
    //add to line bunch instance
    int * input = new int[4];
    bool negative;
    int index = 0, tempI = 0;
    while(line[index] != '\0')
    {
        if(line[index] == '-')
        negative = true;
        if(isdigit(static_cast<int>(line[index])) != 0)
        {
            char numberCh = line[index];
            int num = atoi(&numberCh);
            if(negative == true)
                num *= -1;
            input[tempI] = num;
            negative = false;
            tempI++;
        }
        index++;
    }
    polygonShape newPolygon(input[0],input[1],input[2],input[3]);
    newPolygon.info();
    polygonBunch->add(newPolygon);
    delete[] input; 
}

void addNewPoint(string line, bunch<originPoint> *pointBunch)
{
    //add to line bunch instance
    int * input = new int[2];
    bool negative;
    int index = 0, tempI = 0;
    while(line[index] != '\0')
    {
        if(line[index] == '-')
        negative = true;
        if(isdigit(static_cast<int>(line[index])) != 0)
        {
            char numberCh = line[index];
            int num = atoi(&numberCh);
            if(negative == true)
                num *= -1;
            input[tempI] = num;
            negative = false;
            tempI++;
        }
        index++;
    }
    originPoint newPoint(input[0],input[1]);
    newPoint.info();
    pointBunch->add(newPoint);
    delete[] input; 
}




int main()
{
    screen newScreen;                                       //screen class item
    bunch<originPoint> pointBunch;                          //point bunch class
    bunch<ellipseShape> ellipseBunch;                       //ellipse bunch class
    bunch<polygonShape> polygonBunch;                       //polygon bunch class
    bunch<lineShape> lineBunch;                             //line bunch class
    // if(!out)
    // {
    //     std::cerr << "streaming to file failed to open" << std::endl;
    //     out.close();
    //     return EXIT_FAILURE;
    // }

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
                originPoint point(originX, originY);
                pointBunch.add(point);
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
                ellipseShape ellipse(originX, originY, xRadLength, yRadLength);
                ellipseBunch.add(ellipse);
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
                polygonShape polygon(originX, originY, numOfSides, sideLength);
                polygonBunch.add(polygon);
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
                lineShape line(originX, originY, targetX, targetY);
                lineBunch.add(line);
                break;
            }
            case 5:
            {
                for(int i = 0; i < pointBunch.getNumberOfItems(); i++)
                {
                    pointBunch[i]->info();              
                }
                for(int i = 0; i < ellipseBunch.getNumberOfItems(); i++)
                {
                    ellipseBunch[i]->info();              
                }
                for(int i = 0; i < polygonBunch.getNumberOfItems(); i++)
                {
                    polygonBunch[i]->info();              
                }
                for(int i = 0; i < lineBunch.getNumberOfItems(); i++)
                {
                    lineBunch[i]->info();              
                }
                break;
            }
            case 6:
            {
                int type, shapeIndex;
                std::cout << "Enter option from below and an index to paint: \n1)point \n2)ellipse \n3)polygon \n4)line" << std::endl;
                std::cin >> type >> shapeIndex;

                switch (type) {
                    case 1:
                    {
                        for(int i = 0; i < pointBunch.getNumberOfItems(); i++)
                        {
                            if(shapeIndex == pointBunch.getNumberOfItems() || i == shapeIndex)
                            {
                                pointBunch[i]->draw(&newScreen);
                            }                                              
                        }
                        newScreen.display();
                        newScreen.clear();
                        break;
                    }
                    case 2:
                    {
                        for(int i = 0; i < ellipseBunch.getNumberOfItems(); i++)
                        {
                            if(shapeIndex == ellipseBunch.getNumberOfItems() || i == shapeIndex)
                                ellipseBunch[i]->draw(&newScreen);              
                        }
                        newScreen.display();
                        newScreen.clear();
                        break;
                    }
                    case 3:
                    {
                        for(int i = 0; i < polygonBunch.getNumberOfItems(); i++)
                        {
                            if(shapeIndex == polygonBunch.getNumberOfItems() || i == shapeIndex)
                                polygonBunch[i]->draw(&newScreen);              
                        }
                        newScreen.display();
                        newScreen.clear();
                        break;
                    }
                    case 4:
                    {
                        for(int i = 0; i < lineBunch.getNumberOfItems(); i++)
                        {
                            if(shapeIndex == lineBunch.getNumberOfItems() || i == shapeIndex)
                                lineBunch[i]->draw(&newScreen);              
                        }
                        newScreen.display();
                        newScreen.clear();
                        break;
                    }
                    ;
                    default:
                    {
                      std::cout << "Error selecting shape type" << std::endl;
                      return EXIT_FAILURE;  
                    }
                }
                break;
            }
            case 7:
            {
                //happy face
                ellipseShape face(0, 0, 10, 12);
                ellipseShape rEye(5, 5, 2, 1);
                ellipseShape lEye(-5, 5, 2, 1);
                polygonShape nose(0, 0, 7, 2);
                lineShape leftSmile(-7,-1, -4, -6);
                lineShape midSmile(-4,-6, 4, -6);
                lineShape rightSmile(4, -6, 7, -1);

                ellipseBunch.add(face);
                ellipseBunch.add(rEye);
                ellipseBunch.add(lEye);
                polygonBunch.add(nose);
                lineBunch.add(leftSmile);
                lineBunch.add(midSmile); 
                lineBunch.add(rightSmile);

                std::ofstream out("happy.txt");
                if (!out)
                {
                    std::cerr << "Failed to open output stream for confused" << std::endl;
                    out.close();
                    return EXIT_FAILURE;
                }
                
                for(int i = 0; i < pointBunch.getNumberOfItems(); i++)
                {
                    pointBunch[i]->draw(&newScreen);
                    out << pointBunch[i]->info();
                }
                    
                for(int i = 0; i < lineBunch.getNumberOfItems(); i++)
                {
                    lineBunch[i]->draw(&newScreen);
                    out << lineBunch[i]->info();
                }
                    
                for(int i = 0; i < ellipseBunch.getNumberOfItems(); i++)
                {
                    ellipseBunch[i]->draw(&newScreen);
                    out << ellipseBunch[i]->info();
                }
                    
                for(int i = 0; i < polygonBunch.getNumberOfItems(); i++)
                {
                    polygonBunch[i]->draw(&newScreen);
                    out << polygonBunch[i]->info();
                }
                out.close();
                newScreen.display();
                newScreen.clear();
                break;
            }
            case 8:
            {
                //angry face
                ellipseShape face(0, 0, 10, 12);
                ellipseShape rEye(5, 5, 2, 1);
                ellipseShape lEye(-5, 5, 2, 1);
                polygonShape nose(0, 0, 7, 2);
                lineShape leftSmile(-6,-6, -2, -3);
                lineShape midSmile(-2,-3, 2, -3);
                lineShape rightSmile(2, -3, 6, -6);
                lineShape rightEyeBrow(4, 8, 2, 6);
                lineShape leftEyeBrow(-4, 8, -2, 6);

                ellipseBunch.add(face);
                ellipseBunch.add(rEye);
                ellipseBunch.add(lEye);
                polygonBunch.add(nose);
                lineBunch.add(leftSmile);
                lineBunch.add(midSmile);
                lineBunch.add(rightSmile);
                lineBunch.add(rightEyeBrow);
                lineBunch.add(leftEyeBrow);

                std::ofstream out("angry.txt");
                if (!out)
                {
                    std::cerr << "Failed to open output stream for confused" << std::endl;
                    out.close();
                    return EXIT_FAILURE;
                }
                
                for(int i = 0; i < pointBunch.getNumberOfItems(); i++)
                {
                    pointBunch[i]->draw(&newScreen);
                    out << pointBunch[i]->info();
                }
                    
                for(int i = 0; i < lineBunch.getNumberOfItems(); i++)
                {
                    lineBunch[i]->draw(&newScreen);
                    out << lineBunch[i]->info();
                }
                    
                for(int i = 0; i < ellipseBunch.getNumberOfItems(); i++)
                {
                    ellipseBunch[i]->draw(&newScreen);
                    out << ellipseBunch[i]->info();
                }
                    
                for(int i = 0; i < polygonBunch.getNumberOfItems(); i++)
                {
                    polygonBunch[i]->draw(&newScreen);
                    out << polygonBunch[i]->info();
                }
                out.close();
                newScreen.display();
                newScreen.clear();
                break;
            }
            case 9:
            {
                //unsure face
                ellipseShape face(0, 0, 10, 12);
                ellipseShape rEye(5, 5, 2, 1);
                ellipseShape lEye(-5, 5, 2, 1);
                polygonShape nose(0, 0, 7, 2);
                lineShape leftSmile(-6,-6, -2, -3);
                lineShape midSmile(-2,-3, 2, -6);
                lineShape rightSmile(2, -6, 6, -3);
                originPoint qMarkPoint(0, 13);
                lineShape qMarkBase(0, 15, 0, 16);
                lineShape qMarkSide(0, 16, 2, 18);
                lineShape qMarkCurve(2, 18, 2, 20);
                lineShape qMarkTop(2, 20, -2, 20);
                lineShape qMarkHang(-2, 20, -2, 19);

                ellipseBunch.add(face);
                ellipseBunch.add(rEye);
                ellipseBunch.add(lEye);
                polygonBunch.add(nose);
                lineBunch.add(leftSmile);
                lineBunch.add(midSmile);
                lineBunch.add(rightSmile);
                lineBunch.add(qMarkBase);
                lineBunch.add(qMarkSide);
                lineBunch.add(qMarkCurve);
                lineBunch.add(qMarkTop);
                lineBunch.add(qMarkHang);
                pointBunch.add(qMarkPoint);
                std::ofstream out("unsure.txt");
                if (!out)
                {
                    std::cerr << "Failed to open output stream for confused" << std::endl;
                    out.close();
                    return EXIT_FAILURE;
                }
                
                for(int i = 0; i < pointBunch.getNumberOfItems(); i++)
                {
                    pointBunch[i]->draw(&newScreen);
                    out << pointBunch[i]->info();
                }
                    
                for(int i = 0; i < lineBunch.getNumberOfItems(); i++)
                {
                    lineBunch[i]->draw(&newScreen);
                    out << lineBunch[i]->info();
                }
                    
                for(int i = 0; i < ellipseBunch.getNumberOfItems(); i++)
                {
                    ellipseBunch[i]->draw(&newScreen);
                    out << ellipseBunch[i]->info();
                }
                    
                for(int i = 0; i < polygonBunch.getNumberOfItems(); i++)
                {
                    polygonBunch[i]->draw(&newScreen);
                    out << polygonBunch[i]->info();
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
                for(int i = 0; i < pointBunch.getNumberOfItems(); i++)
                    output << pointBunch[i]->info();
                for(int i = 0; i < lineBunch.getNumberOfItems(); i++)
                    output << lineBunch[i]->info();
                for(int i = 0; i < ellipseBunch.getNumberOfItems(); i++)
                    output << ellipseBunch[i]->info();
                for(int i = 0; i < polygonBunch.getNumberOfItems(); i++)
                    output << polygonBunch[i]->info();
                output.close();
                std::cout << "Current Shapes have been saved to file." << std::endl;
            }
            break;
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

                        if(word.compare("line") == 0)
                        {
                            addNewLine(line, &lineBunch);
                            break;
                        }
                        if(word.compare("ellipse") == 0)
                        {
                            addNewEllipse(line, &ellipseBunch);
                            break;
                        }
                        if(word.compare("polygon") == 0)
                        {
                            addNewPolygon(line, &polygonBunch);
                            break;
                        }
                        if(word.compare("point") == 0)
                        {
                            addNewPoint(line, &pointBunch);
                            break;
                        }
                    } while(ss);
                }

                for(int i = 0; i < pointBunch.getNumberOfItems(); i++)
                    std::cout << pointBunch[i]->info() << std::endl;
                for(int i = 0; i < lineBunch.getNumberOfItems(); i++)
                    std::cout << lineBunch[i]->info() << std::endl;
                for(int i = 0; i < ellipseBunch.getNumberOfItems(); i++)
                    std::cout << ellipseBunch[i]->info() << std::endl;
                for(int i = 0; i < polygonBunch.getNumberOfItems(); i++)
                    std::cout << polygonBunch[i]->info() << std::endl;

                
                std::cout << "Shapes have been imported from file." << std::endl;
                break;
            }
            case 12:
            {
                while(lineBunch.getNumberOfItems() > 0)
                {
                    lineBunch.remove();
                }
                while(polygonBunch.getNumberOfItems() > 0)
                {
                    polygonBunch.remove();
                }
                while(ellipseBunch.getNumberOfItems() > 0)
                {
                    ellipseBunch.remove();
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
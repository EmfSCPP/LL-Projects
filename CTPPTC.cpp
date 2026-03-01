#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int Setprecision();

void CartesianToPolar() {
    long double cx, cy, r, theta;
    cout<<endl<<"Cartesian To Polar Converter :"<<endl<<endl<<"x :-  ";
    cin>>cx;
    cout<<"y :-  ";
    cin>>cy;
    int p = Setprecision();
    r = hypot(cx, cy), theta = atan2(cy, cx); // In rad(radian)       atan2 is arctan(tan inverse)
    if (cx == 0 && cy == 0) {
        cout<<endl<<"Angle at origin undefined";
    }
    else {
        cout<<endl<<"r :-  "<<fixed<<setprecision(p)<<r<<endl<<"θ :-  "<<fixed<<setprecision(p)<<theta<<" rad"<<endl<<"      "<<fixed<<setprecision(p)<<theta * 180 / M_PI<<"°"<<endl<<endl<<"Note: results may sometimes be non-terminating";
    }
}

void PolarToCartesian() {
    long double cx, cy, r, theta;
    cout<<endl<<"Polar To Cartesian Converter :"<<endl<<endl<<"r :-  ";
    cin>>r;
    cout<<"θ :-  ";
    cin>>theta;
    theta = theta * M_PI / 180;
    int p = Setprecision();
    cx = r * cos(theta), cy = r * sin(theta); //LOOK HERE FOR CONVERSION ISSUES WITH PTC
    cout<<endl<<"x :-  "<<fixed<<setprecision(p)<<cx<<endl<<"y :-  "<<fixed<<setprecision(p)<<cy<<endl<<endl<<"Note: results may sometimes be non-terminating";
}

int Setprecision() {
    string dp;  //dp = decimal precision
    int p;  //p = precision
    cout<<endl<<"Decimal Precision(Low, Medium, High) :-  ";
    cin>>dp;
    for (char& dpchar : dp) {
        dpchar = tolower(dpchar);
    }
    if (dp == "low") {
        p = 5;
        return p;
    }
    else if (dp == "medium") {
        p = 9;
        return p;
    }
    else if (dp == "high") {
        p = 17;
        return p;
    }
    else {
        cout<<"You may have mistyped. Choosing default precision(10)";
        p = 10;
        return p;
    }
}

int main() {      // Mode Selection & Calculator Func Execution Function 
    cout<< "Cartesian & Polar"<<endl<<"Coordinates Converter"<<endl<<"𝈴𝈳======================𝈴𝈳"<<endl<<endl;
    cout<<"Enter mode :- "<<endl<<"Cartesian To Polar(Yes/No) :-  ";
    string ctop, ptoc; //ctop = x, y to r, theta     ptoc = r, theta to x, y
    cin >> ctop;
    for (char& ctopchar : ctop) {
        ctopchar = tolower(ctopchar);
    }
    if (ctop == "yes") {
        
        CartesianToPolar();
    }
    else if (ctop == "no") {
        cout<<"Polar To Cartesian(Yes/No) :-  ";
        cin >> ptoc;
        for (char& ptocchar : ptoc) {
            ptocchar = tolower(ptocchar);
        }
        if (ptoc == "yes") {
            
            PolarToCartesian();
            
        }
        else if  (ptoc == "no") {
            cout<<endl<<"No Mode Chosen. Ending Calculator";
            return 0;
        }
        else {
            cout<<"You may have mistyped. Choosing default mode"<<endl; //ctop
            CartesianToPolar();
        }
    }
    else {
            cout<<"You may have mistyped. Choosing default mode"<<endl; //ctop
            CartesianToPolar();
        }
    
    return 0;
}
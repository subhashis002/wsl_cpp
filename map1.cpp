#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    /*Create a map/associative array 
    - keys are strings
    - values are floats
    */

    typedef map<string,float> StringFloatMap;

    StringFloatMap stocks;

    //inserts some elements
    stocks["BASF"] = 369.50;
    stocks["VW"] = 413.50;
    stocks["Daimler"] = 819.00;
    stocks["BMW"] = 834.00;
    stocks["Siemens"] = 842.20;

    //print all elements
    StringFloatMap::iterator pos;

    //boom (all prices doubled)
    for(pos = stocks.begin(); pos!= stocks.end(); pos++){
        cout<<"Stock:   "<<pos->first<<"\t"
            <<"Price:   "<<pos->second<<endl;
    } 
    cout<<endl;

    /*rename the key from "VW" to "Volkswagen"
    - only provided by exchanging element
    */
   stocks["Volkswagen"] = stocks["VW"];
   stocks.erase("VW");

   for(pos = stocks.begin(); pos!= stocks.end(); pos++){
        cout<<"Stock:   "<<pos->first<<"\t"
            <<"Price:   "<<pos->second<<endl;
    }
     
    cout<<endl;
}
/*
File name: HW 3, States anual average temperature
Author: Colin White
Date; 21 may 2018
Description: This program reads from a file called "3data.txt. It has 7 columns. The 1st column is a State ID number.
The 2nd and 3rd columns are latitude and longitude values, respectively, where the temperature values were recorded.
The 4th column is a date. The 5th column is the temperature measurement. The 6th column is State name and the 7th column
is  the day of the year (1-365). This program calculates an average yearly temperature for each state, and prints each
state id with its associated latitude, longitude, adn annual average temperature.

 The proses is done by the program reading a new line from the file, if the state id matches the previous line, it
 keeps a running total of the daily temperature, latitude, and longitude. Once it reaches a line that does not
 match the previous ID, it takes the running totals and divides by the number of lines read. The program then outputs
 the ID, average temperature, average latitude, and average longitude. The program then repeats the proses with the next
 batch of identical id's. Once the program read's the last line in the file, it is furnished.
*/

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>// allows input and output to files
using namespace std;

int main() {
    int n =1;               // Counter. Used to keep track of iterations
    double id = 0;          // column 1 State ID number
    double lat = 0;         // column 2 latitude
    double lon = 0;         // column 3 longitude
    string date = "date";   // column 4 date
    double temp = 0;        // column 5 temperature
    string state = "state"; // column 6 State
    int    day = 0;         // column 7 day of the year
    double tempsum = 0;     // running total of temperatures
    double latsum = 0;      // running total of latitude
    double lonsum = 0;      // running total longitude
    double id2 = 1;         // 1.2 State ID number inside of inner while loop, it starts at 1 so the program can enter the while loop
    double lat2 = 0;        // 2.2 latitude number inside of inner while loop
    double lon2 = 0;        // 3.2 longitude number inside of inner while loop

    //here I set up the files I read and write from
    ifstream fin;               // if stream = input file. fin = arbitray name
    fin.open("3data.txt");      // taking data from "3data.txt"
    ofstream  fout;             // of stream = output file. fopen = arbitrary name
    fout.open("results3.txt");  // writing data too "results.txt"

    //this While Loop reads new lines until the end of the file (eof)
    while(!fin.eof())
    {
        tempsum = temp;                                          //tempsum = 0 the first time, then equals the last temp value from then on
        latsum = lat;                                            //latsum = 0 the first time, then equals the last lat value from then on
        lonsum = lon;                                            //lonsum = 0 the first time, then equals the last lon value from then on
        fin >> id >> lat >> lon >> date >> temp >> state >> day; //gather data from file
        tempsum = tempsum + temp;                                //begin making sunning total of temperature
        latsum = latsum + lat;                                   //begin making sunning total of latitude
        lonsum = lonsum + lon;                                   //begin making sunning total of longitude
        n=1;                                                     //reset the counter to 1 every time

        //this is the inner while loop runs as long as the new state id (id2) matches the old state id (id), and until the end of the file
        while (id == id2 && !fin.eof())
        {
            fin >> id2 >> lat2 >> lon2 >> date >> temp >> state >> day; //gather data from file
            tempsum = tempsum + temp;                                   // running total of temperatures
            latsum = latsum + lat2;                                     // running total of latitude
            lonsum = lonsum + lon2;                                     // running total of longitude
            n++;
        }
        tempsum = tempsum - temp; // the while loop will read one line too many before realizing the state id's don't match. This takes off the last value which belongs to a different state.
        latsum = latsum - lat2;   // the while loop will read one line too many before realizing the state id's don't match. This takes off the last value which belongs to a different state.
        lonsum = lonsum - lon2;   // the while loop will read one line too many before realizing the state id's don't match. This takes off the last value which belongs to a different state.

        if (id==1) //the way the counter, n, is off by 1 only for the first state. This "If" statement corrects that by reindexing n
        {
            n=n-1;               //reindexing b
            tempsum = tempsum/n; //get the average temp
            latsum = latsum/n;   //get the average latitude
            lonsum = lonsum/n;   //get the average longitude
            fout << id <<"\t" << "\t" << "\t" << latsum << "\t" << "\t" << "\t" << lonsum << "\t" << "\t" << "\t" << tempsum << endl; //print data to results3.txt file

        }
        else //the rest of the 49 states do not need n to be reindexed
        {
            tempsum = tempsum/n; //get the average temp
            latsum = latsum/n;   //get the average latitude
            lonsum = lonsum/n;   //get the average longitude
            fout << id <<"\t" << "\t" << "\t" << latsum << "\t" << "\t" << "\t" << lonsum << "\t" << "\t" << "\t" << tempsum << endl; //print data to results3.txt file
        }
    }

    fin.close();  //close file
    fout.close(); //close file
    return 0;     //end of program
}

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    string line;
    char number[3];
    float number_float, sum=0.0f;
    ifstream input_work_hours;
    fstream outfile;
    input_work_hours.open("work_hours.txt", ios::in | ios::out);
    outfile.open("output_with_results_hours.txt", ios::out);

    if(!input_work_hours.is_open()){
        cout << "\nCould not open the file!" << endl;
        return -1;
    }
        
    cout << "\nFILE opened successfully " << endl;

    while(!input_work_hours.eof())
    {
        getline(input_work_hours, line);
        if(input_work_hours.good())
            cout << line << endl;
        number[0] = line[0];
        number[1] = line[1];
        number[2] = line[2];
        number_float = atof(number);
        sum += number_float;
        outfile << line << endl;
    }

    cout << "-----------------------------------\n";
    cout << "Total Hours:  " << sum << endl;
    outfile << "---------------------------------\n";
    outfile << "Total Hours:  " << sum << endl;

    input_work_hours.close();
    outfile.close();

    return 0;
}
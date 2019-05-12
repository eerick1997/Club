#include <bits/stdc++.h>
using namespace std;


using number = long long int;
int main () {

    number MaxDays, daysIWantToStudy, maxTired, stressInDay, restInDay;
    cin >> MaxDays >> daysIWantToStudy >> maxTired >> stressInDay >> restInDay;

    number daysIHaveStudied {}, stressLevel {}, days {1};
    while(daysIHaveStudied < daysIWantToStudy) {


        if (MaxDays < days) {
            days = 0;
            break;
        }
        if (stressLevel + stressInDay > maxTired) {
            // rest
            stressLevel -= restInDay;
            if (stressLevel < 0) stressLevel = 0;
        }
        else {
            daysIHaveStudied++;
            stressLevel += stressInDay;
        }


        //cout << "day " << days << endl;
        //cout << "daysIHaveStudied " << daysIHaveStudied << endl;
        //cout << "stressLevel " << stressLevel << endl << endl;

        days++;   
    }


    cout << days -1  << endl;

    return 0;
}
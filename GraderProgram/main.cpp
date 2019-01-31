//
//  main.cpp
//  GraderProgram
//
//  Created by Bryan Cruz on 1/16/19.
//  Copyright © 2019 Bryan Cruz. All rights reserved.
//
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;
int getExamScore(string);
int getProjectScore(string);
string calcGrade(int , int, int , int, int, int);
string LETTERGRADES[] = {"A", "B", "C", "D", "F"};

int main(int argc, const char * argv[])
{
    void checkValue(int);
    string yesNo;
    int midOneScore, midTwoScore, finalScore , project1Score , project2Score, projectFinalScore;
    string finalGrade;
    midOneScore = getExamScore("midtermOne");
    midTwoScore = getExamScore("midtermTwo");
    finalScore = getExamScore("finalExam");
    project1Score = getProjectScore("projectOne");
    project2Score = getProjectScore("projectTwo");
    projectFinalScore = getProjectScore("projectFinal");
    finalGrade = calcGrade (midOneScore, midTwoScore, finalScore, project1Score, project2Score, projectFinalScore);
    cout << "YOUR FINAL GRADE IS " << finalGrade << endl;
}

int getExamScore(string testName)
{
    int scoreExam;
    cout << "Enter Score for " << testName << " : ";
    cin >> scoreExam;
    while(cin.fail() || scoreExam < 0 ||  scoreExam > 100)
    {
        cout << "Invalid entry. Enter a value between 0 - 100: ";
        cin.clear();
        cin.ignore(1000);
        cin >> scoreExam;
    }
    return scoreExam;
}

int getProjectScore(string projectName)
{
    int scoreProject;
    cout << "Enter Score for " << projectName << " : ";
    cin >> scoreProject;
    while(cin.fail() || scoreProject < 0 || scoreProject  > 100)
    {
        cout << "Invalid entry. Enter a value between 0 - 100: " ;
        cin.clear();
        cin.ignore(1000);
        cin >> scoreProject;
    }
    return scoreProject;
}

string calcGrade(int m1, int m2, int ft, int p1, int p2, int pf)
{
    int fg, testsGrade, projectsGrade = 0;
    testsGrade = (m1 + m2 + ft)/3;
    projectsGrade = (p1 + p2 + pf) / 3;
    fg = ((testsGrade * 60) + (projectsGrade * 40)) / 100;
    if (fg >= 95) {return LETTERGRADES[0];}
    if (fg >= 80 && fg < 95) {return LETTERGRADES[1];}
    if (fg >= 70 && fg < 80) {return LETTERGRADES[2];}
    if (fg >= 60 && fg < 70) {return LETTERGRADES[3];}
    else {return LETTERGRADES[4];}
}


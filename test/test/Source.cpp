//Blaze McNeill
//
//final project
//
//all seems to be working proper
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

//sorting
void sort(vector<float>& grades) {
    int pass, pos, manynum;
    float temp;

    manynum = grades.size();

    for (pass = 0; pass < manynum - 1; pass++)
        for (pos = 0; pos < manynum - pass - 1; pos++)
            if (grades[pos] < grades[pos + 1]) {
                temp = grades[pos];
                grades[pos] = grades[pos + 1];
                grades[pos + 1] = temp;
            }

}

//mean score
float mean(vector<float>& grades) {
    float sum, mean;
    int i;

    sum = 0.0;

    for (i = 0; i < grades.size(); ++i) {
        sum += grades[i];
    }

    mean = sum / grades.size();

    return mean;
}

//median score
void median(vector<float>& grades) {
    int i;
    float median;

    sort(grades);

    if (grades.size() % 2 == 0) {
        median = (grades[grades.size() / 2] + grades[(grades.size() / 2) - 1]) / 2;
    }
    else {
        median = grades[(grades.size() / 2)];
    }

    cout << "The median is: " << median << endl;
}

//mode score
void mode(vector<float>& grades) {
    int i, j, count, maxCount;
    float mode;

    sort(grades);

    maxCount = 1;
    mode = grades[0];

    for (i = 0; i < grades.size() - 1; i++) {
        count = 1;
        for (j = i + 1; j < grades.size(); j++) {
            if (grades[i] == grades[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = grades[i];
        }
    }

    cout << "The mode is: " << mode << endl;
}

//standard deviation
void standardDeviation(vector<float>& grades) {
    int i;
    float sum, standardDeviation;

    sort(grades);
    float _mean = mean(grades);

    sum = 0.0;

    for (i = 0; i < grades.size(); ++i) {
        sum += pow((grades[i] - _mean), 2);
    }

    standardDeviation = sqrt(sum / (grades.size() - 1)) + 0.005;

    cout << "The standard deviation is: " << fixed << setprecision(2) << standardDeviation << endl;
}

//number of each grade
array<int, 5> gradeCount(vector<float>& grades) {
    int A = 0, B = 0, C = 0, D = 0, F = 0;

    for (float grade : grades) {
        if (grade >= 90) {
            A++;
        }
        else if (grade >= 80) {
            B++;
        }
        else if (grade >= 70) {
            C++;
        }
        else if (grade >= 60) {
            D++;
        }
        else {
            F++;
        }
    }

    array<int, 5> grade_list = { A, B, C, D, F };
    return grade_list;
}

int main() {

    int size;
    double grade;

    vector<float> grades/*{95, 80, 82.5, 95, 70, 75, 73, 89, 66, 62, 78, 51}  //TEST*/;

    grade = 0;

        while (grade != -1) {
            cout << "Score? ";
            cin >> grade;
            grades.push_back(grade);
    
        }


        grades.pop_back();

    size = grades.size();

    vector<int> freq(size);
    vector<float> unique_grades;

    cout << "\nThere were " << grades.size() + 1 << " scores entered" << endl;

    sort(grades);


    cout << "The maxumum score was " << grades[0] << endl;//max
    cout << "The minimum score was " << grades[size - 1] << endl;//min
    cout << "The mean score was " << mean(grades) << endl;//mean


    median(grades);
    mode(grades);
    standardDeviation(grades);

    array<int, 5> grade_list = gradeCount(grades);
    cout << "There were " << grade_list[0] << " A's, " << " " << grade_list[1] << " B's, " << " " << grade_list[2]
        << " C's, " << " " << grade_list[3] << " D's, " << " " << grade_list[4] << " F's \n" << endl;

    cout << "Scores in order: " << endl;
    for (float grade : grades) {
        cout << grade << "    ";
    }
    cout << "\n" << endl;

    //Bonus Points: Score chart

    //Reverse grade list
    reverse(grade_list.begin(), grade_list.end());

    cout << "Score Chart: " << endl;
    const int x = grade_list.max_size();
    const int y = grade_list.max_size();


    char chart[x][y] = { " ", " ", " ", " " };

    for (int i = x - 1; i >= 0; i--) {
        for (int j = 0; j < y; j++) {
            if (i >= grade_list[j]) {
                chart[i][j] = ' ';
            }
            else {
                chart[i][j] = '*';
            }
        }
    }

    for (int i = x - 1; i >= 0; i--) {
        for (int j = 0; j < y; j++) {
            cout << chart[i][j] << " ";
        }
        cout << endl;
    }

    cout << "F D C B A" << endl;

    return 0;
}
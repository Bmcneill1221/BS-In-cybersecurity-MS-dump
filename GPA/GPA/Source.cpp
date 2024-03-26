//Blaze McNeill
//
//Calculates GPA
//
//
//PUT MORE HERE

#include <iostream>
#include <iomanip>
using namespace std;

void main()
{
	int courses, hours, courseNumber;
	float totalPoints, totalHours, gradePoints, creditHours, qualityPoints, GPA;
	char grade;

	courseNumber = 1;
	totalPoints = 0;
	totalHours = 0;
	gradePoints = 0;
	creditHours = 0;
	qualityPoints = 0;

	cout << "Number of courses? "; 
	cin >> courses;

	while (courses >= courseNumber)
	{

		cout << "\nFor course " << courseNumber << ":\n";

		courseNumber++;

		cout << "Grade? ";
		cin >> grade;

//case insensitive/retry input/asigning grade to numbers

		if (grade == 'a' || grade == 'A')
			gradePoints = 4;
			else if (grade == 'b' || grade == 'B')
				gradePoints = 3;
				else if (grade == 'c' || grade == 'C')
				gradePoints = 2;
					else if (grade == 'd' || grade == 'D')
					gradePoints = 1;
						else
						{
							cout << "\nIput proper letter grade\n";
							cout << "Grade? ";
							cin >> grade;
						}
		
		cout << "Hours? ";
		cin >> hours;
		while (!(hours < 0 || hours <= 6))// inproper input check
		{

			cout << "Inproper numbers of hours, try again. \n";
			cin >> hours;

		}
		
		qualityPoints = gradePoints * hours; 
		totalHours += hours; // Hours of this loop + hours of past loops = total hours
		totalPoints += qualityPoints; // Points of this loop + points of past loops = total points
		
	}

	GPA = totalPoints / totalHours;

	cout << fixed << setprecision(2);

	cout << "\nGPA is " << GPA;

}
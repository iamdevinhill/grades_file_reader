// Devin Hill
// Open Lab 3
// Grade Review

#include <iostream>
#include <fstream>
#include <iostream>
#include <iomanip>

// global variable
const int MAX = 30;

// prototypes
void PrintGrades(const int grades[], int count);
char CalculateLetter (float grade);

int main() {

  std::cout << std::fixed << std::setprecision(1);

  // variables
  std::string name;
  std::string gradefile;
  std::ifstream file;
  int count = 0;
  int totalpoints = 0;
  int maxpoints = 0;
  float finalpercent = 0.0;
  int grades[MAX];
  float percent = 0.0;
  std::string line;
  
  // user file prompt
  std::cout << "Enter the input file: ";
  std::cin >> gradefile;
  file.open(gradefile);
  std::cout << std::endl;

  if(!file){
    std::cout << gradefile << " is not a good file.";
    return 0;
  }

  // loop and fill array
  // while (file){
    
  //   file >> grades[count];
  //   totalpoints += grades[count];
  //   count++;
  // }

    // loop and fill array
  while (std::getline(file, line)){
    // if the getline line isn't empty
    if (!line.empty()){
      grades[count] = std::stoi(line);
      totalpoints += grades[count];
      count ++;
    }
  }
  
  // close file
  file.close();

  maxpoints = count * 100;
  finalpercent = ((totalpoints / static_cast<float>(maxpoints)) * 100);
  // check for a black entry to assign 0%
  if(totalpoints == 0){
    finalpercent = 0;
  }

  // output
  std::cout << "Number of Grades: " << std::setw(10) << count << std::endl;
  std::cout << "Total Points Earned: " << std::setw(7) << totalpoints << std::endl;
  std::cout << "Max Possible Points: " << std::setw(7) << maxpoints << std::endl;
  std::cout << std::endl;

  PrintGrades(grades, count);
  std::cout << std::endl;

  char finalletter = CalculateLetter(finalpercent);

  std::cout << "Final Grade: " << std::setw(7) << finalletter << std::setw(7) << finalpercent << "%";
  
}

// functions
void PrintGrades(const int grades[], int count){
    int maxpoints;
    float percent;
    for (int i = 0; i < count; i++) {
      maxpoints = count * 100;
      percent = (grades[i] / static_cast<float>(maxpoints)) * 100;
    std::cout << std::setw(20) << grades[i] << std::setw(7) << percent << "%" << std::endl;
  }
}


char CalculateLetter (float grade){
  if (grade >= 90 && grade <= 100){
    return 'A';
  } else if (grade >= 80  && grade < 90){
    return 'B'; 
  } else if (grade >= 70  && grade < 80){
    return 'C';
  } else if (grade >= 60  && grade < 70){
    return 'D';
  } else {
    return 'F';
  }
}


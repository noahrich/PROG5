//---------------------------------------------------------------------------
// File name:   academics.cpp
// Assign ID:   PROG5
// Due Date:    Febuary 24, 2019
//
// Purpose:     (1) Write a program to read and format data for FOUR students.

//              (2) Flag the academic status of each student:
//                  ON PROBATION  -- when GPA < 2.0
//                  HONORS        -- when GPA >= 3.0
//                  GOOD STANDING -- when neither honors nor probation.

//              (3) Compute the arithmetic and weighted average GPA of the 
//                  three students.
//
// Author:      nrichardson Noah Richardson
//
//---------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <fstream>
#include  <stdlib.h>
using namespace std;
int main()
{
    ifstream inF;
    ofstream outH, outG, outR;
    long Student_ID;
    string FirstName, LastName;
    int CumHours, student_Count, honors_Count, good_Count, atrisk_Count;
    float GPA, avgGPA, avgGPA_honors, avgGPA_goodstanding, avgGPA_atrisk, OGPA;
 //-| -----------------------------------------------------------
 //-| NOTE: The following steps 1-4 are the start-up phase.
 //-| -----------------------------------------------------------    
 //-| 1. Open input file.
    inF.open("students.dat");
 //-|    If the input file can not be opened, print termination message and terminate program.
     if(inF.fail())
  {
   cout << "'FATAL ERROR: can not OPEN file 'students.dat'." << endl;
   exit(1);
  }
 //-| 2. Open the output files.
    outH.open("honors.dat");
    outG.open("good_standing.dat");
    outR.open("at_risk.dat");
 //-| 3. Set all the counts and sums to ZERO.
    student_Count = 0;
    honors_Count = 0;
    good_Count = 0;
    atrisk_Count = 0;
     
 //-| 4. Display ACADEMIC STANDING REPORT headings.
    cout << endl; 
    cout << "========================" << endl;
    cout << "ACADEMIC STANDING REPORT" << endl;
    cout << "========================" << endl;
    cout << endl;
    cout << endl;
    cout << "====  =========  =====   ====================  ==================" << endl;
    cout << " GPA  StudentID  Hours   Student_Name          Academic Standing" << endl;
    cout << "====  =========  =====   ====================  ==================" << endl;
 //-| -----------------------------------------------------------
 //-| NOTE: The following steps 5-9 must be repeated 4 times.
 //-| -----------------------------------------------------------

 //-| 5. Read input data for one student from input file. 
 for(int loop = 1; loop < 5; loop++)
 {
    inF >> Student_ID >> FirstName >> LastName >> CumHours >> GPA;
 //-| 6. Write student data to the Standing Report
    cout << fixed << showpoint << setprecision(2);
    cout << setw(4) << right << GPA << "  ";
    cout << setw(9) << right << Student_ID << "  "<< setw(5) << right << CumHours<< "   " << setw(16)<< left<< LastName + ", " + FirstName << "      ";    

 //-| 7. Increment the overall number of students.
    student_Count = student_Count++;
 //-| 8. Add the GPA to the overall GPA sum.
    OGPA = OGPA + GPA;
 //-| 9. Determine the academic standing of student, and based on
 //-|   classification:  
    if(GPA >= 3.00)
    {
        outH << Student_ID << " "<< FirstName << " " << LastName << " " << CumHours << " " << GPA << endl;
        honors_Count = honors_Count++;
        avgGPA_honors = avgGPA_honors + GPA;
        cout << setw(18) <<  "HONORS" << endl;
       
    }else if(GPA < 3.00 && GPA >= 2.00) {
        outG << Student_ID << " "<< FirstName << " " << LastName << " " << CumHours << " " << GPA << endl;
        good_Count = good_Count++;
        avgGPA_goodstanding = avgGPA_goodstanding + GPA;
        cout << setw(18) <<  "GOOD STANDING" << endl;
    }else{  
         outR << Student_ID << " "<< FirstName << " " << LastName << " " << CumHours << " " << GPA << endl;
        atrisk_Count = atrisk_Count++;
        avgGPA_atrisk = avgGPA_atrisk + GPA;
        cout << setw(18) <<  "AT RISK" << endl;
    }
 }
 //-| 9.1 Write student data to required output file
 //-| 9.2 Count the student for the classification (honors, 
 //-|         at-risk, good-standing)
 //-| 9.3 Add the GPA to sum for the classification


 //-| -----------------------------------------------------------
 //-| NOTE: The following steps 10-14 complete the process.
 //-| -----------------------------------------------------------

 //-| 10. Display Standing Report Footer.
    cout << "====  =========  =====   ====================  ==================" << endl; 
    cout << endl;
 //-| 11. Calculate the average GPA for each classification: ZERO
 //-|    if no students in the classification.
    if(student_Count >= 1)
    {
        avgGPA = OGPA / student_Count;
    }else{
        avgGPA = 0;
    }
    
     if(honors_Count >= 1)
    {
        avgGPA_honors = avgGPA_honors / honors_Count;
    }else{
        avgGPA_honors = 0;
    }
    
     if(good_Count >= 1)
    {
        avgGPA_goodstanding = avgGPA_goodstanding / good_Count;
    }else{
        avgGPA_goodstanding = 0;
    }
   
     if(atrisk_Count >= 1)
    {
        avgGPA_atrisk = avgGPA_atrisk / atrisk_Count ;
    }else{
        avgGPA_atrisk = 0;
    }
    

 //-| 12. Write to Standing Report the overall average GPA, then avg 
 //-|    GPA for at-risk, good-standing, and honors.
    cout << fixed << showpoint << setprecision(3);
    cout << avgGPA << " = Average Student GPA" << endl;
    cout << endl;
    cout << avgGPA_atrisk << " = Average At Risk GPA" << endl;
    cout << endl;
    cout << avgGPA_goodstanding << " = Average Good Standing GPA" << endl;
    cout << endl;
    cout << avgGPA_honors << " = Average Honors GPA" << endl;
    cout << endl;
    
 //-| 13. Write to Standing Report the count of students: overall, 
 //-|    at-risk, good-standing, honors.
    cout << "  " << student_Count << " STUDENTS" << endl;
    
    cout << "     " <<  atrisk_Count << " AT RISK" << endl;
    
    cout << "     " << good_Count << " IN GOOD STANDING" << endl;
    
    cout << "     " << honors_Count << " HONORS" << endl;
    cout << endl;
    cout << endl << "(c) 2019, nrichardson Noah Richardson" << endl << endl; 





 //-| 14. Close input and output files.
    
    outH.close();
    outG.close();
    outR.close();
    inF.close();
    
    
    return 0;

}


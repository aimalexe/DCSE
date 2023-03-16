%{
Write a CGPA Calculator program using M-File: Design a transcript for your second-semester
result i.e. take grade points and credit hours of each subject as input from user and store in 
variables. Take the product of each subject grade points with its credit hours and divide by total 
13 credit hours in order to evaluate CGPA. Show the results in the form of well-designed transcript 
using disp and input commands. Use the following table to display equivalent grades for each 
grade point
%}

% CGPA Calculator Program
clc;
clear;

total_credit_hours = 15;
% Initialize variables From user
ps_points = input('Enter grade of Pakstudies? ');
ps_credit = input('Enter credit hour(s) of Pakstudies? ');
ps_grade = ps_points * ps_credit;

de_points = input('Enter grade of Differential Equations? ');
de_credit = input('Enter credit hour(s) of Differential Equations? ');
de_grade = de_points * de_credit;

cp_points = input('Enter grade of Computer Programming? ');
cp_credit = input('Enter credit hour(s) of Computer Programming? ');
cp_grade = cp_points * cp_credit;

cs1_points = input('Enter grade of Circuit & Systems 1? ');
cs1_credit = input('Enter credit hour(s) of Circuit & Systems 1? ');
cs1_grade = cs1_points * cs1_credit;

edc_points = input('Enter grade of Engineering Drawing And Cad? ');
edc_credit = input('Enter credit hour(s) of Engineering Drawing And Cad? ');
edc_grade = edc_points * edc_credit;

cps_points = input('Enter grade of Communocation And Presentation Skills? ');
cps_credit = input('Enter credit hour(s) of Communocation And Presentation Skills? ');
cps_grade = cps_points * cps_credit;


total_grade_points = (ps_grade + de_grade + cp_grade + cs1_grade + edc_grade + cps_grade)/6

% Calculate CGPA
cgpa = total_grade_points / total_credit_hours

% Display transcript
fprintf('\n\t\tTranscript\n');
fprintf('Subject    Credit Hours    Grade Point\n');
fprintf('-------    ------------    -----------\n');
fprintf('%-10d %-15d  %-9.2f\n', 1, ps_credit, ps_points);
fprintf('%-10d %-15d  %-9.2f\n', 2, de_credit, de_points);
fprintf('%-10d %-15d  %-9.2f\n', 3, cp_credit, cp_points);
fprintf('%-10d %-15d  %-9.2f\n', 4, cs1_credit, cs1_points);
fprintf('%-10d %-15d  %-9.2f\n', 5, edc_credit, edc_points);
fprintf('%-10d %-15d  %-9.2f\n', 6, cps_credit, cps_points);
fprintf('---------------------------------------------\n');
fprintf('CGPA: %-10d', cgpa);



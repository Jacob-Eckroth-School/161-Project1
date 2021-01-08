/*******************************
 **Program: taxes.cpp
 **Author: Jacob Eckroth
 **Description: This program takes in info and puts out gross income, taxes, and remaining income
 **Input: monthly salary, number of months worked in a year, cost of a car, number of cars sold, numbers of misconducts, tax year, and tax state
 **Output: Gross income, taxes, remaining income
 *******************************/
#include <iostream>
#include <cstdlib>//to allow for rand()
#include <bits/stdc++.h>//to allow for power function 

using namespace std;

int main(){
	float monthlysalary;
	float yearlysalary;
	float monthsworked;
	float carcost;
	int carssold;
	float carsell;
	int misconducts;
	int taxyear;
	char state;
	float profit;//Profit changes throughout the program, will eventually hold income prior to taxes.
	float taxes;
	float remainingincome;

	srand(time(0)); //makes it so rand() actually generates a random number.
	float modulator=( 1.0 + ((500.0 + (rand() % 600)) / 10000.0)); //Makes a random modulator from 1.05-1.10 for the car price
	cout<<"Please enter your monthly salary:" << endl;
	cin>> monthlysalary;

	while(monthlysalary <0){
		cout<<"Your salary can not be less than 0, please re-enter a number larger than 0:" << endl;
		cin>> monthlysalary;	
	}
	cout<<"Please enter the number of months you've worked this year:"<< endl;	
	cin >> monthsworked;
	while(monthsworked < 0 || monthsworked > 12){
		cout<<"The months you have worked must be between 0 and 12. Please re-enter the number of months worked this year:"<<endl;
		cin>>monthsworked;
	}	

	yearlysalary = monthlysalary * monthsworked;//calculates yearly salary

	cout<<"Please enter the cost of a car:"<<endl;
	cin>>carcost;
	while(carcost < 1){
		cout<<"The car cost must be greater than 0! Please re-enter the car cost:"<<endl;
		cin>>carcost;
	}
	carsell= carcost * modulator; //Makes a random average car sell price

	cout<<"Please enter the amount of cars sold this year:"<<endl;
	cin>>carssold;
	while(carssold<0){
		cout<<"The amount of cars sold must be 0 or higher, please enter the numbers of cars sold again"<<endl;
		cin>>carssold;
	}
	profit = yearlysalary + .02 * (carssold * (carsell- carcost)); //Calculating income before taxes and storing in var profit

	cout<<"Please enter the amount of misconducts observed:"<<endl;	
	cin>>misconducts;
	while(misconducts<0){
		cout<<"The amount of misconducts must be 0 or higher. Please enter the amount of misconducts observed again:"<<endl;
		cin>>misconducts;
	}
	profit = profit - 100 * pow(2,misconducts-1);//deductions due to misconducts

	cout<<"Which tax year are you in? 2017 or 2018?"<<endl;
	cin >> taxyear;	
	cout<<"Are you in Alabama[A], Bexas[B](states dont  begin with B), or California?[C]"<<endl;
	cin>>state;
	if(taxyear == 2017){
		if(state == 'A'){
			taxes = .06*profit;	
		}else if(state == 'B'){
			if(profit<2000){
				taxes = 0;	
			}else if(2000<= profit && profit <=10000){
				taxes = 100;
			}else{
				taxes = 100 + .1 *(profit-10000);
			}			
		}else{
			if(profit <3500){
				taxes = .05 * profit;
			}else if(3500<=profit&& profit<9000){
				taxes = 175 + .07 * (profit-3500)+(.05*3500);
			}else if(9000<=profit&& profit < 125000){
				taxes = 560 + .09 * (profit-9000) + (9000*.07) + (3500 * .05);
			}else{
				taxes = 11000 + .099 * (profit-125000) + (9000*.07) + (3500*.05);
			}
		}
	}else{ //If tax year is 2018
		if(state=='A'){     
			taxes = .08 * profit;
		}else if(state =='B'){
			if(profit<2500){
				taxes = 0;
			}else if(2500 <profit && profit < 10000){
				taxes = 115;
			}else{
				taxes = 115 +  115 + .105 * (profit-10000);
			}
		}else{
			if(profit<3450){
				taxes = .05 * profit;
			}else if(3450<= profit && profit <8700){
				taxes = 172.5 + .07 * (profit-3450) + (.05*3450);
			}else if(8700 <= profit && profit < 125000){
				taxes = 540 + .09 * (profit-8700) + ((8700-3450) * .07) + 172.5 + (3450 * .05) ;
			}else{
				taxes = 11007 + .099 * (profit - 125000) + (116300 * .09) + 540 + (8700-3450)*.07 + 172.5 +
(3450*.05);
			}
		}
	}
	remainingincome = profit-taxes;//calculates remaining income after taxes
	cout<<"Gross income: $"<<profit<<endl;
	cout<<"Taxes: $"<<taxes<<endl;
	cout<<"Remaining Income: $"<<remainingincome<<endl;

	return 0;
}









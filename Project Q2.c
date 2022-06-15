// Note: User input errors are not handled. Assuming user will always input choices from what user is offered.
#include <stdio.h>

#include <stdlib.h>

//declaring the variables first

char name[30];
int id;
int meterCharge = 50;
int replacement = 0;
float agricultureUnit = 3.82;
int agricultureServiceCharge = 30;
float siFlat = 7.66, siOffPeak = 6.90, siPeak = 9.24, siService = 70;
float totalBill = 0;
int replacementFlag = 0;
float nonResidentialUnit = 5.22;
float coFlat = 9.80, coOffPeak = 8.45, coPeak = 11.98;
void mainMenu();
void customerInfo();

void printBill() {
  printf("\nBill Summary");
  printf("\nCustomer name: %s\nCustomer id: %d\nMonthly Electricity Bill is %.2f Taka\nThank you\n", name, id, totalBill);

} // After calculating the bill the user name,number and total sum of the bill is printed.

void residential() { //function for residential
  float unit;
  int unitRange[] = {
    600,
    400,
    300,
    200,
    75,
    0
  }; //declaring an array for the range of units.
  float unitPrice[] = {
    9.98,
    8.70,
    5.63,
    5.36,
    5.14,
    3.80
  }; //declaring an array for the range of unit costs.
  printf("Enter units consumed: ");
  scanf("%f", & unit);
  int phase; //declaring phase.
  printf("1. 1-Phase\n2. 3-Phase\nEnter a choice:");
  scanf("%d", & phase);
  if (phase == 1) {
    phase = 10;
  } else {
    phase = 30;
  } //the above portion is to add the service charge based on the user's input of phase.
  totalBill = totalBill + meterCharge + phase;
  if (unit <= 50) { //using this loop we are calculating the bill below 50 units. If the unit's more than 50 then accessing the units from unitRange and it's corresponding value from unitPrice.
    totalBill = totalBill + unit * 3.33;
  } else {
    int start = 0;
    for (int i = 0; i < 6; i++) {
      if (unit > unitRange[i]) {
        start = i;
        break;
      }
    }
    for (int i = start; i < 6; i++) {
      totalBill = totalBill + (unit - unitRange[i]) * unitPrice[i];
      unit = unitRange[i];
    }
  }
}

void agriculturalPumping() { //function for agricultural pumping.
  float unit;
  printf("Enter units consumed: ");
  scanf("%f", & unit);
  totalBill = totalBill + unit * agricultureUnit + meterCharge + agricultureServiceCharge;
}

void smallIndustry() {
  float flat, offPeak, peak;
  printf("Unit consumed at flat rate:");
  scanf("%f", & flat);
  printf("Unit consumed at off-peak rate:");
  scanf("%f", & offPeak);
  printf("Unit consumed at peak rate:");
  scanf("%f", & peak);
  totalBill = totalBill + meterCharge + siService + flat * siFlat + offPeak * siOffPeak + peak * siPeak;
} //taking user input for small industry and updating the value of totalBill.

void nonResidential() { //function for Non residential.
  float unit;
  int phase;
  printf("Enter units consumed: ");
  scanf("%f", & unit);
  printf("1. 1-Phase\n2. 3-Phase\nEnter a choice:");
  scanf("%d", & phase);
  if (phase == 1) {
    phase = 10;
  } else {
    phase = 30;
  }
  totalBill = totalBill + nonResidentialUnit * unit + phase + meterCharge;
}

void commercialAndOffice() { //Function for Commercial and offices.
  float flat, offPeak, peak;
  int phase;
  printf("Unit consumed at flat rate:");
  scanf("%f", & flat);
  printf("Unit consumed at off-peak rate:");
  scanf("%f", & offPeak);
  printf("Unit consumed at peak rate:");
  scanf("%f", & peak);
  printf("1. 1-Phase\n2. 3-Phase\nEnter a choice:");
  scanf("%d", & phase);
  if (phase == 1) {
    phase = 10;
  } else {
    phase = 30;
  }
  totalBill = totalBill + meterCharge + phase + flat * coFlat + offPeak * coOffPeak + peak * coPeak;
}

void meterReplacement() { //function for meter replacement.
  if (replacementFlag == 0) {

    printf("\n|| You will be charged extra 2000tk as a meter replacement fee. ||");

    replacement = 2000;
    totalBill += replacement;
    replacementFlag = 1;
  } else { //If we choose meter replacement more than once then the extra meter replacement cost won't be added in the total bill.

    printf("|| You have been already charged 2000 Tk as replacement fee. ||\n");

  }
  mainMenu();
}
void calculateBill() { //function for calculating the bill.
  int choice;
  printf("\n\n 1.Residential          \n 2.Agricultural Pumping \n 3.Small Industries     \n 4.Non-Residential      \n 5.Commercial and Office\n \n");
  printf("Enter a choice:");
  scanf("%d", & choice);
  switch (choice) { // if the user inputs 1 then it'll direct to the residential semester, and for 2,3,4 the it'll be directed to functions of agricultural, small industry and non residential correspondingly.
  case 1:
    residential();
    break;
  case 2:
    agriculturalPumping();
    break;
  case 3:
    smallIndustry();
    break;
  case 4:
    nonResidential();
    break;
  case 5:
    commercialAndOffice();
    break;
  }
}
void billOptions() { //function for billing options.
  int choice;
  if (totalBill > 0) {
    printf("\nRecalculate bill?\n1.Yes\n2.No\nEnter a choice:");
    scanf("%d", & choice);
    if (choice == 1) {
      if (replacementFlag == 1) { //by "replacementFlag == 1" we are assuming we have already been charged for the meter replacement.
        totalBill = 2000;
      } else {
        totalBill = 0;
      }
      calculateBill();
    }
  } else {
    calculateBill();
  }
  printBill();
  mainMenu();
}

void mainMenu() { //declaring the main menu function.
  int choice;
  printf("\n\n 1.Monthly bill      \n 2.Meter replacement \n 3.Main Menu         \n 4.Exit              \n \n");
  printf("Enter a choice:");
  scanf("%d", & choice);
  switch (choice) { // if the user inputs 1 then it'll direct to the function of bill options, and for 2,3,4 the it'll be directed to functions of meterRplacement, customer info and exit correspondingly.
  case 1:
    billOptions();
    break;
  case 2:
    meterReplacement();
    break;
  case 3:
    customerInfo();
    break;
  case 4:
    exit(0);
    break;
  }
}

void customerInfo() { //function for customer info.
  totalBill = 0;
  replacement = 0;
  replacementFlag = 0;
  printf("\n\n~~~~~~~~~~Check Your Electricity Bill~~~~~~~~~~~\n");
  printf("Enter the name of the customer: ");
  scanf("\n%[^\n]s", name);
  printf("Customer number: ");
  scanf("%d", & id);
  mainMenu();
}

int main() {
  customerInfo();
  return 0;
}

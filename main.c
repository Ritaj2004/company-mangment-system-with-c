#include <stdio.h>
#include <string.h>
//structs
typedef struct {
	unsigned char id;
	char employeeType[10];
	char phone[11];
	char name[20];
	char address[10];
	float salary;
    char department[10];
	char age;
} Employee;

typedef struct {
	char name[20];
	Employee emp;
} department;
//======prototypes=====
void newdepart(Employee employees[], char *empcount, department departments[], char *departcount, char *mancount);
void AddNewEmployee(Employee employees[], char *empcount, department departments[], char *departcount);
void dispemp(Employee employees[], char *empcount);
void searchByID(Employee employees[], char *empcount);
void dispHighestSalary(Employee employees[], char *empcount);
void searchByDep(Employee employees[], char *empcount, char *departcount, department departments[]);
void compcounter(char *empcount, char *mancount);
void edit_employe_information(Employee employees[], char *empcount);
void count_of_employee(Employee employees[], char *empcount, department departments[], char *departcount);
void interface(char *choice);
//======FUNCTIONS======
//======OWNER=========
void owner(Employee employees[],char *empcount,department departments[],char *departcount,char *mancount) {
	department depart;
	char check = 0;
    strcpy(depart.name, "Royal fam");//string copy
	printf("Enter name of OWNER: ");
	scanf(" %[^\n]", depart.emp.name);
	getchar();
	printf("Enter address: ");
	scanf(" %[^\n]", depart.emp.address);
	getchar();
	printf("Enter phone number :");
	scanf("%s",depart.emp.phone);
	strcpy(depart.emp.employeeType, "OWNER");//string copy
	strcpy(depart.emp.department, depart.name);
	check=0;
    depart.emp.salary=0;
	do { //check the age is positive
		printf("Enter the age :");
		scanf("%d",&depart.emp.age);
		if(depart.emp.age<=16 || depart.emp.age>60) {
			printf("make the age from 17 to 60 \n");
			check=1;
		} else {
			check=0;
		}
	} while(check);
	depart.emp.id=*empcount;
	employees[*empcount]=depart.emp;
	departments[*departcount]=depart;
	(*empcount)++;
	(*departcount)++;
	(*mancount)++;
}
//start add new employee
void AddNewEmployee(Employee employees[], char *empcount, department departments[], char *departcount) {
	char num = 0;
	if(*departcount==1) {
		printf("\nplease add department first");
	}
	else {
		printf("\nEnter number of Employees you want to add :");
		scanf("%d", &num);
		if(num<=0) {
			printf("put positive number in next time\n");
		} else {
			Employee emp;
			for (int i = 0; i < num; i++) {
				char check = 1;
				do {
					printf("Enter the department: ");
					scanf("%s", emp.department);
					check = 1;
					for (int i = 0; i < *departcount; i++) {
						if (strcmp(departments[i].name, emp.department) == 0) {
							check = 0;  // Department found, set check to 0
							break;
						}
					}
					if (check == 1) {
						printf("Enter an existing department\n");
					}
				} while (check);
				printf("Enter name of Employee: ");
				scanf(" %[^\n]",emp.name);
				getchar();
				printf("Enter address: ");
				scanf(" %[^\n]",emp.address);
				getchar();
				printf("Enter phone number :");
				scanf("%s", emp.phone);
				strcpy(emp.employeeType, "Employee");  // string copy

				check=0;
				do { //check the salary is positive
					printf("Enter the salary :");
					scanf("%f",&emp.salary);
					if(emp.salary<=0) {
						printf("enter positive number\n");
						check=1;
					} else {
						check=0;
					}
				} while(check);

				do { //check the age is positive
					printf("Enter the age :");
					scanf("%d",&emp.age);
					if(emp.age<=16 ||emp.age>60) {
						printf("make the age from 16 to 60 \n");
						check=1;
					} else {
						check=0;
					}
				} while(check);
				emp.id = *empcount;
				employees[*empcount] = emp;
				(*empcount)++;
				printf("==================\n");
			}
		}
	}
}
//start newdepartment
void newdepart(Employee employees[],char *empcount,department departments[],char *departcount,char *mancount) {
	department depart;
	char check = 0;
	do {//check this is new department
		printf("Enter the department :");
		scanf("%s",depart.name);
		getchar();
		// Check if the department exists
		for (int i = 0; i < *departcount; i++) {
			if (strcmp(departments[i].name, depart.name) == 0) {
				check = 1;
				printf("this department is exists enter new one\n");
				break;
			} else {
				check = 0;
			}
		}
	} while (check);
	printf("Enter name of manager: ");
	scanf(" %[^\n]", depart.emp.name);
	getchar();
	printf("Enter address: ");
	scanf(" %[^\n]", depart.emp.address);
	getchar();
	printf("Enter phone number :");
	scanf("%s",depart.emp.phone);
	strcpy(depart.emp.employeeType, "Manager");//string copy
	strcpy(depart.emp.department, depart.name);
	check=0;
	do { //check the salary is positive
		printf("Enter the salary :");
		scanf("%f",&depart.emp.salary);
		if(depart.emp.salary<=0) {
			printf("enter positive number\n");
			check=1;
		} else {
			check=0;
		}
	} while(check);

	do { //check the age is positive
		printf("Enter the age :");
		scanf("%d",&depart.emp.age);
		if(depart.emp.age<=16 || depart.emp.age>60) {
			printf("make the age from 17 to 60 \n");
			check=1;
		} else {
			check=0;
		}
	} while(check);
	depart.emp.id=*empcount;
	employees[*empcount]=depart.emp;
	departments[*departcount]=depart;
	(*empcount)++;
	(*departcount)++;
	(*mancount)++;
}
//END newdepartment

//start display employees
void dispemp(Employee employees[],char *empcount) {

	if (*empcount==1) {
		printf("There is no employees to display\n");
	} else {
		printf("Total employees: %d\n", *empcount);
		for(int i=0; i<*empcount; i++) {
			printf("\nName : %s",employees[i].name);
			printf("\nID : %d",employees[i].id);
			printf("\nPostion : %s",employees[i].employeeType);
			printf("\nDepartment : %s",employees[i].department);
			printf("\nSalary : %.2f",employees[i].salary);
			printf("\nAge : %d",employees[i].age);
			printf("\nPhone number : %s",employees[i].phone);
			printf("\nAddress : %s",employees[i].address);
			printf("\n================\n");
		}
	}
}
//start search by id
void searchByID(Employee employees[],char *empcount) {
	Employee emp;
	if(*empcount==1) {
		printf("No Employees To Search For");
	}
	else {
		char ID =0;
		int check=0;
		while(check==0) {
			printf("Search by ID : ");
			scanf("%d",&ID);
			if (ID>*empcount-1||ID<0) {
				printf("This ID isn't Existed.\n");
				check=0;
			}
			else {
				printf("\nName : %s",employees[ID].name);
				printf("\nID : %d",employees[ID].id);
				printf("\nPostion : %s",employees[ID].employeeType);
				printf("\nDepartment : %s",employees[ID].department);
				printf("\nSalary : %.2f",employees[ID].salary);
				printf("\nAge : %d",employees[ID].age);
				printf("\nPhone number : %s",employees[ID].phone);
				printf("\nAddress : %s",employees[ID].address);
				printf("\n================\n");
				check=1;
				break;
			}
		}

	}
}
//start display highest Salary Employee
void dispHighestSalary(Employee employees[],char *empcount) {
	if (*empcount==1) {
		printf("There is no employees to display\n");
	} else {
		Employee emp;
		float highestSalary =0;
		for(int i=0; i<*empcount; i++) {
			if(employees[i].salary>highestSalary) {
				highestSalary= employees[i].salary;
			}
		}
		printf("Employees with the highest salary: (%.2f)\n", highestSalary);
		for (int i = 0; i < *empcount; i++) {
			if (employees[i].salary == highestSalary) {
				printf("Name: %s\n", employees[i].name);
				printf("Salary: %.2f\n", employees[i].salary);
				printf("ID: %d\n", employees[i].id);
				printf("Position: %s\n", employees[i].employeeType);
				printf("Department: %s\n", employees[i].department);
				printf("Age: %d\n", employees[i].age);
				printf("Phone number: %s\n", employees[i].phone);
				printf("Address: %s\n", employees[i].address);
				printf("================\n");

			}
		}

	}
}
//start search by department
void searchByDep(Employee employees[],char *empcount,char *departcount,department departments[]) {
	if(*empcount==1) {
		printf("No Employees To Search For");
	}
	else {
		char check = 1;
		char searchdepartment[30];
		do {

			printf("Enter the department: ");
			scanf("%s",searchdepartment);
			check = 1;
			for (int i = 0; i < *departcount; i++) {
				if (strcmp(departments[i].name,searchdepartment) == 0) {
					check = 0;  // Department found, set check to 0
					break;
				}
			}
			if (check == 1) {
				printf("Enter an existing department\n");
			}
		} while (check);
		for (int i = 0; i < *empcount; i++) {
			if(strcmp(employees[i].department,searchdepartment)==0) {
				printf("Name: %s\n", employees[i].name);
				printf("Salary: %.2f\n", employees[i].salary);
				printf("ID: %d\n", employees[i].id);
				printf("Position: %s\n", employees[i].employeeType);
				printf("Department: %s\n", employees[i].department);
				printf("Age: %d\n", employees[i].age);
				printf("Phone number: %s\n", employees[i].phone);
				printf("Address: %s\n", employees[i].address);
				printf("================\n");
			}
		}
	}
}
//=======start company count ====
void compcounter(char *empcount,char *mancount) {
	if((*empcount)==0) {
		printf("the company is empty \n");
	} else if((*empcount)-(*mancount)==0) {
		printf("there is only %d managers and no employee\n",*mancount);
	} else {
		printf("we have in our company :%d member \n %d managers and %d employee\n",*empcount,*mancount,*empcount-*mancount);
	}
}
//============ start edit =========

//====end interface====
//===============int main===============
int main() {
	unsigned char departcount=0;//counter for department
	unsigned char empcount=0;//counter for employee
	unsigned char mancount=0;//counter for manager
	Employee employees[50];//array of emp
	department departments[50];//array of depart
	//infinity for loop
	owner(employees,&empcount,departments,&departcount,&mancount);
	while(1) {
		unsigned char choice=0;
		interface(&choice);
		switch(choice) {
		//start case 1
		case 1:
			AddNewEmployee(employees, &empcount,departments,&departcount);
			break;
		//start case 2
		case 2:
			dispemp(employees,&empcount);
			break;
		//start case 3
		case 3:
			searchByID(employees,&empcount);
			break;
		//start case 4
		case 4:
			dispHighestSalary(employees,&empcount);
			break;
		//start case 5    start
		case 5:
			newdepart(employees,&empcount,departments,&departcount,&mancount);
			break;
		//start case 6
		case 6:
			searchByDep(employees,&empcount,&departcount,departments);
			break;
		//start case 7
		case 7:
			compcounter(&empcount,&mancount);
			break;
		//start case 8
		case 8:
		    count_of_employee(employees,&empcount,departments,&departcount);
		     break;
            //start case 9
        case 9:
           edit_employe_information(employees,&empcount);
            break;
		//start case 10
		case 10:
			return 0;
			break;
		//start other case
		default:
			printf("Invalid choice. Please try again.\n");
			break;
		}
	}
	return 0;
}

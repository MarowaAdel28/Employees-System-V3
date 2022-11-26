/*

 * employee application version 3

 * using c/cpp programming [dynamic allocation,array,class,functions,conditions]

 * features new disply search by name delete by code exit

 * new:

 *     user can enter number of employee he want to add

 *	   user can increase #employee and add more without lost data

 *     code must be unique

 *     salary must be >= 5k

 *     bonus must be >= 0

 *     reduction must be < (0.5*salary)

 *	   user name must be contain only lower case letter

 * display:

 *     press next and last employee is displayed will disply first employee

 *     press prev and first employee is displayed will disply last employee

 *     press home then press disply will disply first employee

 * search

 *	   can search by any part of name in upper or lower case

 *	   will disply all matched employee

 *	   if there is no employee wilth this name will print message

 * delete

 *     enter the code of employee user want to delete

 *	   if found it will delete it

 *     if not found it will disply message

 * exit: will display thanking message

*/

#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>

#include<iostream.h>

int resSrcEmpCount=0,*srchList;

class Employee
{
	private:

		int code;

		char* name;

		float salary;

		float reduction;

		float bonus;

		int lenText;

		static int currentEmpNo,currentDisplyEmpNo,reqEmpNo,empArrSize;

	public:

		static void incrementEmpNo()
		{
			currentEmpNo++;
		}

		static void decrementEmpNo()
		{
			currentEmpNo--;
		}

		static int getEmpNo()
		{
			return currentEmpNo;
		}

		static void setDisplyEmpNo(int num)
		{
			currentDisplyEmpNo=num;
		}

		static void incrementDisplyEmpNo()
		{
			currentDisplyEmpNo++;
		}

		static void decrementDisplyEmpNo()
		{
			currentDisplyEmpNo--;
		}

		static int getDisplyEmpNo()
		{
			return currentDisplyEmpNo;
		}

		static int getEmpArrSize()
		{
			return empArrSize;
		}

		static void setEmpArrSize(int num)
		{
			empArrSize=num;
		}

		static int getReqEmpNo()
		{
			return reqEmpNo;
		}

		static void setReqEmpNo(int num)
		{
			reqEmpNo=num;
		}

		int getCode()
		{
			return code;
		}

		char* getName()
		{
			return name;
		}

		float getSalary()
		{
			return salary;
		}

		float getReduction()
		{
			return reduction;
		}

		float getBonus()
		{
			return bonus;
		}

		int getLen()
		{
			return lenText;
		}

		void setCode(int code)
		{
			this->code=code;
		}

		void setName(char *name,int lenText)
		{
			this->lenText=lenText;

			this->name=name;
		}

		void setSalary(float salary)
		{
			this->salary=salary;
		}

		void setReduction(float reduction)
		{
			this->reduction=reduction;
		}

		void setBonus(float bonus)
		{
			this->bonus=bonus;
		}

};

int Employee::currentEmpNo=0;

int Employee::currentDisplyEmpNo=0;

int Employee::reqEmpNo=0;

int Employee::empArrSize=0;

Employee *empArr; //create pointer of class employee

void drawRect(int st_pos_x,int st_pos_y,int width,int height);

void drawText(int st_pos_x,int st_pos_y,int text_len,char text[],char clor[]);

void drawNoEmpMeg();

void drawFullArrMeg();

void setArrSize();

void resetArrSize();

void createArrOfEmp();

void colorHomeButtons(int currentposY);

int moveCurrentPositionY(int currentposY);

void executeEnterKey(int currentposY);

int moveCurrentPositionX(int positionX);

void colorDisplyButtons(int positionX);

void displyNextPrevEmp(int positionX);

void displyNextPrevEmp(int positionX);

int searchByName(char name[]);

void displyNextPrevForEmpSrch(int positionX,int index);

void displayEmpOfSearch(int emp_num,int index);

void drawResultOfSearchPage(char name[]);

void drawSearchPage();

void drawEmpInfo(int emp_num);

void runHomePage();

void drawExit();

int iscodeunique(int emp_num,int code);

int getUserCode(int emp_num);

char* getUserName();

float getUserSalary();

float getUserBonus();

float getUserReduction(float salary);

void addNewEmp(int emp_num);

void displayEmp(int emp_num);

void drawHomePage();

void drawHomeButton();

void drawNextButton();

void drawPrevButton();

void drawNewButton();

void drawDisplyButton();

void drawExitButton();

void drawDeleteButton();

void drawSearchButton();

void drawDeletePage();

int searchByCode(int code);

int deleteEmpByCode(int code);

void drawResultOfDeletePage(int code);

int main()
{

	drawHomePage();

	getch();

	return 0;

}

void setArrSize()
{
	int size=0;

	while(1)
	{

		system("cls");

		drawRect(5,3,70,21);

		drawText(5,4,70,"ITI System","GREEN");

		drawText(5,6,70,"please enter numbers of employees you want to enter ",

		"BLUE");

		drawRect(35,10,10,3);

		gotoxy(40,11);

		scanf("%d",&size);

		if (size>0) break;

		drawText(5,13,70,"please enter valid number of employees and greater than 0",

		"BLUE");

		drawText(5,14,70,"please press enter to continue ",

		"BLUE");

		getch();

		flushall();
	}

	Employee::setEmpArrSize(size);
}
void createArrOfEmp()
{
	char arrow;

	setArrSize();

	empArr=new Employee[Employee::getEmpArrSize()]; //create array of objects

	if(empArr==NULL)

	{
		printf("\n no space ");

		return;

	}
	drawRect(35,13,10,3);

	gotoxy(40,14);

	drawText(35,13,10,"Enter","GREEN");

	while(1)
	{
		flushall();

		arrow=getch();

		if(arrow==13) break;

	}

	addNewEmp(Employee::getEmpNo());
}


void drawHomePage(){

	system("cls");

	//start position x, start position y, width ,height

	drawRect(20,2,40,23);       //home page

	drawRect(30,5,20,3);        // new button

	drawRect(30,9,20,3);        // display button

	drawRect(30,13,20,3);      // delete button

	drawRect(30,17,20,3);      // search button

	drawRect(30,21,20,3);      // exit button

	drawText(30,2,20,"ITI System","GREEN");

	drawText(30,5,20,"New","GREEN");

	drawText(30,9,20,"Display","BLUE");

	drawText(30,13,20,"Delete","GREEN");

	drawText(30,17,20,"Search","BLUE");

	drawText(30,21,20,"Exit","BLUE");

	gotoxy(40,6); // in the middle of first rect new button

	runHomePage();
}

void colorHomeButtons(int positionY)
{
	int currentPosY=positionY;

	if(currentPosY ==6) drawNewButton();

	else if (currentPosY==10) drawDisplyButton();

	else if (currentPosY==14) drawDeleteButton();

	else if (currentPosY==18) drawSearchButton();

	else if (currentPosY==22) drawExitButton();
}

int moveCurrentPositionY(int positionY)
{
	char arrow;

	int currentPosY=positionY;

	arrow=getch();

	if(arrow==72)  //go to up
	{

		if (currentPosY==6) currentPosY=22;

		else currentPosY -=4;

	}

	else if(arrow==80) //go to down
	{
		if(currentPosY == 22) currentPosY=6;

		else currentPosY+=4;

	}
	gotoxy(wherex(),currentPosY);

	return currentPosY;
}

void executeEnterKey(int positionY)
{
	int currentPosY=positionY;

	if(currentPosY==6)   //add new employee

	{
		if(Employee::getEmpNo()==0) createArrOfEmp(); //create array of employee

		else if(Employee::getEmpNo()>Employee::getEmpArrSize()-1) drawFullArrMeg();//no space to add new employee

		else addNewEmp(Employee::getEmpNo());
	}

	else if(currentPosY==10)// display employee

	{
		if (Employee::getEmpNo()==0) //if there is no employee to disply
		{
			drawNoEmpMeg();

			drawHomePage();
		}

		else
		{
			Employee::setReqEmpNo(0); //to print always first employee user disply

			displayEmp(Employee::getReqEmpNo());
		}
	}

	else if(currentPosY==14) drawDeletePage();

	else if(currentPosY==18) drawSearchPage();

	else if(currentPosY==22) drawExit();

}


void runHomePage()
{
	int currentPosY=wherey();

	char arrow;

	while(1)

	{
		colorHomeButtons(currentPosY);

		flushall();

		arrow=getch();

		if(arrow==NULL) //press on arrows key

			currentPosY=moveCurrentPositionY(currentPosY);

		else if (arrow ==13) //press on enter
		{
			executeEnterKey(currentPosY);

			break;  //when press enter mean another page will disply so break from home page
		}
	}
}

void drawDeletePage()
{
	int code;

	system("cls");

	drawRect(10,3,60,19);

	drawText(30,4,20,"ITI System","GREEN");

	drawText(30,8,20,"please enter the employee code which you want to delete","GREEN");

	drawRect(30,10,20,3);

	gotoxy(35,11);

	flushall();

	cin>>code;

	drawResultOfDeletePage(code);
}

void drawResultOfDeletePage(int code)
{
	int res=deleteEmpByCode(code);

	if (!res) drawText(30,14,20,"employee has this code deleted successfully","GREEN");

	else
	{
		drawText(30,14,20,"there is no employee with this code!","RED");
	}
	drawText(30,16,20,"please press any key to back to home","GREEN");

	getch();

	drawHomePage();
}

int deleteEmpByCode(int code)
{
	int index=searchByCode(code);

	if(index==-1) return -1; //not found this code

	for(int i=0;i<Employee::getEmpNo();i++)
	{
		if(i>=index) //shift date to override employee data

			empArr[i]=empArr[i+1];
	}

	Employee::decrementEmpNo();

	return 0;
}

int searchByCode(int code)
{
	for (int i=0;i<Employee::getEmpNo();i++)
	{
		if(code==empArr[i].getCode()) return i;
	}
	return -1;
}

void drawSearchPage()
{
	char name[50];

	system("cls");

	drawRect(10,5,60,15);

	drawText(30,6,20,"ITI System","GREEN");

	drawText(30,8,20,"please enter the name which you want to search for","GREEN");

	drawRect(30,10,20,3);

	gotoxy(35,11);

	gets(name);

	for(int i=0;i<strlen(name);i++)
	{
		if(name[i]>=65 && name[i]<=90) name[i]=name[i]+32;

	}

	drawResultOfSearchPage(name);
}


int searchByName(char n[])
{
	resSrcEmpCount=0;

	srchList=new int[Employee::getEmpNo()-1];

	for (int i=0;i<Employee::getEmpNo();i++)
	{
		int len=empArr[i].getLen();

		char *ptr=NULL,name[50]={'0'};

		ptr=empArr[i].getName();//pointer point to name

		for (int j=0;j<len;j++) name[j]=ptr[j];

		if(strstr(name,n) !=NULL) //matching text
		{
			 srchList[resSrcEmpCount++]=i;

		}
	}

	if(resSrcEmpCount) return 1;

	return 0;
}

void drawResultOfSearchPage(char n[])
{

	int emp_num,i=0;

	emp_num=searchByName(n);

	if (!emp_num)
	{

		drawText(25,10,30,"sorry! there is no employee with this name","RED");

		drawText(25,13,30,"press enter key to back to home","BLUE");

		getch();

		drawHomePage();
	}

	else

		displayEmpOfSearch(*(srchList+i),i);
}

void displayEmpOfSearch(int emp_num,int index)
{

	int positionX;

	char arrow;

	drawEmpInfo(emp_num);

	positionX=40;

	while(1)
	{
		colorDisplyButtons(positionX);

		flushall();

		arrow=getch();//press arrow keys to move to spacific button

		if(arrow==NULL) positionX=moveCurrentPositionX(positionX);

		else if (arrow ==13) //press enter on specific button
		{
			 displyNextPrevForEmpSrch(positionX,index);

			 break;

		}
	}
}

void displyNextPrevForEmpSrch(int positionX,int index)
{
	int reqNo;

	if(positionX == 20) //press previou button
	{

		 // get previous employee

		index --;

		if(index<0) index=resSrcEmpCount-1;

		reqNo=*(srchList+index);

		displayEmpOfSearch(reqNo,index);

	}

	else if (positionX == 40)

	{ //press menu button

		drawHomePage();
	}

	else if (positionX == 60) //press next button
	{
		index++;

		if(index==resSrcEmpCount) index=0;

		reqNo=*(srchList+index);

		displayEmpOfSearch(reqNo,index);

	}
}


void drawNoEmpMeg()
{
	char arrow;

	system("cls");

	drawRect(10,5,60,15);//screen app width=40 height=15

	drawText(30,6,20,"ITI System","GREEN");

	drawText(25,10,30,"must add all employees you enter their size!","RED");

	drawText(25,12,30,"Please add the rest of employees then you can disply them!","GREEN");

	drawText(25,13,30,"press enter key to back to home","");

	arrow=getch();

	if (arrow==13) return;

}


void drawFullArrMeg()
{

	system("cls");

	drawRect(5,5,70,15);

	drawText(5,6,70,"ITI System","GREEN");

	drawText(5,7,70,"Array is full!","RED");

	drawText(5,8,70,"please enter numbers of employees you want to add again",

	"BLUE");

	resetArrSize();


}

void resetArrSize()
{
	int size;

	Employee *tempArr;

	while(1)
	{

		drawRect(35,10,10,3);

		gotoxy(40,11);

		printf("   ");

		gotoxy(40,11);

		scanf("%d",&size);

		if(size>Employee::getEmpArrSize()) break;

		drawText(15,14,50,"must enter new size more than original size!","RED");

		drawText(15,15,50,"press enter to continue!","RED");

		flushall();

		getch();

		gotoxy(15,15);

		printf("                                                     ");

		gotoxy(15,16);

		printf("                                                     ");
	}

	tempArr=new Employee[size];

	for (int i=0;i<Employee::getEmpArrSize();i++) tempArr[i]=empArr[i];

	Employee::setEmpArrSize(size);

	delete []empArr;

	empArr=tempArr;

	addNewEmp(Employee::getEmpNo());
}

int iscodeunique(int emp_num,int code)
{
	int i;

	for (i=0;i<emp_num;i++)//start from first employee to last one entered
	{
		if (code == empArr[i].getCode()) return 1;//duplicated code so refuse it
	}
	return 0;
}

int getUserCode(int emp_num)
{

	int code;

	while (1)
	{

		system("cls");

		drawRect(5,3,70,21);

		drawText(5,4,70,"ITI System","GREEN");

		drawText(10,6,20,"Emplyee_ID: ","BLUE");

		gotoxy(35,7);

		scanf("%d",&code);

		if(iscodeunique(emp_num,code)==0 && code>0) return code; //this code is unique

						  //so accept it and break to enter the rest of info


		drawText(15,8,50,"please enter uniqu code! To continue press enter"

		,"RED");

		getch();
	}

}

float getUserSalary()
{
	float salary;

	while(1)
	{

		drawText(10,10,20,"Employee_Salary: ","BLUE");

		gotoxy(35,11);

		printf("                ");

		gotoxy(35,11);

		scanf("%f",&salary);

		if(salary>=5000) return salary;

		drawText(15,13,50,

		"can't enter employee'salary less than 5k! To continue press enter"

		,"RED");

		getch();

		gotoxy(6,14);

		printf("                                                                   ");

	}

}

float getUserBonus()
{
	float bonus;

	while(1)
	{
		drawText(10,12,20,"Employee_Bonus: ","BLUE");

		gotoxy(35,13);

		printf("                ");

		gotoxy(35,13);

		scanf("%f",&bonus);

		if(bonus>=0) return bonus;

		drawText(15,14,50,"can't enter negative bonus! To continue press enter"

		,"RED");

		getch();

		gotoxy(6,15);

		printf("                                                                    ");
	}

}

float getUserReduction(float salary)
{

	float reduction;

	while(1)
	{

		drawText(10,15,20,"Emplyee_Reduction: ","BLUE");

		gotoxy(35,16);

		printf("                ");

		gotoxy(35,16);

		scanf("%f",&reduction);

		if(reduction>=0 && reduction<0.5*salary) return reduction;

		drawText(30,16,20,"can't enter reduction negative!"

		,"RED");

		drawText(30,17,20,"or more than the half of employee salary!","RED");

		drawText(30,18,20,"To continue press enter","RED");

		getch();

		gotoxy(6,17);

		printf("			                                            ");

		gotoxy(6,18);

		printf("                                                        ");

		gotoxy(6,19);

		printf("                                                        ");
	}


}

char* getUserName()
{
	int text_len,up=0;

	char *ptr_name;

	drawText(10,8,20,"Emplyee_Name: ","BLUE");

	while(1)
	{
		ptr_name=new char[50];

		gotoxy(35,9);

		flushall();

		gets(ptr_name);

		text_len=strlen(ptr_name);

		for (int i=0;i<text_len;i++)
		{
			if((ptr_name[i]<97 && ptr_name[i]>33) || ptr_name[i]>122)
			{
				up=1;

				break;

			}
		}

		if(!up) break; //valid name

		up=0;

		drawText(10,9,60,"must enter char only in lower case! press any key to continue","RED");

		//drawText(10,10,80,"press any key to continue","GREEN");

		getch();

		gotoxy(10,10);

		cout<<"                                                                ";

		gotoxy(35,9);

		cout<<"                          ";

		delete ptr_name;
	}

	return ptr_name;
}

void addNewEmp(int emp_num)
{
	int code;

	float salary,reduction,bonus;

	char arrow,*ptr_name;

	code=getUserCode(emp_num);

	ptr_name=getUserName();

	int text_len=strlen(ptr_name);

	salary=getUserSalary();

	bonus=getUserBonus();

	reduction=getUserReduction(salary);

	gotoxy(40,21);

	drawRect(35,20,10,3);

	drawText(35,20,10,"Save","GREEN");

	while (1)
	{

		flushall();

		arrow=getch();

		if(arrow==13) //press enter to save data
		{
			empArr[emp_num].setCode(code);

			empArr[emp_num].setName(ptr_name,text_len);

			empArr[emp_num].setSalary(salary);

			empArr[emp_num].setReduction(reduction);

			empArr[emp_num].setBonus(bonus);

			empArr[emp_num].incrementEmpNo();

			drawHomePage();

			break;

		}
	}
}

void drawEmpInfo(int emp_num)
{
	char *ptr,name[50];

	double netSalary;

	netSalary=empArr[emp_num].getSalary()+empArr[emp_num].getBonus()

	-empArr[emp_num].getReduction();

	system("cls");

	drawRect(10,4,60,18);

	gotoxy(40-strlen("EmployeeNo    ")/2,6);

	textcolor(GREEN);

	cprintf("EmployeeNo %d",emp_num+1);

	drawText(10,8,25,"Emplyee_Name: ","BLUE");

	gotoxy(40,9);

	textcolor(GREEN);

	ptr=empArr[emp_num].getName();

	for (int i=0;i<empArr[emp_num].getLen();i++) cprintf("%c",*(ptr+i));

	drawText(10,10,25,"Emplyee_ID: ","BLUE");

	gotoxy(40,11);

	textcolor(GREEN);

	cprintf("%d",empArr[emp_num].getCode());

	drawText(10,12,25,"Employee_Net_Salary: ","BLUE");

	gotoxy(40,13);

	textcolor(GREEN);

	cprintf("%f",netSalary);
}

void colorDisplyButtons(int positionX)
{

	if (positionX == 20) drawPrevButton();

	else if (positionX == 40) drawHomeButton();

	else if (positionX == 60) drawNextButton();
}

int moveCurrentPositionX(int positionX)
{
	char arrow;

	arrow=getch();

	if(arrow==77) //go to right
	{
		if(positionX !=60) positionX +=20;

		else positionX =20;

	}
	else if(arrow == 75) //go to left
	{
		if (positionX !=20) positionX -=20;

		else positionX =60;
	}

	return positionX;
}

void displyNextPrevEmp(int positionX)
{
	if(positionX == 20) //press previou button
	{

		Employee::setReqEmpNo(Employee::getDisplyEmpNo()-1); // get previous employee

		if (Employee::getReqEmpNo() <0) Employee::setReqEmpNo(Employee::getEmpNo()-1);  //get last employee

		displayEmp(Employee::getReqEmpNo());

	}

	else if (positionX == 40)

	{ //press menu button

		drawHomePage();
	}

	else if (positionX == 60) //press next button
	{
		Employee::setReqEmpNo(Employee::getDisplyEmpNo()+1);

		if(Employee::getReqEmpNo() >= Employee::getEmpNo()) Employee::setReqEmpNo(0);//get first employee

		displayEmp(Employee::getReqEmpNo());

	}

}

void displayEmp(int emp_num)
{

	int positionX;

	char arrow;

	Employee::setDisplyEmpNo(emp_num);

	drawEmpInfo(emp_num);

	positionX=40;

	while(1)
	{
		colorDisplyButtons(positionX);

		flushall();

		arrow=getch();

		if(arrow==NULL) positionX=moveCurrentPositionX(positionX);

		else if (arrow ==13) //press enter
		{
			 displyNextPrevEmp(positionX);

			 break;

		}
	}
}

void drawRect(int st_pos_x,int st_pos_y,int width,int height)
{
	int i=0,j=0,startX=st_pos_x;

	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			gotoxy(st_pos_x ++,st_pos_y);


			if(i==0 || i==height-1) printf("* ");

			else if(j==0||j==width-1) printf("* ");

		}
		st_pos_y++;

		st_pos_x=startX;
	}
}

void drawText(int st_pos_x,int st_pos_y,int text_len,char text[],char clor[])
{
	int strLen=strlen(text);

	int startPosX=(text_len-strLen)/2;

	gotoxy(st_pos_x+startPosX,st_pos_y+1);


	if(strcmp(clor,"BLUE")==0) textcolor(BLUE);

	else if(strcmp(clor,"GREEN")==0) textcolor(GREEN);

	else if(strcmp(clor,"RED")==0) textcolor(RED);

	cprintf("%s",text);

}

void drawHomeButton()
{
	drawRect(35,18,10,3);

	drawText(35,18,10,"Home","GREEN");

	drawRect(15,18,10,3);

	drawText(15,18,10,"prev","BLUE");

	drawRect(55,18,10,3);

	drawText(55,18,10,"Next","BLUE");
}
void drawNextButton()
{
	drawRect(35,18,10,3);

	drawText(35,18,10,"Home","BLUE");

	drawRect(15,18,10,3);

	drawText(15,18,10,"prev","BLUE");

	drawRect(55,18,10,3);

	drawText(55,18,10,"Next","GREEN");
}
void drawPrevButton()
{
	drawRect(35,18,10,3);

	drawText(35,18,10,"Home","BLUE");

	drawRect(15,18,10,3);

	drawText(15,18,10,"prev","GREEN");

	drawRect(55,18,10,3);

	drawText(55,18,10,"Next","BLUE");
}

void drawExit()
{
	system("cls");

	drawRect(20,5,40,15);

	drawRect(30,9,20,9);

	drawText(20,6,40,"ITI System","GREEN");

	drawText(30,10,20,"Thank you! ","BLUE");

	drawText(30,13,20," for your time ","BLUE");

}

void drawNewButton()
{
	drawText(30,5,20,"New","GREEN");

	drawText(30,9,20,"Display","BLUE");

	drawText(30,13,20,"Delete","BLUE");

	drawText(30,17,20,"Search","BLUE");

	drawText(30,21,20,"Exit","BLUE");
}

void drawDisplyButton()
{
	drawText(30,5,20,"New","BLUE");

	drawText(30,9,20,"Display","GREEN");

	drawText(30,13,20,"Delete","BLUE");

	drawText(30,17,20,"Search","BLUE");

	drawText(30,21,20,"Exit","BLUE");
}

void drawExitButton()
{
	drawText(30,5,20,"New","BLUE");

	drawText(30,9,20,"Display","BLUE");

	drawText(30,13,20,"Delete","BLUE");

	drawText(30,17,20,"Search","BLUE");

	drawText(30,21,20,"Exit","GREEN");
}
void drawDeleteButton()
{
	drawText(30,5,20,"New","BLUE");

	drawText(30,9,20,"Display","BLUE");

	drawText(30,13,20,"Delete","GREEN");

	drawText(30,17,20,"Search","BLUE");

	drawText(30,21,20,"Exit","BLUE");
}

void drawSearchButton()
{
	drawText(30,5,20,"New","BLUE");

	drawText(30,9,20,"Display","BLUE");

	drawText(30,13,20,"Delete","BLUE");

	drawText(30,17,20,"Search","GREEN");

	drawText(30,21,20,"Exit","BLUE");
}



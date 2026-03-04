#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void LowerStr(string& str);
void DisplayTasks(const vector<string>& taskList);
void EditM(vector<string>& taskList)
{
	int nte; //number of tasks to edit
	cout << "Number Of Tasks To Edit :-  ";
	cin >> nte;
	if (nte == 0)
	{
		cout << "No Tasks To Edit";
	}
	else if (nte > 0 && nte <= (int)taskList.size())
	{
		vector<int> EditTN;
		cout << "Task Number(s) :" << endl;
		for (int edl = 0; edl < nte; edl++)
		{
			int et;
			cin >> et;
			if (et <= 0)
			{
				cerr << "Invalid. Task does not exist";
			}
			else
			{
				EditTN.push_back(et);
			}
		}
		cout << "Enter New Description(s) :" << endl;
		cin.ignore();
		for (int ndl = 0; ndl < (int)EditTN.size(); ndl++)
		{
			string tasknew;
			getline(cin, tasknew);
			taskList.at(EditTN.at(ndl) - 1) = tasknew;
		}
		cout << "Successfully Edited Task(s)!" << '\n';
		DisplayTasks(taskList);
	}
	else if (nte > (int)taskList.size())
	{
		cerr << "Error. " << nte << " Is Greater Than The Number Of Tasks In To-Do List";
	}
	else
	{
		cerr << "Invalid Input, You May Have A Typo";
	}
}
void TickM(vector<string>& taskList)
{
	int ttn; //task tickoff number
	cout << "Task Number :-  ";
	cin >> ttn;
	if (ttn >= 1 && ttn <= (int)taskList.size())
	{
		string ttc; //tasktickoffconfirmation
		cout << "Confirm(Yes/No)? :-  ";
		cin >> ttc;
		LowerStr(ttc);
		if (ttc == "yes")
		{
			taskList.erase(taskList.begin() + (ttn - 1));
		cout << "Task Ticked Off!" << '\n';
		DisplayTasks(taskList);
		}
		else if (ttc == "no")
		{
			cout << "Ok";
		}
		else
		{
			cerr << "Invalid Input, You May Have A Typo";
		}
		
	}
	else if (ttn - 1 == 0)
	{
		cerr << "Error, Task " << ttn << " Does Not Exist";
	}
	else
	{
		cerr << "Invalid Input, You May Have A Typo";
	}
}
void AddM(vector<string>& taskList)
{
	int nnt;//number of new tasks
	cout << "Number Of New Tasks :-  ";
	cin >> nnt;
	if (nnt == 0)
	{
		cout << "No Tasks To Be Added";
	}
	else if (nnt > 0)
	{
		cout << "Enter New Task(s) :" << endl;
		cin.ignore();
		for (int ntl = 0; ntl < nnt; ntl++) //new task loop
		{
			string newTask;
			getline(cin, newTask);
			taskList.push_back(newTask);
		}
		cout << "Successfully Added New Task(s)!" << '\n';
		DisplayTasks(taskList);
	}
	else 
	{
			cerr << "Invalid Input, You May Have A Typo";
	}
}
void ClearM(string file, vector<string>& taskList)
{
		string tcc; //task clear confirmation
		cout << "Confirm(Yes/No)? :-  ";
		cin >> tcc;
		LowerStr(tcc);
		if (tcc == "yes")
		{
			ofstream tasks(file, ios::trunc);
			tasks << "";
			tasks.close();
			taskList.clear();
		    cout << "Task List Cleared!";
		}
		else if (tcc == "no")
		{
			cout << "Ok";
		}
		else
		{
			cerr << "Invalid Input, You May Have A Typo";
		}
}
	void LowerStr(string& str)
	{
		for (char& c : str)
		{
			c = tolower(c);
		}
	}
	void Help()
	{
		ifstream help("help.txt");
		string line;
		while (getline(help, line))
		{
			cout << line << endl;
		}
		help.close();
	}
	void DisplayTasks(const vector<string>& taskList)
	{
		if ((int)taskList.size() == 0)
		{
			cout << "Empty, No Tasks" << '\n';
		}
		else 
		{
			for (int dtl = 1; dtl <= (int)taskList.size(); dtl++)
		{ //display task loop
			cout << dtl << ".  " << taskList.at(dtl - 1) << endl;
		}
		}
	}
	void ModeSelex(string input, string filen, vector<string>& taskList)
	{
		if (input == "edit")
		{
			EditM(taskList);
		}
		else if (input == "tickoff")
		{
			TickM(taskList);
		}
		else if (input == "add")
		{
			AddM(taskList);
		}
		else if (input == "more")
		{
			string moreMO;
			cout << "More(Clear) :-  ";
			cin >> moreMO;
			LowerStr(moreMO);
			if (moreMO == "clear") 
			{
				ClearM(filen, taskList);
			}
			else
			{
				cerr << "Please Check For Typos";
			}
		}
		else
		{
			cerr << "Please Check For Typos";
		}
	}

		int main()
		{
			cout << "TO-DO LIST" << endl
				 << "---------------" << endl
				 << endl;
			bool appRun = true, appEntry = true;
			string spo;
			while (appEntry)
			{
				cout << "Type Start/Help/Quit :-  "; //Start or Help Option
				cin >> spo;
				LowerStr(spo);
				if (spo == "start")
				{
					cout << "Program Starting" << '\n';
					appEntry = false;
				}
				else if (spo == "help")
				{
					Help();
				}
				else if (spo == "quit")
				{
					cout << "App/Program Terminating.";
					return 0;
				}
				else
				{
					cout << "Invalid. You may have mistyped" << endl;
				}
			}
            int taskNum;
			string task;
			vector<string> taskList;
			ifstream file("tasklist.txt");
			while (getline(file, task))
			{
				taskList.push_back(task);
			}
			file.close();
			cout << "Enter Number of Tasks Today :-  ";
			cin >> taskNum;
			if (taskNum == 0)
			{
				cout << endl
					 << "No Tasks. Reading tasks in storage(Wont appear if none exist). " << endl;
			}
			else if (taskNum > 0)
			{
				cout << "Enter Tasks :" << endl
					 << endl;
				cin.ignore();
				for (int el = 0; el < taskNum; el++)
				{ // entry loop
					getline(cin, task);
					taskList.push_back(task);
				}
			}
			else
			{
				cout << "Negative Number of Tasks is Invalid, Rerun.";
				return 0;
			}
			while (appRun)
			{
				cout << endl
					 << "Display Tasks(Yes/No)?  ";
				string DTO, MO, loopquery;
				cin >> DTO; //Display Task Option
				LowerStr(DTO);
				if (DTO == "yes")
				{
					DisplayTasks(taskList);
				}
				else if (DTO == "no")
				{
					cout << "Ok" << endl;
				}

				else
				{
					cout << "Please Check For Typos." << endl;
				}

				cout << "Choose Mode(Edit, TickOff, Add, More) :-  ";
				cin >> MO; //Mode Option
				LowerStr(MO);
				ModeSelex(MO, "tasklist.txt", taskList);

				cout << endl
					 << "Exit App/Program?  ";
				cin >> loopquery;
				LowerStr(loopquery);
				if (loopquery == "yes")
				{
					ofstream file("tasklist.txt");
					for (string fotask : taskList)
					{
						file << fotask << endl;
					}
					appRun = false;
				}
				else if (loopquery == "no")
				{
					cout << "App/Program Will Run." << endl << endl << endl;
				}
				else
				{
					cout << "Please Check For Typos" << endl << "App/Program Will Run.";
				}
			}
		}
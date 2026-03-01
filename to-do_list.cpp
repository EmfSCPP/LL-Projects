#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    cout << "TO-DO LIST" << endl << "---------------" << endl << endl;
    bool appRun = true;
    string task;
    int taskIndVec, newTaskNum, taskNum; // taskIndVec for line 41 input
    vector<string> taskList;
    ifstream file("tasklist.txt");
    while (getline(file, task)) {
    	taskList.push_back(task);
    }
    file.close();
    cout << "Enter Number of Tasks Today :  ";
    cin >> taskNum;
    if (taskNum == 0) {
        cout << endl << "No Tasks. Reading tasks in storage(Wont appear none exist). " << endl;
    }
    else if (taskNum > 0){
    cout << "Enter Tasks :" << endl << endl;
    cin.ignore();
    for (int el = 0; el < taskNum; el++) {   // entry loop
        getline(cin, task);
        taskList.push_back(task);
    }
    }
    else {
        cout << "Negative Number of Tasks is Invalid, Rerun.";
        return 0;
    }
    while(appRun) {
    cout << endl << "Display Tasks?  ";
    string DTO, MO, TTC, TEC, DET, loopquery; 
    cin >> DTO; //Display Task Option
    for (char& dtoc : DTO) {
    	dtoc = tolower(dtoc);
    }
    if (DTO == "yes") {
        for (int dty = 0; dty < (int)taskList.size(); dty++) {
            cout << dty + 1 << ".  " << taskList.at(dty) << endl;
        }
    }
    else if (DTO == "no") {
        cout << "Ok" << endl;
    }
    
    else {
        cout << "Please Check For Typos." << endl;
        
    }
    
    cout << "Choose Mode(Edit, TickOff, Add) :-  ";
    cin >> MO;  //Mode Option
    for (char& moc : MO) {
    	moc = tolower(moc);
    }
    if (MO == "edit") {
        cout << endl << "Choose Task Number :-  ";
        cin >> taskIndVec;
        if (taskIndVec > 0 && taskIndVec <= (int)taskList.size()) {
        int RI = taskIndVec - 1;
        cout << taskList.at(RI) << endl << "Do you want to edit this task?  ";
        cin >> TEC; //Task Edit Confirmation
        for (char& tecc : TEC) {
        	tecc = tolower(tecc);
        }
        if (TEC == "yes") {
            cout << "Enter New Description :-  ";
            cin.ignore();
            getline(cin, taskList.at(RI));
            cout << "Edited Succesfully! Would You Like To Display The Edited Task?  ";
            cin >> DET; //Display Edited Task
            for (char& detc : DET) {
            	detc = tolower(detc);
            }
            if (DET == "yes") {
                cout << taskList.at(RI) << endl << "Done";
            }
            else if (DET == "no") {
                cout << "Ok";
            }
            else {
                cout << "Please Check For Typos";
            }
          }
        else if (TEC == "no") {
            cout << "Ok";
        }
        else {
            cout << "Please Check For Typos";
        }
        }      
        else {
            cout << "Error, Task " << taskIndVec << " Does Not Exist";
        }
    }
     else if (MO == "tickoff") {
         cout << endl << "Choose Task Number :-  ";
         cin >> taskIndVec;
         if (taskIndVec > 0 && taskIndVec <= (int)taskList.size()) {
         int RI = taskIndVec - 1;
         cout << taskList.at(RI) << endl << "Do you want tick off this task?  ";
         cin >> TTC; //Task Tickoff Confirmation
         for (char& ttcc : TTC) {
         	ttcc = tolower(ttcc);
         }
         if (TTC == "yes") {
             taskList.erase(taskList.begin() + RI);
             cout << "Task Ticked Off!";
         }
         else if (TTC == "no") {
             cout << "Ok";
         }
         else {
             cout << "Please Check For Typos";
         }
         }
         else {
             cout << "Error, Task  " << taskIndVec << " Does Not Exist";
         }
     }
        else if (MO == "add") {
            cout << "Enter Number Of New Tasks :-  ";
            cin >> newTaskNum;
            cout << "Enter New Tasks" << endl;
            cin.ignore();
            for (int ntql = 0; ntql < newTaskNum; ntql++) {   //new task query loop
                string newtask;
                getline(cin, newtask);
                taskList.push_back(newtask);
            }
            cout << "Succesfully Added New Task(s)!";
        }
     else {
         cout << "Please Check For Typos";
     }
        
        cout << endl << "Exit App/Program?  ";
        cin >> loopquery;
        for (char& lpc : loopquery) {
        	lpc = tolower(lpc);
        }
        if (loopquery == "yes") {
            ofstream file("tasklist.txt");
            for (string fotask : taskList) {
            	file << fotask << endl;
            }
            appRun = false;
        }
        else if (loopquery == "no") {
            cout << "App/Program Will Run." << endl << endl << endl;
        }
        else {
            cout << "Please Check For Typos" << endl << "App/Program Will Run.";
        }
    }
}
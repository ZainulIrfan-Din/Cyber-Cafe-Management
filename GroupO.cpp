#include <iostream>
#include <iomanip> //for setprecision (two decimals point)
#include <windows.h> //for delaying output (only works with windows)
#include <fstream> //for file input output
#include <string> //for string use
#include <cstring> //for search record

using namespace std;
		
void mainmenu()													//function for mainmenu
{			
	cout << "CYBER CAFE MANAGEMENT SYSTEM" << endl;
	cout << endl;
	
	cout << "1. Master Entry" << endl;
	cout << "2. Cafe Management" << endl;
	cout << "3. Exit" << endl;
	
	cout << endl;
}

int main()
{
						//declaration
	
	int choice, m_opt, c_opt, b_opt, ch_opt, manage, no, memper, cID, offset, compIDupd, memperupd, memperupdate;
	char resp, back[10], manualmember, entry, memlogin;
	float charge, manualcharge;
	double manuallogin, manuallogout, manualhours;
	
	string nameupd, emelupd, noupd, compNamebaru, updcom;
	string upd_name;
	string search, csearch;
	string name;
	string emel;
	string cname;
	string delmem;
	string delcom;
	string ren_name;
	
	string username = " ";		//for login
	string password = " ";	
	
	bool loginSuccess = false; //for true or false for login homepage
	
	int ctr = 1, cnt = 1;
	
do
{	
	cout << "CYBER CAFE MANAGEMENT SYSTEM" << endl << endl;
	
	cout << "FOR AUTHORIZED USER ONLY" << endl;					//login page
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	
	system("CLS");													//clear screen
	cout << "CYBER CAFE MANAGEMENT SYSTEM" << endl << endl;		//show * at password
	
	cout << "FOR AUTHORIZED USER ONLY" << endl;
	cout << "Username: " << username << endl;
	cout << "Password: " << "*****" << endl;
	Sleep(450);											//delay output for 450 miliseconds
		
	if ((username == "ADMIN") && (password == "ADMIN"))	 //pre-defined login 
{	
	loginSuccess = true;				//if username and password true, bool will changed to true
	
	system("CLS");
	
	cout << "CYBER CAFE MANAGEMENT SYSTEM" << endl << endl;
	cout << "LOGGING IN..." << endl;
	Sleep(700);
	
	system("CLS");
	
	cout << "CYBER CAFE MANAGEMENT SYSTEM" << endl << endl;
	cout << "LOGGED IN SUCCESSFULLY" << endl;
	Sleep(700);
	
	system("CLS");	
	
	int valid;									//variable for error checking
	
	do
	{
	retmain: 									//benchmark to return here for return option
	mainmenu();
	
	valid = 0;						//default value
	
	cout << "Choice: ";
	cin >> choice;
	
	if (cin.fail())						//error checking
		{	
			cin.clear();				//clears the error so future i/o work correctly
			cin.ignore();				//skip to next newline
			
			cout << endl;
			cout << "Error" << endl << endl;
			Sleep(450);
			system("CLS");
			
			valid=1;			//if fail, valid changed to 1
		}
				
	} while(valid ==1);	
	
	system("CLS");
	
	switch (choice)
	{
		case 1:
			{	
				cout << "MASTER ENTRY" << endl << endl;
				cout << "Member Entry (M) or Computer Entry (C)?" << endl;
				
				cout << "Choice: ";
				cin >> entry;	
						
				system("CLS");
				
				switch(entry)
				{
					case 'M': case 'm':
						{	
							do
							{
							retmentry:
							cout << "MEMBER ENTRY" << endl << endl;
							cout << "OPTION (Enter the number):" << endl;
							cout << "1. Add New Member" << endl;
							cout << "2. Show Member" << endl;
							cout << "3. Update Record" << endl;
							cout << "4. Delete Record" << endl;
							cout << "5. Search Record" << endl;
							cout << "6. Return" << endl;
							
							valid = 0;
							
							cout << endl;
							
							cout << "Choice: " ;
							cin >> m_opt;
							
							if (cin.fail())						//error checking
							{	
							cin.clear();
							cin.ignore();
			
							cout << endl;
							cout << "Error" << endl << endl;
							Sleep(450);
							system("CLS");
			
							valid=1;
							}
							
							}while (valid == 1);
							
							system("CLS");
							
							switch (m_opt)
							{
								case 1:
									{	retaddm:									
										cout << "ADD NEW MEMBER" << endl; 
										cout << "(enter CANCEL000 to cancel)" << endl << endl;
										
										fstream oufile("GroupO_member.txt", ios::in | ios::out | ios::app); //open file for admin to write 	//for adding value to file, not replacing value (append)
										
										if(!oufile.is_open())
										{
											cout << "File Error" << endl; 	//for error when opening file
											goto retmentry;
										}
										else
										{	
											cout << "File Opened" << endl << endl;
											
											do
												{	
													cout << "Name: ";
													cin >> name;
													
													if(name == "CANCEL000")						//if the user accidentally press add member and wanted to cancel
													{	
														cout << endl;
														cout << "Cancelling..." << endl;
														Sleep(600);
														
														system("CLS");
														goto retmentry;
													}
													
													cout << "Email: ";
													cin >> emel;
													
													do
													{
														
														valid = 0;
													cout << "Phone Number: ";
													cin >> no;
													if (cin.fail())
													{	
														cin.clear();
														cin.ignore();
			
														cout << endl;
														cout << "Error" << endl << endl;
														Sleep(450);
														system("CLS");
														
														cout<< "ADD NEW MEMBER" << endl << endl;
														cout << "Name: " << name << endl;
														cout << "Email: " << emel << endl;
			
														valid=1;
													}
													}while (valid ==1);
													
													do
													{
														
														valid = 0;
													cout << "Membership Period (months): ";
													cin >> memper;
													
													if (cin.fail())
													{	
														cin.clear();
														cin.ignore();
			
														cout << endl;
														cout << "Error" << endl << endl;
														Sleep(450);
														system("CLS");
														
														cout<< "ADD NEW MEMBER" << endl << endl;
														cout << "Name: " << name << endl;
														cout << "Email: " << emel << endl;
														cout << "Phone Number: " << no << endl;
			
														valid=1;
													}
													}while (valid ==1);
													
													cout << endl;
													
													cout << "Continue? (Y/N)" << endl;
													cin >> resp;
													
													cout << endl;
													
													oufile << endl;					//storing data into file
													oufile << name << endl;
													oufile << emel << endl;
													oufile << no << endl;
													oufile << memper << endl << endl;
													
												} while (resp == 'Y');
										}
	
										cout << "ENTER ANY LETTER TO RETURN" << endl;		//return to option menu
										cin >> back;
										
										system("CLS");
										goto retmentry;
										
										break;
									}
								case 2:
									{	
										cout << "SHOW MEMBER" << endl << endl;
										
										cout << "Members List: " << endl;
										cout << endl;
										
										ifstream infile("GroupO_member.txt"); //open file for read only
	
										string name;
										int hours;
										
										while(infile >> name >> emel >> no >> memper)			//so program know which data is name or emel, etc
										{
											cout << ctr << ") Name: " << name << endl;
											cout << "E-mail: " << emel << endl;
											cout << "Phone Number: " << no << endl;
											cout << "Membership Period: " << memper << endl;
											cout << endl;
											ctr++;
										}
										
										ctr = 1;				//return the initial value of ctr
										
										infile.close();								//closing the file
										
										cout << endl;
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										
										system("CLS");
										goto retmentry;
										
										break;
									}
								case 3:
									
									{	retmemupd:
										cout << "UPDATE RECORD" << endl;
										cout << "(enter CANCEL000 to cancel)" << endl << endl;
										
										ifstream infile("GroupO_member.txt"); //open file for read only
										
										while(infile >> name >> emel >> no >> memper)
										{
											cout << ctr << ") " << name << endl;
											ctr++;
										}
										
										ctr = 1;
										
										infile.close();
										
										cout << endl;
										
										cout << "Enter the name of the member that you want to update: ";
										cin >> upd_name;
										
										if(upd_name == "CANCEL000")
													{	
														cout << endl;
														cout << "Cancelling..." << endl;
														Sleep(600);
														
														system("CLS");
														goto retmentry;
													}
										
										if( name != upd_name)					//to notify user if they enter wrong input
										{
										cout << endl;
										cout << "Error. Enter the NAME of the member to update their record." << endl;
										Sleep(700);
										
										system("CLS");
										goto retmemupd;
										}
										
										cout << endl;
										
										ifstream upd;								//opening old member txt for read only
										upd.open("GroupO_member.txt");
										
										ofstream barupd;								//creating new member txt
										barupd.open("GroupO_newmember.txt");
										
										upd >> name;
										upd >> emel;					
										upd >> no;
										upd >> memper;
									
										while(!upd.eof())
										{
											if(name != upd_name)
											{	
												
												barupd << endl;
												barupd << name;					//copying the data in old file
												barupd << endl;
												barupd << emel;
												barupd << endl;
												barupd << no;
												barupd << endl;
												barupd << memper;
												barupd << endl;
											}
											
											else
											{	
												system("CLS");
												
												cout << "UPDATE RECORD" << endl << endl;
												
												cout << "Update: " << upd_name << endl;
												cout << "Update name: ";
												cin >> nameupd;
												cout << "Update email: ";
												cin >> emelupd;
												cout << "Update phone number: ";
												cin >> noupd;
												
												cout << endl;
												
											 	barupd << endl;
												barupd << nameupd;				//updating data to new file
												barupd << endl;
												barupd << emelupd;
												barupd << endl;
												barupd << noupd;
												barupd << endl;
												barupd << memper;
												barupd << endl;
												
												cout << "Updating Record..." << endl;
												Sleep(800);
												
												system("CLS");
												
												cout << "UPDATE RECORD" << endl << endl;
												
												cout << "Update: " << upd_name << endl;
												cout << "New name: " << nameupd << endl;
												cout << "New email: " << emelupd << endl;
												cout << "New phone number: " << noupd << endl;
												
												cout << endl;
												
												cout << "Record Updated" << endl << endl;
												Sleep(700);
											}
											
											upd >> name;
											upd >> emel;
											upd >> no;
											upd >> memper;
										}
										
										barupd.close();
										upd.close();
										
										remove("GroupO_member.txt");				//delete old file
										
										rename("GroupO_newmember.txt", "GroupO_member.txt");			//rename new file with the same name as the old file
										
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										
										system("CLS");
										goto retmentry;
										
										break;
									}
								case 4:
									{	retdelmem:
										cout << "DELETE RECORD" << endl;
										cout << "(enter CANCEL000 to cancel)" << endl << endl;
										
										cout << "Members List: " << endl;
										
										ifstream infile("GroupO_member.txt"); //open file for read only
										
										while(infile >> name >> emel >> no >> memper)
										{
											cout << ctr << ") " << name << endl;
											ctr++;
										}
										
										ctr = 1;
										
										infile.close();
										
										cout << endl;
										
										cout << "Enter name of member to delete record: ";
										cin >> delmem;
										
										if(delmem == "CANCEL000")
													{	
														cout << endl;
														cout << "Cancelling..." << endl;
														Sleep(600);
														
														system("CLS");
														goto retmentry;
													}
										
										ifstream del;
										del.open("GroupO_member.txt");
										
										ofstream baru;
										baru.open("GroupO_newmember.txt");
										
										del >> name;
										del >> emel;
										del >> no;
										del >> memper;
										
										while(!del.eof())
										{
											if(name != delmem)
											{	
												baru << endl;
												baru << name;
												baru << endl;
												baru <<	emel;
												baru << endl;
												baru << no;
												baru << endl;
												baru << memper;
												baru << endl;
											}
											
											else
											{	
												cout << endl;
												
												cout << "Deleting Record..." << endl;
												Sleep(800);
												
												system("CLS");
												
												cout << "DELETE RECORD" << endl << endl;
												
												cout << "Members List: " << endl;
												
												ifstream infile("GroupO_member.txt"); //open file for read only
										
												while(infile >> name >> emel >> no >> memper)
												{
													cout << ctr << ") Name: " << name << endl;
													ctr++;
												}
										
												ctr = 1;
										
												infile.close();
												
												cout << endl;
												
												cout << "Record Deleted" << endl;
												Sleep(700);
											}
											
											del >> name;
											del >> emel;
											del >> no;
											del >> memper;
										}
									
										baru.close();
										del.close();
										
										remove("GroupO_member.txt");
										
										rename("GroupO_newmember.txt", "GroupO_member.txt");
										
										cout << endl;
										
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										system("CLS");
										goto retmentry;
										
										break;
									}
								case 5:
									{	
										retsearch:
										cout << "SEARCH RECORD" << endl;
										cout << "(enter CANCEL000 to cancel)" << endl << endl;
										
										ifstream filesearch;
										filesearch.open("GroupO_member.txt");
										
										cout << "Enter name to search: ";
										cin >> search;
										
										if(search == "CANCEL000")
													{	
														cout << endl;
														cout << "Cancelling..." << endl;
														Sleep(600);
														
														system("CLS");
														goto retmentry;
													}
	
										size_t mpos;									//size_t is one of unsigned int type, represent of any object
	
										if (filesearch.is_open())
										{
											while(getline(filesearch, name))			//getline to string input from user
											{	
												mpos = name.find(search);				//read a string umtil end of line in a file (\n)
												if ( mpos != string::npos )				//constant to check if there is name that is equal to search, in the file	
													{
														cout << endl;
														cout << search << " is in the record" << endl;
														break;
													}
											}
		
											filesearch.close();
										}
									
										cout << endl;
										
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										
										system("CLS");
										goto retmentry;
										
										break;
									}
								case 6:
									{
										system("CLS");
										goto retmain;
										
										cout << endl;
										
										break;
									}
								default:
									{	
										cout << "ERROR" << endl << endl;
										cout << "Invalid Input. Input must be number between (1-6)" << endl;
									 	
									 	cout << endl;
									 	
									 	Sleep(700);
										system("CLS");
										goto retmentry;
										
										break;
									}
							}
							
							break;
						}
					case 'C': case 'c':
						{	
							do
							{
							retcentry:
							cout << "COMPUTER ENTRY" << endl << endl;
							cout << "OPTION (Enter the number):" << endl;
							cout << "1. Add New Computer" << endl;
							cout << "2. Show Computer" << endl;
							cout << "3. Update Record" << endl;
							cout << "4. Delete Record" << endl;
							cout << "5. Search Record" << endl;
							cout << "6. Return" << endl;
							
							valid = 0;
							
							cout << endl;
							
							cout << "Choice: " ;
							cin >> c_opt;
							
							if (cin.fail())						//error checking
							{	
								cin.clear();
								cin.ignore();
			
								cout << endl;
								cout << "Error" << endl << endl;
								Sleep(450);
								system("CLS");
			
								valid=1;
							}
							}while(valid ==1);
							
							system("CLS");
							
							switch (c_opt)
							{
								case 1:
									{
										cout << "ADD COMPUTER" << endl;
										cout << "(enter CANCEL000 to cancel)" << endl << endl;
										
										fstream oufile("GroupO_computer.txt", ios::in | ios::out | ios::app); //file for computer  	//for adding value to file, not replacing value (append)
										
										if(!oufile.is_open())
										{
											cout << "File Error" << endl; 	//for error when opening file
											goto retcentry;
										}
										else
										{	
											cout << "File Opened" << endl << endl;
											
											do
												{	
													cout << "Computer: ";
													cin >> cname;
													
													if(cname == "CANCEL000")
													{	
														cout << endl;
														cout << "Cancelling..." << endl;
														Sleep(600);
														
														system("CLS");
														goto retcentry;
													}
													
													cout << "Computer ID: ";
													cin >> cID;
													
													cout << endl;
													
													cout << "Continue? (Y/N)" << endl;
													cin >> resp;
													
													cout << endl;
		
													oufile << cname << " " << cID << endl;
													
												} while (resp == 'Y');
										}
										
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										system("CLS");
										goto retcentry;
										
										break;
									}
								case 2:
									{
										cout << "SHOW COMPUTER" << endl << endl;
										
										cout << "Computer List: " << endl;
										cout << endl;
										
										ifstream infile("GroupO_computer.txt");
										
										cout << "No\t\t" <<  " | " << "Computer\t\t" << " | " << "ID\t\t" << endl;
										cout << "------------------------------------------------" << endl;
										
										while(infile >> cname >> cID)
										{
											cout << cnt << "\t\t | " << cname << "\t\t | " << cID << endl;
											cnt++;
										}
										
										cnt = 1;
										
										infile.close();
										
										cout << endl;
										
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										system("CLS");
										goto retcentry;
										
										break;
									}
								case 3:
									{	retpcupd:
										cout << "UPDATE RECORD" << endl;
										cout << "(enter CANCEL000 to cancel)" << endl << endl;
										
										ifstream infile("GroupO_computer.txt");
										
										while(infile >> cname >> cID)
										{
											cout << cnt << ") " << cname << endl;
											cnt++;
										}
										
										cnt = 1;
										
										infile.close();
										
										cout << endl;
										
										cout << "Enter the name of the computer that you want to update record: ";
										cin >> updcom;
										
										if(updcom == "CANCEL000")
													{	
														cout << endl;
														cout << "Cancelling..." << endl;
														Sleep(600);
														
														system("CLS");
														goto retcentry;
													}
										
										if(cname != updcom)
										{	
											cout << endl;
											cout << "That name is not in the record." << endl;
											Sleep(700);
											
											system("CLS");
											goto retpcupd;
										}
										
										cout << endl;
										
										ifstream updc;
										updc.open("GroupO_computer.txt");
										
										ofstream barupdc;
										barupdc.open("GroupO_newcomputer.txt");
										
										updc >> cname;
										updc >> cID;
										
										while(!updc.eof())
										{
											if(cname != updcom)
											{	
												barupdc << endl;
												barupdc << cname;
												barupdc << endl;
												barupdc << cID;
												barupdc << endl;
											}
											
											else
											{	
												system("CLS");
												
												cout << "UPDATE RECORD" << endl << endl;
												cout << "Update: " << updcom << endl;
												
												
												cout << "Enter new name: ";
												cin >> compNamebaru; 
												cout << "Enter new computer ID: ";
												cin >> compIDupd;
												
												cout << endl;
												
												barupdc << endl;
												barupdc << compNamebaru;
												barupdc << endl;
												barupdc << compIDupd;
												barupdc << endl;
												
												cout << "Updating Record..." << endl;
												Sleep(800);
												
												system("CLS");
												
												cout << "UPDATE RECORD" << endl << endl;
												cout << "Update :" << updcom << endl;
												cout << "New name: " << compNamebaru << endl;
												cout << "New ID: " << compIDupd << endl << endl;
												
												cout << "Record Updated" << endl;
												Sleep (700);
											}
											
											updc >> cname;
											updc >> cID;
										}
										
										barupdc.close();
										updc.close();
										
										remove("GroupO_computer.txt");
										
										rename("GroupO_newcomputer.txt", "GroupO_computer.txt");
										
										cout << endl;
										
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										system("CLS");
										goto retcentry;
										
										break;
									}
								case 4:
									{	retpcdel:
										cout << "DELETE RECORD" << endl;
										cout << "(enter CANCEL000 to cancel)" << endl << endl;
										
										cout << "Computers List: " << endl;
										
										ifstream infile("GroupO_computer.txt");
										
										while(infile >> cname >> cID)
										{
											cout << cnt << ") " << cname << endl;
											cnt++;
										}
										
										cnt = 1;
										
										infile.close();
										
										cout << endl;
										
										cout << "Enter name of computer to delete record: ";
										cin >> delcom;
										
										if(delcom == "CANCEL000")
													{	
														cout << endl;
														cout << "Cancelling..." << endl;
														Sleep(600);
														
														system("CLS");
														goto retcentry;
													}
										
										ifstream delc;
										delc.open("GroupO_computer.txt");
										
										ofstream cbaru;
										cbaru.open("GroupO_newcomputer.txt");
										
										delc >> cname;
										delc >> cID;
										
										while(!delc.eof())
										{
											if(cname != delcom)
											{	
												cbaru << endl;
												cbaru << cname;
												cbaru << endl;
												cbaru << cID;
												cbaru << endl;
											}
											
											else
											{	cout << endl;
												
												cout << "Deleting Record..." << endl;
												Sleep(800);
												
												system("CLS");
												
												cout << "DELETE RECORD" << endl << endl;
												
												cout << "Computers List: " << endl;
												
												ifstream infile("GroupO_computer.txt"); //open file for read only
										
												while(infile >> cname >> cID)
												{
													cout << cnt << ") " << cname << endl;
													cnt++;
												}
										
												cnt = 1;
										
												infile.close();
												
												cout << endl;
												
												cout << "Record Deleted" << endl;
												Sleep(700);
												cout << endl;
											}
											
											delc >> cname;
											delc >> cID;
										}
										
										cbaru.close();
										delc.close();
										
										remove("GroupO_computer.txt");
										
										rename("GroupO_newcomputer.txt", "GroupO_computer.txt");
										
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										system("CLS");
										goto retcentry;
										
										break;
									}
								case 5:
									{	retpcsearch:
										cout << "SEARCH RECORD" << endl;
										cout << "(enter CANCEL000 to cancel)" << endl << endl;
										
										ifstream filesearch;
										filesearch.open("GroupO_computer.txt");
										
										cout << "Enter name to search: ";
										cin >> csearch;
										
										if(csearch == "CANCEL000")
													{	
														cout << endl;
														cout << "Cancelling..." << endl;
														Sleep(600);
														
														system("CLS");
														goto retmentry;
													}
													
										size_t pos;				
	
										if (filesearch.is_open())
										{
											while(getline(filesearch, cname))
											{	
												pos = cname.find(csearch);				//read a string umtil end of line in a file (\n)
												if ( pos != string::npos )			//checking if there is name that is equal to search, in the file	
													{
														cout << endl;
														cout << csearch << " is in the record" << endl;
														break;
													}
											}
		
											filesearch.close();
										}
										
										cout << endl;
										
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										system("CLS");
										goto retcentry;
										
										break;
									}
								case 6:
									{
										system("CLS");	
										goto retmain;
										
										break;
									}
								default:
									{	cout << "ERROR" << endl << endl;
										cout << "Invalid Input. Input must be number between (1-6)" << endl;
										
										Sleep(700);
										system("CLS");
										goto retcentry;
										
										break;
									}
							}
							
							break;
						}
					default:
						{	cout << "ERROR" << endl << endl;
							cout << "Invalid Input. Input must be either 'M' or 'C' " << endl;
							
							Sleep(700);
							system("CLS");
							goto retmain;
									 	
							cout << endl;
							
							break;
						}
				}
				
				break;
			}
		case 2:
			{
				retcafe:
					
				do
				{
					
				valid = 0;
				cout << "CAFE MANAGEMENT" << endl << endl;
				cout << "OPTION (Enter the number):" << endl;
				cout << "1. Booking" << endl;
				cout << "2. Charges" << endl;
				cout << "3. Renewal" << endl;
				cout << "4. Return" << endl << endl;
				
				cout << "Choice: " ;
				cin >> manage;
				
				if(cin.fail())
				{
					cin.clear();
					cin.ignore();
					
					cout << endl;
					cout << "Error" << endl << endl;
					Sleep(450);
					system("CLS");
					
					valid = 1;
				}
				}while(valid == 1);
				
				system("CLS");
				
				switch (manage)
				{
					case 1:
						{	
							do
							{
							retbook:
						 	cout << "BOOKING" << endl << endl;
							cout << "OPTION (Enter the number):" << endl;
							cout << "1. Member Login" << endl;
							cout << "2. Member Log Out" << endl;
							cout << "3. Non-Member User Login" << endl;
							cout << "4. Non-Member User Log Out" << endl;
							cout << "5. Return" << endl;
							
							valid = 0;
							
							cout << endl;
							
							cout << "Choice: " ;
							cin >> b_opt;
							
							if (cin.fail())						//error checking
							{	
								cin.clear();
								cin.ignore();
			
								cout << endl;
								cout << "Error" << endl << endl;
								Sleep(450);
								system("CLS");
						
								valid=1;
							}
							}while(valid ==1);
							
							switch (b_opt)
							{
								case 1:
									{	retmemlogin:
										system("CLS");
										cout << "MEMBER LOGIN" << endl << endl;
											
										cout << "Check Login (C) or Add New Login (N)" << endl;
										cin >> memlogin;
										
										//checking all members (included with how many hours used pc) that logged in
										
										switch(memlogin)
										{
											case 'C': case 'c':
												{	
													system("CLS");
													
													cout << "MEMBER LOGIN" << endl << endl;
													ifstream infile("GroupO_mlogin.txt");
	
													string name;
													double mtimelogin, mtimelogout;
													string timein, timeout;
										
													while(infile >> name >> mtimelogin >> timein >> mtimelogout >> timeout)
													{	
														cout << fixed << setprecision(2);
											
														cout << ctr << ") " << name << endl;
														cout << "Login: "  << mtimelogin << timein << endl << endl;
														ctr++;
													}
										
													ctr = 1;
										
													infile.close();
													break;
												}
											case 'N': case 'n':
												{	
													system("CLS");
													
													string name;
													double mtimelogin, mtimelogout;
													string timein, timeout;
													
													cout << "MEMBER LOGIN" << endl;
													cout << "(enter CANCEL000 to cancel)" << endl << endl;
													
													fstream oufile("GroupO_mlogin.txt", ios::in | ios::out | ios::app);
													
													do
													{
														cout << "Name: ";
														cin >> name;
														
															if(name == "CANCEL000")					
															{	
																cout << endl;
																cout << "Cancelling..." << endl;
																Sleep(600);
														
																system("CLS");
																goto retbook;
															}
														
														do
														{
															valid = 0;
														cout << "Time Started Using PC (24-Hours format): ";
														cin >> mtimelogin;
															if(cin.fail())
															{
																cin.clear();
																cin.ignore();
																
																cout << endl;
																cout << "Error" << endl << endl;
																Sleep(450);
																system("CLS");
																
																cout << "MEMBER LOGIN" << endl << endl;
																cout << "Name: " << name << endl;
																
																valid = 1;
															}
														}while (valid ==1);
														
														cout << "AM or PM? : ";
														cin >> timein;
														
														cout << endl;
														
														cout << "Continue? (Y/N)" << endl;
														cin >> resp;
														
														mtimelogout = 0;
														timeout = " unknown";
														
														oufile << name << " " << mtimelogin << " " << timein << " " << mtimelogout << " " << timeout << endl << endl;
														
													}while (resp == 'Y');
													break;
												}
											default:	
												{	system("CLS");
												
													cout << "ERROR" << endl << endl;
													cout << "Invalid Input. Input must be either 'C' or 'N' " << endl;
							
													Sleep(700);
													system("CLS");
													goto retmemlogin;
									 	
													cout << endl; 
													
													break;
												}
												}
										
										cout << endl;
										
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										
										system("CLS");
										
										goto retbook;
										
										break;
									}
								case 2:
									{	
										system("CLS");
										
										cout << "MEMBER LOGOUT" << endl << endl;
										
										//checking all members that logged out and hours used on pc
										
										cout << "Check Logout (C) or Add New Logout (N)" << endl;
										cin >> memlogin;
										
										//checking all members (included with how many hours used pc) that logged in
										
										switch(memlogin)
										{
											case 'C': case 'c':
												{	
													system("CLS");
													
													cout << "MEMBER LOGOUT" << endl << endl;
													ifstream infile("GroupO_mlogin.txt");
	
													string name;
													double mtimelogin, mtimelogout;
													string timein, timeout;
													float mcharge;
										
													while(infile >> name >> mtimelogin >> timein >> mtimelogout >> timeout)
													{	
														cout << fixed << setprecision(2);
											
														mcharge = (mtimelogout - mtimelogin) * 1.50;
											
														cout << ctr << ") " << name << endl;
														cout << "Logout: "  << mtimelogout << timeout << endl << endl;
														ctr++;
											
														fstream oufile("GroupO_membercharge.txt", ios::in | ios::out | ios::app);
														{	
															oufile << name << " " << mcharge << endl << endl;
														}
													}
										
													ctr = 1;
										
													infile.close();
													break;
												}
											case 'N': case 'n':
												{	
													system("CLS");
													
													string name;
													double mtimelogin, mtimelogout;
													string timein, timeout;
													
													cout << "MEMBER LOGOUT" << endl;
													cout << "(enter CANCEL000 to cancel)" << endl << endl;
													
													fstream oufile("GroupO_mlogin.txt", ios::in | ios::out | ios::app);
													
													do
													{
														cout << "Name: ";
														cin >> name;
														
														if(name == "CANCEL000")					
															{	
																cout << endl;
																cout << "Cancelling..." << endl;
																Sleep(600);
														
																system("CLS");
																goto retbook;
															}
														
														do
														{
															valid = 0;
														cout << "Time Stopped Using PC (24-Hours format): ";
														cin >> mtimelogout;
															if(cin.fail())
															{
																cin.clear();
																cin.ignore();
																
																cout << endl;
																cout << "Error" << endl << endl;
																Sleep(450);
																system("CLS");
																
																cout << "MEMBER LOGOUT" << endl << endl;
																cout << "Name: " << name << endl;
																
																valid = 1;
															}
														}while (valid ==1);
														
														cout << "AM or PM? : ";
														cin >> timeout;
														
														cout << endl;
														
														cout << "Continue? (Y/N)" << endl;
														cin >> resp;
														
														oufile << endl;
														oufile << name << " " << mtimelogin << " " << timein << " " << mtimelogout << " " << timeout << endl << endl;
														
													}while (resp == 'Y');
													
													break;
												}
											default:	
												{	system("CLS");
												
													cout << "ERROR" << endl << endl;
													cout << "Invalid Input. Input must be either 'C' or 'N' " << endl;
							
													Sleep(700);
													system("CLS");
													goto retmemlogin;
									 	
													cout << endl; 
													
													break;
												}
											}
										
										cout << endl;
										
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										
										system("CLS");
										
										goto retbook;
										
										break;
									}
								case 3:
									{	retguelogin:
										system("CLS");
										
										cout << "NON-MEMBER LOGIN" << endl;
										cout << endl;
										
										cout << "Check Login (C) or Add New Login (N)" << endl;
										cin >> memlogin;
										
										//checking all members (included with how many hours used pc) that logged in
										
										switch(memlogin)
										{
											case 'C': case 'c':
												{	
													system("CLS");
													
													cout << "NON-MEMBER LOGIN" << endl << endl;
													ifstream infile("GroupO_glogin.txt");
	
													string name;
													double gtimelogin, gtimelogout;
													string gtimein, gtimeout;
										
													while(infile >> name >> gtimelogin >> gtimein >> gtimelogout >> gtimeout)
													{	
														cout << fixed << setprecision(2);
											
														cout << ctr << ") " << name << endl;
														cout << "Login: "  << gtimelogin << gtimein << endl << endl;
														ctr++;
													}
										
													ctr = 1;
										
													infile.close();
													break;
												}
											case 'N': case 'n':
												{	
													system("CLS");
													
													string name;
													double gtimelogin, gtimelogout;
													string gtimein, gtimeout;
													
													cout << "NON-MEMBER LOGIN" << endl;
													cout << "(enter CANCEL000 to cancel" << endl << endl;
													
													fstream oufile("GroupO_glogin.txt", ios::in | ios::out | ios::app);
													
													do
													{
														cout << "Name: ";
														cin >> name;
														
														if(name == "CANCEL000")					
															{	
																cout << endl;
																cout << "Cancelling..." << endl;
																Sleep(600);
														
																system("CLS");
																goto retbook;
															}
														
														do
														{
															valid = 0;
														cout << "Time Started Using PC (24-Hours format): ";
														cin >> gtimelogin;
															if(cin.fail())
															{
																cin.clear();
																cin.ignore();
																
																cout << endl;
																cout << "Error" << endl << endl;
																Sleep(450);
																system("CLS");
																
																cout << "MEMBER LOGIN" << endl << endl;
																cout << "Name: " << name << endl;
																
																valid = 1;
															}
														}while (valid ==1);
														
														cout << "AM or PM? : ";
														cin >> gtimein;
														
														cout << endl;
														
														cout << "Continue? (Y/N)" << endl;
														cin >> resp;
														
														gtimelogout = 0;
														gtimeout = " unknown";
														
														oufile << name << " " << gtimelogin << " " << gtimein << " " << gtimelogout << " " << gtimeout << endl << endl;
														
													}while (resp == 'Y');
													break;
												}
											default:	
												{	system("CLS");
												
													cout << "ERROR" << endl << endl;
													cout << "Invalid Input. Input must be either 'C' or 'N' " << endl;
							
													Sleep(700);
													system("CLS");
													goto retguelogin;
									 	
													cout << endl; 
													
													break;
												}
										}
										
										cout << endl;
										
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										
										system("CLS");
										
										//checking non-member login (same like member)
										
										goto retbook;
										
										break;
									}
								case 4:
									{
										system("CLS");
										
										cout << "NON-MEMBER LOGOUT" << endl;		//checking non-member logout (same like member)
										cout << endl;
										
										cout << "Check Logout (C) or Add New Logout (N)" << endl;
										cin >> memlogin;
										
										//checking all members (included with how many hours used pc) that logged in
										
										switch(memlogin)
										{
											case 'C': case 'c':
												{
													system("CLS");
													
													cout << "NON-MEMBER LOGOUT" << endl << endl;
													ifstream infile("GroupO_glogin.txt");
	
													string name;
													double gtimelogin, gtimelogout;
													string gtimein, gtimeout;
													float gcharge;
										
													while(infile >> name >> gtimelogin >> gtimein >> gtimelogout >> gtimeout)
													{	
														cout << fixed << setprecision(2);
											
														gcharge = (gtimelogout - gtimelogin) * 2.50;
											
														cout << ctr << ") " << name << endl;
														cout << "Logout: "  << gtimelogout << gtimeout << endl << endl;
														ctr++;
											
														fstream oufile("GroupO_guestcharge.txt", ios::in | ios::out | ios::app);
														{	
															oufile << name << " " << gcharge << endl << endl;
														}
													}
										
													ctr = 1;
										
													infile.close();
													
													break;
												}
											case 'N': case 'n':
												{
													system("CLS");
													
													string name;
													double gtimelogin, gtimelogout;
													string gtimein, gtimeout;
													
													cout << "NON-MEMBER LOGOUT" << endl;
													cout << "(enter CANCEL000 to cancel)" << endl << endl;
													
													fstream oufile("GroupO_glogin.txt", ios::in | ios::out | ios::app);
													
													do
													{
														cout << "Name: ";
														cin >> name;
														
														if(name == "CANCEL000")					
															{	
																cout << endl;
																cout << "Cancelling..." << endl;
																Sleep(600);
														
																system("CLS");
																goto retbook;
															}
														
														do
														{
															valid = 0;
														cout << "Time Started Using PC (24-Hours format): ";
														cin >> gtimelogin;
															if(cin.fail())
															{
																cin.clear();
																cin.ignore();
																
																cout << endl;
																cout << "Error" << endl << endl;
																Sleep(450);
																system("CLS");
																
																cout << "NON-MEMBER LOGIN" << endl << endl;
																cout << "Name: " << name << endl;
																
																valid = 1;
															}
														}while (valid ==1);
														
														cout << "AM or PM? : ";
														cin >> gtimein;
														
														cout << endl;
														
														cout << "Continue? (Y/N)" << endl;
														cin >> resp;
														
														oufile << endl;
														oufile << name << " " << gtimelogin << " " << gtimein << " " << gtimelogout << " " << gtimeout << endl << endl;
														
													}while (resp == 'Y');
													
													break;
												}
											default:
												{
													system("CLS");
												
													cout << "ERROR" << endl << endl;
													cout << "Invalid Input. Input must be either 'C' or 'N' " << endl;
							
													Sleep(700);
													system("CLS");
													goto retmemlogin;
									 	
													cout << endl; 
													
													break;
													
													break;
												}
										}
										
										cout << endl;
										
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										
										system("CLS");
										
										goto retbook;
										
										break;
									}
								case 5:
									{
										cout << "Return" << endl;
										
										system("CLS");
										goto retcafe;
										
										break;
									}
								default:
									{	cout << "ERROR" << endl << endl;
										cout << "Invalid Input. Input must be number between (1-5)" << endl;
							
										Sleep(700);
										system("CLS");
										goto retbook;
									 	
										cout << endl;
										
										break;
									}
							}
							
							break;
						}
					case 2:
						{	
							do
							{
							retcharge:
							cout << "CHARGE" << endl << endl;
							cout << "OPTION (Enter the number):" << endl;
							cout << "1. Take Charges" << endl;
							cout << "2. Show Charges" << endl;
							cout << "3. Return" << endl;
							
							valid = 0;
							
							cout << endl;
							
							cout << "Choice: " ;
							cin >> ch_opt;
							
							if (cin.fail())						//error checking
							{	
								cin.clear();
								cin.ignore();
			
								cout << endl;
								cout << "Error" << endl << endl;
								Sleep(450);
								system("CLS");
			
								valid=1;
							}
							
							}while (valid ==1);
							
							system("CLS");
							
							switch (ch_opt)
							{
								case 1:
									{	
										do
										{
										retmanlog:
										cout << "TAKE CHARGES" << endl;
										cout << "(enter 000 to cancel)" << endl << endl;
										
										cout << "Member - 1 hour RM1.50" << endl;
										cout << "Non-Member - 1 hour RM2.50" << endl << endl;
										
										cout << "What time did the user start using the pc (24 hours format): ";
										cin >> manuallogin;
										
										if(manuallogin == 000)
													{	
														cout << endl;
														cout << "Cancelling..." << endl;
														Sleep(600);
														
														system("CLS");
														goto retcharge;
													}
										
										
										if(manuallogin < 0 || manuallogin > 24)	
										{	
											cout << endl;
											
											cout << "Error. Hours must between 0 to 24" << endl;
											Sleep(500);
											
											system("CLS");
											goto retmanlog;
										}
										
										cout << "What time did the user stop using the pc (24 hours format): ";
										cin >> manuallogout;
										
										manualhours = manuallogout - manuallogin;
										
										if (manualhours < 0)
										{
											cout << endl;
											cout << "Error. Logout time must be later than login time" << endl << endl;
											Sleep(650);
											
											system("CLS");
										}
										}while (manualhours < 0);
										
										cout << endl;
										
										if(manuallogout < 0 || manuallogout > 24)
										{
											cout << "Error. Hours must between 0 to 24" << endl;
											Sleep(500);
											
											system("CLS");
											goto retmanlog;
										}
										
										do
										{
										retmanual:
										cout << "Member (M) or Guest (G)?" << endl;
										
										valid = 0;
										
										cout << "Choice: ";
										cin >> manualmember;
										
										if (cin.fail())						//error checking
										{	
											cin.clear();
											cin.ignore();
			
											cout << endl;
											cout << "Error" << endl << endl;
											Sleep(450);
											system("CLS");
			
											valid=1;
										}
										}while (valid ==1);
										
										cout << fixed << setprecision(2);
										
										switch(manualmember)
										{
											case 'M': case'm':
												{
													manualcharge = manualhours * 1.50;
													
													break;
												}
											case 'G': case'g':
												{
													manualcharge = manualhours * 2.50;
													
													break;
												}
											default:
												{	
													cout << endl;
													cout << "Error. Input must be either M or G." << endl << endl;
													cout << "--------------------------------------------" << endl << endl;
													goto retmanual;
													
													break;
												}
										}
										
										cout << endl;
										
										cout << "Total charge is: RM" << manualcharge << endl << endl;
										
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										system("CLS");
										goto retcharge;
										
										break;
									}
								case 2:
									{
										cout << "SHOW CHARGES" << endl << endl;					//must check login and logout first before able to check charges
										cout << "Non-Member - 1 Hours = RM2.50" << endl;
										cout << "Member - 1 hours = RM1.50" << endl;    //discount for member
										cout << endl;
										
										ifstream infile("GroupO_membercharge.txt");
	
										string mname;
										float mcharge;
										
										cout << fixed << setprecision(2);
										
										cout << "Member Charges: " << endl;
										while(infile >> mname >> mcharge)
										{
											cout << ctr << ") " << mname << endl;
											cout << "Charges: RM" << mcharge << endl;
											cout << endl;
											ctr++;
										}
										
										ctr = 1;
										
										infile.close();
										
										cout << endl;
										
										ifstream guestfile("GroupO_guestcharge.txt");
	
										string gname;
										float gcharge;
										
										cout << fixed << setprecision(2);
										
										cout << "Guest Charges: " << endl;
										while(guestfile >> gname >> gcharge)
										{
											cout << ctr << ") " << gname << endl;
											cout << "Charges: RM" << gcharge << endl;
											cout << endl;
											ctr++;
										}
										
										ctr = 1;
										
										guestfile.close();
										
										cout << endl;
										
										cout << "ENTER ANY LETTER TO RETURN" << endl;
										cin >> back;
										
										fstream oufile("GroupO_membercharge.txt", ios::out | ios::trunc);					//removing all data in charge file (trunc)
										fstream ou_file("GroupO_guestcharge.txt", ios::out | ios::trunc); 
										
										system("CLS");
										goto retcharge;
										
										break;
									}
								case 3:
									{
										cout << "Return" << endl;
										
										system("CLS");
										goto retcafe;
										
										break;
									}
								default:
									{	cout << "ERROR" << endl << endl;
										cout << "Invalid Input. Input must be number between (1-3)" << endl;
										
										Sleep(500);
										system("CLS");
										goto retcharge;
										
										break;
									}
							}
							
							break;
						}
					case 3:
						{	
							retrenew:
							cout << "RENEWAL" << endl;
							cout << "(enter CANCEL000 to cancel)" << endl << endl;
										
							ifstream infile("GroupO_member.txt"); //open file for read only
									
							while(infile >> name >> emel >> no >> memper)
								{
									cout << ctr << ") " << name << endl;
									cout << "Membership Period: " << memper << " months" << endl;
									cout << endl;
									ctr++;
								}
										
							ctr = 1;
								
							infile.close();
										
							cout << endl;
										
							cout << "Enter the name of the member that you want to renew membership: ";
							cin >> ren_name;
							
							if(ren_name == "CANCEL000")
							{	
								cout << endl;
								cout << "Cancelling..." << endl;
								Sleep(600);
														
								system("CLS");
								goto retcharge;
							}
													
							cout << endl;
							
									
							ifstream upd;
							upd.open("GroupO_member.txt");
										
							ofstream barupd;
							barupd.open("GroupO_newmember.txt");
										
							upd >> name;
							upd >> emel;
							upd >> no;
							upd >> memper;
									
							while(!upd.eof())
								{
									if(name != ren_name)
										{	
											
											barupd << endl;
											barupd << name;
											barupd << endl;
											barupd << emel;
											barupd << endl;
											barupd << no;
											barupd << endl;
											barupd << memper;
											barupd << endl;
										}
											
									else
										{	
											system("CLS");
												
											cout << "RENEW MEMBERSHIP" << endl << endl;
											
											do
											{
											cout << "Renew: " << ren_name << endl;
											cout << "Renew Membership: ";
											cin >> memperupdate;
											
											cout << endl;
											
											}while(memperupdate < 0 );
											
											memperupd = memperupdate + memper;
												
										 	barupd << endl;
											barupd << name;
											barupd << endl;
											barupd << emel;
											barupd << endl;
											barupd << no;
											barupd << endl;
											barupd << memperupd;
											barupd << endl;
												
											cout << "Renewing Membership..." << endl;
											Sleep(800);
												
											system("CLS");
												
											cout << "RENEWAL" << endl << endl;
											
											cout << "Renew: " << ren_name << endl;
											cout << "Membership Period: " << memperupd << " months" << endl;
												
											cout << endl;
												
											cout << "Membership Renewed" << endl << endl;
											Sleep(700);
									}
											
										upd >> name;
										upd >> emel;
										upd >> no;
										upd >> memper;
								}
										
									barupd.close();
									upd.close();
										
									remove("GroupO_member.txt");
										
									rename("GroupO_newmember.txt", "GroupO_member.txt");
						
								cout << endl;
										
								cout << "ENTER ANY LETTER TO RETURN" << endl;
								cin >> back;
										
								system("CLS");
										
								goto retcafe;
							
								break;
						}
						
					case 4:
						{
							system("CLS");
							goto retmain;
							
							break;
						}
					default:
						{	cout << "ERROR" << endl << endl;
							cout << "Invalid Input. Input must be between (1-4)" << endl;
							
							Sleep(700);
							
							system("CLS");
							goto retcafe;
							
							break;
						}
				}
				
				break;
			}
		case 3:
			{
				cout << "EXIT" << endl << endl;
				cout << "THANK YOU FOR USING THIS PROGRAM. GOODBYE!" << endl;
				exit(1);
				
				break;
			}
		default:
			{	cout << "ERROR" << endl << endl;
				cout << "Invalid Input. Input must be number between (1-3)" << endl;
				Sleep(700);
				
				system("CLS");
				goto retmain;
				
				break;
			}
	}	
}

else
{
	system ("CLS");
	
	cout << "CYBER CAFE MANAGEMENT SYSTEM" << endl << endl;
	cout << "LOGGING IN..." << endl;
	Sleep(700);
	
	system ("CLS");
	
	cout << "CYBER CAFE MANAGEMENT SYSTEM" << endl << endl;
	cout << "LOG IN FAILED." << endl;
	cout << "Wrong username or password." << endl;
	Sleep(700);
	
	system("CLS");
}

} while (!loginSuccess);
	
	system("pause");
	
	return 0;
}


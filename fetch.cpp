#include <iostream>
#include <string>
#include <ctime>
#include "sqlite3.h"

using namespace std;

// Create a callback function  
int callback(void *NotUsed, int argc, char **argv, char **azColName){

    // int argc: holds the number of results
    // (array) azColName: holds each column returned
    // (array) argv: holds each value
	
	cout << "\t|\n\t|\t";
    for(int i = 0; i < argc; i++) {
        
        // Show column name, value, and newline
        cout <<"> " << argv[i] ;
			// azColName[i]
    }

    // Insert a newline
    //cout << "\t|\n\t|\t";

    // Return successful
    return 0;
}


int callback1(void *NotUsed, int argc, char **argv, char **azColName){


    // Return successful
    return 0;
}





void board(){
	cout<<"\t|\t\t\tWellcom To ChatRoom\n";
	cout<<"\t|\t\n";
}

  
int main() {
	
    // Pointer to SQLite connection
    sqlite3 *db;

    // Save any error messages
    char *zErrMsg = 0;

    // Save the result of opening the file
    int rc;
	// Init Date and time;
	
	 time_t tmNow = time(0);
    char *dt = ctime(&tmNow);


    // Save any SQL
    string sql , uname;

    // Save the result of opening the file
    rc = sqlite3_open("king.db", &db);
    
    
	board();
	
	cout<<"\tEnter your name: ";cin>>uname;
    
    
    
    if( rc ){
        // Show an error message
        cout << "DB Error: " << sqlite3_errmsg(db) << endl;
        // Close the connection
        sqlite3_close(db);
        // Return an error
        return(1);
    }

   
    
	// Save SQL insert data
    while (true){
    	string msg = uname+" joined the  Chat";
    
	system("cls");
	board();
	sql = "SELECT message,user,time  FROM 'msgs';";
    
    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);


		
    
	cout<<"\n\t|\t>>> ";getline(cin, msg);
    	
	sql = "INSERT INTO msgs ('message', 'time','user') VALUES ('"+ msg+"','"+dt+"','"+uname+"');";
    
    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback1, 0, &zErrMsg);
    
    
}
    // Save SQL insert data
    
    
	
	
    // Close the SQL connection
    sqlite3_close(db);
    
    return 0;
}

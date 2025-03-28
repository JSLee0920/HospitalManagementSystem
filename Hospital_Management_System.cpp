#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

const string file_name = "hospital_data.txt"; // declare a constant string for the file name

class Human // create a class for human
{
    private:
        string name, phone_num, gender;  //declare the private attributes of the class
        int id, age; //the attributes are the information of a person
    public:
        Human(int id, string name, int age, string gender, string phone_num)  // Create the constructor
        : id(id), name(name), age(age), gender(gender), phone_num(phone_num)  // initializer list
        {}
        int get_ID() {return id;} // get or return the attributes
        string get_Name() {return name;}
        int get_Age() {return age;}
        string get_Gender() {return gender;}
        string get_Phone_Num(){return phone_num;}
        void set_ID(int id){this->id = id;} // set the value of the attributes
        void set_Name(string name) {this->name = name;}
        void set_Age(int age){this->age = age;}
        void set_Gender(string gender){this->gender = gender;}
        void set_Phone_Num(string phone_num){this->phone_num = phone_num;}
        virtual void display() = 0; //pure virtual function
};

class Patient : public Human //Create a class called Patient which is the subclass of Human
{
    private:
        string service_type, disease, blood_type, specialist_type; //Create the private attributes.
    public:
        Patient(int id, string name, int age, string gender,string blood_type, string phone_num, string service_type, string disease, string specialist_type) //create the constructor
        : Human(id, name, age, gender, phone_num), blood_type(blood_type), service_type(service_type), disease(disease), specialist_type(specialist_type) // initializer list
        {}

        void setPatient_Blood(string blood_type) { this->blood_type = blood_type;} // set the value of the attribute
        string getPatient_Blood() {return blood_type;} // get or return the attributes

        void setPatient_Service(string service_type) { this->service_type = service_type;}
        string getPatient_Service() {return service_type;}

        void setPatient_Disease(string disease) { this->disease = disease;}
        string getPatient_Disease() {return disease;}

        void set_specialist_type(string specialist_type) {this->specialist_type = specialist_type;}
        string get_specialist_type(){return specialist_type;}


        void display(); //declare display function to display patient information
};

class Doctor : public Human // A class called Doctor is created and is the subclass of Human
{
    private:
        string specialization, working_time; //declare the private attributes
        int room_num;
    public:
        Doctor(int id, string name, int age, string gender, string phone_num, string specialization, string working_time, int room_num) //create the constructor
        : Human(id, name, age, gender, phone_num), specialization(specialization), working_time(working_time),room_num(room_num) {} //initializer list

        void set_specialization (string specialization) {this->specialization = specialization;} //set the value of the attribute
        string get_specialization() {return specialization;} // get or return the attribute

        void set_working_time(string working_time) {this->working_time = working_time;}
        string get_working_time (){return working_time;}

        void set_room_num(int room_num) {this->room_num = room_num;}
        int get_room_num() {return room_num;}

        void display(); //declare display function
};

//Declarations of functions
void main_menu();    //display main menu
void patient_menu(); //display patient menu
void doctor_menu();  //display doctor menu
void specialist_menu(); //display specialist menu
void addNewPatient(vector <Patient> &patient); //add patient records
void searchPatient(vector <Patient> &patient); //search patient by ID
void displayAllPatients(vector <Patient> &patient); //display the information of all patients
void editPatient(vector <Patient> &patient); //edit a patient record
void deletePatient(vector <Patient> &patient); //delete a patient record
void addNewDoctor(vector<Doctor> &doctor);  //add doctor records
void searchDoctor(vector <Doctor> &doctor); //search a doctor by ID
void displayAllDoctors(vector <Doctor> &doctor); //display information of all doctors
void editDoctor(vector <Doctor> &doctor);        //edit a doctor record
void deleteDoctor(vector <Doctor> &doctor);      //delete a doctor record
void load_data(vector<Patient> &patient, vector<Doctor> &doctor);  //load data from the file
void save_data(vector<Patient> &patient, vector<Doctor> &doctor);  //save data to the file


int main() //main function
{
    vector <Patient> patient; //use vector store instantiated objects
    vector <Doctor> doctor;
    int option, patient_choice, doctor_choice; //declare variables for option or choice purpose
    load_data(patient, doctor); //load data from the text file
    do //use do while loop to loop through the main menu, patient menu and doctor menu
    {
        main_menu();
        cout << "\t\t\t     Enter your choice: ";
        cin >> option; //input option
        if(option == 1) //choose patient menu
        {
            do{
                system("cls");
                patient_menu();
                cout << "\t\t\t     Enter your choice: ";
                cin >> patient_choice;
                switch(patient_choice) //use switch case to choose options
                {
                    case 1:
                        system("cls"); //clear the screen
                        addNewPatient(patient); //function to add new patients
                        cout << "\n\t\t\t";
                        system("PAUSE");
                        break;
                    case 2:
                        system("cls");
                        searchPatient(patient); //function to search patient
                        cout << "\n\t\t\t";
                        system("PAUSE");
                        break;
                    case 3:
                        system("cls");
                        displayAllPatients(patient); //function to display all patients
                        cout << "\n\t\t\t";
                        system("PAUSE");
                        break;
                    case 4:
                        system("cls");
                        editPatient(patient); //function to edit a patient
                        cout << "\n\t\t\t";
                        system("PAUSE");
                        break;
                    case 5:
                        system("cls");
                        deletePatient(patient); //function to delete patient
                        cout << "\n\t\t\t";
                        system("PAUSE");
                        break;
                    default:
                        cout << "Please enter a valid choice!\n";
                        cin.clear();  // To prevent errors and program from crashing
                        cin.ignore();
                        system("cls");
                }

            }while(patient_choice != 6); //condition
        }
        else if(option == 2) //choose doctor menu
        {
            do
            {
                system("cls");
                doctor_menu();
                cout << "\t\t\t    Enter your choice: ";
                cin >> doctor_choice;
                switch(doctor_choice)
                {
                    case 1:
                        system("cls");
                        addNewDoctor(doctor); //function to add doctor
                        cout << "\n\t\t\t";
                        system("PAUSE");
                        break;
                    case 2:
                        system("cls");
                        searchDoctor(doctor); //function to search doctor
                        cout << "\n\t\t\t";
                        system("PAUSE");
                        break;
                    case 3:
                        system("cls");
                        displayAllDoctors(doctor); //function to display all doctors
                        cout << "\n\t\t\t";
                        system("PAUSE");
                        break;
                    case 4:
                        system("cls");
                        editDoctor(doctor); //function to edit a doctor
                        cout << "\n\t\t\t";
                        system("PAUSE");
                        break;
                    case 5:
                        system("cls");
                        deleteDoctor(doctor); //function to delete doctor
                        cout << "\n\t\t\t";
                        system("PAUSE");
                        break;
                    default:
                        cout << "Please enter a valid choice!\n";
                        cin.clear();  // To prevenr errors and program from crashing
                        cin.ignore();
                        system("cls");
                }
            }while(doctor_choice != 6); //condition
        }
        else
        {
            cin.clear();
            cin.ignore();
            system("cls");
        }
    }while(option != 3);
    save_data(patient, doctor); //save data to the text file
    return 0;
}

void Patient :: display() //display function from patient class
{
    cout << "\t\t\t |  ID: " << get_ID() << "\n";           //return the attributes
    cout << "\t\t\t | 1. Name: " << get_Name() << "\n";
    cout << "\t\t\t | 2. Age: " << get_Age() << "\n";
    cout << "\t\t\t | 3. Gender: " << get_Gender() << "\n";
    cout << "\t\t\t | 4. Blood-Type: " << getPatient_Blood() << "\n";
    cout << "\t\t\t | 5. Phone Number: " << get_Phone_Num() << "\n";
    cout << "\t\t\t | 6. Service Type: " << getPatient_Service() << "\n";
    cout << "\t\t\t | 7. Disease: " << getPatient_Disease() << "\n";
    cout << "\t\t\t | 8. Specialist Type: " << get_specialist_type() << "\n";
}

void Doctor :: display() //display function from doctor class
{
    cout << "\t\t\t |  ID: " << get_ID() << "\n";          //return the attributes
    cout << "\t\t\t | 1. Name: " << get_Name() << "\n";
    cout << "\t\t\t | 2. Age: " << get_Age() << "\n";
    cout << "\t\t\t | 3. Gender: " << get_Gender() << "\n";
    cout << "\t\t\t | 4. Phone Number: " << get_Phone_Num() << "\n";
    cout << "\t\t\t | 5. Specialization: " << get_specialization() << "\n";
    cout << "\t\t\t | 6. Working Hours: " << get_working_time() << "\n";
    cout << "\t\t\t | 7. Room Number: " << get_room_num() << "\n";
}

void main_menu()
{
    cout << "\t\t\t  ----------------------------\n";
    cout << "\t\t\t | Hospital Management System |\n";
    cout << "\t\t\t  ----------------------------\n\n";
    cout << "\t\t\t     ---------------------\n";
    cout << "\t\t\t    | 1. Patients Records |\n";
    cout << "\t\t\t    | 2. Doctors Records  |\n";
    cout << "\t\t\t    | 3. Exit             |\n";
    cout << "\t\t\t     ---------------------\n";
}

void patient_menu()
{
    cout << "\t\t\t          --------------\n";
    cout << "\t\t\t         | Patient Menu |\n";
    cout << "\t\t\t          --------------\n";
    cout << "\t\t\t   ----------------------------\n";
    cout << "\t\t\t  | 1. Add a Patient           |\n";
    cout << "\t\t\t  | 2. Search a Patient        |\n";
    cout << "\t\t\t  | 3. Display all Patients    |\n";
    cout << "\t\t\t  | 4. Edit a Patient Record   |\n";
    cout << "\t\t\t  | 5. Delete a Patient Record |\n";
    cout << "\t\t\t  | 6. Exit                    |\n";
    cout << "\t\t\t   ----------------------------\n";
}

void doctor_menu()
{
    cout << "\t\t\t        -------------\n";
    cout << "\t\t\t       | Doctor Menu |\n";
    cout << "\t\t\t        -------------\n";
    cout << "\t\t\t  ---------------------------\n";
    cout << "\t\t\t | 1. Add a Doctor           |\n";
    cout << "\t\t\t | 2. Search a Doctor        |\n";
    cout << "\t\t\t | 3. Display all Doctors    |\n";
    cout << "\t\t\t | 4. Edit a Doctor Record   |\n";
    cout << "\t\t\t | 5. Delete a Doctor Record |\n";
    cout << "\t\t\t | 6. Exit                   |\n";
    cout << "\t\t\t  ---------------------------\n";
}

void specialist_menu() //menu for choosing specialist
{
    cout << "\n\t\t\t  ----------------------------------------\n";
    cout << "\t\t\t | List of specializations to choose from:| \n";
    cout << "\t\t\t | 1. Cardiology                          |\n";
    cout << "\t\t\t | 2. Neurology                           |\n";
    cout << "\t\t\t | 3. Endocrinology                       |\n";
    cout << "\t\t\t | 4. Infectious Disease                  |\n";
    cout << "\t\t\t | 5. Emergency Medicine                  |\n";
    cout << "\t\t\t | 6. Gastroenterology                    |\n";
    cout << "\t\t\t  ----------------------------------------\n";
}

void addNewPatient(vector <Patient> &patient) //function for adding new patient record
{
    int id, age, specialist_num;  //declare local variables
    string name, gender, blood_type, phone_num, service_type, disease, specialist_type;
    cout << "\t\t\t ------------------\n";
    cout << "\t\t\t| Adding a Patient |\n";
    cout << "\t\t\t ------------------\n\n";
    cout << "\t\t\tEnter ID: ";
    while(!(cin >> id))  //use a while loop to ensure correct input of id
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\t\t\tPlease enter a valid id(only integer is accepted): ";
    }
    for (int i = 0; i < patient.size(); i++) //loop through the vector to check existing id
    {
        if(patient[i].get_ID() == id)
        {
            cout << "\n\t\t\tPatient already exists!\n";
            return;       //stops the execution of the function
        }
    }
    cin.ignore();
    cout << "\t\t\tEnter name: ";
    getline(cin, name);

    while(name == "") //To avoid input empty string
    {
        cin.clear();
        cout << "\t\t\tPlease enter name: ";
        getline(cin, name);
    }

    cout << "\t\t\tEnter age: ";
    while(!(cin >> age) || age < 0 || age >= 110) //use while loop to input the correct age range
    {
        cout << "\t\t\tPlease enter a valid age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\t\t\tEnter gender(Male or Female): ";
    cin >> gender;
    gender[0] = toupper(gender[0]); //convert first character to uppercase
    while(gender != "Male" && gender != "Female") //while loop to ask user to enter the correct input
    {
        cout << "\t\t\tPlease enter a valid gender: ";
        cin >> gender;
        gender[0] = toupper(gender[0]);
    }
    cout << "\t\t\tEnter Blood-Type(A, B, AB, O): ";
    cin >> blood_type;
    blood_type[0] = toupper(blood_type[0]); //convert first character of string to uppercase
    while (blood_type != "A" && blood_type != "B" && blood_type != "AB" && blood_type != "O")
    {
        cout << "\t\t\tPlease enter a valid blood-type: ";
        cin >> blood_type;
        blood_type[0] = toupper(blood_type[0]);
    }

    cout << "\t\t\tEnter Phone Number: ";
    cin >> phone_num;

    cout << "\t\t\tEnter service-type(Emergency or Ordinary): ";
    cin >> service_type;
    service_type[0] = toupper(service_type[0]);

    while(service_type != "Emergency" && service_type != "Ordinary") //use while loop to ask user to enter the correct input
    {
        cout << "\t\t\tPlease enter a valid service: ";
        cin >> service_type;
        service_type[0] = toupper(service_type[0]);
    }
    cin.ignore();
    cout << "\t\t\tEnter disease: ";
    getline(cin, disease);
    disease[0] = toupper(disease[0]); //convert first character to uppercase
    while(disease == "")
    {
        cin.clear();
        cout << "\t\t\tPlease enter the disease: ";
        getline(cin, disease);
        disease[0] = toupper(disease[0]);
    }
    specialist_menu();
    do                     //use do while loop to loop through the switch case statements
    {
        cout << "\t\t\tEnter types of specializations for the patient(Choose corresponding number): ";
        cin >> specialist_num;
        switch(specialist_num)    //use switch case to choose the specialists
        {
            case 1:
                specialist_type = "Cardiology";
                break;
            case 2:
                specialist_type = "Neurology";
                break;
            case 3:
                specialist_type = "Endocrinology";
                break;
            case 4:
                specialist_type = "Infectious Disease";
                break;
            case 5:
                specialist_type = "Emergency Medicine";
                break;
            case 6:
                specialist_type = "Gastroenterology";
                break;
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\t\t\tPlease choose the correct option!\n";
        }
    }while(specialist_num < 1 || specialist_num > 6);
    Patient new_patient(id, name, age, gender, blood_type, phone_num, service_type, disease, specialist_type); //use constructor to create object
    patient.push_back(new_patient); //add the object into the vector

    cout << "\t\t\tPatient record is added!\n";
}

void searchPatient(vector <Patient> &patient)
{
    int id;
    cout << "\t\t\t -------------------------\n";
    cout << "\t\t\t| Searching for a Patient |\n";
    cout << "\t\t\t -------------------------\n\n";
    cout << "\t\t\tEnter Patient's ID: ";
    cin >> id;

    for(int i = 0; i < patient.size(); i++) //Loop through the vector to find the patient id
    {
        if(patient[i].get_ID() == id)
        {
            cout << "\t\t\tPatient found!\n\n";
            patient[i].display();   //display patient information
            return;
        }
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\t\t\tPatient does not exist!\n";
}

void displayAllPatients(vector<Patient> &patient)  //display all patients records
{
    cout << "\t\t\t ----------------------\n";
    cout << "\t\t\t| All Patients Records |\n";
    cout << "\t\t\t ----------------------\n\n";
    if(patient.empty())    //if the vector is empty, returns true
    {
        cout << "\t\t\tNo records!\n";
        return;
    }
    for(int i = 0; i < patient.size(); i++) //loops through the objects in the vector
    {
        patient[i].display();   //display the reocrds
        cout << "\n";
    }
}

void editPatient(vector<Patient> &patient) //edit the records of patients
{
    int id, age, option, specialist_num;  //declare the local variables
    string name, gender, blood_type, phone_num, service_type, disease, specialist_type;

    cout << "\t\t\t -----------------------\n";
    cout << "\t\t\t| Edit a Patient Record |\n";
    cout << "\t\t\t -----------------------\n\n";
    cout << "\t\t\tEnter Patient's ID to edit: ";
    cin >> id;


    for(int i = 0; i < patient.size(); i++)
    {
        if(patient[i].get_ID() == id)  //find the patient's id
        {
            patient[i].display();
            cout << "\n\t\t\tEnter your option to choose which field to edit: ";
            cin >> option;

            switch(option)  //use switch case to choose which field to edit
            {
                case 1:
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\t\t\tEnter name: ";
                    getline(cin, name);
                    while(name == "")
                    {
                        cin.clear();
                        cout << "\t\t\tPlease enter name: ";
                        getline(cin, name);
                    }
                    patient[i].set_Name(name); //set the value of the attribute
                    break;
                case 2:
                    cout << "\t\t\tEnter age: ";
                    while(!(cin >> age) || age < 0 || age >= 110)
                    {
                        cout << "\t\t\tPlease enter a valid age: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    patient[i].set_Age(age);
                    break;
                case 3:
                    cout << "\t\t\tEnter gender(Male or Female): ";
                    cin >> gender;
                    gender[0] = toupper(gender[0]);
                    while(gender != "Male" && gender != "Female")
                    {
                        cout << "\t\t\tPlease enter a valid gender: ";
                        cin >> gender;
                    }
                    patient[i].set_Gender(gender);
                    break;
                case 4:
                    cout << "\t\t\tEnter Blood-Type(A, B, AB, O): ";
                    cin >> blood_type;
                    blood_type[0] = toupper(blood_type[0]);
                    while (blood_type != "A" && blood_type != "B" && blood_type != "AB" && blood_type != "O")
                    {
                        cout << "\t\t\tPlease enter a valid blood-type: ";
                        cin >> blood_type;
                        blood_type[0] = toupper(blood_type[0]);
                    }
                    patient[i].setPatient_Blood(blood_type);
                    break;
                case 5:
                    cout << "\t\t\tEnter Phone Number: ";
                    cin >> phone_num;
                    patient[i].set_Phone_Num(phone_num);
                    break;
                case 6:
                    cout << "\t\t\tEnter service-type(Emergency or Ordinary): ";
                    cin >> service_type;
                    service_type[0] = toupper(service_type[0]);

                    while(service_type != "Emergency" && service_type != "Ordinary")
                    {
                        cout << "\t\t\tPlease enter a valid service: ";
                        cin >> service_type;
                        service_type[0] = toupper(service_type[0]);
                    }
                    patient[i].setPatient_Service(service_type);
                    break;
                case 7:
                    cin.ignore();
                    cout << "\t\t\tEnter disease: ";
                    getline(cin, disease);
                    disease[0] = toupper(disease[0]);
                    while(disease == "")
                    {
                        cin.clear();
                        cout << "\t\t\tPlease enter the disease: ";
                        getline(cin, disease);
                        disease[0] = toupper(disease[0]);
                    }
                    patient[i].setPatient_Disease(disease);
                    break;
                case 8:
                    specialist_menu();
                   do
                   {
                        cout << "\t\t\tEnter types of specializations for the patient(Choose corresponding number): ";
                        cin >> specialist_num;
                        switch(specialist_num)
                        {
                            case 1:
                                specialist_type = "Cardiology";
                                break;
                            case 2:
                                specialist_type = "Neurology";
                                break;
                            case 3:
                                specialist_type = "Endocrinology";
                                break;
                            case 4:
                                specialist_type = "Infectious Disease";
                                break;
                            case 5:
                                specialist_type = "Emergency Medicine";
                                break;
                            case 6:
                                specialist_type = "Gastroenterology";
                                break;
                            default:
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "\t\t\tPlease choose the correct option!\n";
                        }
                    }while(specialist_num < 1 || specialist_num > 6);
                    patient[i].set_specialist_type(specialist_type);
                    break;
                default:
                    cin.clear();  // To prevent errors and program from crashing
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\t\t\tWrong input! Return to Menu\n";
            }
            return;
        }
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\t\t\tPatient does not exist!\n";
}

void deletePatient(vector <Patient> &patient)
{
    int id;
    char confirmation; //to confirm to delete or no
    cout << "\t\t\t -----------------\n";
    cout << "\t\t\t| Delete a Record |\n";
    cout << "\t\t\t -----------------\n\n";
    cout << "\t\t\tEnter Patient's ID to delete: ";
    cin >> id;

    for (int i = 0; i < patient.size(); i++) //loop through the vector to find the ID
    {
        if (patient[i].get_ID() == id)
        {
            patient[i].display();
            cout << "\t\t\tDo you want to delete this record[y/n]: ";
            cin >> confirmation;
            if(confirmation == 'y' || confirmation == 'Y')  //to confirm the delete
            {
                patient.erase(patient.begin() + i);      //remove the object from the vector based on the index
                cout << "\t\t\tPatient Record Deleted!\n";
                return;
            }
            else
            {
                cout << "\t\t\tNo action taken\n";  //Not confirm with the delete
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return;
            }
        }
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\t\t\tPatient does not exist!\n";
}

void addNewDoctor(vector<Doctor> &doctor)
{

    int id, age, room_num, specialization_num;
    bool checkRoom;
    string name, gender, phone_num, working_time, specialization;
    cout << "\t\t\t -----------------\n";
    cout << "\t\t\t| Adding a Doctor |\n";
    cout << "\t\t\t -----------------\n\n";
    cout << "\t\t\tEnter ID: ";
    while(!(cin >> id)) //Use while loop to input the correct id
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\t\t\tPlease enter a valid id(only integer is accepted): ";
    }

    for (int i = 0; i < doctor.size(); i++) //To check the existing ID
    {
        if (doctor[i].get_ID() == id) {
            cout << "\n\t\t\tDoctor already exists!";
            return;
        }
    }
    cin.ignore();
    cout << "\t\t\tEnter name: ";
    getline(cin, name);

    while(name == "")
    {
        cin.clear();
        cout << "\t\t\tPlease enter name: ";
        getline(cin, name);
    }

    cout << "\t\t\tEnter age: ";
    while (!(cin >> age) || age < 26 || age >= 60)
    {
        cout << "\t\t\tPlease enter a valid age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\t\t\tEnter gender(Male or Female): ";
    cin >> gender;
    gender[0] = toupper(gender[0]);
    while (gender != "Male" && gender != "Female")
    {
        cout << "\t\t\tPlease enter a valid gender: ";
        cin >> gender;
        gender[0] = toupper(gender[0]);
    }

    cin.ignore();
    cout << "\t\t\tEnter phone number: ";
    cin >> phone_num;

    specialist_menu();
    do
    {
        cout << "\t\t\tEnter types of specializations that the doctor belongs(Choose corresponding number): ";
        cin >> specialization_num;
        switch(specialization_num)  //use switch case to choose the specialist
        {
            case 1:
                specialization = "Cardiology";
                break;
            case 2:
                specialization = "Neurology";
                break;
            case 3:
                specialization = "Endocrinology";
                break;
            case 4:
                specialization = "Infectious Disease";
                break;
            case 5:
                specialization = "Emergency Medicine";
                break;
            case 6:
                specialization = "Gastroenterology";
                break;
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\t\t\tPlease choose the correct option!\n";
        }
    }while(specialization_num < 1 || specialization_num > 6);

    cout << "\t\t\tEnter working hours: ";
    cin >> working_time;

    do   //use do while loop to input the correct room num
    {
        checkRoom = false;
        cout << "\t\t\tEnter room number: ";
         while (!(cin >> room_num) || room_num < 0 || room_num >= 60)
         {
            cout << "\t\t\tPlease enter a valid room number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
         }
        for (int i = 0; i < doctor.size(); i++) //loop through the vector to check whether the room number is occupied already
        {
            if (doctor[i].get_room_num() == room_num && doctor[i].get_ID() != id)
            {
                checkRoom = true; //as the condition for do while loop
                cout << "\n\t\t\tRoom already occupied!\n";
                break;   //break the loop
            }
        }
    }while(checkRoom);

    Doctor new_doctor(id, name, age, gender, phone_num, specialization, working_time, room_num); //use constructor to create the doctor object
    doctor.push_back(new_doctor); //add the object to the vector

    cout << "\t\t\tDoctor record is added!\n";
}

void searchDoctor(vector<Doctor> &doctor)
{
    int id;
    cout << "\t\t\t ------------------------\n";
    cout << "\t\t\t| Searching for a Doctor |\n";
    cout << "\t\t\t ------------------------\n\n";
    cout << "\t\t\tEnter Doctor's ID: ";
    cin >> id;

    for (int i = 0; i < doctor.size(); i++)
    {
        if (doctor[i].get_ID() == id)
        {
            cout << "\t\t\tDoctor found!\n\n";
            doctor[i].display();
            return;
        }
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\t\t\tDoctor does not exist!\n";
}

void displayAllDoctors(vector<Doctor> &doctor)
{
    cout << "\t\t\t ---------------------\n";
    cout << "\t\t\t| All Doctors Records |\n";
    cout << "\t\t\t ---------------------\n\n";

    if (doctor.empty()) {
        cout << "\t\t\tNo records!\n";
    }

    for (int i = 0; i < doctor.size(); i++)
    {
        doctor[i].display();
        cout << "\n";
    }
}

void editDoctor(vector<Doctor> &doctor) {
    int id, age, room_num, option, specialization_num;
    string name, gender, phone_num, working_time, specialization;
    bool checkRoom = false;

    cout << "\t\t\t ----------------------\n";
    cout << "\t\t\t| Edit a Doctor Record |\n";
    cout << "\t\t\t ----------------------\n\n";
    cout << "\t\t\tEnter Doctor's ID to edit: ";
    cin >> id;

    for (int i = 0; i < doctor.size(); i++)
    {
        if (doctor[i].get_ID() == id)
        {
            doctor[i].display();
            cout << "\n\t\t\tEnter your option to choose which field to edit: ";
            cin >> option;

            switch (option)
            {
                case 1:
                    cin.ignore();
                    cout << "\t\t\tEnter name: ";
                    getline(cin, name);
                    while(name == "")
                    {
                        cin.clear();
                        cout << "\t\t\tPlease enter name: ";
                        getline(cin, name);
                    }
                    doctor[i].set_Name(name);
                    break;
                case 2:
                    cout << "\t\t\tEnter age: ";
                    while (!(cin >> age) || age < 26 || age >= 60)
                    {
                        cout << "\t\t\tPlease enter a valid age: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    doctor[i].set_Age(age);
                    break;
                case 3:
                    cout << "\t\t\tEnter gender(Male or Female): ";
                    cin >> gender;
                    gender[0] = toupper(gender[0]);
                    while (gender != "Male" && gender != "Female")
                    {
                        cout << "\t\t\tPlease enter a valid gender: ";
                        cin >> gender;
                        gender[0] = toupper(gender[0]);
                    }
                    doctor[i].set_Gender(gender);
                    break;
                case 4:
                    cin.ignore();
                    cout << "\t\t\tEnter phone number: ";
                    cin >> phone_num;
                    doctor[i].set_Phone_Num(phone_num);
                    break;
                case 5:
                    specialist_menu();
                    do
                    {
                        cout << "\t\t\tEnter types of specializations that the doctor belongs(Choose corresponding number): ";
                        cin >> specialization_num;
                        switch(specialization_num)
                        {
                            case 1:
                                specialization = "Cardiology";
                                break;
                            case 2:
                                specialization = "Neurology";
                                break;
                            case 3:
                                specialization = "Endocrinology";
                                break;
                            case 4:
                                specialization = "Infectious Disease";
                                break;
                            case 5:
                                specialization = "Emergency Medicine";
                                break;
                            case 6:
                                specialization = "Gastroenterology";
                                break;
                            default:
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "\t\t\tPlease choose the correct option!\n";
                        }
                    }while(specialization_num < 1 || specialization_num > 6);
                    doctor[i].set_specialization(specialization);
                    break;
                case 6:
                    cout << "\t\t\tEnter working hours: ";
                    cin >> working_time;
                    doctor[i].set_working_time(working_time);
                case 7:
                     do
                     {
                        checkRoom = false;
                        cout << "\t\t\tEnter room number: ";
                        while (!(cin >> room_num) || room_num < 0 || room_num >= 60)
                        {
                            cout << "\t\t\tPlease enter a valid room number: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        for (int i = 0; i < doctor.size(); i++)
                        {
                            if (doctor[i].get_room_num() == room_num && doctor[i].get_ID() != id)
                            {
                                checkRoom = true;
                                cout << "\n\t\t\tRoom already occupied!\n";
                                break;
                            }
                        }
                    }while(checkRoom);
                    doctor[i].set_room_num(room_num);
                    break;
                default:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\t\t\tWrong input! Return to Menu\n";
            }
            return;
        }
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\t\t\tDoctor does not exist!\n";
}

void deleteDoctor(vector<Doctor> &doctor)
{
    int id;
    char confirmation;
    cout << "\t\t\t ------------------------\n";
    cout << "\t\t\t| Delete a Doctor Record |\n";
    cout << "\t\t\t ------------------------\n\n";
    cout << "\t\t\tEnter Doctor's ID to delete: ";
    cin >> id;

    for (int i = 0; i < doctor.size(); i++)
    {
        if (doctor[i].get_ID() == id)
        {
            doctor[i].display();
            cout << "\t\t\tDo you want to delete this record[y/n]: ";
            cin >> confirmation;
            if(confirmation == 'Y' || confirmation == 'y')
            {
                doctor.erase(doctor.begin() + i);   //remove the object from the vector based on the index
                cout << "\t\t\tDoctor Record Deleted!\n";
                return;
            }
            else
            {
                cout << "\t\t\tNo action taken\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return;
            }
        }
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\t\t\tDoctor does not exist!\n";
}

void save_data(vector<Patient> &patient, vector<Doctor> &doctor) //To save patient and doctor data to the file
{
    ofstream file(file_name); //output file stream

    if(file.is_open())  //if file is open
    {
        file << patient.size() << "\n";
        for(int i = 0; i < patient.size(); i++)  //loop through the vector to write object's data to the file
        {
            file << patient[i].get_ID() << "\n";
            file << patient[i].get_Name() << "\n";
            file << patient[i].get_Age() << "\n";
            file << patient[i].get_Gender() << "\n";
            file << patient[i].getPatient_Blood() << "\n";
            file << patient[i].get_Phone_Num() << "\n";
            file << patient[i].getPatient_Service() << "\n";
            file << patient[i].getPatient_Disease() << "\n";
            file << patient[i].get_specialist_type() << "\n";
        }
        file << doctor.size() << "\n";
        for(int i = 0; i < doctor.size(); i++)
        {
            file << doctor[i].get_ID() << "\n";
            file << doctor[i].get_Name() << "\n";
            file << doctor[i].get_Age() << "\n";
            file << doctor[i].get_Gender() << "\n";
            file << doctor[i].get_Phone_Num() << "\n";
            file << doctor[i].get_specialization() << "\n";
            file << doctor[i].get_working_time() << "\n";
            file << doctor[i].get_room_num() << "\n";
        }
        file.close(); //close file
    }
    else
    {
        cout << "\t\t\tError!!\n";
    }
}

void load_data(vector<Patient> &patient, vector<Doctor> &doctor)
{
    ifstream file(file_name); //input file stream
    if(file.is_open())
    {
        int patient_count;
        file >> patient_count; //read the patient size or count

        for(int i = 0; i < patient_count; i++)  //use loop to read data from the file
        {
            int id, age;
            string name, gender, blood_type, phone_num, service_type, disease, specialist_type;

            file >> id;
            file.ignore();
            getline(file, name);
            file >> age >> gender >> blood_type >> phone_num >> service_type;
            file.ignore();
            getline(file, disease);
            getline(file, specialist_type);

            Patient newPatient(id, name, age, gender, blood_type, phone_num, service_type, disease, specialist_type);
            patient.push_back(newPatient);
        }

        int doctor_count;
        file >> doctor_count;
        for(int i = 0; i < doctor_count; i++)
        {
            int id, age, room_num;
            string name, gender, phone_num, specialization, working_time;
            file >> id;
            file.ignore();
            getline(file, name);
            file >> age >> gender >> phone_num;
            file.ignore();
            getline(file, specialization);
            file >> working_time >> room_num;

            Doctor newDoctor(id, name, age, gender, phone_num, specialization, working_time, room_num);
            doctor.push_back(newDoctor);
        }

        file.close(); //close file
    }
    else
    {
        cout << "\t\t\tError!\n";
    }
}




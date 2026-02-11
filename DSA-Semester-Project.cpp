#include <iostream>
using namespace std;
const int MAX = 50;
// ------Manage Residents Coding By Anmol Ihsan ----------
int ids[MAX];
int ages[MAX]; 
int health[MAX];
string names[MAX]; 
int rooms[MAX];
int countRes = 0;

void addResident() {
    cout << "\nEnter ID: ";
    cin >> ids[countRes];

    cout << "Enter Name: ";
    cin >> names[countRes];

    cout << "Enter Age: ";
    cin >> ages[countRes];

    cout << "Enter Room: ";
    cin >> rooms[countRes];

    cout << "Enter Health Score: ";
    cin >> health[countRes];

    countRes++;
    cout << "Resident added successfully!\n";
}
void searchByID() {
    int searchID;
    cout << "\nEnter ID to search: ";
    cin >> searchID;

    for (int i = 0; i < countRes; i++) {
        if (ids[i] == searchID) {
            cout << "\nResident Found:\n";
            cout << "ID: " << ids[i]
                 << " Name: " << names[i]
                 << " Age: " << ages[i]
                 << " Room: " << rooms[i]
                 << " Health: " << health[i] << endl;
            return;
        }
    }
    cout << "Resident not found!\n";
}

void sortByHealth() {
    for (int i = 0; i < countRes - 1; i++) {
        for (int j = 0; j < countRes - i - 1; j++) {
            if (health[j] > health[j + 1]) {
                swap(health[j], health[j + 1]);
                swap(ids[j], ids[j + 1]);
                swap(names[j], names[j + 1]);
                swap(ages[j], ages[j + 1]);
                swap(rooms[j], rooms[j + 1]);
            }
        }
    }
    cout << "Residents sorted by health score!\n";
}
void displayResidents() {
    if (countRes == 0) {
        cout << "No residents available.\n";
        return;
    }
    cout << "\nCurrent Residents:\n";
    cout << "-------------------------------------------------\n";
    cout << "ID\tName\tAge\tRoom\tHealth\n";
    cout << "-------------------------------------------------\n";

    for (int i = 0; i < countRes; i++) {
        cout << ids[i] << "\t"
             << names[i] << "\t"
             << ages[i] << "\t"
             << rooms[i] << "\t"
             << health[i] << endl;
    }
}
void manageResidents() {
    int choice;
    do {
        cout << "\n--- RESIDENT MANAGEMENT ---\n";
        cout << "1. Add New Resident\n";
        cout << "2. Search Resident by ID\n";
        cout << "3. Sort Residents by Health Score\n";
        cout << "4. Display ALL Residents\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addResident(); break;
        case 2: searchByID(); break;
        case 3: sortByHealth(); break;
        case 4: displayResidents(); break;
        case 0: break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}
// ------STAFF SCHEDULING Coding By Fatima Saheli----------

#define STAFF_SIZE 5

string staffQueue[STAFF_SIZE] = {
    "Nurse Anmol", "Nurse Fatima", "Nurse Mujtaba", "Nurse Ismail", "Dr. Ali"
};
int staffCount = 5; 

void rotateDuty() {
    if (staffCount <= 1) {
        cout << "Not enough staff members to rotate!\n";
        return;
    }
    string firstStaff = staffQueue[0];
    
    for (int i = 0; i < staffCount - 1; i++) {
        staffQueue[i] = staffQueue[i + 1];
    }
    
    staffQueue[staffCount - 1] = firstStaff;
    
    cout << "Duty rotated successfully!\n";
}

void displayDutySchedule() {
    cout << "\n=== CURRENT STAFF DUTY SCHEDULE ===\n";
    cout << "Queue Order: FRONT -> ";
    for (int i = 0; i < staffCount; i++) {
        cout << staffQueue[i];
        if (i < staffCount - 1) {
            cout << " -> ";
        }
    }
    cout << " -> BACK\n\n";
    
    cout << "Detailed Schedule:\n";
    cout << "---------------------------------\n";
    for (int i = 0; i < staffCount; i++) {
        cout << "Position " << (i + 1) << ": " << staffQueue[i];
        if (i == 0) {
            cout << " [CURRENTLY ON DUTY]";
        }
        cout << endl;
    }
    cout << "---------------------------------\n";
}
void staffScheduler() {
    int choice;
    do {
        cout << "\n--- STAFF SCHEDULING ---\n";
        cout << "1. Rotate Duty\n";
        cout << "2. Display Duty Schedule\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: rotateDuty(); break;
            case 2: displayDutySchedule(); break;
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}
// ------Health & Medicine Logs Coding By Syed Mujtaba Hassan----------
struct HealthLog {
    int residentID;
    string date;
    string medicine;
    int dosage;
    string notes;
    int healthScore;
    HealthLog* next;
    
    HealthLog(int id, string d, string med, int dos, string n, int score) {
        residentID = id;
        date = d;
        medicine = med;
        dosage = dos;
        notes = n;
        healthScore = score;
        next = NULL;
    }
};
struct MedicineUpdate {
    int residentID;
    string oldMedicine;
    string newMedicine;
    int oldDosage;
    int newDosage;
    MedicineUpdate* next;
    
    MedicineUpdate(int id, string oldMed, string newMed, int oldDos, int newDos) {
        residentID = id;
        oldMedicine = oldMed;
        newMedicine = newMed;
        oldDosage = oldDos;
        newDosage = newDos;
        next = NULL;
    }
};

HealthLog* healthLogsHead = NULL;
MedicineUpdate* undoStackTop = NULL;
// Linked List insertion at beginning.
void addHealthLog() {
    int id, dosage, score;
    string date, medicine, notes;
    
    cout << "\n--- ADD HEALTH LOG ---\n";
    cout << "Enter Resident ID: ";
    cin >> id;
    
    cout << "Enter Date (DD-MM-YYYY): ";
    cin >> date;
    
    cout << "Enter Medicine Name: ";
    cin.ignore();
    getline(cin, medicine);
    
    cout << "Enter Dosage (mg): ";
    cin >> dosage;
    
    cout << "Enter Notes: ";
    cin.ignore();
    getline(cin, notes);
    
    cout << "Enter Health Score (0-100): ";
    cin >> score;
    
    HealthLog* newLog = new HealthLog(id, date, medicine, dosage, notes, score);   

    newLog->next = healthLogsHead;
    healthLogsHead = newLog;
    
    cout << "Health log added successfully!\n";
}
void displayHealthLogs() {
    if (healthLogsHead == NULL) {
        cout << "\nNo health logs available.\n";
        return;
    }
    cout << "\n--- ALL HEALTH LOGS ---\n";
    cout << "==================================================================================\n";
    cout << "ResID\tDate\t\tMedicine\t\tDosage\tScore\tNotes\n";
    cout << "==================================================================================\n";
    
    HealthLog* current = healthLogsHead;
    int count = 0;
    
    while (current != NULL) {
        cout << current->residentID << "\t"
             << current->date << "\t"
             << current->medicine;
             
        if (current->medicine.length() < 8) cout << "\t\t";
        else if (current->medicine.length() < 16) cout << "\t";
        
        cout << current->dosage << "mg\t"
             << current->healthScore << "\t"
             << current->notes << endl;
        
        current = current->next;
        count++;
    }
    cout << "==================================================================================\n";
    cout << "Total logs: " << count << endl;
}
void displayResidentLogs() {
    int searchID;
    cout << "\nEnter Resident ID to view logs: ";
    cin >> searchID;
    
    HealthLog* current = healthLogsHead;
    bool found = false;
    int count = 0;
    
    cout << "\n--- HEALTH LOGS FOR RESIDENT ID: " << searchID << " ---\n";
    cout << "=================================================================\n";
    cout << "Date\t\tMedicine\tDosage\tScore\tNotes\n";
    cout << "=================================================================\n";
    
    while (current != NULL) {
        if (current->residentID == searchID) {
            found = true;
            count++;
            cout << current->date << "\t"
                 << current->medicine << "\t"
                 << current->dosage << "mg\t"
                 << current->healthScore << " \t"
                 << current->notes << endl;
        }
        current = current->next;
    }
    
    if (!found) {
        cout << "No health logs found for Resident ID: " << searchID << endl;
    } else {
        cout << "=================================================================\n";
        cout << "Total logs: " << count << endl;
    }
}
// Update medicine and push to undo stack
void updateMedicine() {
    int id, newDosage;
    string newMedicine;
    
    cout << "\n--- UPDATE MEDICINE ---\n";
    cout << "Enter Resident ID: ";
    cin >> id;

    HealthLog* current = healthLogsHead;
    string currentMedicine = "";
    int currentDosage = 0;
    
    while (current != NULL) {
        if (current->residentID == id) {
            currentMedicine = current->medicine;
            currentDosage = current->dosage;
            break;
        }
        current = current->next;
    }
    
    if (currentMedicine == "") {
        cout << "No health log found for Resident ID: " << id << endl;
        return;
    }
    
    cout << "Current Medicine: " << currentMedicine << " (" << currentDosage << "mg)\n";
    cout << "Enter New Medicine Name: ";
    cin.ignore();
    getline(cin, newMedicine);
    
    cout << "Enter New Dosage (mg): ";
    cin >> newDosage;
    
    MedicineUpdate* update = new MedicineUpdate(id, currentMedicine, newMedicine, currentDosage, newDosage);
    update->next = undoStackTop;
    undoStackTop = update;
    
    current->medicine = newMedicine;
    current->dosage = newDosage;
    
    cout << "Medicine updated successfully! (Can be undone)\n";
}
void undoMedicineUpdate() {
    if (undoStackTop == NULL) {
        cout << "\nNo updates to undo!\n";
        return;
    }
    
    MedicineUpdate* update = undoStackTop;
    HealthLog* current = healthLogsHead;
    while (current != NULL) {
        if (current->residentID == update->residentID) {
        	
            current->medicine = update->oldMedicine;
            current->dosage = update->oldDosage;
            
            cout << "\n--- UPDATE UNDONE ---\n";
            cout << "Resident ID: " << update->residentID << endl;
            cout << "Medicine reverted from '" << update->newMedicine 
                 << "' to '" << update->oldMedicine << "'\n";
            cout << "Dosage reverted from " << update->newDosage 
                 << "mg to " << update->oldDosage << "mg\n";
        
            undoStackTop = undoStackTop->next;
            delete update;
            return;
        }
        current = current->next;
    }
    
    cout << "Could not find corresponding health log!\n";
}

void displayUndoStack() {
    if (undoStackTop == NULL) {
        cout << "\nUndo stack is empty.\n";
        return;
    }
    
    cout << "\n--- UNDO STACK (Most Recent First) ---\n";
    cout << "===========================================\n";
    cout << "ResID\tOld Medicine\tNew Medicine\n";
    cout << "===========================================\n";
    
    MedicineUpdate* current = undoStackTop;
    int count = 0;
    
    while (current != NULL) {
        cout << current->residentID << "\t"
             << current->oldMedicine << " (" << current->oldDosage << "mg)\t"
             << current->newMedicine << " (" << current->newDosage << "mg)\n";
        current = current->next;
        count++;
    }
    
    cout << "===========================================\n";
    cout << "Updates available for undo: " << count << endl;
}
void evaluateHealthRiskRecursive(HealthLog* node) {
    if (node == NULL) {
        return;
    }
    evaluateHealthRiskRecursive(node->next);
    
    cout << "Resident ID " << node->residentID << " -> Score: " << node->healthScore << " ->";
    
    if (node->healthScore < 50) {
        cout << "Status: Critical ";
    } else if (node->healthScore < 70) {
        cout << "Status: Moderate ";
    } else {
        cout << "Status: Stable ";
    }   
    cout << endl;
}
void evaluateHealthRisk() {
    if (healthLogsHead == NULL) {
        cout << "\nNo health logs available for evaluation.\n";
        return;
    }
    cout << "\n--- EVALUATING HEALTH RISK (Recursively) ---\n";
    cout << "==============================================\n";
    
    evaluateHealthRiskRecursive(healthLogsHead);
    
    cout << "==============================================\n";
}
void healthMedicineLogs() {
    int choice;
    
    do {
        cout << "\n--- HEALTH & MEDICINE LOGS ---\n";
        cout << "1. Add Health Log (Linked List)\n";
        cout << "2. Display All Health Logs\n";
        cout << "3. Display Logs for Specific Resident\n";
        cout << "4. Update Medicine (Push to Stack)\n";
        cout << "5. Undo Last Medicine Update (Pop from Stack)\n";
        cout << "6. Display Undo Stack\n";
        cout << "7. Evaluate Health Risk (Recursion)\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: addHealthLog(); break;
            case 2: displayHealthLogs(); break;
            case 3: displayResidentLogs(); break;
            case 4: updateMedicine(); break;
            case 5: undoMedicineUpdate(); break;
            case 6: displayUndoStack(); break;
            case 7: evaluateHealthRisk(); break;
            case 0: cout << "Returning to Main Menu...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}
// -------- CARE PRIORITY TREE (BST) by Ismail Khalid --------

struct TreeNode {                                                      
    int health;
    string name;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* insertTree(TreeNode* root, int health, string name) {     
    if (!root) {                                                    
        TreeNode* node = new TreeNode;
        node->health = health;
        node->name = name;
        node->left = node->right = NULL;
        return node;
    }

    if (health < root->health)                                    
        root->left = insertTree(root->left, health, name);         
    else                                                             
        root->right = insertTree(root->right, health, name);        

    return root;
}

void inorder(TreeNode* root) {                                      
    if (!root) return;
    inorder(root->left);
    cout << root->name << " (Health: " << root->health << ")"<<endl;
    inorder(root->right);
}

void carePriorityTree() {                                        
    TreeNode* root = NULL;

    for (int i = 0; i < countRes; i++) {
        root = insertTree(root, health[i], names[i]);
    }

    cout << "\n--- CARE PRIORITY (Low -> High) ---"<<endl;
    inorder(root);
}

int main() {
    int choice;

    do {
        cout << "\n====================================\n";
        cout << " OLD AGE HOME MANAGEMENT SYSTEM \n";
        cout << "====================================\n";
        cout << "1. Manage Residents\n";
        cout << "2. Staff Scheduling\n";
        cout << "3. Health & Medicine Logs\n";
        cout << "4. Care Priority Tree\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
           case 1: manageResidents(); break;
            case 2: staffScheduler(); break;
            case 3: healthMedicineLogs(); break;
            case 4: carePriorityTree(); break;
            case 0: cout << "\nExiting Program...\n"; break;
            default: cout << "\nInvalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}


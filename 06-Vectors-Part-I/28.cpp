#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

// --- 1. التوصيفات العامة ---
enum class MemberTier { Regular, Gold, Premium };
enum class UserRole { Admin, Staff };

// --- 2. أدوات الوقت والتواريخ ---
string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
    return string(buffer);
}

string getDueDate(int days) {
    time_t now = time(0) + (days * 24LL * 3600LL);
    tm* ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
    return string(buffer);
}

// --- 3. هياكل البيانات ---
struct BorrowRecord {
    string bookBarcode, bookTitle, bookAuthor, dueDate, staffInCharge, borrowDate;
};

struct UserAccount {
    string fullName, phone, username;
    size_t passwordHash;
    UserRole role;

    string toString() {
        return fullName + "|" + phone + "|" + username + "|" + to_string(passwordHash) + "|" + (role == UserRole::Admin ? "A" : "S");
    }
};

class Book {
public:
    string title, author, barcode, category;
    int totalCopies, availCopies, timesBorrowed, totalReturns;

    Book(string t, string a, string bc, string cat, int tc, int ac, int tb = 0, int tr = 0)
        : title(t), author(a), barcode(bc), category(cat), totalCopies(tc), availCopies(ac), timesBorrowed(tb), totalReturns(tr) {}

    string toString() {
        return title + "|" + author + "|" + barcode + "|" + category + "|" + to_string(totalCopies) + "|" + to_string(availCopies) + "|" + to_string(timesBorrowed) + "|" + to_string(totalReturns);
    }
};

class Member {
public:
    int id;
    string name;
    MemberTier tier;
    vector<BorrowRecord> activeLoans;

    Member(int i, string n, MemberTier t) : id(i), name(n), tier(t) {}

    int getMaxBooks() {
        if (tier == MemberTier::Premium) return 10;
        if (tier == MemberTier::Gold) return 5;
        return 3;
    }

    string toString() {
        string lStr = "";
        for (auto& l : activeLoans)
            lStr += l.bookBarcode + ";" + l.bookTitle + ";" + l.bookAuthor + ";" + l.dueDate + ";" + l.staffInCharge + ";" + l.borrowDate + ",";
        return to_string(id) + "|" + name + "|" + (tier == MemberTier::Premium ? "P" : (tier == MemberTier::Gold ? "G" : "R")) + "|" + lStr;
    }
};

// --- 4. المحرك الرئيسي للنظام ---
class ImperialLibraryOS {
private:
    string libName, managerName, managerPhone;
    vector<UserAccount> accounts;
    vector<Book> books;
    vector<Member> members;
    vector<string> categories;
    UserAccount* currentUser = nullptr;
    bool isSetupDone = false;

    void clear() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    ImperialLibraryOS() { loadAllData(); }
    ~ImperialLibraryOS() { saveAllData(); }

    void loadAllData() {
        ifstream conf("config.dat");
        if (getline(conf, libName) && getline(conf, managerName) && getline(conf, managerPhone)) {
            isSetupDone = true;
        }
        conf.close();

        if (!isSetupDone) return;

        ifstream catFile("categories.dat"); string cL;
        categories.clear();
        while (getline(catFile, cL)) if (!cL.empty()) categories.push_back(cL);
        catFile.close();

        ifstream uFile("users.dat"); string ln;
        accounts.clear();
        while (getline(uFile, ln)) {
            stringstream ss(ln); string fn, ph, un, phash, r;
            if (getline(ss, fn, '|') && getline(ss, ph, '|') && getline(ss, un, '|') && getline(ss, phash, '|') && getline(ss, r, '|'))
                accounts.push_back({ fn, ph, un, (size_t)stoull(phash), (r == "A" ? UserRole::Admin : UserRole::Staff) });
        } uFile.close();

        ifstream bFile("books.dat");
        books.clear();
        while (getline(bFile, ln)) {
            stringstream ss(ln); string p[8]; int i = 0;
            while (getline(ss, p[i], '|') && i < 8) i++;
            if (i >= 8) books.emplace_back(p[0], p[1], p[2], p[3], stoi(p[4]), stoi(p[5]), stoi(p[6]), stoi(p[7]));
        } bFile.close();

        ifstream mFile("members.dat");
        members.clear();
        while (getline(mFile, ln)) {
            stringstream ss(ln); string id, nm, tr, lData;
            if (getline(ss, id, '|') && getline(ss, nm, '|') && getline(ss, tr, '|') && getline(ss, lData, '|')) {
                Member m(stoi(id), nm, (tr == "P" ? MemberTier::Premium : (tr == "G" ? MemberTier::Gold : MemberTier::Regular)));
                stringstream ssL(lData); string rec;
                while (getline(ssL, rec, ',')) {
                    if (rec.empty()) continue;
                    stringstream ssR(rec); string bc, tt, au, dd, st, bd;
                    getline(ssR, bc, ';'); getline(ssR, tt, ';'); getline(ssR, au, ';'); getline(ssR, dd, ';'); getline(ssR, st, ';'); getline(ssR, bd, ';');
                    m.activeLoans.push_back({ bc, tt, au, dd, st, bd });
                } members.push_back(m);
            }
        } mFile.close();
    }

    void saveAllData() {
        ofstream conf("config.dat"); conf << libName << "\n" << managerName << "\n" << managerPhone; conf.close();
        ofstream cats("categories.dat"); for (auto& c : categories) cats << c << "\n"; cats.close();
        ofstream uFile("users.dat"); for (auto& a : accounts) uFile << a.toString() << "\n"; uFile.close();
        ofstream bFile("books.dat"); for (auto& b : books) bFile << b.toString() << "\n"; bFile.close();
        ofstream mFile("members.dat"); for (auto& m : members) mFile << m.toString() << "\n"; mFile.close();
    }

    void performSetup() {
        cout << "\n--- 📥 IMPERIAL SYSTEM INITIAL SETUP ---\n";
        cout << "Enter Library Name: "; getline(cin, libName);
        cout << "Enter Manager Full Name: "; getline(cin, managerName);
        cout << "Enter Manager Phone/Contact: "; getline(cin, managerPhone);
        cout << "Create Master Admin Password: "; string p; cin >> p;
        accounts.push_back({ managerName, managerPhone, "admin", hash<string>{}(p), UserRole::Admin });
        isSetupDone = true;
        saveAllData();
        cout << "\n✅ Setup successful! System is now permanent.\n";
        clear();
    }

    void generateReceipt(string type, Member* m, Book* b, string staff, int days, string due) {
        ofstream f("Receipt.txt");
        string body = "==========================================\n"
                      "      OFFICIAL: " + libName + "\n"
                      "      MANAGER: " + managerName + "\n"
                      "==========================================\n"
                      "TYPE: " + type + " RECEIPT\nSTAFF: " + staff + "\nDATE: " + getCurrentDate() + "\n"
                      "------------------------------------------\n"
                      "STUDENT: " + m->name + " [ID: " + to_string(m->id) + "]\n"
                      "BOOK: " + b->title + "\nAUTHOR: " + b->author + "\nBARCODE: " + b->barcode + "\n";
        if (type == "BORROW") body += "DUE DATE: " + due + " (" + to_string(days) + " Days)\n";
        body += "==========================================\n";
        f << "[[ STUDENT COPY ]]\n" << body << "\n\n[[ LIBRARY COPY ]]\n" << body;
        f.close();
        cout << "\n>>> RECEIPT GENERATED (Receipt.txt) <<<\n";
    }

    bool checkAlerts(Member* m) {
        string today = getCurrentDate(); bool late = false;
        for (auto& l : m->activeLoans) {
            if (today > l.dueDate) {
                cout << "\n!!! BLACKLIST ALERT: LATE BOOK FOUND [" << l.bookTitle << "] !!!\n";
                late = true;
            }
        }
        return late;
    }

    void managerDashboard() {
        while (true) {
            cout << "\n👑 MANAGER PANEL: " << managerName << "\n";
            cout << "1. Manage Categories (المجموعات)\n2. Add Staff Member\n3. View All Students & Alerts\n4. Global Statistics\n5. Export HTML Report\n6. Logout\nChoice: ";
            int c; cin >> c;
            if (c == 1) {
                cout << "\nCurrent: "; for (auto& s : categories) cout << "[" << s << "] ";
                cout << "\nAdd New Category: "; clear(); string nc; getline(cin, nc);
                categories.push_back(nc); cout << "Group Added.\n";
            } else if (c == 2) {
                string fn, ph, p; cout << "Staff Full Name: "; clear(); getline(cin, fn);
                cout << "Staff Phone: "; getline(cin, ph); cout << "Set Password: "; cin >> p;
                accounts.push_back({ fn, ph, "staff", hash<string>{}(p), UserRole::Staff });
                cout << "Staff Added.\n";
            } else if (c == 4) {
                map<string, int> catMap; int total = 0, brw = 0;
                for (auto& b : books) { catMap[b.category]++; total += b.totalCopies; brw += (b.totalCopies - b.availCopies); }
                cout << "\n--- STATS ---\nTotal Books: " << total << "\nActive Loans: " << brw << endl;
            } else if (c == 6) break;
            saveAllData();
        }
    }

    void staffTerminal() {
        while (true) {
            cout << "\n🛠️ STAFF TERMINAL: " << currentUser->fullName << "\n";
            cout << "1. Add/Stock Book\n2. Register Student\n3. Issue Borrowing\n4. Process Return\n5. Student Profile/Alerts\n6. Logout\nChoice: ";
            int c; cin >> c;
            if (c == 1) {
                if (categories.empty()) { cout << "Error: Manager must add Categories first!\n"; continue; }
                string bc; cout << "Scan Barcode: "; cin >> bc;
                auto it = find_if(books.begin(), books.end(), [&](Book& b) { return b.barcode == bc; });
                if (it != books.end()) {
                    int q; cout << "Book: " << it->title << ". Qty to Add: "; cin >> q;
                    it->totalCopies += q; it->availCopies += q;
                } else {
                    string t, a; int q; cout << "Title: "; clear(); getline(cin, t);
                    cout << "Author: "; getline(cin, a); cout << "Select Category:\n";
                    for (int i = 0; i < categories.size(); i++) cout << i + 1 << ". " << categories[i] << endl;
                    int idx; cin >> idx; string ct = (idx > 0 && idx <= categories.size()) ? categories[idx - 1] : "General";
                    cout << "Stock: "; cin >> q; books.emplace_back(t, a, bc, ct, q, q);
                }
            } else if (c == 2) {
                string n; int t; cout << "Student Name: "; clear(); getline(cin, n);
                cout << "Tier (0:Regular, 1:Gold, 2:Premium): "; cin >> t;
                members.emplace_back(1001 + members.size(), n, (t == 2 ? MemberTier::Premium : (t == 1 ? MemberTier::Gold : MemberTier::Regular)));
                cout << "Success. ID: " << members.back().id << endl;
            } else if (c == 3) {
                int id; cout << "Student ID: "; cin >> id;
                auto m = find_if(members.begin(), members.end(), [&](Member& x) { return x.id == id; });
                if (m != members.end()) {
                    if (checkAlerts(&(*m))) { cout << "DENIED: STUDENT IS BLACKLISTED (LATE BOOKS)\n"; continue; }
                    if (m->activeLoans.size() >= (size_t)m->getMaxBooks()) { cout << "LIMIT REACHED!\n"; continue; }
                    string bc; cout << "Scan Book: "; cin >> bc;
                    auto b = find_if(books.begin(), books.end(), [&](Book& x) { return x.barcode == bc; });
                    if (b != books.end() && b->availCopies > 0) {
                        int d; cout << "Loan Days: "; cin >> d; string due = getDueDate(d);
                        b->availCopies--; b->timesBorrowed++;
                        m->activeLoans.push_back({ bc, b->title, b->author, due, currentUser->fullName, getCurrentDate() });
                        generateReceipt("BORROW", &(*m), &(*b), currentUser->fullName, d, due);
                    }
                }
            } else if (c == 4) {
                int id; cout << "Student ID: "; cin >> id;
                auto m = find_if(members.begin(), members.end(), [&](Member& x) { return x.id == id; });
                if (m != members.end()) {
                    string bc; cout << "Scan Return: "; cin >> bc;
                    auto it = find_if(m->activeLoans.begin(), m->activeLoans.end(), [&](BorrowRecord& r) { return r.bookBarcode == bc; });
                    if (it != m->activeLoans.end()) {
                        auto b = find_if(books.begin(), books.end(), [&](Book& x) { return x.barcode == bc; });
                        b->availCopies++; b->totalReturns++;
                        generateReceipt("RETURN", &(*m), &(*b), currentUser->fullName, 0, "");
                        m->activeLoans.erase(it);
                        cout << "Returned successfully.\n";
                    }
                }
            } else if (c == 6) break;
            saveAllData();
        }
    }

    void run() {
        if (!isSetupDone) { performSetup(); }
        while (true) {
            cout << "\n====================================\n";
            cout << "      " << libName << " SYSTEM\n";
            cout << "====================================\n";
            cout << "1. Manager Login\n2. Staff Login\n3. Exit System\nChoice: ";
            int r; cin >> r;
            if (r == 3) break;
            if (r == 1) {
                cout << "Manager Password: "; string p; cin >> p;
                if (hash<string>{}(p) == accounts[0].passwordHash) { currentUser = &accounts[0]; managerDashboard(); }
                else cout << "Incorrect!\n";
            } else if (r == 2) {
                vector<UserAccount*> sList; for (auto& a : accounts) if (a.role == UserRole::Staff) sList.push_back(&a);
                if (sList.empty()) { cout << "No staff. Manager must add staff first.\n"; continue; }
                for (int i = 0; i < sList.size(); i++) cout << i + 1 << ". " << sList[i]->fullName << endl;
                int idx; cin >> idx;
                if (idx > 0 && idx <= sList.size()) {
                    cout << "Password: "; string p; cin >> p;
                    if (hash<string>{}(p) == sList[idx - 1]->passwordHash) { currentUser = sList[idx - 1]; staffTerminal(); }
                }
            }
        }
    }
};

int main() {
    ImperialLibraryOS sys;
    sys.run();
    return 0;
}

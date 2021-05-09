
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct course_info_t {
    string code;
    string title;
    int credit;
    int level;
    string preRequisite;
};

ostream &operator<<(ostream &out, const course_info_t &c) {
    out << "Code: " << c.code << endl;
    out << "Title: " << c.title << endl;
    out << "Credit: " << c.credit << endl;
    out << "Level: " << c.level << endl;
    out << "Pre-requisite: " << c.preRequisite << endl;
    return out;
}

vector<course_info_t> load_data();
vector<course_info_t> find_mode1(const vector<course_info_t> &data, const string &keyword);
vector<course_info_t> find_mode2(const vector<course_info_t> &data, const string &keyword);
vector<course_info_t> find_mode3(const vector<course_info_t> &data, int Num);
vector<course_info_t> find_mode4(const vector<course_info_t> &data, int Num);
void standardOut(const vector<course_info_t> &result);

int main() {
    string keyword;// keyword is used for string input
    int modeNum, keyword2;// keyword2 is used for numeric input
    int input=0;
    
    vector <course_info_t> data = load_data();
    cout << "       Undergraduate course search in COMP      "<<endl;
    cout << "================================================================="<<endl;
    cout << "Three search modes offered by Group 52" << endl;
    cout << "1. Search related courses by typing keyword of course ID \n"<< endl;
    cout << "2. Search related courses by typing keyword of course title\n"<< endl;
    cout << "3. Search related courses by typing keyword of course credit number \n"<< endl;
    cout << "4. Search related courses by typing keyword of course level \n"<< endl;
    
    while(input==0){
        cout << "Please type in mode numebr: ";
        cin >> modeNum;
        
        if(modeNum==1){
            
            input=1;
            cout << "Please type keyword of course ID: ";
            cin >> keyword;
            vector <course_info_t> result = find_mode1(data, keyword);

            standardOut(result);
            
        }else if(modeNum==2){
            input=1;
            cout << "Please type keyword of course title: ";
            
            vector <course_info_t> result = find_mode2(data, keyword);
            standardOut(result);
            
            
        }else if(modeNum==3){
            input=1;
            cout << "Please type keyword of course credit number: ";
            cin >> keyword2;
            
            vector <course_info_t> result = find_mode3(data, keyword2);
            standardOut(result);
            
        }else if(modeNum==4){
            input=1;
            cout << "Please type keyword of course level: ";
            cin >> keyword2;
            
            vector <course_info_t> result = find_mode4(data, keyword2);
            standardOut(result);
            

        }else{
            cout << "Wrong input, please input again!" <<endl;
        }
    }
    return 0;
}

// keyword from course ID 
vector<course_info_t> find_mode1(const vector<course_info_t> &data, const string &keyword) {
    vector <course_info_t> result;
    for (const course_info_t &info : data) {
        if (info.code.find(keyword) != string::npos) {
            result.push_back(info);
        }
    }
    return result;
}

// keyword from course title
vector<course_info_t> find_mode2(const vector<course_info_t> &data, const string &keyword) {
    vector <course_info_t> result;
    for (const course_info_t &info : data) {
        if (info.title.find(keyword) != string::npos) {
            result.push_back(info);
        }
    }
    return result;
}
// keyword from credit
vector<course_info_t> find_mode3(const vector<course_info_t> &data, int Num) {
    vector <course_info_t> result;
    for (const course_info_t &info : data) {
        if (info.credit==Num) {
            result.push_back(info);
        }
    }
    return result;
}

// keyword from level
vector<course_info_t> find_mode4(const vector<course_info_t> &data, int Num) {
    vector <course_info_t> result;
    for (const course_info_t &info : data) {
        if (info.level==Num) {
            result.push_back(info);
        }
    }
    return result;
}


void standardOut(const vector<course_info_t> &result){
    if (result.empty()) {
        cout << "No related course are found" << endl;
    } else {
        cout << "Found " << result.size() << " results" << endl;
    }
    for (int i = 0; i < result.size(); i++) {
        cout << i + 1 << '/' << result.size() << endl;
        cout << result[i] << endl;
    }
}


vector<course_info_t> load_data() {
    vector <course_info_t> data;
    data.push_back({"COMP1001", "Problem Solving Methodology in Information Technology", 3, 1, "Nil"});

    data.push_back({"COMP1002", "Computational Thinking and Problem Solving", 4, 1, "Nil"});

    data.push_back({"COMP1003", "Statistical Tools and Applications", 1, 1, "Nil"});

    data.push_back({"COMP1011", "Programming Fundamentals", 3, 1, "Nil"});

    data.push_back({"COMP1411", "Introduction to Computer Systems", 3, 1, "Nil"});

    data.push_back({"COMP1433", "Introduction to Data Analytics", 3, 1, "Nil"});

    data.push_back({"COMP1901", "Seminars and Topics in Information Technology", 3, 1, "Nil"});

    data.push_back({"COMP1B02", "Friends, Followers and Circles: Connections in a Socially-Computed World",
                    3, 1, "Nil"});

    data.push_back({" COMP1B03 ", "Innovation and Entrepreneurship: The Rise of the ICT Industry in China",
                    3, 1, "Nil"});

    data.push_back({"COMP1D04",
                    "From Scratch to Apps: Foundations of Computational Thinking and Literacy for Problem Solving",
                    3, 1, "Nil"});

    data.push_back({"COMP2011", "Data Structures", 3, 2, "COMP1011"});

    data.push_back({"COMP2012", "Discrete Mathematics", 3, 2, "Nil"});

    data.push_back({"COMP2021", "Object-oriented Programming", 3, 2, "COMP1011"});

    data.push_back({"COMP2022", "Programming for FinTech Applications", 3, 2,
                    "Any programming related subject, e.g., COMP1001 or relevant IT background"});

    data.push_back({"COMP2121", "E-Business", 3, 2, "Nil"});

    data.push_back({"COMP2222", "Introduction to Human-Computer Interaction Methods", 3, 2, "Nil"});

    data.push_back({"COMP2322", "Computer Networking", 3, 2, "COMP1011"});

    data.push_back({"COMP2411", "Database Systems", 3, 2, "COMP1011"});

    data.push_back({"COMP2421", "Computer Organization", 3, 2, "Nil"});

    data.push_back({"COMP2422", "Visual Interface and Interaction Development", 3, 2,
                    "COMP2011, COMP2021"});

    data.push_back({"COMP2432", "Operating Systems", 3, 3, "COMP2011"});

    data.push_back({"COMP2A01", "Whose Data is it Anyway? Information and Internet Ethics, Privacy and Security",
                    3, 2, "Nil"});

    data.push_back({"COMP2S01, COMP2S01S",
                    "Technology Beyond Borders: Service Learning across Cultural, Ethnic and Community Lines",
                    3, 2, "Nil"});

    data.push_back({"COMP3011", "Design and Analysis of Algorithms", 3, 3,
                    "COMP2011 Data Structures or EIE3320 Object-Oriented Design and Programming or equivalent"});

    data.push_back({"COMP3021", "Programming Language Paradigms", 3, 3,
                    "COMP2011 Data Structures or equivalent"});

    data.push_back({"COMP3121", "Social and Collaborative Computing", 3, 3,
                    "Nil"});

    data.push_back({"COMP3122", "Information Systems Development", 3, 3, "COMP2411"});


    data.push_back({"COMP3131", "e Business and Information Systems Strategies", 3, 3, "Nil"});


    data.push_back({"COMP3133", "Chinese Language Processing", 3, 3, "COMP1011"});


    data.push_back({"COMP3134", "Business Intelligence and Customer Relationship Management", 3, 3,
                    "Nil"});

    data.push_back({"COMP3211", "Software Engineering", 3, 3, "COMP2011"});


    data.push_back({"COMP3222", "Software Design Principles", 3, 3, "COMP2011, COMP2021"});


    data.push_back({"COMP3233", "Software Testing and Quality Assurance", 3, 4, "COMP3211"});


    data.push_back({"COMP3235", "Software Project Management", 3, 3, "Nil"});


    data.push_back({"COMP3334", "Computer Systems Security", 3, 3, "COMP2432"});


    data.push_back({"COMP3334", "Computer Systems Security", 3, 3, "COMP2432"});

    data.push_back({"COMP3335", "Database Security", 3, 3,
                    "COMP2411 or equivalent introductory database subject"});

    data.push_back({"COMP3421", "Web Application Design and Development", 3, 3, "COMP1011"});

    data.push_back({"COMP3422", "Creative Digital Media Design", 3, 3, "COMP2011"});

    data.push_back({"COMP3423", "Human Computer Interaction", 3, 3, "COMP1011"});

    data.push_back({"COMP3432", "Innovative Computing Paradigms", 3, 3, "COMP2011, COMP2021"});

    data.push_back({"COMP3438", "System Programming", 3, 3, "COMP2432"});

    data.push_back({"COMP3511", "Legal Aspects and Ethics of Computing", 2, 3, "Nil"});

    data.push_back({"COMP3512", "Legal Aspects, Professionalism and Ethics of Computing", 3, 3, "Nil"});

    data.push_back({"COMP3531", "IT Entrepreneurship", 3, 3, "Nil"});

    data.push_back({"COMP3911", "Service-Learning and Civic Engagement in the Information Age", 3, 3, "Nil"});

    data.push_back({"COMP3921-3923", "FinTech Seminars and Case Studies (I, II and III)", 3, 3, "Nil"});

    data.push_back({"COMP3924", "FinTech Seminars and Case Studies", 3, 3, "COMP3921-23"});

    data.push_back({"COMP3S02", "Socially Responsible Global Leadership in a Digital World", 3, 3, "Nil"});

    data.push_back({"COMP4000", "Industrial Placement", 24, 4, "Nil"});

    data.push_back({"COMP4001", "Internship", 12, 4, "Nil"});

    data.push_back({"COMP4011", "Theory of Computation", 3, 4, "COMP3011"});

    data.push_back({"COMP4121", "E-Commerce Technology and Applications", 3, 4, "COMP2411, COMP3421"});

    data.push_back({"COMP4122", "Game Design and Development", 3, 4, "COMP2011"});

    data.push_back({"COMP4123", "Business Process and Workflow Management", 3, 4, "Nil"});

    data.push_back({"COMP4125", "Operations Research and Logistics Management", 3, 4, "COMP1011, COMP2011"});

    data.push_back({"COMP4127", "Information Systems Audit and Control", 3, 4, "Nil"});

    data.push_back({"COMP4127", "Information Systems Audit and Control", 3, 4, "Nil"});

    data.push_back({"COMP4133", "Information Retrieval", 3, 4, " COMP2011, COMP2411"});

    data.push_back({"COMP4134", "Biometrics and Security", 3, 4, "Nil"});

    data.push_back({"COMP4135", "Knowledge and Information Management", 3, 4, "Nil"});

    data.push_back({"COMP4141", "Crowdfunding and E-Finance", 3, 4,
                    "Basic concepts of finance and computing"});

    data.push_back({"COMP4142", "E-Payment and Cryptocurrency", 3, 4, "COMP3334"});

    data.push_back({"COMP4146", "Computational Finance", 3, 4, "Nil"});

    data.push_back({"COMP4322", "Internetworking Protocols, Software and Management", 3, 4, "COMP2322"});

    data.push_back({"COMP4332", "Mobile Security: Principles and Practice", 3, 4,
                    "COMP1011 and COMP2322 and COMP2432/COMP1411 and COMP3334"});

    data.push_back({"COMP4334", "Principles and Practice of Internet Security", 3, 4, "COMP3334"});

    data.push_back({"COMP4422", "Computer Graphics", 3, 4, "COMP2011"});

    data.push_back({"COMP4423", "Computer Vision", 3, 4,
                    "COMP2011 or EIE2106 (Signals and Systems) for EIE students"});

    data.push_back({"COMP4431", "Artificial Intelligence", 3, 4, "COMP2011"});

    data.push_back({"COMP4432", "Machine Learning", 3, 4,
                    "Nil (but students are preferred to have some previous exposure to introductory"
                    "Artificial Intelligence/Data Analytics concepts and be familiar with basic notions in"
                    "linear algebra and probability)"});

    data.push_back({"COMP4433", "Data Mining and Data Warehousing", 3, 4, "COMP2411"});

    data.push_back({"COMP4434", "Big Data Analytics", 3, 4, "AMA1104, COMP1011, COMP2011, COMP2411"});

    data.push_back({"COMP4435", "Dependable Computing", 3, 4, "Nil"});

    data.push_back({"COMP4438", "Embedded Software", 3, 4, "COMP3438"});

    data.push_back({"COMP4441", "Enterprise Middleware and Application", 3, 4, "COMP1011"});

    data.push_back({"COMP4442", "Service and Cloud Computing", 3, 4,
                    "2421 Computer Organization & COMP 2432 Operating Systems, or equivalent subjects"});

    data.push_back({"COMP4512", "Intellectual Property Protection and Management", 3, 4, "Nil"});

    data.push_back({"COMP4531", "Emerging Topics in FinTech", 3, 4, "Nil"});

    data.push_back({"COMP4911/4912", "Capstone Project I / II", 3, 4,
                    "COMP 4911 for taking COMP 4912"});

    data.push_back({"COMP4913", "Capstone Project", 6, 4, "Nil"});

    data.push_back({"COMP4921", "Final Year Project", 9, 4, "COMP4911/4912 "});

    return data;

}

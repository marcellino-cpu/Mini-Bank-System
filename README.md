# Mini-Bank-System
​🏦 Mini Bank Management System (C++)

📖 Project Background

Hello! I am a first-year student at Ain Shams University – Faculty of Computer and Information Sciences.
This project initially started as a university assignment with the following basic requirements:

- Input account details
- Display yearly amount for 10 years
- Display the amount at a specified year

However, I took the initiative to expand the assignment into a fully functional banking system by independently learning and applying the STL (Standard Template Library) to implement more advanced and efficient features.

---

🚀 Expanded Features

💰 Financial Operations

- Real-time Deposit and Withdrawal functionality.

👤 Account Management

- Add new bank accounts.
- Search accounts using Customer ID.

📜 Transaction Tracking

- Maintain a complete log of all successful transactions.

🛡️ Input Validation

- Prevents:
  - Negative deposits or withdrawals
  - Duplicate Customer IDs or negative IDs .
  - Invalid inputs for questions .
  - searching about a non-existing account or deposit or withdrawal from a non-exsiting account .

---

🛠️ Technical Implementation & Optimization


Code cleanliness :Removing using namespace std; and switched to explicict std:: namespacing to avoid naming collisions.

To enhance performance and move beyond traditional arrays, the system uses advanced STL containers:


🔹std::unordered_map<std::string, AccoundData> Stored_accounts

- Ensures efficient account lookup with O(1) time complexity for faster access by Customer's ID .
- Initially , "std::map<std::string, AccountData>" was considered , which provides O(log n) lookup time and maintains elements in sorted order . However , since this system performs frequent account lookups by ID and does not require sorted traversal , unordered map was chosen as a more efficient allternative.

  
🔹 "std::map<int, float>" Stored_years 

- Used to store yearly data with O(log n) lookup complexity.
In this case, maintaining the elements in sorted order by year is required for structured traversal and chronological display. Therefore, std::map was chosen instead of std::unordered_map, as it guarantees ordered storage of elements.
  
🔹 High-Speed Searching

- Implemented using the Single-Shot Technique:
"auto itr = find.accounts()"
"if (itr != accounts.end())"

This avoids unnecessary looping and enables instant access to account data.

---
Modern C++ Techniques & Optimization

- ​The project utilizes advanced C++ standards to ensure memory efficiency and high execution speed:
​Passing by Reference for maps and vectors :

1 - ​Used in all major functions to prevent unnecessary Deep Copying .
2 - ​Significantly reduces CPU overhead and memory consumption during account lookups.


- ​Classical Iterators(in maps) : For precise control over STL containers .


- ​Range-Based Loops(maps):
for (const auto& account : accounts).


- ​Const Correctness: Applied to function parameters to ensure data integrity and prevent accidental modification of customer records.


** And when needed to modify the vector M in History_display function 
Const is removed .

---

🔹 "vector<string>"

- Used to store dynamic transaction history logs.

---

🧩 Modular Programming

The entire system is structured using reusable functions to improve:

- Code readability
- Maintainability
- Scalability

---
Click here to watch the program Demo on Google drive : 
https://drive.google.com/file/d/112kKQzVO7tRcXjv4UiSdpaTcnMnIdPRQ/view?usp=sharing



📌 Future Improvements

- GUI Integration
- File Handling System
- Authentication Layer
- Database Support

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
  - Duplicate Customer IDs or negative ISs .
  - Invalid inputs for questions and also .
  - searching about a non-existing account or deposit or withdrawal from a non-exsiting account .

---

🛠️ Technical Implementation & Optimization

To enhance performance and move beyond traditional arrays, the system uses advanced STL containers:

🔹 "map<int, AccountData>"

- Ensures efficient account lookup with O(log n) time complexity.

🔹 High-Speed Searching

- Implemented using the Single-Shot Technique:

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


📌 Future Improvements

- GUI Integration
- File Handling System
- Authentication Layer
- Database Support

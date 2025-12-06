🚗 Car Sales Management System (C Program)

A fully interactive Car Sales Management System built in C.
This program allows customers to purchase cars, apply membership discounts, view sale statistics, add reviews, and stores all transaction history in a file for future use.

⭐ Features
🛒 Customer Purchase System

Choose from multiple car brands

Enter desired quantity

Automatically checks inventory

Membership-based discount (20%)

Calculates total cost per sale

Stores all sales in memory and file

📊 Sales History & Stats

Saves transactions to sales_data.txt

Loads previous sales automatically at startup

Displays:

Customer name

Car brand

Quantity purchased

Total price

Discount given

Shows total cars sold, revenue, and remaining stock

⭐ Customer Reviews

Add reviews (up to 300 characters each)

View all previously added reviews

Supports up to 500 reviews

🔧 System Features

Input validation for all user choices

Structured menus and clean navigation

Uses arrays and file handling

Suitable for university assignments or portfolio projects

🛠 Technologies Used

C / GCC

File handling (fopen, fprintf, fgets)

Strings & arrays

Modular functions

Input validation logic

📦 Project Structure
main.c               -> Main program
sales_data.txt       -> Auto-generated file storing sales history
README.md            -> Project documentation

▶️ How to Compile & Run
gcc main.c -o car_sales
./car_sales


Works on Windows, macOS, and Linux.

📌 Future Improvements

Replace text file with SQLite or MySQL

Add admin login system

Add a GUI (Qt, GTK, or Tkinter—via bindings)

Export sales as CSV/PDF

Add unit tests

👤 Author

Developed by Md. Afrajur Rahman Arif, Computer Science Undergraduate.

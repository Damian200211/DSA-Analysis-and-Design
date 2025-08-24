# DSA-Analysis-and-Design

# Portfolio Reflection

These projects were all about one core idea: how to handle data efficiently. The main goal was to build a C++ program that could load, sort, and print a list of university courses. But before writing the program, I had to analyze the tools for the job—specifically, the performance and memory costs of different data structures.

My biggest takeaway was that choosing the right data structure from the start is half the battle. A bad choice can slow a program to a crawl, especially as data grows. With that in mind, I chose a vector to hold the course data. After loading everything, I implemented my own Quicksort algorithm to organize the list alphanumerically. Building the sort myself was a powerful exercise, as it forced me to understand exactly how the data was being partitioned and moved around in memory.

The most challenging part was connecting theory to practice. This became very real when I was implementing the Quicksort algorithm; getting the partitioning logic correct was tricky and had a direct impact on performance. Another hurdle was reliably parsing the course data from the CSV file. I solved that by creating a dedicated function just for that task, which kept my code much cleaner and easier to debug.

Overall, this work has changed how I approach programming. I no longer just jump in and start coding. I now stop and think about the data first, How should it be stored? What operations will be most common? This shift has made me a more thoughtful and effective developer. I also focus on writing code that is easy to read and maintain, breaking it into smaller functions and leaving comments that explain why I made a certain decision. I learned that writing code for your future self or your team is just as important as making it work today.

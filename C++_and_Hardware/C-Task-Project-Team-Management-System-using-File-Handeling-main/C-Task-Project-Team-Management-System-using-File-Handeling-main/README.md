##  The project consists of the following main components implemented in C++:

- **Task Class** – Represents individual tasks with ID, name, description, and priority.
- **Project Class** – Groups multiple tasks under a project with ID, name, and deadline.
- **Employee Class** – Holds employee details and assigned tasks.
- **Team Class** – Combines project and employee data using multiple inheritance.
- **TaskManager Class** – Provides functions to update tasks/projects and generate summary reports.
- **Friend Functions** – Used to assign tasks to employees safely across classes.
- **File Handling** – Saves and loads data for tasks, projects, employees, and teams into text files.

The main program demonstrates:

1. Creating tasks, projects, employees, and teams.
2. Assigning tasks to employees and projects to teams.
3. Saving all records to text files.
4. Loading records and displaying them in the console.
5. Generating a consolidated summary report.

> The full C++ code is available in the `Task_Management_System.cpp` file in this repository.

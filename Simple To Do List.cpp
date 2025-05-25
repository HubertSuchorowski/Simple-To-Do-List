#include <iostream>
#include <vector>
#include <string>


struct Task {
	std::string name;
	std::string description;
};

void printWelcomeMessage()
{
	std::cout << "Welcome to the Simple To-Do List!" << std::endl;
}

void printMenu()
{
	std::cout << "Instructions:" << std::endl;
	std::cout << "1. Add a task" << std::endl;
	std::cout << "2. Remove a task" << std::endl;
	std::cout << "3. View tasks" << std::endl;
	std::cout << "4. Exit" << std::endl;
}

void getTask(Task& task) {
	std::cout << "Enter the task: ";
	std::cin >> task.name;
	std::cout << "Enter the task description: ";
	std::cin.ignore();
	std::getline(std::cin, task.description);
}

void addTask(std::vector<Task>& list, const Task& task) {
	list.push_back(task);
	std::cout << "Task added: " << task.name << " " << task.description << std::endl;
}

void removeTask(std::vector<Task>& list) {
	std::cout << "Enter the number of the task to remove: \n";
	int i;
	std::cin >> i;
	if (i >= 1 && i <= static_cast<int>(list.size())) {
		Task removedTask = list[i - 1];
		list.erase(list.begin() + (i - 1));
		std::cout << "Task: " << removedTask.name << " " << removedTask.description << " removed\n";
	}
	else {
		std::cout << "Wrong choice. No such task. \n";
	}
}

void displayTasks(const std::vector<Task>& list) {
	if (list.empty()) {
		std::cout << "No tasks available." << std::endl;
		return;
	}
	else
	{
		std::cout << "Your tasks are: \n";
		for (size_t i = 0; i < list.size(); i++) {
			std::cout << (i + 1) << ": " << list[i].name << " - " << list[i].description << std::endl;
		}
	}
}

void askContinue(std::string& continueChoice) {
	std::cout << "Do you want to continue? (y/n): ";
	std::cin >> continueChoice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
	std::vector<Task> list;
	Task task;
	int choice;
	std::string continueChoice;

	printWelcomeMessage();
	do {
		printMenu();
		std::cin >> choice;
		switch (choice) {
			case 1:
				getTask(task);
				addTask(list, task);
				break;
			case 2:
				removeTask(list);
				break;
			case 3:
				displayTasks(list);
				break;
			case 4:
				std::cout << "Exiting the program." << std::endl;
				return 0;
			default:
				std::cout << "Invalid choice. Please try again." << std::endl;
				break;
		}
		askContinue(continueChoice);
	} while (std::tolower(continueChoice[0]) == 'y');
}



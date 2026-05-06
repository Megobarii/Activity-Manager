# Daily Task Manager

A simple terminal-based application for managing daily activities.  
It allows users to add, delete, complete, and view tasks.

This is my first GitHub repository, so the project may still look relatively raw. Feedback, suggestions, and improvements are welcome.

---

## Features

- Add daily activities
- Mark activities as completed
- Delete activities
- View current activity list

Future updates may introduce additional features and improvements.

---

## Project Structure

The project is organized as follows:

### `daily.cpp`
Acts as the main entry point of the application. It handles program flow and user interaction logic.

### `utility.cpp` / `utility.h`
Contains helper functions and core utilities used across the project (excluding menu logic). Future shared functionality will likely be added here.

### Menu Functions
- `add_menu`
- `complete_menu`
- `delete_task`

These functions handle user interactions for their respective operations and are called from `daily.cpp` based on user input.

> **Note:** There is a naming inconsistency (`*_menu` vs `delete_task`). This is a known issue and will be standardized in a future update.

---

## Code Notes

- The codebase includes comments explaining implementation details and design decisions.
- Some placeholder or empty functions exist in `daily.cpp`; these are planned features for future development.
- The project is intentionally simple and will evolve over time.

---

## Feedback

If you have any suggestions, improvements, or feedback, feel free to reach out or contribute.

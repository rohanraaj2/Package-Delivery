
# Package Delivery System

This project implements a **Binary Search Tree (BST)** to manage and simulate journeys for delivery trucks.

### Features
- **Truck Management:** Each truck has a driver, petrol, registration number, and mileage attributes.
- **BST Storage:** Trucks are stored in a BST, ordered by registration number.
- **Journey Simulation:** Each truck attempts a 60 km loaded + 60 km return trip, with fuel deducted based on mileage. Only trucks with enough fuel complete the trip.
- **File I/O:**
  - `Input.txt`: Input file with truck data (5 lines per truck).
  - `Trip.txt`: Output file with updated truck data after the journey, sorted by registration number.

### Main Functions
- `loadTrucks()`: Parses `Input.txt` and populates the BST.
- `makeJourney()`: Simulates the journey and updates fuel for each truck.
- `unloadTrucks()`: Outputs the updated truck data in order to `Trip.txt`.

### File Structure
```
Package-Delivery/
├── PackageDelivery/
│   ├── Input.txt         # Input data for trucks
│   ├── Trip.txt          # Output after simulation
│   ├── main.cpp          # Main program logic
│   ├── truck.hpp         # Truck class definition
│   ├── node.hpp          # BST node definition
├── vectorDemo.cpp        # Example usage of std::vector
├── Assignment03.tex      # Assignment writeup (LaTeX)
├── CS224___Homework_3.pdf# Assignment PDF
├── .gitignore            # Git ignore file
```

### Example Truck Entry in `Input.txt`
```
Elton John
34
AB218
9
7
```

### Technical Notes
- **Vectors:** See `vectorDemo.cpp` for an example of using `std::vector`.
- **File I/O:** Standard C++ file streams are used for reading and writing files.

### How to Run
1. Ensure all source files are in `PackageDelivery/`.
2. Compile `main.cpp`:
   ```bash
   g++ PackageDelivery/main.cpp -o package_delivery
   ```
3. Run the program:
   ```bash
   ./package_delivery
   ```
4. Check `Trip.txt` for the output.

### Credits
Some parts adapted from assignments by **Dr. Umair Azfar Khan**.

---

For more details, see the assignment PDF and LaTeX files included in this repository.
